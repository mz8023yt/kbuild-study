# 编译中间文件和成果物输出到指定的目录

通过 make 时传入 O 参数指定输出路径。

## 用法

### 默认编译，不指定输出路径。

编译前目录结构：

```
paul@maz:~/study/kbuild-study/output-separate/1$ tree
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
    ├── Makefile.build
    ├── Makefile.clean
    └── Makefile.include

4 directories, 16 files
```

使用 `make` 命令进行编译。

```
paul@maz:~/study/kbuild-study/output-separate/1$ make 
gcc -Wall -O2 -g -c -o a/a1/a1.o a/a1/a1.c
ld -r -o a/a1/built-in.o a/a1/a1.o
gcc -Wall -O2 -g -c -o a/a.o a/a.c
ld -r -o a/built-in.o a/a.o a/a1/built-in.o
gcc -Wall -O2 -g -c -o b/b.o b/b.c
ld -r -o b/built-in.o b/b.o
gcc -Wall -O2 -g -c -o main.o main.c
ld -r -o built-in.o main.o a/built-in.o b/built-in.o
gcc  -o app built-in.o
```

编译结束后，中间文件和成果物位于源码对应目录中。

```
paul@maz:~/study/kbuild-study/output-separate/1$ tree
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
    ├── Makefile.build
    ├── Makefile.clean
    └── Makefile.include

4 directories, 25 files
paul@maz:~/study/kbuild-study/output-separate/1$
```

### 通过 O 参数指定输出路径。

通过 O 参数指定输出路径为 output 目录。

```
paul@maz:~/study/kbuild-study/output-separate/1$ make O=output
mkdir: cannot create directory ‘/home/paul/study/kbuild-study/output-separate/1/output/.’: File exists
gcc -Wall -O2 -g -c -o /home/paul/study/kbuild-study/output-separate/1/output/a/a1/a1.o a/a1/a1.c
ld -r -o /home/paul/study/kbuild-study/output-separate/1/output/a/a1/built-in.o /home/paul/study/kbuild-study/output-separate/1/output/a/a1/a1.o
gcc -Wall -O2 -g -c -o /home/paul/study/kbuild-study/output-separate/1/output/a/a.o a/a.c
ld -r -o /home/paul/study/kbuild-study/output-separate/1/output/a/built-in.o /home/paul/study/kbuild-study/output-separate/1/output/a/a.o /home/paul/study/kbuild-study/output-separate/1/output/a/a1/built-in.o
gcc -Wall -O2 -g -c -o /home/paul/study/kbuild-study/output-separate/1/output/b/b.o b/b.c
ld -r -o /home/paul/study/kbuild-study/output-separate/1/output/b/built-in.o /home/paul/study/kbuild-study/output-separate/1/output/b/b.o
gcc -Wall -O2 -g -c -o /home/paul/study/kbuild-study/output-separate/1/output/./main.o main.c
ld -r -o /home/paul/study/kbuild-study/output-separate/1/output/./built-in.o /home/paul/study/kbuild-study/output-separate/1/output/./main.o /home/paul/study/kbuild-study/output-separate/1/output/./a/built-in.o /home/paul/study/kbuild-study/output-separate/1/output/./b/built-in.o
gcc  -o /home/paul/study/kbuild-study/output-separate/1/output/app /home/paul/study/kbuild-study/output-separate/1/output/built-in.o
```

编译后成果物全部存放在 output 对应目录结构中。保持源码目录干净整洁。

```
paul@maz:~/study/kbuild-study/output-separate/1$ tree
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
├── output
│   ├── a
│   │   ├── a1
│   │   │   ├── a1.o
│   │   │   └── built-in.o
│   │   ├── a.o
│   │   └── built-in.o
│   ├── app
│   ├── b
│   │   ├── b.o
│   │   └── built-in.o
│   ├── built-in.o
│   └── main.o
├── README.md
└── scripts
    ├── Makefile.build
    ├── Makefile.clean
    └── Makefile.include

8 directories, 25 files
```

注意：使用 O 参数指定输出路径后，make clean 也需要指定，不然 clean 的时候不知道该 clean 哪里。