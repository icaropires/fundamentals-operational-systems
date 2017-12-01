# Keylogger

* Disciplina:

Fundamento de Sistemas Operacionais

* Professor:

Fernando W Cruz

* Integrantes:

|Nome|Github|
|----|------|
|Arthur Temporim|[arthurTemporim](https://github.com/arthurTemporim/)|
|Ícaro Pires|[icaropires](https://github.com/icaropires/)|


## Introdução

O driver aqui descrito, foi feito de forma experimental e não passou por uma bateria rígida de testes. Logo não nos responsabilizamos por eventuais problemas e/ou danificações em seu dispositivo.

### O que é Vírus?

Vírus são softwares maliciosos que após entrar na máquina host, tem a função de se propagarem por meio da rede ou de se multiplicarem e também causar danos ao sistema. Outra caracterísca dos vírus, é que eles precisam de uma ação do usuário para ser disparado e começar a agir.

Relatório do projeto final da disciplina de FSO. Neste documento é descrito a construção de um device driver capaz de coletar todas as teclas digitadas pela máquina infectada e armazenar em um arquivo.

### Tipos de Vírus

1. Setor de boot

Vírus de boot são os aqueles que infectam a parte de inicialização do sistema para serem inicializados quando o HD é carregado.

2. Macro

Vírus de macro vinculam suas macros a modelos de documentos e a outros arquivos para que quando um aplicativo carregar o arquivo, executar as instruções do vírus alí "alojadas".

3. Proteção

Existem recomendações como:

* Manter o Sistema Operacional atualizado.

* Instalar softwares de Antivírus.

* Instalar Firewalls.

* Instalar antispywares para remover ou detectar vírus.

## Metodologia

Para a construção deste driver foram seguidos os seguintes passos:

1. Estudo inicial sobre Device Drivers e Vírus

Existem inúmeras opções na construção de device drivers, logo um estudo inicial foi feito para ter uma visão geral das possibilidades e assim decidir qual tema utilizar.

2. Definição do projeto

Após efetuar o estudo o tema de **Teclado** foi escolhido, por ser um dispositivo de I/O comum em todos os computadores e com várias possibilidades de abordagem.

3. Estudo da implementação

Com o tema definido foi estudado como implementar um device driver que utiliza o teclado. Nesse ponto foi definido a criação de um **Keylogger**.

4. Definição do escopo

O escopo do projeto foi definido com a construção de um driver que fosse capaz de coletar tudo que o usuário digita e armazenar esta informação. Outro ponto do projeto foi também a criação de scripts de tradução para que fosse capaz a leitura das informações coletadas.

5. Planejamento do projeto

O tempo disponível para a construção do projeto juntamente com o escopo definido foi levado em conta para a definição das atividades, divisão das atividades e marcação dos econtros presenciais ou não para a construção do projeto.

6. Implementação

A implementação foi feita utilizando a linguagem **C** para a construção do driver, linguagem **Python** para a implementação do script de tradução e **Bash scripts** para automatizar execuções e chamada de partes da solução.

7. Testes

Os testes foram feitos em dois computadores de sistemas distintos, **Ubuntu 16.04** e **Manjaro**. Para garantir que o keylogger estava com comportamento correto ele foi instalado e testado nas duas máquinas e a verificação do seu comportamento era verificada a cada nova adição no sistema.

8. Evolução

Após a versão inicial finalizada e todas as partes do Keylogger estarem finalizadas, mais estudos foram feitos e uma solução mais eficiente surgiu. O processo de evolução foi iniciado para a implementação desta nova solução que será descrita no tópico de **solução**.

## Solução

### Versão Beta

A solução implementada foi a criação de um device driver que, após instalado, fica armazenando um um arquivo oculto todas as teclas pressionadas pelo computador "infectado", inclusive quando são liberadas no caso de teclas como **capslock** e **shift**.

Após as informações serem armazenadas, um script python é executado para fazer a tradução dos dados armazenados.

### Versão Alpha

## Instruções

Neste tópico é descrito como instalar e utilizar o Keylogger.

### Instalação

### Uso

### Monitoramento

### Remoção

## Referências

Vírus de computador, https://pt.wikipedia.org/wiki/V%C3%ADrus_de_computador, acessado em 27/11/2017.

What Is the Difference: Viruses, Worms, Trojans, and Bots?, https://www.cisco.com/c/en/us/about/security-center/virus-differences.html, acessado em 27/11/2017.
