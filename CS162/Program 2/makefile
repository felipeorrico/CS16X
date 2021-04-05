CC = g++
exe_file = course_catalog
$(exe_file): university.o course.o functions.o prog.o
	$(CC) -std=c++11 university.o course.o functions.o prog.o -o $(exe_file) -g
functions.o: functions.cpp
	$(CC) -c -g -std=c++11 functions.cpp
course.o: course.cpp
	$(CC) -c -g -std=c++11 course.cpp
prog.o: prog.cpp 
	$(CC) -c -g -std=c++11 prog.cpp
university.o:
	$(CC) -c -g -std=c++11 university.cpp

clean: 
	rm -f *.out *.o $(exe_file)