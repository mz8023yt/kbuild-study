__clean_files := app *.o

app: main.c printf.h printf.c
	@echo '  CC      main.o'        && gcc -o main.o -c main.c
	@echo '  CC      printf.o'      && gcc -o printf.o -c printf.c
	@echo '  LD      built-in.o'    && ld -r -s -o built-in.o printf.o main.o
	@echo '  LD      app'           && gcc -o app built-in.o

clean:
	@echo '  CLEAN   $(__clean_files)' && rm -rf $(__clean_files)