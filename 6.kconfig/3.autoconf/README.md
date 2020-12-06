# 生成 auto.conf 和 autoconf.h 文件

根据 .config 文件生成 auto.conf 和 autoconf.h 文件。

其中 `scripts/kconfig/conf -s Kconfig` 这条指令用于生成 auto.conf 和 autoconf.h 文件。

## 用法

```
paul@maz:~/study/kbuild-study/6.kconfig/3.autoconf$ make menuconfig 


*** End of Linux kernel configuration.
*** Execute 'make' to build the kernel or try 'make help'.

paul@maz:~/study/kbuild-study/6.kconfig/3.autoconf$ make 
mkdir -p include/config
mkdir -p include/linux
scripts/kconfig/conf -s Kconfig
gcc -Wall -O2 -g -Wp,-MD,./a/a1/a1.o.d -c -o a/a1/a1.o a/a1/a1.c
ld -r -o a/a1/built-in.o a/a1/a1.o
gcc -Wall -O2 -g -Wp,-MD,./a/a.o.d -c -o a/a.o a/a.c
ld -r -o a/built-in.o a/a.o a/a1/built-in.o
gcc -Wall -O2 -g -Wp,-MD,./b/b.o.d -c -o b/b.o b/b.c
ld -r -o b/built-in.o b/b.o
gcc -Wall -O2 -g -Wp,-MD,./main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o a/built-in.o b/built-in.o
gcc  -o app built-in.o

```

编译结束后，将生成 auto.conf 和 autoconf.h 文件。

```
paul@maz:~/study/kbuild-study/6.kconfig/3.autoconf$ tree include/
include/
├── config
│   ├── auto.conf
│   ├── auto.conf.cmd
│   ├── func
│   │   ├── a1.h
│   │   ├── a.h
│   │   └── b.h
│   └── menu
│       └── func
│           ├── a.h
│           └── b.h
└── linux
    └── autoconf.h

5 directories, 8 files
paul@maz:~/study/kbuild-study/6.kconfig/3.autoconf$
```

