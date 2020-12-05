## 编译时动态控制 cc ld 打印形式

```
paul@maz:~/study/kbuild/beautify-output/4$ make V=1 && make clean V=1
  gcc -c printf.c -o printf.o
  gcc -c main.c -o main.o
  ld -r -s -o built-in.o printf.o main.o
  LD      app
  rm -f app *.o
paul@maz:~/study/kbuild/beautify-output/4$ make && make clean
  CC      printf.c
  CC      main.c
  LD      built-in.o
  LD      app
  CLEAN   app *.o
paul@maz:~/study/kbuild/beautify-output/4$ 
```
