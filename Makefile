all : main.o dz1.o
	g++ main.o dz1.o -g

main.o : main.c
	g++ main.c -c -g

dz1.o : dz1.c dz1.h
	g++ dz1.c dz1.h -c -g

clean :
	rm -rf *.o a.out
