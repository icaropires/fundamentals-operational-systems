#include "utils.h"

void generate_arb_file(){
    FILE* arb_file = fopen(ARB_FILE, "w");
    assert(arb_file != NULL);

    fclose(arb_file);
}

char *remove_last_from_path(char* str){
	int i;

	for(i = 0; str[i] != '\0'; ++i);
	str[i] = '\0';

	return str;
}
