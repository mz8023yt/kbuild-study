# 最简单的Makefile

多个c文件编译为一个可执行文件。

## 用法

```
paul@maz:~/study/kbuild-study/1.ld-built-in/1.simple$ make
gcc -o app main.c printf.c printf.h
paul@maz:~/study/kbuild-study/1.ld-built-in/1.simple$ make clean
rm -rf app
paul@maz:~/study/kbuild-study/1.ld-built-in/1.simple$
```



