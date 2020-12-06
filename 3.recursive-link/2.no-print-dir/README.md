# 子目录递归编译

基于 `/kbuild-study/3.recursive-link/1.subdir` 工程基础上，make 时增加 `--no-print-directory` 选项，不显示目录信息。

## 用法

```
paul@maz:~/study/kbuild-study/3.recursive-link/2.no-print-dir$ make
gcc -Wall -O2 -g -Wp,-MD,.a1.o.d -c -o a1.o a1.c
ld -r -o built-in.o a1.o
gcc -Wall -O2 -g -Wp,-MD,.a.o.d -c -o a.o a.c
ld -r -o built-in.o a.o a1/built-in.o
gcc -Wall -O2 -g -Wp,-MD,.b.o.d -c -o b.o b.c
ld -r -o built-in.o b.o
gcc -Wall -O2 -g -Wp,-MD,.main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o a/built-in.o b/built-in.o
gcc  -o app built-in.o
paul@maz:~/study/kbuild-study/3.recursive-link/2.no-print-dir$ make clean
rm -f ./main.o ./b/b.o ./b/built-in.o ./built-in.o ./a/built-in.o ./a/a1/built-in.o ./a/a1/a1.o ./a/a.o
rm -f ./b/.b.o.d ./.main.o.d ./a/.a.o.d ./a/a1/.a1.o.d
rm -f app
paul@maz:~/study/kbuild-study/3.recursive-link/2.no-print-dir$
```

这是没有添加 `--no-print-directory` 选项的打印输出。

```
paul@maz:~/study/kbuild-study/3.recursive-link/1.subdir$ make
make -C ./ -f /home/paul/study/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[1]: Entering directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir'
make -C a -f /home/paul/study/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[2]: Entering directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir/a'
make -C a1 -f /home/paul/study/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[3]: Entering directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir/a/a1'
gcc -Wall -O2 -g -Wp,-MD,.a1.o.d -c -o a1.o a1.c
ld -r -o built-in.o a1.o
make[3]: Leaving directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir/a/a1'
gcc -Wall -O2 -g -Wp,-MD,.a.o.d -c -o a.o a.c
ld -r -o built-in.o a.o a1/built-in.o
make[2]: Leaving directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir/a'
make -C b -f /home/paul/study/kbuild-study/3.recursive-link/1.subdir/scripts/Makefile.build
make[2]: Entering directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir/b'
gcc -Wall -O2 -g -Wp,-MD,.b.o.d -c -o b.o b.c
ld -r -o built-in.o b.o
make[2]: Leaving directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir/b'
gcc -Wall -O2 -g -Wp,-MD,.main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o a/built-in.o b/built-in.o
make[1]: Leaving directory '/home/paul/study/kbuild-study/3.recursive-link/1.subdir'
gcc  -o app built-in.o
paul@maz:~/study/kbuild-study/3.recursive-link/1.subdir$ make clean
rm -f ./main.o ./b/b.o ./b/built-in.o ./built-in.o ./a/built-in.o ./a/a1/built-in.o ./a/a1/a1.o ./a/a.o
rm -f ./b/.b.o.d ./.main.o.d ./a/.a.o.d ./a/a1/.a1.o.d
rm -f app
paul@maz:~/study/kbuild-study/3.recursive-link/1.subdir$
```



