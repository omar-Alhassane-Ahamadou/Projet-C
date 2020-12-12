
CFLAGS=-g
LDFLAGS=

all : all

main : main.o
	g++ -o main $^ $(LDFLAGS)

%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ main
