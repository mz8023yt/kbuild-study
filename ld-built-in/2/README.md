## 细化编译过程

```
paul@maz:~/study/kbuild/ld-built-in/2$ make
gcc -o main.o -c main.c
gcc -o printf.o -c printf.c
ld -r -s -o built-in.o main.o printf.o
gcc -o app built-in.o
paul@maz:~/study/kbuild/ld-built-in/2$ make clean
rm -rf app
paul@maz:~/study/kbuild/ld-built-in/2$
```
