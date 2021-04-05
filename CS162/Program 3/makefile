CC = g++
exe_file = zoo_tycoon
$(exe_file): Tiger.o Bear.o Sea_lion.o Animal.o Zoo.o driver.o
	$(CC) -std=c++11 Tiger.o Bear.o Sea_lion.o Animal.o Zoo.o driver.o -o $(exe_file) -g
driver.o: driver.cpp
	$(CC) -c -g -std=c++11 driver.cpp
Tiger.o: Tiger.cpp
	$(CC) -c -g -std=c++11 Tiger.cpp
Bear.o: Bear.cpp 
	$(CC) -c -g -std=c++11 Bear.cpp
Sea_lion.o: Sea_lion.cpp
	$(CC) -c -g -std=c++11 Sea_lion.cpp
Animal.o: Animal.cpp
	$(CC) -c -g -std=c++11 Animal.cpp
Zoo.o: Zoo.cpp
	$(CC) -c -g -std=c++11 Zoo.cpp

clean: 
	rm -f *.out *.o $(exe_file)