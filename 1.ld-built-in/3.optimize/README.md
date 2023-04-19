# 使用自动变量

Makefile 提供了自动变量简化 Makefile 规则的编写。
自动变量是局部变量，作用域范围在当前的规则内。

- $@：目标
- $^：所有目标依赖
- $<：目标依赖列表中的第一个依赖
- $?：所有目标依赖中被修改过的文件

有了这些自动变量，我们就可以改进 Makefile。

```
app: main.o printf.o
	ld -r -s -o built-in.o $^
	gcc -o $@ built-in.o

%.o: %.c
	gcc -c -o $@ $^

clean:
	rm -rf app *.o
```

## 用法

```
$ make
gcc -c -o main.o main.c
gcc -c -o printf.o printf.c
ld -r -s -o built-in.o main.o printf.o
gcc -o app built-in.o
```
