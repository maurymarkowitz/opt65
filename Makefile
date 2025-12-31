CC = gcc
CFLAGS = -Wall -Wextra -std=c99
FLEX = flex
BISON = bison

TARGET = asm65
SOURCES = main.c parser.tab.c lex.yy.c stats.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -ll || $(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -lfl

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y

lex.yy.c: lexer.l parser.tab.h
	$(FLEX) lexer.l

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) parser.tab.c parser.tab.h lex.yy.c

