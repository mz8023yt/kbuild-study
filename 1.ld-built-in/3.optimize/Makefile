app: main.o printf.o
	ld -r -s -o built-in.o $^
	gcc -o $@ built-in.o

%.o: %.c
	gcc -c -o $@ $^

clean:
	rm -rf app *.o
