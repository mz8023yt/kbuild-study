# 手动美化

众所周知，Kernel 编译的时候，编译打印输出是很漂亮的。

本示例就是研究 Kbuild 编译打印美化的功能的。

## 用法

编译（看输出效果）

```
paul@maz:~/study/kbuild-study/beautify-output/1$ make
  CC      main.o
  CC      printf.o
  LD      built-in.o
  LD      app
```

清除（看输出效果）

```
paul@maz:~/study/kbuild-study/beautify-output/1$ make clean
  CLEAN   app *.o
```



