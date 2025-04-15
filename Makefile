all : main.o node.o dz1.o file_oper.o filo.o test.o work_array.o test_node.o 
	g++ main.o node.o dz1.o file_oper.o filo.o test.o work_array.o test_node.o 

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

test_node.o : test_node.cpp
	g++ -c test_node.cpp

clean :
	rm -rf *.o a.out
