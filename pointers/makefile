# makefile for pointers
compiler = g++
flags = -std=c++17 -Wall     
compile = $(compiler) $(flags) -c 
link = $(compiler) $(flags) -o 

pointers.o : pointers.cc
	$(compile) $<

pointers : pointers.o
	$(link) $@ $^

test : pointers
	./$<

clean :
	rm *.o pointers