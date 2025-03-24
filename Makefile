all : main.o test.o dz1.o file_oper.o filo.o node.o test_node.o
	g++ main.o test.o dz1.o file_oper.o filo.o node.o test_node.o -g


test_node.o : test_node.c test_node.h
	g++ -g -c test_node.c test_node.h

test.o : test.c test.h
	g++ -g -c test.c test.h

main.o : main.c
	g++ main.c -c -g

dz1.o : dz1.c dz1.h
	g++ dz1.c dz1.h -c -g

file_oper.o : file_oper.c
	g++ file_oper.c -c -g

filo.o : filo.c
	g++ filo.c -c -g

node.o : node.c node.h
	g++ node.c node.h -c -g

clean :
	rm -rf *.o a.out

work_array.o : work_array.c
	g++ work_array.c -c -g


clean :
	rm -rf *.o *.out
