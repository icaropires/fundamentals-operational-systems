#include <stdio.h>
#include "calcula.h" /* Criado pelo rpcgen */
int add( CLIENT *clnt, int x, int y) {
	operandos ops;
	int *result;

	ops.x = x; ops.y = y;
	/* Chama o stub cliente criado pelo rpcgen */
	result = add_100(&ops,clnt);
	if (result==NULL) {
		fprintf(stderr,"Problema na chamada RPC\n");
		exit(0); }
	return(*result);
} /* fim função add local */

int sub( CLIENT *clnt, int x, int y) {
	operandos ops;
	int *result;
	/* Preenche struct operandos p ser enviada ao outro lado */
	ops.x = x;
	ops.y = y;
	/* Chama o stub cliente criado pelo rpcgen */
	result = sub_100(&ops,clnt);
	if (result==NULL) {
		fprintf(stderr,"Problema na chamada RPC\n");
		exit(0);
	}
	return(*result);
} /* fim funcao sub local */

int main( int argc, char *argv[]) {
	CLIENT *clnt;
	int x,y;

	if (argc!=4) {
		fprintf(stderr,"Uso: %s hostname num1 num2\n",argv[0]);
		exit(0); }
	clnt = clnt_create(argv[1], PROG, VERSAO, "udp");
	/* Garantindo a criacao da ligacao com o remoto */
	if (clnt == (CLIENT *) NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1); }
	/* Recupera os 2 operandos passados como argumento */
	x = atoi(argv[2]); y = atoi(argv[3]);
	printf("%d + %d = %d\n",x,y, add(clnt,x,y));
	printf("%d - %d = %d\n",x,y, sub(clnt,x,y));
	return(0);
} /* fim main */
