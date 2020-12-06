# 编译得到 conf 工具

基于 `kbuild-study/7.host-prog/1.conf` 程序基础上，对编译过程进行优化。

主要是解决编译警告。

## 用法

```
paul@maz:~/study/kbuild-study/7.host-prog/3.mconf$ make
gcc -o mconf -I./lxdialog -DCURSES_LOC="<ncurses.h>" -DLOCALE mconf.c zconf.tab.c lxdialog/checklist.c lxdialog/util.c lxdialog/inputbox.c lxdialog/textbox.c lxdialog/yesno.c lxdialog/menubox.c -lncurses
makpaul@maz:~/study/kbuild-study/7.host-prog/3.mconf$ make clean
rm -rf mconf
rm -rf *.o
rm -rf lxdialog/.*.o.cmd
rm -rf lxdialog/*.o
paul@maz:~/study/kbuild-study/7.host-prog/3.mconf$
```

