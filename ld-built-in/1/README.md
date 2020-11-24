# 最简单的Makefile

多个c文件编译为一个可执行文件。

## 用法

编译

```
paul@maz:~/study/kbuild-study/ld-built-in/1$ make
gcc -o app main.c printf.c printf.h
```

清除

```
paul@maz:~/study/kbuild-study/ld-built-in/1$ make clean
rm -rf app
```

