compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

book.o : book.cc book.h
	$(compile) $<

textbook.o : textbook.cc textbook.h book.h
	$(compile) $<

april8.o : april8.cc book.h textbook.h
	$(compile) $<

test : april8.o book.o textbook.o
	$(link) $^
	./a.out 

clean : 
	rm *.o a.out
