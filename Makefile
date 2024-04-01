CC=gcc
FLAGS=-lm -Wall
TARGET=echo-rsa
BINDIR=build
SRCDIR=src
INCDIR=src/include

$(BINDIR)/$(TARGET):
	$(CC) -I$(INCDIR) $(SRCDIR)/*.c -o $(BINDIR)/$(TARGET) $(FLAGS)

install: $(BINDIR)/$(TARGET)
	cp $(BINDIR)/$(TARGET) /usr/local/bin

clean:
	rm -f $(SRCDIR)/*.o $(INCDIR)/*.o
	rm -f $(BINDIR)/$(TARGET)
	rm -f /usr/local/bin/$(TARGET)
