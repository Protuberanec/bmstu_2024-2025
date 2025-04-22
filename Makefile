all : main.o node.o dz1.o file_oper.o filo.o test.o work_array.o 
	g++ main.o node.o dz1.o file_oper.o filo.o test.o work_array.o 

main.o : main.cpp
	g++ -c main.cpp

node.o : node.c
	g++ -c node.c

dz1.o : dz1.c
	g++ -c dz1.c

file_oper.o : file_oper.c
	g++ -c file_oper.c

filo.o : filo.c
	g++ -c filo.c

test.o : test.cpp
	g++ -c test.cpp

work_array.o : work_array.c
	g++ -c work_array.c


clean :
	rm -rf *.o a.out
