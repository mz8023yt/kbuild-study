# 细化编译过程

最简单的 Makefile 直接从源文件一步到位编译得到可执行文件。

但是其实源码到可执行文件转化过程一般分为 4 个步骤，分别是：

- 预处理，.c --> .d，gcc -E
- 编译，.d --> .s，gcc -s
- 汇编，.s --> o，gcc -C
- 链接，.o --> elf, ld

这里考虑到 Kbuild 的特点，是将一个目录下的所有源文件先编译为 .o 然后统一链接为 built-in.o 后。再将各个目录的 built-in.o 一起链接为 app，因此参考这套思想，优化 Makefile。

```
app: main.c printf.c printf.h
	gcc -o main.o -c main.c
	gcc -o printf.o -c printf.c
	ld -r -s -o built-in.o main.o printf.o
	gcc -o app built-in.o

clean:
	rm -rf app *.o
```

## 用法

```
$ make
gcc -o main.o -c main.c
gcc -o printf.o -c printf.c
ld -r -s -o built-in.o main.o printf.o
gcc -o app built-in.o

$ make clean 
rm -rf app *.o
```

## 学习总结

### 1. ld 链接命令选项

参考资料：https://blog.csdn.net/wdjjwb/article/details/86536169

```
-r'–relocateable’
这个选项目前只支持ELF平台. 产生可重定位的输出.
比如, 产生一个输出文件它可再次作为 ’ld’ 的输入.这经常被叫做"部分连接".

-s –strip-all
忽略输出文件中所有的符号信息.

-S –strip-debug 
忽略输出文件中所有的调试符号信息(但不是所有符号).
```
