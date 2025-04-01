compiler = g++
flags = -std=c++17 -Wall     
compile = $(compiler) $(flags) -c 
link = $(compiler) $(flags) -o 

classes.o : classes.cc
	$(compile) $<

classes : classes.o
	$(link) $@ $^

test_classes : classes
	./$<

structs.o : structs.cc
	$(compile) $<

structs : structs.o
	$(link) $@ $^

test_structs : structs
	./$<

temperature.o : temperature.cc classes.o temperature.h
	$(compile) temperature.cc

forecast.o : forecast.cc forecast.h temperature.h
	$(compile) forecast.cc

temperature : temperature.o forecast.o classes.o
	$(link) $@ $^

test_temp : temperature
	./temperature

clean :
	rm -f *.o classes structs temperature