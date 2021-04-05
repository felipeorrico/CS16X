CC = g++
exe_file = list
$(exe_file): Linked_List.o Node.o Driver.o List_Program.o
	$(CC) -std=c++11 Linked_List.o Node.o Driver.o List_Program.o -o $(exe_file) -g
Node.o: Node.cpp
	$(CC) -c -g -std=c++11 Node.cpp
Linked_List.o: Linked_List.cpp
	$(CC) -c -g -std=c++11 Linked_List.cpp
Driver.o: Driver.cpp 
	$(CC) -c -g -std=c++11 Driver.cpp
List_Program.o: List_Program.cpp 
	$(CC) -c -g -std=c++11 List_Program.cpp

clean: 
	rm -f *.out *.o $(exe_file)