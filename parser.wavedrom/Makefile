
CFLAGS=-g
LDFLAGS= -std=c++11 -Wall -pedantic

all : all

main : main.o parser_wavedrom.o
	g++ -o main $^ $(LDFLAGS)

%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ main
