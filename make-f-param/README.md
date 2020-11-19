## make -f 传参

param0，调试用传参
param1，导出为环境变量传参
param2，传递失败

```

paul@maz:~/study/kbuild/make-f-param$ make
 --------------- top makefile print start ---------------
make -f scripts/Makefile.build param0=val0
make[1]: Entering directory '/home/paul/study/kbuild/make-f-param'
echo val0
val0
echo val1
val1
echo

make[1]: Leaving directory '/home/paul/study/kbuild/make-f-param'
 ---------------- top makefile print end ----------------
paul@maz:~/study/kbuild/make-f-param$
``
