#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INTEGER_SCANCODES_FILE "../../io/integer_scancodes_file" // File after
																 // to int translation

unsigned char *read_file(char* file_path, int *size);
																 
void write_to_file(char *file_path, unsigned char *keys, int size);

#endif // FUNCTIONS_H
