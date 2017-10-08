CC = gcc
CFLAGS =-Wall -Wextra -pedantic -std=gnu11
LD_FLAGS = -lpthread

all : cache

rebuild : clean all

hexreader.o : hexreader.c hexreader.h
	$(CC) $(CFLAGS) -c $< -o $@

cachelog.o : cachelog.c cachelog.h
	$(CC) $(CFLAGS) -c $< -o $@

cache : cache.c hexreader.o cachelog.o
	$(CC) $(CFLAGS) $< *.o -o $@

clean :
	rm -rf *.o cache
