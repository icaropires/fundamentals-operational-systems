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
HOSTA := $(wildcard src/*.c)

# Compile project. 
all: create_folders $(HOSTA:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/host_a

create_folders:
	@mkdir -p $(OBJ) $(BIN)

# Generate .o files.
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

# Run the executable files.
run: bin/host_a
	bin/host_a

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
