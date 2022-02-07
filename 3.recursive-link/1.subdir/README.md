# 子目录递归编译

通过 make -C 进入到子目录后，再调用通用的 Makefile.build 编译当前目录的源文件，临时链接为 built-in.o。

## 用法

```
$ make
make -C ./ -f /home/paul/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[1]: Entering directory '/home/paul/kbuild-study/3.recursive-link/1.subdir'
make -C a -f /home/paul/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[2]: Entering directory '/home/paul/kbuild-study/3.recursive-link/1.subdir/a'
make -C a1 -f /home/paul/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[3]: Entering directory '/home/paul/kbuild-study/3.recursive-link/1.subdir/a/a1'
gcc -Wall -O2 -g -Wp,-MD,.a1.o.d -c -o a1.o a1.c
ld -r -o built-in.o a1.o
make[3]: Leaving directory '/home/paul/kbuild-study/3.recursive-link/1.subdir/a/a1'
gcc -Wall -O2 -g -Wp,-MD,.a.o.d -c -o a.o a.c
ld -r -o built-in.o a.o a1/built-in.o
make[2]: Leaving directory '/home/paul/kbuild-study/3.recursive-link/1.subdir/a'
make -C b -f /home/paul/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[2]: Entering directory '/home/paul/kbuild-study/3.recursive-link/1.subdir/b'
gcc -Wall -O2 -g -Wp,-MD,.b.o.d -c -o b.o b.c
ld -r -o built-in.o b.o
make[2]: Leaving directory '/home/paul/kbuild-study/3.recursive-link/1.subdir/b'
gcc -Wall -O2 -g -Wp,-MD,.main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o a/built-in.o b/built-in.o
make[1]: Leaving directory '/home/paul/kbuild-study/3.recursive-link/1.subdir'
gcc  -o app built-in.o
```

## 编译前后文件

### 编译前

```
$ tree
.
├── a
│   ├── a1
│   │   ├── a1.c
│   │   ├── a1.h
│   │   └── Makefile
│   ├── a.c
│   ├── a.h
│   └── Makefile
├── b
│   ├── b.c
│   ├── b.h
│   └── Makefile
├── main.c
├── main.h
├── Makefile
├── README.md
└── scripts
    └── Makefile.build

4 directories, 14 files
```

### 编译后

```
$ tree
.
├── a
│   ├── a1
│   │   ├── a1.c
│   │   ├── a1.h
│   │   ├── a1.o
│   │   ├── built-in.o
│   │   └── Makefile
│   ├── a.c
│   ├── a.h
│   ├── a.o
│   ├── built-in.o
│   └── Makefile
├── app
├── b
│   ├── b.c
│   ├── b.h
│   ├── b.o
│   ├── built-in.o
│   └── Makefile
├── built-in.o
├── main.c
├── main.h
├── main.o
├── Makefile
├── README.md
└── scripts
    └── Makefile.build

4 directories, 23 files
```

不难发现，在当前目录下生成了源文件对应的 o 文件。并且临时先链接为 built-in.o 文件也能看到的。
依赖文件.d不显示。
