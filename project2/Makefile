# Exe files
BIN := bin/
# .h files
INC := inc/
# .c files
SRC := src/
# .o files
OBJ := obj/

CC := gcc

CFLAGS := -Wall -ansi -pedantic -g -std=c11

# Source files.
# Add all files to be used in onde project here. 

# Concatenates all files to the project.
PROJECT := $(wildcard src/*.c)

# Compile project. 
all: create_folders $(PROJECT:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/project

create_folders:
	@mkdir -p $(OBJ) $(BIN)

# Generate .o files.
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

# Run the executable files.
run: bin/project
	bin/project

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
