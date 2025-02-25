ArrayFunctions.o : ArrayFunctions.cc ArrayFunctions.h
	g++ -Wall  -std=c++17 -c $<

ArrayFunctionTester.o : ArrayFunctionTester.cc ArrayFunctions.h
	g++ -Wall  -std=c++17 -c $<

test : ArrayFunctionTester.o ArrayFunctions.o
	g++ -Wall  -std=c++17  $^
	./a.out

clean :
	rm *.o a.out