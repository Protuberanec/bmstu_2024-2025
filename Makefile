all : main.o work_array.o
	g++ main.o work_array.o -g

main.o : main.c
	g++ main.c -c -g

work_array.o : work_array.c
	g++ work_array.c -c -g


clean :
	rm -rf *.o *.out
