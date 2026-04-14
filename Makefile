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

.PHONY: all clean

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

