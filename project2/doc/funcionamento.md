# Funcionamento

## Entidades

* **Corda:** array *R[7]*
* **Crianças:** *Kn* processos definidos pelo usuário

## Fluxo

### Instante 0
* Crianças com fome
* A criança *K0* vai começar a atravessar
* Ninguém entra na corda além de *K0*

### Instante 1
* *K0* está na posição *R0* da corda
* Travessia no sentido oposto bloqueada

### Instante 2
* *K0* em *R1*
* *K1* em *R0*
* Travessia no sentido oposto bloqueada

....

### Instante n
...

## Procedimentos

### Bloquear posição da corda
* Dar down no semáforo ao entrar
* Dar up ao sair
	* o próximo que tentar entrar será bloqueado até que a posição seja liberada

### Garantir que ninguém entre no sentido oposto
* Avisar por mensagens?
* Botar todo mundo do lado oposto pra dormir?

### Garantir que todas crianças atravessem 
* ???

### Política de revezamento entre os lados
* Rodadas???
* Quantidade de crianças que querem atravessar?
