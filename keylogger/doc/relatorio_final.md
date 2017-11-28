# Keylogger

## Integrantes

* Disciplina:

Fundamento de Sistemas Operacionais

* Professor:

Fernando W Cruz

|Nome|Github|
|----|------|
|Arthur Temporim|[arthurTemporim](https://github.com/arthurTemporim/)|
|Ícaro Pires|[icaropires](https://github.com/icaropires/)|

### Introdução

Relatório do projeto final da disciplina de FSO. Neste documento é descrito a construção de um device driver capaz de coletar todas as teclas digitadas pela máquina infectada e armazenar em um arquivo.

#### 1. O que é Vírus?

Vírus são softwares maliciosos que após entrar na máquina host, tem a função de se propagarem por meio da rede ou de se multiplicarem e também causar danos ao sistema. Outra caracterísca dos vírus, é que eles precisam de uma ação do usuário para ser disparado e começar a agir.

#### 2. Como construir Device Drivers?

Este tutorial foi feito com base no livro **"LINUX DEVICE DRIVERS"** de Jonathan Corbet, Alessandro, Rubini, and Greg Kroah-Hartman.

1. Cria o arquivo Hello World:

```
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");
static int hello_init(void)
{
 printk(KERN_ALERT "Hello, world\n");
 return 0;
}
static void hello_exit(void)
{
 printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
```

#### 3. Keylogger

#### 4. Resultados

### Discussão

#### 1. Metodologia

Foi utilizado a metodologia do **kanban** para o gerenciamento de tarefas e reuniões presenciais e remotas por meio de [Hangouts](https://hangouts.google.com/) para a construção do projeto.

#### 2. Solução

A solução implementada foi a criação de um device driver que, após instalado, fica armazenando um um arquivo oculto todas as teclas pressionadas pelo computador "infectado", inclusive quando são liberadas no caso de teclas como **capslock** e **shift**.

Após as informações serem armazenadas, um script python é executado para fazer a tradução dos dados armazenados.

#### 3. Opniões

1. Arthur Temporim

É possível construir várias ferramentas com o conhecimentos adquiridos com o tema de "drivers". Neste projeto consegui aprender o comportamento do sistema linux com a pespectiva de interação com os dispositivos de I/O, por exemplo.

2. Ícaro Píres

#### 4. Manipulação do Keylogger

Para utilizar o driver construído deve:

* Instalação

* Acompanhamento

* Leitura dos resultados

* Remoção

#### 5. Vírus

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

### Referências

Vírus de computador, https://pt.wikipedia.org/wiki/V%C3%ADrus_de_computador, acessado em 27/11/2017.

What Is the Difference: Viruses, Worms, Trojans, and Bots?, https://www.cisco.com/c/en/us/about/security-center/virus-differences.html, acessado em 27/11/2017.
