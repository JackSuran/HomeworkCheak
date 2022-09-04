CC = g++
CFLAGS = -g -Wall

main : Student.o Manager.o main.o
	$(CC) Student.o Manager.o main.o -o check.exe
Student.o : Student.cpp Student.h
	$(CC) $(CFLAGS) Student.cpp -c -o Student.o
Manager.o : Manager.cpp Manager.h path.h
	$(CC) $(CFLAGS) Manager.cpp -c -o Manager.o
main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp -c -o main.o
clean :
	del *.o *.exe 

all :
	cls
	make clean
	make