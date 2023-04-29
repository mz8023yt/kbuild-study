srctree         := $(shell pwd)
export srctree

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

CFLAGS          := -Iinclude
LDFLAGS         := -Wl,-Bsymbolic-functions -lncursesw -ltinfo
export CFLAGS LDFLAGS

include $(srctree)/scripts/Makefile.include

TARGET := mconf

obj-y += src/

all:
	$(Q)$(MAKE) $(mbuild)=.
	$(CC) built-in.o $(LDFLAGS) -o $(TARGET)

clean:
	$(Q)$(MAKE) $(mclean)=.
	rm -f $(TARGET)

.PHONY:all clean