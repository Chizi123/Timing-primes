default: 
	gcc timings.c -o timings

all: timings
	gcc timings.o meme.o prime.o -o timings

prime: 
	gcc -c prime.c -o prime.o

header: prime
	gcc -c meme.h -o meme.o

timings: header prime
	gcc timings.c -o timings.o

remneg:
	gcc remneg.c -o remneg

clean:
	rm *.o