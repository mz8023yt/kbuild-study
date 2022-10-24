#
# include the auto.conf files
#
srctree		:= $(shell pwd)
export srctree

#
# specify the compiler
#
HOSTCC	= gcc
AS	= $(CROSS_COMPILE)as
LD	= $(CROSS_COMPILE)ld
CC	= $(CROSS_COMPILE)gcc
CPP	= $(CC) -E
AR	= $(CROSS_COMPILE)ar
NM	= $(CROSS_COMPILE)nm
STRIP	= $(CROSS_COMPILE)strip
OBJCOPY	= $(CROSS_COMPILE)objcopy
OBJDUMP	= $(CROSS_COMPILE)objdump
export AS LD CC CPP AR NM STRIP OBJCOPY OBJDUMP

# specify the compiler options
CFLAGS	= -Wall -O2 -g -fPIC
LDFLAGS	=
export CFLAGS LDFLAGS

include $(srctree)/scripts/Makefile.include
-include include/config/auto.conf

#
# specify target name
#
TARGET := kbuild-sample



#
# adding subdirectories
#
obj-y += application/
obj-y += components/
obj-y += drivers/



#
# simplified printing information
#
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



#
# specify the output path
#
ifeq ("$(origin O)", "command line")
  KBUILD_OUTPUT := $(O)
endif

ifneq ($(KBUILD_OUTPUT),)
saved-output    := $(KBUILD_OUTPUT)
KBUILD_OUTPUT   := $(shell mkdir -p $(KBUILD_OUTPUT) && cd $(KBUILD_OUTPUT) && /bin/pwd)
$(if $(KBUILD_OUTPUT),,$(error failed to create output directory "$(saved-output)"))
export KBUILD_OUTPUT
out             := $(KBUILD_OUTPUT)/
else
out             :=
endif



#
# build target
#
all:
	$(Q)$(MAKE) $(mbuild)=.
	$(call cmd,melf)

#
# specify the output path
#
ifneq ($(KBUILD_OUTPUT),)
clean:
	$(call cmd,clr,$(out))
	$(call cmd,clr,include/linux)
else
clean:
	$(Q)$(MAKE) $(mclean)=.
	$(call cmd,clr,include/linux)
	$(call cmd,clr,$(TARGET))
endif

distclean: clean
	$(call cmd,clr,.config)
	$(call cmd,clr,.config.old)
	$(call cmd,clr,include/config)



#
# simplified printing information
# mliba  : main elf
# mliba  : main static lib
# mlibso : main dynamic lib
# clr    : clean
#
quiet_cmd_melf      = CC      $(out)$(TARGET)
      cmd_melf      = $(CC)  -o $(out)$(TARGET) $(LDFLAGS) $(out)built-in.o

quiet_cmd_mliba     = AR      $(out)$(TARGET).a
      cmd_mliba     = $(AR) cr $(out)$(TARGET).a $(out)built-in.o

quiet_cmd_mlibso    = LD      $(out)$(TARGET).so
      cmd_mlibso    = $(CC) -o $(out)$(TARGET).so $(LDFLAGS) -shared -fPIC $(out)built-in.o

quiet_cmd_clr      = RM      $(2)
      cmd_clr      = rm -rf $(2)

cmd = @$(if $($(quiet)cmd_$(1)),echo '  $($(quiet)cmd_$(1))' &&) $(cmd_$(1))



.PHONY:all clean distclean
