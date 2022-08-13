# 生成 auto.conf 和 autoconf.h 文件

根据 .config 文件生成 auto.conf 和 autoconf.h 文件。

其中 `scripts/kconfig/conf -s Kconfig` 这条指令用于生成 auto.conf 和 autoconf.h 文件。

## 用法

```
paul@maz:~/study/kbuild-study/6.kconfig/3.autoconf$ make menuconfig 
scripts/kconfig/mconf Kconfig
#
# configuration written to .config
#


*** End of Linux kernel configuration.
*** Execute 'make' to build the kernel or try 'make help'.

paul@maz:~/study/kbuild-study/6.kconfig/3.autoconf$ make autoconf 
mkdir -p include/config
mkdir -p include/linux
scripts/kconfig/conf -s Kconfig
paul@maz:~/study/kbuild-study/6.kconfig/3.autoconf$ 
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

