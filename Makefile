#define compilador principal
CC := gcc

#seta diretorios, extensoes de arquivos e flags de compilacao
SRCDIR := src
BUILDDIR := build
BINDIR := bin
MAINDIR := main
TESTDIR := test
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -std=c11 -Wall
LIB := #-lncurses
INC := -I include

#compila o programa
all: dsatur

#compila o programa
dsatur: $(OBJECTS) $(BUILDDIR)/main.o
	@mkdir -p $(BINDIR)
	@echo " Linkando Snake..."
	@echo " $(CC) $^ -o $(BINDIR)/dsatur $(LIB)"; $(CC) $^ -o $(BINDIR)/dsatur $(LIB)

#compila o arquivo main.c
$(BUILDDIR)/main.o: $(MAINDIR)/main.c
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

#compila a teste
test: $(OBJECTS) $(BUILDDIR)/test.o
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $(BINDIR)/test $(LIB)

#compile a main da test
$(BUILDDIR)/test.o: $(TESTDIR)/test.c
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

#compila os demais arquivos .c
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

#clean
clean:
	@echo " Limpando...";
	@echo " $(RM) -rf $(BUILDDIR) $(BINDIR)"; $(RM) -rf $(BUILDDIR) $(BINDIR)

.PHONY: clean test dsatur

