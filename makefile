CC = gcc
CFLAGS = -Wall -g -Iinclude -std=c11

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#main-> DES.a pqueue.a


all: main

main: lib/libstringArray.a scaffold.o
	$(CC) $(CFLAGS) scaffold.o -o bin/main -lm -L./lib/ -lstringArray -lioHandler

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#pqueue -> pqueue.c


pqueue: lib/libstringArray.a

lib/libstringArray.a: stringArray.o
	ar cr lib/libstringArray.a stringArray.o

stringArray.o: src/stringArray.c
	$(CC) $(CFLAGS) -c src/stringArray.c

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#scaffold -> only headers from other functions


scaffold: scaffold.o

scaffold.o: src/scaffold.c
	$(CC) $(CFLAGS) -c src/scaffold.c

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

#Utility Funtions


clean:
	rm *.o
	rm lib/libstringArray.a
	rm bin/main

run:
	./bin/main

cclear:
	clear
	clear

r: cclear clean main run

