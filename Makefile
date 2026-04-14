SHELL = /bin/bash

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Isrc
LEX_CFLAGS = -Wno-unused-function -Wno-unneeded-internal-declaration -Wno-sign-compare
FLEX = flex
BISON = bison

TARGET = opt65
SRCDIR = src
SOURCES = $(SRCDIR)/main.c parser.tab.c lex.yy.c $(SRCDIR)/stats.c
OBJECTS = $(SRCDIR)/main.o parser.tab.o lex.yy.o $(SRCDIR)/stats.o

# Detect platform for install behavior
ifeq ($(OS),Windows_NT)
    PREFIX ?= $(PROGRAMFILES)\opt65
    BINDIR := $(PREFIX)\bin
    DOCDIR := $(PREFIX)\doc
    MANDIR := $(PREFIX)\man
else
    PREFIX ?= /usr/local
    BINDIR ?= $(PREFIX)/bin
    MANDIR ?= $(PREFIX)/share/man
    DOCDIR ?= $(PREFIX)/share/doc/opt65
endif

.PHONY: all clean install uninstall debug

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -ll || $(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -lfl

parser.tab.c parser.tab.h: $(SRCDIR)/parser.y
	$(BISON) -d $(SRCDIR)/parser.y

lex.yy.c: $(SRCDIR)/lexer.l parser.tab.h
	$(FLEX) $(SRCDIR)/lexer.l

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) $(LEX_CFLAGS) -c lex.yy.c -o lex.yy.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) parser.tab.c parser.tab.h lex.yy.c

debug:
	$(MAKE) DEBUG=1 all

install: $(TARGET)
ifeq ($(OS),Windows_NT)
	@echo Installing opt65 to $(PREFIX)...
	@if not exist "$(BINDIR)" mkdir "$(BINDIR)"
	@if not exist "$(DOCDIR)" mkdir "$(DOCDIR)"
	@if not exist "$(MANDIR)" mkdir "$(MANDIR)"
	copy /Y "$(TARGET).exe" "$(BINDIR)\"
	copy /Y "docs\opt65.1" "$(MANDIR)\" 2>nul || true
	@echo Installation complete!
else
	@echo "Installing opt65 to $(PREFIX)..."
	mkdir -p $(BINDIR) $(MANDIR)/man1 $(DOCDIR)
	install -m 755 $(TARGET) $(BINDIR)/
	install -m 644 docs/opt65.1 $(MANDIR)/man1/ 2>/dev/null || true
	cp -r docs $(DOCDIR)/
	@echo "Installation complete!"
endif

uninstall:
ifeq ($(OS),Windows_NT)
	@echo Uninstalling opt65 from $(PREFIX)...
	@if exist "$(BINDIR)\$(TARGET).exe" del /Q "$(BINDIR)\$(TARGET).exe"
	@if exist "$(MANDIR)\opt65.1" del /Q "$(MANDIR)\opt65.1"
	@if exist "$(DOCDIR)" rmdir /S /Q "$(DOCDIR)"
	@echo Uninstall complete!
else
	@echo "Uninstalling opt65 from $(PREFIX)..."
	rm -f $(BINDIR)/$(TARGET)
	rm -f $(MANDIR)/man1/opt65.1
	rm -rf $(DOCDIR)
	@echo "Uninstall complete!"
endif
