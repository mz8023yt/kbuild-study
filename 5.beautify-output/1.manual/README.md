# 手动美化

众所周知，Kernel 编译的时候，编译打印输出是很漂亮的。

本系列示例程序就是要研究 Kbuild 编译打印美化的功能的。

第一步，最简单的动作就是，先手动的进行美化，不做让任何抽象的动作。

## 用法（看输出效果）

```
paul@maz:~/study/kbuild-study/5.beautify-output/1.manual$ make
  CC      main.o
  CC      printf.o
  LD      built-in.o
  LD      app
paul@maz:~/study/kbuild-study/5.beautify-output/1.manual$ make clean
  CLEAN   app *.o
paul@maz:~/study/kbuild-study/5.beautify-output/1.manual$
```



