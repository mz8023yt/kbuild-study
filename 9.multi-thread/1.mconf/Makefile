BIN     = mconf
CC      = gcc
Q       = @

IFLAGS  = -Iinclude
LFLAGS  = -Wl,-Bsymbolic-functions -lncursesw -ltinfo
CFLAGS  = $(IFLAGS)

SRCS = $(wildcard src/*.c)
SRCS += $(wildcard src/lxdialog/*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

# $(info SRCS=$(SRCS))
# $(info OBJS=$(OBJS))

$(BIN) : $(OBJS)
	$(Q)$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@

%.o:%.c
	$(Q)$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(Q)rm -rf $(BIN)
	$(Q)rm -f $(shell find -name "*.o")
