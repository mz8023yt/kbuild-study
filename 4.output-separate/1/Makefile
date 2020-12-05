
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
endif # ifneq ($(KBUILD_OUTPUT),)

CROSS_COMPILE   =
AS              = $(CROSS_COMPILE)as
LD              = $(CROSS_COMPILE)ld
CC              = $(CROSS_COMPILE)gcc
CPP             = $(CC) -E
AR              = $(CROSS_COMPILE)ar
NM              = $(CROSS_COMPILE)nm
STRIP           = $(CROSS_COMPILE)strip
OBJCOPY         = $(CROSS_COMPILE)objcopy
OBJDUMP         = $(CROSS_COMPILE)objdump
export AS LD CC CPP AR NM STRIP OBJCOPY OBJDUMP

CFLAGS          := -Wall -O2 -g
LDFLAGS         :=
export CFLAGS LDFLAGS

srctree         := $(shell pwd)
export srctree
include $(srctree)/scripts/Makefile.include

TARGET := $(out)app

obj-y += main.o
obj-y += a/
obj-y += b/

all:
	$(Q)$(MAKE) $(mbuild)=.
	$(CC) $(LDFLAGS) -o $(TARGET) $(out)built-in.o

ifeq ($(KBUILD_OUTPUT),)
clean:
	$(Q)$(MAKE) $(mclean)=.
	rm -f $(TARGET)
else
clean:
	rm -rf $(out)
endif
.PHONY:all clean
