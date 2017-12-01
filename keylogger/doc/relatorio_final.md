# Keylogger

* **Disciplina**:

	Fundamento de Sistemas Operacionais

* **Professor**:

	Fernando W Cruz

* **Integrantes**:

	|Nome|Matrícula|Github|
	|----|---------|------|
	|Arthur Temporim|14/xxxxxx|[arthurTemporim](https://github.com/arthurTemporim/)|
	|Ícaro Pires|15/0129815|[icaropires](https://github.com/icaropires/)|


## Introdução

O módulo aqui descrito foi feito no contexto da disciplina universitária de Fundamentos de Sistemas Operacionais e tem apenas objetivos acadêmicos. O foco desse trabalho é na área de __device drivers__ e foi proposto que uníssemos esse contexto ao contexto dos vírus, construindo assim um módulo que contém um vírus, além de algumas exigências mais específicas.

Caso o leitor queira reproduzir o experimento, não nos responsabilizamos por eventuais problemas/danos em dispositivos e nem outras eventuais consequências de seu uso.

### Vírus

#### Conceito

Vírus são softwares maliciosos que após entrar numa máquina host, têm a função de se propagarem por meio da rede ou de se multiplicarem e também causar danos ao sistema. Outra caracterísca dos vírus é a de que eles precisam de uma ação do usuário para serem disparados e começarem a agir.

#### Vírus para device drivers

Um vírus que se infiltra num computador pelo software device driver (o software usado para controlar periféricos como o teclado).

## Fases do projeto

Para a construção deste módulo foram seguidos os seguintes passos:

### 1. Estudo inicial sobre device drivers e vírus

Diante da abragência do assunto, foi realizado um estudo inicial para melhor entendimento e assim uma melhor escolha do módulo que estaríamos desenvolvendo.

### 2. Definição do projeto e escopo

Após o estudo inicial foi decidido que faríamos um módulo para **teclados**. O escolhemos Por ser um dispositivo de I/O bastante comum, com várias possibilidades de abordagem e não ser um dispositivo demasiadamente complexo para o nosso contexto atual. Inicialmente havíamos decidido por um device driver que permitisse ao usuário mapear facilmente as teclas, mas com mais estudo e alguns motivos que citaremos mais tarde neste documento, decidimos alterar a escolha para um __keylogger__.

### 3. Estudo da implementação

Nessa fase procuramos por referências mais específicas ao nosso projeto, como captaríamos as teclas pressionadas? Como salvaríamos isso no espaço do usuário? Como funciona o teclado?

### 4. Planejamento do projeto

O tempo disponível para a construção do projeto juntamente com o escopo definido foi levado em consideração para a definição/divisão das atividades assim como para   datas de econtros presenciais ou não para a construção do projeto. Com boa parte do estudo já feita, definimos as seguintes tarefas que seriam realizadas até que o projeto fosse finalizado:

- [x] Conseguir compilar um módulo hello world

- [x] Descobrir qual driver está sendo usado pelo teclado

- [x] Descobrir se o driver é geral para todo driver que usa esse barramento

- [x] Escrever um interrup_handler que imprima qual tecla foi pressionada

- [x] Fazer com que seja possível remover o interrupt_handler sem ser necessário reiniciar o computador

- [x] Conseguir mapa de todos os scancodes para teclas

- [x] Conseguir fazer o driver imprimir os valores das teclas em um arquivo no espaço do usuário

- [x] Fazer script para traduzir o arquivo de scancodes para teclas

- [x] Facilitar uso do mecanismo como um todo

### 5. Implementação

#### Estratégia
A estratégia era a de que construiríamos um módulo que capturaria as teclas digitadas pelo usuário e apenas isso. Isso seria o que seria feito no kernel. E então, no espaço do usuário, seria escrito um tradutor processaria esses dados coletados (dados completamente crús, scancodes) em caracteres ASCII que poderiam ser lidos pelo usuário.

Fazendo essa separação, seria possível diminuir a quantidade de processamento e memória utilizada no espaço do kernel (que é um espaço mais limitado se tratando de recursos) e faríamos isso num espaço que temos mais ferramentas a disposição. Além disso, estaríamos seguindo a prática de separar o mecanismo da política e atribuiríamos ao módulo apenas a tarefa de interagir com o hardware.

#### Módulo

Como o módulo seria feito para o sistema operacional Linux, que é escrito em **C**, o mais apropriado é que o módulo também fosse implementado em **C**, pois ele seria inserido no kernel. E essa foi a escolha que fizemos.

Na primeira versão, tínhamos decidido que os dados seriam passados para o espaço do usuário através de um arquivo que seria escrito em tempo de execução do módulo, mesmo com a comunidade do Linux reprovando esse tipo de estratégia (de escrever em arquivos à partir de um módulo do kernel) devido a vários fatores, se o leitor se interessar, poderá se aprofundar mais no assunto nos links nas referências.

Não nos preocupamos tanto com as desvantagens que a comunidade relatava pois não era nossa intenção fazer um módulo que realmente seria integrado como parte do kerneldo linux, mas apenas um keylogger. Insistir nessa estratégia nos trouxe vários problemas, pois como a prática é reprovada pela comunidade, não haviam muitos tutoriais e nem dúvidas solucionadas online.

Mas enfim conseguimos realizar a gravação dos scancodes digitados em um arquivo, utilizando a biblioteca de filesystem provida pelo kernel, utilizando funções de baixo nível como a vfs_write() e chaveando o espaço de endereçamento do file system manualmente, através das funções get_fs() e set_fs().

Porém, o módulo só funcionou corretamente num computador com a distribuição Manjaro e não funcionou em computadores com as ditribuições Ubuntu 16.04 e Mint, após a primeira tecla digitada o dispositivo parava de responder e nada podia ser feito além de forçar seu desligamento.

Para a captura das teclas do usuário utilizamos as próprias biliotecas do kernel para escrever um interrupt_handler. Esse interrupt_handler seria cadastrado na lista de interrupt handlers do teclado e, portanto, seria chamado a cada vez que o teclado causasse uma interrupção em alguma das CPU's.

Um detalhe importante a se notar, é que nessa parte foi considerado que o dispositivo teclado seria sempre o dispositivo com identificador 1 na lista de dispositivos que podem causar interrupções na CPU,  esse arquivo encontra-se em /proc/interrupt_handlers. Mas provavelmente esse detalhe não será problema em versões mais recentes do kernel e uso de dispositivos mais recentes.

Um detalhe que ainda não foi citado é o de que a função que foi usada para gravar as teclas digitadas no arquivo só suportava que fossem gravados chars, ou seja, tínhamos a disposição um byte e poderíamos gravar valores apenas até 255 (já desconsiderando valores sinalizados).

Felizmente, os scancodes das teclas principais ficam todas abaixo desse limiar, ficando acima dele apenas algumas funções especiais de teclados modernos, como teclas multimídia. Outro problema derivado disso, é que o arquivo estaria todo gravado com chars ao invés de inteiros que representariam os scancodes, dificultando a tradução.

#### Tradutores

Tendo o arquivo com os scancodes das teclas digitadas, precisávamos agora traduzir esse arquivo para ASCII para que alguém consigo lê-lo. Como o arquivo foi gravado com chars, escolhemos a linguagem **C** para realizar a primeira etapa da tradução, devido sua característica em tratar tudo como números.

De fato, essa característica facilitou o trabalho, foi necessário apenas ler as entradas do arquivo formatadas para unsigned int e salvá-las num inteiro. Com isso, já tínhamos os scancodes representados em inteiros. Por fim, gravávamos o conteúdo, já em inteiro, num segundo arquivo (para preservar os dados originais).

Numa segunda etapa, escrevemos um programa em python que:

* Executaria o binário gerado pelo código em C;

* Processaria esse arquivo de inteiros gerado na primeira etapa;

* Trocaria os scancodes pelas teclas, já realizando os tratamentos necessários;

* Gravaria o conteúdo "amigável" num novo arquivo.

Python foi utilizado por sua facilidade em lidar com esse tipo de tarefa e tratamentos, além de que não é necessário um desempenho extramente rápido como o do C.

Para obter o mapeamento das teclas para scancodes, utilizamos o programa evtest. Dado o dispositivo, ele gera uma lista com os scancodes e nome associado a cada scancode. Salvamos esses dados num arquivo e adicionamos nele algumas informações que poderiam ser úteis, como a representação em hexadecimal do scancode (para checar se os valores em decimal estavam corretos), e os "nicks" das teclas. Dessa forma consegueríamos mapear uma tecla KEY_A para apenas "a" e uma tecla ENTER para a quebra de linha, gerando assim uma saída mais fácil de ser interpretada.

Também adaptamos essa lista gerada para que fosse compatível o mapeamento de teclado brasileiro ABNT-2. As duas versões foram mantidas e o usuário consegue traduzir a entrada crua usando o padrão brasileiro para mapeamento do teclado ou o americano.

#### Usabilidade

Claro que a intenção não era produzir um software comercial, mas como foram utilizados vários mini-programas independentes, também escrevemos um script em bash que lidaria com eles e para isso, só precisaria que o usuário lhe informasse qual idioma do mapeamento de teclas e qual arquivo desejasse traduzir, se não seria usado o default.

### 7. Testes

### Ambiente

Os testes foram realizados em dois ambientes:

#### Ambiente Ubuntu:

	Distribuição: Ubuntu 16.04
	Versão do kernel: 4.4.0-101-generic

##### Ambiente Manjaro:

	Distribuição: Manjaro
	Versão do kernel: 4.9.65-1-MANJARO 

OBS: Não foram utilizadas máquinas virtuais, pois o interrup_handler não captava as teclas digitadas a partir dela. 

### 8. Evolução

Tentamos de várias formas resolver o problema de compatibilidade com o Ambiente Ubuntu e descobrimos que essa incompatibilidade era na chamada da função vfs_write(). Após várias tentativas sem sucesso de solucionar esse problema (provavelmente seria alguma incompatibilidade na versão do kernel), desistimos dessa abordagem de escrever num arquivo.

Decidimos utilizar o próprio log do kernel para armazenar os dados das teclas pressionadas, visto que para imprimir no log do kernel apenas a função printk() utilizada no interrupt_handler já é suficiente. Não utilizamos essa abordagem antes pois imaginos que separar os dados de scancodes do restante dos logs seria mais custoso pra executar e mais trabalhoso para implementar, o que não se mostrou verdade comparado a estratégia de escrever no arquivo.

Para separar os dados dos scancodes do restante dos logs, utilizamos funções do próprio bash, como grep, sed e cut. Para facilitar o procedimento e manter os dados disfarçados no ambiente, para continuar coerente com a situação hipotética do vírus, imprimos os scancodes como uso se fossem mW de bateria sendo gastos.

Para que o restante do mecanismo se adaptasse ao novo sistema, removemos os códigos de tratamento de arquivos do módulo, apagamos o tradutor em C e embutimos as chamadas das funções do bash no tradutor em python, assim, eliminamos uma das etapas. Foi também adaptado o script em bash, na prática a principal diferença é que agora, o segundo parâmetro passado a ele se refere a quantidade de linhas do log do kernel que ele deseja processar.

Dessa forma, o keylogger passou a funcionar em ambos ambientes, apenas com a diferença de que foi feita uma alteração no script em bash para que ele leia diretamente o arquivo de log no caso do Ambiente Ubuntu (este arquivo está em /var/log/.kern_log) e para o Ambiente Manjaro, ele execute o comando journalctl.

OBS: Muito provavelmente o keylogger pode ser executado em todas as distribuições variantes do Debian e Arch com poucas ou nenhuma alteração, testes são necessários.

## Instruções

Neste tópico é descrito como instalar e utilizar o Keylogger.

### Instalação

### Uso

### Monitoramento

### Remoção

## Referências

Vírus de computador, https://pt.wikipedia.org/wiki/V%C3%ADrus_de_computador, acessado em 27/11/2017.

What Is the Difference: Viruses, Worms, Trojans, and Bots?, https://www.cisco.com/c/en/us/about/security-center/virus-differences.html, acessado em 27/11/2017.

### arrumar:
https://en.wikipedia.org/wiki/PC_System_Design_Guide#PC_97
https://en.wikipedia.org/wiki/USB_human_interface_device_class#Keyboards
http://www.usb.org/developers/hidpage/Hut1_12v2.pdf (Capítulo 10)
https://www.computerhope.com/jargon/i/irq.htm
https://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html (Tópico 1.4)
Capítulos 1, 2, 3, 10 do Livro Linux Device Drivers
http://cs.smith.edu/~nhowe/262/oldlabs/keyboard.html
http://www.linuxjournal.com/node/8110/print
http://ytliu.info/notes/linux/file_ops_in_kernel.html
https://github.com/Golevka/rapoov7-keyboard-driver/blob/master/keystroke.c
https://github.com/kinglongmee/rapoo-keyboard-driver/blob/master/hid-rapoo.c
https://github.com/aleksandr-rakov/hid-a320/blob/master/hid-a320.c
https://github.com/its-izhar/USB_HID_Keyboard_Driver_v2/blob/master/usbkbd_v2.c
https://github.com/torvalds/linux/tree/ead751507de86d90fa250431e9990a8b881f713c/drivers/input/keyboard
http://www.linuxjournal.com/article/8110
