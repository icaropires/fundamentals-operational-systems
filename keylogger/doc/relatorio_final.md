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

Não nos rensponsábilizamos por qualquer tipo de dano no uso deste software.

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

1. Estudo inicial sobre Device Drivers e Vírus

2. Definição do projeto

3. Estudo da implementação

4. Definição do escopo

5. Planejamento do projeto

6. Implementação

7. Testes

8. Evolução

## Solução

A solução implementada foi a criação de um device driver que, após instalado, fica armazenando um um arquivo oculto todas as teclas pressionadas pelo computador "infectado", inclusive quando são liberadas no caso de teclas como **capslock** e **shift**.

Após as informações serem armazenadas, um script python é executado para fazer a tradução dos dados armazenados.

### Versão Beta

### Versão Alpha

## Instruções

### Instalação

### Uso

### Monitoramento

### Remoção

## Referências

Vírus de computador, https://pt.wikipedia.org/wiki/V%C3%ADrus_de_computador, acessado em 27/11/2017.

What Is the Difference: Viruses, Worms, Trojans, and Bots?, https://www.cisco.com/c/en/us/about/security-center/virus-differences.html, acessado em 27/11/2017.
