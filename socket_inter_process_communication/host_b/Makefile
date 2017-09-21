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
HOSTB := $(wildcard src/*.c)

# Compile project. 
all: create_folders $(HOSTB:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/host_b

create_folders:
	@mkdir -p $(OBJ) $(BIN)

# Generate .o files.
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc
	$(CC) $(CFLAGS) -c ../utils/utils.c -o obj/utils.o -I../utils
	$(CC) $(CFLAGS) -c ../utils/socket.c -o obj/socket.o -I../utils
	$(CC) $(CFLAGS) -c ../middleware_b/src/middleware_b.c -o obj/middleware_b.o -I../middleware_b/inc

# Run the executable files.
run: bin/host_b
	bin/host_b

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
