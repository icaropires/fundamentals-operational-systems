# Relatório RPC

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

[Código](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/tree/rpc/rpc/exemplo_base)

* A primeira parte do projeto consiste em aplicar o exemplo de RPC dado na apostila, para isso foi utilizado 2 VMs com as dependÃªncias instaladas. O tutorial abaixo foi usado para configurar o NFS nas VMs:

[Tutorial](http://mpitutorial.com/tutorials/running-an-mpi-cluster-within-a-lan/)

* Depois os passos do enunciado do projeto foram seguidos.

* Houve um problema com o RPC então os seguintes comandos foram usados para solucionar:

`sudo -i service portmap stop`

`sudo -i rpcbind -i -w`

`sudo -i service portmap start`

* Após os passos anteriores os comandos de execução do projeto foram feitos.

### Exercício 1

[Código](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/tree/rpc/rpc/ex1)

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

### Exercício 2

[Código](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/tree/rpc/rpc/ex2)

* Para fazer a multiplicação e a divisão os seguintes arquivos foram alterados do exemplo base:

1. calcula_client.c
2. calcula_server.c

* Não foi possível usar o nome **div** para a função de divisão. Para contornar este erro, esta função foi alterada para **divi**.

* os seguintes resultados foram alcançados:

#### Server

```
Requisicao de adicao para 0 e 0
Requisicao de subtracao para 0 e 0
Requisicao de adicao para 1 e 0
Requisicao de subtracao para 1 e 0
Requisicao de adicao para 1 e 2
Requisicao de subtracao para 1 e 2
Requisicao de multiplicacao para 1 e 2
Requisicao de divisao para 1 e 2
```
#### Client

```
./calcula_client localhost 0 0
0 + 0 = 0
0 - 0 = 0
Valor 0 inválido!
```

```
./calcula_client localhost 1 0
1 + 0 = 1
1 - 0 = 1
Valor 0 inválido!
```

```
./calcula_client localhost 1 2
1 + 2 = 3
1 - 2 = -1
1 * 2 = 2
1 / 2 = 0
```

## FIBONACII

[Código](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/tree/rpc/rpc/fibonacci)

Para finalizar também foi construído o algorítmo de fibonacci utilizando **RPC**. Os seguintes passos foram feitos:

1. Criacção do arquivo .x .
2. Os arquivos `fibonacci_client` e `fibonacci_server` foram editados para adicionar a lógica do algorítmo e efetuar a comunicação entre eles.
3. Os seguintes resultados foram alcançados:

#### Server

```
Requisicao de fibonacci para 5 
Requisicao de fibonacci para 7 
Requisicao de fibonacci para 17 

```
#### Client

```
./fibonacci_client localhost 5
Resultado: 13 
```

```
./fibonacci_client localhost 7
Resultado: 34 
```

```
./fibonacci_client localhost 17
Resultado: 4181 
```

## Conclusão

A implementação do projeto utilizando RPC foi bem mais simples do que o projeto de MPI, mesmo a complexidade dos problemas serem diferentes, foi notável que as facilitações que o RPC traz ajuda na contrução de aplicações em que suas "partes" estejam distribuídas.

# Instruções para execução

* Sever:

./fibonacci_server

* Client

./fibonacci_client [ip do server] nº
