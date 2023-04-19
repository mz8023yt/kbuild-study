# makefile 调试手段

Makefile 提供调试打印函数 info、warning、error 函数。

其中 error 函数除了打印报错信息以外，还会终止 make 编译过程。

```
var = kbuild

### 打印提示信息, 打印参数指定的字符串，变量则打印变量值
$(info --------------------- 1 --------------------)
$(info here is Makefile info!\n $(var))

### 打印调试信息, 相比于 info 多 打印 Makefile 具体的文件名和行号
$(info --------------------- 2 --------------------)
$(warning here is Makefile warning!)

### 打印错误信息, 并停止 Makefile 解析执行流程
$(info --------------------- 3 --------------------)
$(error "here is Makefile error!")

### 这里不会打印，前面 error 已经终止了
$(info --------------------- 4 --------------------)
```

## 用法

```
$ make
--------------------- 1 --------------------
here is Makefile info!\n kbuild
--------------------- 2 --------------------
Makefile:7: here is Makefile warning!
--------------------- 3 --------------------
Makefile:10: *** "here is Makefile error!".  Stop.
```

## 学习总结

### 1. 打印函数后面不需要加双引号

```
$(info --------------------- 2 --------------------)
$(warning here is Makefile warning!)
```

都是直接打印的，不需要双引号，有空格也没有关系。

### 2. 打印函数无法解析转义字符

```
### 打印提示信息, 打印参数指定的字符串
$(info --------------------- 1 --------------------)
$(info here is Makefile info!\n)
```

不难发现，\n 还是 \n，并没有转义为换行符。
