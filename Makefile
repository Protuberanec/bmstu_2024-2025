all : main.o ring_buffer.o 
	g++ main.o ring_buffer.o -g

main.o : main.cpp
	g++ -c main.cpp -g

ring_buffer.o : ring_buffer.cpp
	g++ -c ring_buffer.cpp -g

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
