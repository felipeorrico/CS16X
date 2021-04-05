CC = g++
exe_file = wumpus_hunt
$(exe_file): Game.o Room.o Event.o Bats.o Gold.o Source.o Pits.o Wumpus.o Rope.o
	$(CC) -std=c++11 Game.o Room.o Event.o Bats.o Gold.o Wumpus.o Pits.o Rope.o Source.o -o $(exe_file) -g
Event.o: Event.cpp
	$(CC) -c -g -std=c++11 Event.cpp
Gold.o: Gold.cpp
	$(CC) -c -g -std=c++11 Gold.cpp
Source.o: Source.cpp 
	$(CC) -c -g -std=c++11 Source.cpp
Bats.o:
	$(CC) -c -g -std=c++11 Bats.cpp
Game.o:
	$(CC) -c -g -std=c++11 Game.cpp
Room.o:
	$(CC) -c -g -std=c++11 Room.cpp
Wumpus.o:
	$(CC) -c -g -std=c++11 Wumpus.cpp
Pits.o:
	$(CC) -c -g -std=c++11 Pits.cpp
Rope.o:
	$(CC) -c -g -std=c++11 Rope.cpp

clean: 
	rm -f *.out *.o $(exe_file)