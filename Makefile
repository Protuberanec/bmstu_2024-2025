all : main.o dz1.o file_oper.o filo.o
	g++ main.o dz1.o file_oper.o filo.o -g

main.o : main.c
	g++ main.c -c -g

dz1.o : dz1.c dz1.h
	g++ dz1.c dz1.h -c -g

file_oper.o : file_oper.c
	g++ file_oper.c -c -g

filo.o : filo.c
	g++ filo.c -c -g

clean :
	rm -rf *.o a.out
