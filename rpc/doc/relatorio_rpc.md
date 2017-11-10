# RelatÃ³rioRPC

## Dados

* Disciplina: Fundamentos de Sistemas Operacionais
* Professor: Fernando W Cruz
* Alunos:

	* Nome: Arthur Temporim
	* Matrícula: 14/0016759

	* Nome: Ícaro Pires
	* Matrícula: 15/0129815
* Repositório:

	* [GitHub](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais)

## Introdução

Este projeto consiste na implementação de um exemplo de RPC, a aplicação aqui descrita é capaz de somar e subtrair 2 números inseridos pelo usuário, e por meio do RPC, efetuar a comunicação entre o **client** e o **server** para efetuar os calculos desejados.

## Descrição da Solução

### Exemplo base

* A primeira parte do projeto consiste em aplicar o exemplo de RPC dado na apostila, para isso foi utilizado 2 VMs com as dependÃªncias instaladas. O tutorial abaixo foi usado para configurar o NFS nas VMs:

[Tutorial](http://mpitutorial.com/tutorials/running-an-mpi-cluster-within-a-lan/)

* Depois os passos do enunciado do projeto foram seguidos.

* Houve um problema com o RPC então os seguintes comandos foram usados para solucionar:

`sudo -i service portmap stop`

`sudo -i rpcbind -i -w`

`sudo -i service portmap start`

* Após os passos anteriores os comandos de execução do projeto foram feitos.

### Exercício 1

As seguintes mudanças foram observadas:

1. Os métodos no calcula_server.c e em outros arquivos que tinham o número **100** agora possuem o número **101** pois este foi o novo número da versão.

2. Após gerar o novo binário, e rodar o comando `rpcinfo -p` a seguinte saída foi gerada:

```
   program vers proto   port  service
    100000    4   tcp    111  portmapper
    100000    3   tcp    111  portmapper
    100000    2   tcp    111  portmapper
    100000    4   udp    111  portmapper
    100000    3   udp    111  portmapper
    100000    2   udp    111  portmapper
  55555555  100   udp  58402
  55555555  100   tcp  40215
  55555555  101   udp  50283
  55555555  101   tcp  36185
```
É observável que aa nova versão está usando outra porta.

## Conclusão

A implementação do projeto utilizando RPC foi bem mais simples do que o projeto de MPI, mesmo a complexidade dos problemas serem diferentes, foi notável que as facilitações que o RPC traz ajuda na contrução de aplicações em que suas "partes" estejam distribuídas.

# Instruções para execução

* Sever:

./calcula_server

* Client

./calcula_client [ip do server] nº1 nº2

