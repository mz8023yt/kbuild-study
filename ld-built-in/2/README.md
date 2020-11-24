# 细化编译过程

最简单的 Makefile 直接从 c 文件一步到位得到可执行文件。

但是其实代码的编译一般分为 4 个步骤，分别是：

- 预处理，.c --> .d，gcc -E
- 编译，.d --> .s，gcc -s
- 汇编，.s --> o，gcc -C
- 链接，.o --> app, ld

这里考虑到 Kbuild 的特点，是将一个目录下的所有源文件先编译为 .o 然后统一链接为 built-in.o 后。再将各个目录的 built-in.o 一起链接为 app。

## 用法

编译

```
paul@maz:~/study/kbuild-study/ld-built-in/2$ make
gcc -o main.o -c main.c
gcc -o printf.o -c printf.c
ld -r -s -o built-in.o main.o printf.o
gcc -o app built-in.o
```

清除

```
paul@maz:~/study/kbuild-study/ld-built-in/2$ make clean
rm -rf app *.o
```

