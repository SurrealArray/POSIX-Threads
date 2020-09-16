########################################################################
# Makefile for Assignment 1  
# Omar Beltran
# RedID: 818036447 
# cssc2146
# CS 570, Summer 2020
# Assignment #1, Multiple Threads Manager
# Makefile
########################################################################

EXEC = bots
CC = gcc

$(EXEC):
	$(CC) -o $(EXEC) assignment1.c -lpthread
	rm -f *.o

clean:
	rm -f *.o core a.out $(EXEC)

###########################[ EOF: Makefile ]############################
