# 目录结构说明

```
paul@maz:~/study/kbuild-study/ld-built-in$ tree
.
├── 1		// 最简单的 Makefile，多个 c 文件编译得到一个可执行文件。
│   ├── app
│   ├── main.c
│   ├── Makefile
│   ├── printf.c
│   ├── printf.h
│   └── README.md
├── 2		// 将多个 c 文件先编译为对应的 o 文件，并所有的 o 文件链接为 built-in.o，最后再链接为可执行文件。
│   ├── main.c
│   ├── Makefile
│   ├── printf.c
│   ├── printf.h
│   └── README.md
└── README.md

2 directories, 12 files
```

