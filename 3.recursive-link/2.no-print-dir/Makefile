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

include scripts/Makefile.include

TARGET := app

obj-y += main.o
obj-y += drivers/
obj-y += modules/

all:
	$(Q)$(MAKE) -C ./ -f $(srctree)/scripts/Makefile.build
	$(CC) $(LDFLAGS) -o $(TARGET) built-in.o

clean:
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)

.PHONY:all clean
