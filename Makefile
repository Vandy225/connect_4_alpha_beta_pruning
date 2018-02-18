CCC = g++

CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11
all : main

main : configuration.o main.o
	$(CCC) $(CCCFLAGS) -o $@ $^

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f main
