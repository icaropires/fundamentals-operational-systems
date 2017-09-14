# Exe files
BINFOLDER := bin/
# .h files
INCFOLDER := inc/
# .c files
SRCFOLDER := src/
# .o files
OBJFOLDER := obj/

CC := gcc

CFLAGS :=

# Any file of .c extension.
# If many executables is needed, create anothers flags.
SRCFILES := $(wildcard src/*.c)

# Compile project. 
all: $(SRCFILES:src/%.c=obj/%.o)
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

