# 编译得到 mconf 工具

参考 linux-2.6.22.6 源码，提取出其中 mconf 主机程序的编译相关的文件。单独编译得到 mconf 工具。

## 用法

```
paul@maz:~/study/kbuild-study/7.host-prog/3.mconf$ make
gcc -o mconf -I./lxdialog -DCURSES_LOC="<ncurses.h>" -DLOCALE mconf.c zconf.tab.c lxdialog/checklist.c lxdialog/util.c lxdialog/inputbox.c lxdialog/textbox.c lxdialog/yesno.c lxdialog/menubox.c -lncurses
makpaul@maz:~/study/kbuild-study/7.host-prog/3.mconf$ make clean
rm -rf mconf
rm -rf *.o
rm -rf lxdialog/.*.o.cmd
rm -rf lxdialog/*.o
paul@maz:~/study/kbuild-study/7.host-prog/3.mconf$ file mconf
mconf: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=8f89876c1f5a50ff78913d8d62a9c568944203a1, not stripped
paul@maz:~/study/kbuild-study/7.host-prog/3.mconf$
```

