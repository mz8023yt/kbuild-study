# 目录结构说明

```
paul@maz:~/study/kbuild-study/3.recursive-link$ tree -Ld 1
.
├── 1.subdir
├── 2.no-print-dir
├── 3.param
└── 4.clean

4 directories
paul@maz:~/study/kbuild-study/3.recursive-link$
```

说明：

- 1.subdir，通过 make -C 进入到子目录后，再调用 Makefile.build 编译当前目录。
- 2.no-print-dir，基于1的基础上，不打印目录进入进出信息。
- 3.param，直接调用 Makefile.build 编译指定的目录，目录通过 make -f 时参数进行传递。
- 4.clean，参考递归编译，实现递归清除。