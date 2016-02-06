CC = gcc
CFLAGS = -g -Wall -ansi -pedantic
FILE = morpion.o main.o
PROG = morpion

all:$(FILE)
  $(CC) $(CFLAGS) $(FILE) -o $(PROG)
  
morpion.c:morpion.c
  $(CC) -c $(CFLAGS) morpion.c
  
main.o:main.c
  $(CC) -c $(CFLAGS) main.c
