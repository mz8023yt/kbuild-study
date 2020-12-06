# 子目录递归clean

参考递归编译的方式，实现 Makefile.clean 递归清除的规则。

前面几个工程的清除都是简单粗暴的直接find然后清除：

```
clean:
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)
```

## 用法

```
paul@maz:~/study/kbuild-study/3.recursive-link/4.clean$ make
gcc -Wall -O2 -g -Wp,-MD,./a/a1/a1.o.d -c -o a/a1/a1.o a/a1/a1.c
ld -r -o a/a1/built-in.o a/a1/a1.o
gcc -Wall -O2 -g -Wp,-MD,./a/a.o.d -c -o a/a.o a/a.c
ld -r -o a/built-in.o a/a.o a/a1/built-in.o
gcc -Wall -O2 -g -Wp,-MD,./b/b.o.d -c -o b/b.o b/b.c
ld -r -o b/built-in.o b/b.o
gcc -Wall -O2 -g -Wp,-MD,./main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o a/built-in.o b/built-in.o
gcc  -o app built-in.o
paul@maz:~/study/kbuild-study/3.recursive-link/4.clean$ make clean
rm -rf a/a1/a1.o a/a1/a1.o.d a/a1/built-in.o
rm -rf a/a.o a/a.o.d a/built-in.o
rm -rf b/b.o b/b.o.d b/built-in.o
rm -rf ./main.o ./main.o.d ./built-in.o
rm -f app
paul@maz:~/study/kbuild-study/3.recursive-link/4.clean$
```

