# 子目录递归编译

通过 make -C 进入到子目录后，再调用通用的 Makefile.build 编译当前目录的源文件，临时链接为 built-in.o。

## 用法

```
$ make
make -C ./ -f /home/paul/work/kbuild-system/3.recursive-link/1.subdir/scripts/Makefile.build
make[1]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir'
make -C drivers -f /home/paul/work/kbuild-system/3.recursive-link/1.subdir/scripts/Makefile.build
make[2]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/drivers'
make -C input -f /home/paul/work/kbuild-system/3.recursive-link/1.subdir/scripts/Makefile.build
make[3]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/drivers/input'
make[3]: Nothing to be done for 'build'.
make[3]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/drivers/input'
make -C lcd -f /home/paul/work/kbuild-system/3.recursive-link/1.subdir/scripts/Makefile.build
make[3]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/drivers/lcd'
make[3]: Nothing to be done for 'build'.
make[3]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/drivers/lcd'
make[2]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/drivers'
make -C modules -f /home/paul/work/kbuild-system/3.recursive-link/1.subdir/scripts/Makefile.build
make[2]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/modules'
make[2]: Nothing to be done for 'build'.
make[2]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir/modules'
make[1]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/1.subdir'
gcc  -o app built-in.o
```

## 编译前后文件

### 编译前

```
$ tree
.
├── drivers
│   ├── input
│   │   ├── keypad.c
│   │   ├── Makefile
│   │   └── touchpad.c
│   ├── lcd
│   │   ├── Makefile
│   │   ├── st7735.c
│   │   └── st7789.c
│   ├── Makefile
│   └── sensor.c
├── main.c
├── main.h
├── Makefile
├── modules
│   ├── cmd.c
│   ├── list.c
│   └── Makefile
├── README.md
└── scripts
    └── Makefile.build
```

### 编译后

```
.
├── app
├── built-in.o
├── drivers
│   ├── built-in.o
│   ├── input
│   │   ├── built-in.o
│   │   ├── keypad.c
│   │   ├── keypad.o
│   │   ├── Makefile
│   │   ├── touchpad.c
│   │   └── touchpad.o
│   ├── lcd
│   │   ├── built-in.o
│   │   ├── Makefile
│   │   ├── st7735.c
│   │   ├── st7735.o
│   │   ├── st7789.c
│   │   └── st7789.o
│   ├── Makefile
│   ├── sensor.c
│   └── sensor.o
├── main.c
├── main.h
├── main.o
├── Makefile
├── modules
│   ├── built-in.o
│   ├── cmd.c
│   ├── cmd.o
│   ├── list.c
│   ├── list.o
│   └── Makefile
├── README.md
└── scripts
    └── Makefile.build
```

不难发现，在当前目录下生成了源文件对应的 o 文件。并且临时先链接为 built-in.o 文件也能看到的。
依赖文件.d不显示。
