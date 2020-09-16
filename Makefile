
EXEC = bots
CC = gcc

$(EXEC):
	$(CC) -o $(EXEC) threads.c -lpthread
	rm -f *.o

clean:
	rm -f *.o core a.out $(EXEC)

###########################[ EOF: Makefile ]############################
