## 编译时动态控制 clean 打印形式

```
paul@maz:~/study/kbuild/beautify-output/3$ make && make clean
  CC      printf.c
  CC      main.c
  LD      built-in.o
  LD      app
  CLEAN   app *.o
paul@maz:~/study/kbuild/beautify-output/3$ make && make clean V=1
  CC      printf.c
  CC      main.c
  LD      built-in.o
  LD      app
  rm -f app *.o
paul@maz:~/study/kbuild/beautify-output/3$ 
```
