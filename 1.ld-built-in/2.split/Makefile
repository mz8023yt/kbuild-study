app: main.c printf.c printf.h
	gcc -o main.o -c main.c
	gcc -o printf.o -c printf.c
	ld -r -s -o built-in.o main.o printf.o
	gcc -o app built-in.o

clean:
	rm -rf app *.o
