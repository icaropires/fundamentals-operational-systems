#include "../../utils/utils.h"

char *remove_last_from_path(char* str){
	int i;
	for(i = 0; str[i] != '\0'; ++i){
		int u = 0;
		if(str[i] == '/'){
			u = i;  
		}
	}
	str[i] = '\0';
	return str;
}

int main() {
	int msqid = create_message_queue(FILE_PATH, ARB_CHAR_A);
	char aux[MESSAGE_SIZE];
	Message msg = {NORMAL_MESSAGE_TYPE, "Message_test_1."};
	pid_t pid;
	char *path = strcat(PWD,"/../middleware_a/bin/middleware_a");
	path = remove_last_from_path(path);

	fprintf(stdout, "Messages will be sent to queue with msqid %d.\n", msqid);
	fprintf(stdout, "Type END to stop sending.\n");
	fprintf(stdout, "Sending messsage from HOST A...\n");


	pid = fork();
	if(pid) {
		do {
			fgets(aux, sizeof(aux), stdin);
			strcpy(msg.msg, aux);
			sending_message(msqid, &msg, FLAG);
		} while(strcmp(aux, "END"));
	} else {

		if(execvp(path, NULL) ==-1 ) {
			perror("Can't start middleware_A");
		}
	}

	//	fprintf(stdout, "All messages sent from HOST A\n");

	return 0;
}
