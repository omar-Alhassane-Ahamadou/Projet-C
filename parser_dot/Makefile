CFLAGS=-g
LDFLAGS=-Wall -pedantic -std=c++11

all : clean main parser_dot

main :main.o parser_dot.o
	g++ -o main $^ $(LDFLAGS)

parser_dot :main.o parser_dot.o
	g++ -o parser_dot $^ $(LDFLAGS)

%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ main parser_dot
