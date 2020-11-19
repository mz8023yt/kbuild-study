# 代码参考 顶层Makefile
$(@warning $(origin V))
ifeq ("$(origin V)", "command line")
  KBUILD_VERBOSE = $(V)
endif
ifndef KBUILD_VERBOSE
  KBUILD_VERBOSE = 0
endif

ifeq ($(KBUILD_VERBOSE),1)
  quiet =
  Q =
else
  quiet=quiet_
  Q = @
endif

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
	$(call cmd,clean)

# 代码参考 Makefile.clean

quiet_cmd_clean    = CLEAN   $(__clean_files)
      cmd_clean    = rm -f $(__clean_files)

cmd = @$(if $($(quiet)cmd_$(1)),echo '  $($(quiet)cmd_$(1))' &&) $(cmd_$(1))