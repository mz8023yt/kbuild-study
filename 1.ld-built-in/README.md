# 目录结构说明

```
$ tree -Ld 1
.
├── 1.simple
├── 2.split
└── 3.optimize
```

说明：

- 1.simple，最简单的 Makefile，多个 c 文件编译得到一个可执行文件。
- 2.split，将多个 c 文件先编译为对应的 o 文件，并所有的 o 文件链接为 built-in.o，最后再链接为可执行文件。
- 3.optimize，使用 Makefile 自动变量优化 Makefile。