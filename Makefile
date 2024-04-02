CC=gcc
FLAGS=-lm -Wall
TARGET=echo-rsa
BINDIR=build
SRCDIR=src
INCDIR=src/include

# Define object files
OBJ=$(BINDIR)/encryption.o $(BINDIR)/main.o

# Rule to build the target executable
$(BINDIR)/$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(FLAGS)

# Rule to compile the encryption module
$(BINDIR)/encryption.o: $(INCDIR)/encryption.c $(INCDIR)/encryption.h
	$(CC) -c -o $@ $(INCDIR)/encryption.c -I$(INCDIR) $(FLAGS)

# Rule to compile the main module
$(BINDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/encryption.h
	$(CC) -c -o $@ $(SRCDIR)/main.c -I$(INCDIR) $(FLAGS)

install: $(BINDIR)/$(TARGET)
	cp $(BINDIR)/$(TARGET) /usr/local/bin

clean:
	rm -f $(BINDIR)/*.o
	rm -f $(BINDIR)/$(TARGET)
	rm -f /usr/local/bin/$(TARGET)
