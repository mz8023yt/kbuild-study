# 编译时动态控制 clean 打印形式

make clean 支持 V 变量控制打印输出的格式。

## 用法

```
paul@maz:~/study/kbuild-study/5.beautify-output/3.clean-dyn-ctrl$ make && make clean 
  CC      printf.c
  CC      main.c
  LD      built-in.o
  LD      app
  CLEAN   app *.o
paul@maz:~/study/kbuild-study/5.beautify-output/3.clean-dyn-ctrl$ make && make clean V=1
  CC      printf.c
  CC      main.c
  LD      built-in.o
  LD      app
  rm -f app *.o
paul@maz:~/study/kbuild-study/5.beautify-output/3.clean-dyn-ctrl$
```
