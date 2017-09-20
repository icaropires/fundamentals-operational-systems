# Exe files
BIN := bin/
# .h files
INC := inc/
# .c files
SRC := src/
# .o files
OBJ := obj/

CC := gcc

CFLAGS := -ansi -pedantic -g -std=c11

# Source files.
# Add all files to be used in onde project here. 

# Concatenates all files to the project.
SOCKET := $(wildcard src/*.c)

# Compile project. 
all: create_folders $(SOCKET:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/socket

create_folders:
	@mkdir -p $(OBJ) $(BIN)

# Generate .o files.
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

# Run the executable files.
run: bin/socket
	bin/socket

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
