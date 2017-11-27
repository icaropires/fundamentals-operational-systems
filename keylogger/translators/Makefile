# Needs many improvements

OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin
INC_DIR = inc

CFLAGS = -std=c11
INCLUDES = -I$(INC_DIR)

MAIN_OBJ_NAME = to_int_translator.o
FUNCTIONS_OBJ_NAME = functions.o
BIN_NAME = to_int_translator
MAIN_SRC_FILE = to_int_translator.c
FUNCTIONS_SRC_FILE = functions.c

CC = gcc

default:
	mkdir -p $(OBJ_DIR)
	$(CC) $(INCLUDES) -c $(SRC_DIR)/$(MAIN_SRC_FILE) $(CFLAGS) -o $(OBJ_DIR)/$(MAIN_OBJ_NAME)
	$(CC) $(INCLUDES) -c $(SRC_DIR)/$(FUNCTIONS_SRC_FILE) $(CFLAGS) -o $(OBJ_DIR)/$(FUNCTIONS_OBJ_NAME)
	$(CC) $(INCLUDES) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$(BIN_NAME)

clean:
	rm -f $(BIN_DIR)/$(BIN_NAME)
	rm -rf $(OBJ_DIR) $(SRC_DIR)/__pycache__
	@echo "\nAttention: Don't delete bin folder, it contains a python script!"
