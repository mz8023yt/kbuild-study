
conf:
	gcc -Wp,-MD,.zconf.tab.o.d -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -DCURSES_LOC="<ncurses.h>" -DLOCALE -Iscripts/kconfig -c -o zconf.tab.o zconf.tab.c
	gcc -o conf conf.c zconf.tab.o -lncurses

clean:
	rm -rf conf
	rm -rf *.o
	rm -rf .zconf.tab.o.d