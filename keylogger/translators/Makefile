OBJDIR = obj
SRCDIR = src
BINDIR = bin
INCDIR = inc

CFLAGS = -std=c11
INCLUDES = -I$(INCDIR)

OBJNAME = to_int_translator.o
BINNAME = to_int_translator
SRCFILE = to_int_translator.c

CC = gcc

default:
	mkdir -p $(OBJDIR)
	$(CC) -c $(SRCDIR)/$(SRCFILE) $(CFLAGS) -o $(OBJDIR)/$(OBJNAME)
	$(CC) $(OBJDIR)/*.o $(CFLAGS) -o $(BINDIR)/$(BINNAME)

clean:
	rm -f $(BINDIR)/$(BINNAME)
	rm -rf $(OBJDIR)
	@echo "\nAttention: Don't delete bin folder, it contains a python script!"
