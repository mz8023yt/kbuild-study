__source_files := main.c printf.c
__object_files := $(patsubst %.c,%.o,$(wildcard *.c))
__clean_files := app *.o

#$(info __source_files = $(__source_files))
#$(info __object_files = $(__object_files))
#$(info __clean_files  = $(__clean_files))

app: $(__object_files)
	@echo '  LD      built-in.o'    && ld -r -s -o built-in.o $(__object_files)
	@echo '  LD      app'           && gcc -o $@ built-in.o

%.o:%.c
	@echo '  CC      $^'            && gcc -c $^ -o $@

clean:

	@echo '  CLEAN   $(__clean_files)' && rm -rf $(__clean_files)
