# Exe files
BIN := bin/
# .h files
INC := inc/
# .c files
SRC := src/
# .o files
OBJ := obj/

CC := gcc

CFLAGS := -W -Wall -ansi -pedantic

# Source files.
# Add all files to be used in onde project here. 
PROCESSFILE := $(SRC)process.c 

# Concatenates all files to the project.
PROJECT1 := $(PROCESSFILE)

# Compile project. 
all: $(PROJECT1:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/prog

# Generate .o files.
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

# Run the executable files.
run: bin/prog
	bin/prog

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

