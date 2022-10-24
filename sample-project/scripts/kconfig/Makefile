
all: conf mconf

conf:
	gcc -o conf conf.c confdata.c expr.c lexer.lex.c menu.c parser.tab.c preprocess.c symbol.c util.c

mconf:
	gcc -o mconf mconf.c lxdialog/checklist.c lxdialog/inputbox.c lxdialog/menubox.c lxdialog/textbox.c lxdialog/util.c lxdialog/yesno.c confdata.c expr.c lexer.lex.c menu.c parser.tab.c preprocess.c symbol.c util.c -Wl,-Bsymbolic-functions -lncursesw -ltinfo

clean:
	rm -rf conf
	rm -rf mconf
	rm -rf *.o
	rm -rf lxdialog/*.o
	rm -rf lxdialog/.*.o.cmd

.PHONY:conf mconf clean
