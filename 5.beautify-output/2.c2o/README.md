# 简单改进 c2o 优化

显示效果没有改变，仅仅是将 c2o 的过程单独拎出来了。

## 用法

```
paul@maz:~/study/kbuild-study/5.beautify-output/2.c2o$ make 
  CC      printf.c
  CC      main.c
  LD      built-in.o
  LD      app
paul@maz:~/study/kbuild-study/5.beautify-output/2.c2o$ make clean
  CLEAN   app *.o
paul@maz:~/study/kbuild-study/5.beautify-output/2.c2o$
```
