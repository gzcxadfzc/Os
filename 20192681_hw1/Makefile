all: fork exec cat pipe

a.out : fork.o exec.o cat.o pipe.o
	gcc -o a.out fork.o exec.o cat.o pipe.o

fork.o : fork.c
	gcc -c -o fork.o fork.c

exec.o : exec.c
	gcc -c -o exec.o exec.c

cat.o : cat.c
	gcc -c -o cat.o cat.c

pipe.o : pipe.c
	gcc -c -o pipe.o pipe.c

clean:
	rm *.o *.out
	rm -f shared_library

cleanL:
	rm -f shared_library
