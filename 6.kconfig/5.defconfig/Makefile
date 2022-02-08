
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
-include include/config/auto.conf

TARGET := app

obj-y += main.o
obj-$(CONFIG_MENU_FUNC_A) += a/
obj-$(CONFIG_MENU_FUNC_B) += b/
# $(info 222 >>> obj-$(CONFIG_MENU_FUNC_B))

# $(info 111 >>> obj-$(CONFIG_MENU_FUNC_A))

all: autoconf
	$(Q)$(MAKE) $(mbuild)=.
	$(CC) $(LDFLAGS) -o $(TARGET) built-in.o

%_defconfig: scripts/kconfig/conf FORCE
	scripts/kconfig/conf -D configs/$@ Kconfig

menuconfig: scripts/kconfig/mconf
	$(Q)$< Kconfig

autoconf: scripts/kconfig/conf FORCE
	mkdir -p include/config
	mkdir -p include/linux
	$< -s Kconfig

clean:
	$(Q)$(MAKE) $(mclean)=.
	rm -f $(TARGET)
	rm -rf include

.PHONY:all clean
