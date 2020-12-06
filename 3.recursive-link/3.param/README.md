# 子目录递归编译 - 目录作为参数

直接通过 make -f 调用通用的 Makefile.build 编译参数指定的目录，将参数目录临时链接为 built-in.o。

和前面工程的具体差异点为：进入子目录编译的方式略有不同。

方案1：kbuild-study/3.recursive-link/1.subdir 参考CSDN博客

```
$(subdir-y):
	$(Q)$(MAKE) -C $@ -f $(srctree)/scripts/Makefile.build
```

方案2：kbuild-study/3.recursive-link/3.param 参考Linux内核源码

```
kbuild-study/3.recursive-link/3.param
```

## 用法

```
paul@maz:~/study/kbuild-study/3.recursive-link/3.param$ make
gcc -Wall -O2 -g -Wp,-MD,./a/a1/a1.o.d -c -o a/a1/a1.o a/a1/a1.c
ld -r -o a/a1/built-in.o a/a1/a1.o
gcc -Wall -O2 -g -Wp,-MD,./a/a.o.d -c -o a/a.o a/a.c
ld -r -o a/built-in.o a/a.o a/a1/built-in.o
gcc -Wall -O2 -g -Wp,-MD,./b/b.o.d -c -o b/b.o b/b.c
ld -r -o b/built-in.o b/b.o
gcc -Wall -O2 -g -Wp,-MD,./main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o a/built-in.o b/built-in.o
gcc  -o app built-in.o
paul@maz:~/study/kbuild-study/3.recursive-link/3.param$ make clean
rm -f ./main.o ./b/b.o ./b/built-in.o ./built-in.o ./a/built-in.o ./a/a1/built-in.o ./a/a1/a1.o ./a/a.o
rm -f ./b/b.o.d ./main.o.d ./a/a1/a1.o.d ./a/a.o.d
rm -f app
```

