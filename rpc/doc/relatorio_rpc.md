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

* A primeira parte do projeto consiste em aplicar o exemplo de RPC dado na apostila, para isso foi utilizado 2 VMs com as dependÃªncias instaladas. O tutorial abaixo foi usado para configurar o NFS nas VMs:

[Tutorial](http://mpitutorial.com/tutorials/running-an-mpi-cluster-within-a-lan/)

* Depois os passos do enunciado do projeto foram seguidos.

* Houve um problema com o RPC então os seguintes comandos foram usados para solucionar:

`sudo -i service portmap stop`

`sudo -i rpcbind -i -w`

`sudo -i service portmap start`

* Após os passos anteriores os comandos de execução do projeto foram feitos.


## Conclusão

A implementação do projeto utilizando RPC foi bem mais simples do que o projeto de MPI, mesmo a complexidade dos problemas serem diferentes, foi notável que as facilitações que o RPC traz ajuda na contrução de aplicações em que suas "partes" estejam distribuídas.

# Instruções para execução

* Sever:

./calcula_server

* Client

./calcula_client [ip do server] nº1 nº2

