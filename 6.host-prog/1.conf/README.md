# 编译得到 conf 工具

参考 linux-2.6.22.6 源码，提取出其中 conf 主机程序的编译相关的文件。单独编译得到 conf 工具。

## 用法

```
paul@maz:~/study/kbuild-study/7.host-prog/1.conf$ make
gcc -Wp,-MD,.zconf.tab.o.d -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer -DCURSES_LOC="<ncurses.h>" -DLOCALE -Iscripts/kconfig -c -o zconf.tab.o zconf.tab.c
In file included from zconf.tab.c:158:0:
zconf.hash.c:161:43: warning: ‘kconf_id_strings_contents’ is static but used in inline function ‘kconf_id_lookup’ which is not static
 #define kconf_id_strings ((const char *) &kconf_id_strings_contents)
                                           ^
zconf.hash.c:233:44: note: in expansion of macro ‘kconf_id_strings’
               register const char *s = o + kconf_id_strings;
                                            ^~~~~~~~~~~~~~~~
zconf.hash.c:226:26: warning: ‘kconf_id_hash’ is static but used in inline function ‘kconf_id_lookup’ which is not static
       register int key = kconf_id_hash (str, len);
                          ^~~~~~~~~~~~~
zconf.hash.c:177:26: warning: ‘wordlist’ is static but declared in inline function ‘kconf_id_lookup’ which is not static
   static struct kconf_id wordlist[] =
                          ^~~~~~~~
In file included from zconf.tab.c:2340:0:
scripts/kconfig/lex.zconf.c:1620:16: warning: ‘input’ defined but not used [-Wunused-function]
gcc -o conf conf.c zconf.tab.o -lncurses
paul@maz:~/study/kbuild-study/7.host-prog/1.conf$ make clean
rm -rf conf
rm -rf *.o
rm -rf .zconf.tab.o.d
paul@maz:~/study/kbuild-study/7.host-prog/1.conf$
```

不难发现，还有很多的编译警告没有做处理。