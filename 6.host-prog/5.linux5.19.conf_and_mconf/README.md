# 编译得到 conf 工具

基于 `kbuild-study/7.host-prog/2.conf.optimize` 和 `/kbuild-study/7.host-prog/3.mconf` 程序基础上，将两个工具组合起来，集成到一个工程中。

```
sudo apt-get install libncursesw5-dev
```

## 用法

```
paul@maz:~/study/kbuild-study/7.host-prog/4.conf_and_mconf$ make
gcc -o conf conf.c zconf.tab.c -lncurses
paul@maz:~/study/kbuild-study/7.host-prog/4.conf_and_mconf$ ls conf
conf
paul@maz:~/study/kbuild-study/7.host-prog/4.conf_and_mconf$ make mconf 
gcc -o mconf -I./lxdialog -DCURSES_LOC="<ncurses.h>" -DLOCALE mconf.c zconf.tab.c lxdialog/checklist.c lxdialog/util.c lxdialog/inputbox.c lxdialog/textbox.c lxdialog/yesno.c lxdialog/menubox.c -lncurses
paul@maz:~/study/kbuild-study/7.host-prog/4.conf_and_mconf$ ls mconf
mconf
paul@maz:~/study/kbuild-study/7.host-prog/4.conf_and_mconf$ make clean
rm -rf conf
rm -rf mconf
rm -rf *.o
rm -rf lxdialog/*.o
rm -rf lxdialog/.*.o.cmd
paul@maz:~/study/kbuild-study/7.host-prog/4.conf_and_mconf$
```

