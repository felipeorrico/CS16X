CC = g++
exe_file = pokedex 
$(exe_file): pokedex.o prog.o
	$(CC) -std=c++11 pokedex.o prog.o -o $(exe_file) -g
pokedex.o: pokedex.cpp 
	$(CC) -c -g -std=c++11 pokedex.cpp 
prog.o: prog.cpp 
	$(CC) -c -g -std=c++11 prog.cpp

clean: 
	rm -f *.out *.o $(exe_file)