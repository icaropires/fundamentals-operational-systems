#include "middleware_b.h"

int main() {

	fprintf(stdout, "Middleware B started.\n");
	
	//signal(SIGINT, SIG_IGN);
	//signal(SIGTERM, SIG_IGN); 


	//do {
        Message msg;
        msg.mtype = NORMAL_MESSAGE_TYPE;

		if(!strcmp(msg.msg, "END")){
			//break;
		}

		// Start socket.
		msg = client(msg);

		fprintf(stdout, "Sending messsage %s from MIDDLEWARE B...\n", msg.msg);

        int msqid = create_message_queue(FILE_PATH, ARB_CHAR_B);
	    sending_message(msqid, &msg, FLAG);

		fprintf(stdout, "Message sent from MIDDLEWARE B.\n");
	//} while(1);

	return 0;
}
