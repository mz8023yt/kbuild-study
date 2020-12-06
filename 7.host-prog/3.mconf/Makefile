
mconf:
	gcc -o mconf -I./lxdialog -DCURSES_LOC="<ncurses.h>" -DLOCALE mconf.c zconf.tab.c lxdialog/checklist.c lxdialog/util.c lxdialog/inputbox.c lxdialog/textbox.c lxdialog/yesno.c lxdialog/menubox.c -lncurses

clean:
	rm -rf mconf
	rm -rf *.o
	rm -rf lxdialog/.*.o.cmd
	rm -rf lxdialog/*.o

.PHONY:mconf clean
