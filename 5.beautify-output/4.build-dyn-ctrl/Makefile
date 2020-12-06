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
	$(call cmd,ld)
	@echo '  LD      app'           && gcc -o $@ built-in.o

%.o:%.c
	$(call cmd,cc)

clean:
	$(call cmd,clean)

quiet_cmd_cc       = CC      $^
      cmd_cc       = gcc -c $^ -o $@

quiet_cmd_ld       = LD      built-in.o
      cmd_ld       = ld -r -s -o built-in.o $(__object_files)

quiet_cmd_clean    = CLEAN   $(__clean_files)
      cmd_clean    = rm -f $(__clean_files)

cmd = @$(if $($(quiet)cmd_$(1)),echo '  $($(quiet)cmd_$(1))' &&) $(cmd_$(1))