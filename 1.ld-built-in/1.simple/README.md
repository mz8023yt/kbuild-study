# 最简单的Makefile

实现的功能为：多个c文件编译为一个可执行文件。

针对原始的 gcc 编译命令不做任何处理，仅仅利用 Makefile 依赖规则将原本在命令行中执行的命令 `gcc -o app main.c printf.c printf.h` 写入 Makefile 脚本中执行。

```
app: main.c printf.c printf.h
	gcc -o app main.c printf.c printf.h

clean:
	rm -rf app
```

这里将头文件和源文件都放在依赖列表中。属于最简单粗暴的实现方式，后续将慢慢优化和完善。

## 用法

```
$ make
gcc -o app main.c printf.c printf.h

$ make clean
rm -rf app
```

## 学习总结

### 1. Makefile 基本规则

```
目标: 依赖文件列表
    给出从依赖文件生成目标的实际命令, shell 命令
```

### 2. gcc 编译 c 程序

```
-o 指定输出文件名
```
