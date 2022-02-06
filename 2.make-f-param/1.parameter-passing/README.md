# make -f 传参验证

Kbuild 在递归编译子目录的时候，是通过遍历得到的各级子目录作为参数传递给 scripts/Makefile.build 通用编译规则进行编译，因为有必要研究下 make -f 调用其他 Makefile 时，参数传递的机制。

本示例是验证几种传参方式的是否能够正确传递。

顶层 Makefile 内容为：

```
export param1 := val1
param2 := val2

all:
	@echo " --------------- top makefile print start ---------------"
	make -f scripts/Makefile.build param0=val0
	@echo " ---------------- top makefile print end ----------------"
```

脚本 Makefile 内容为：

```
PHONY := __build

__build: 
	echo $(param0)
	echo $(param1)
	echo $(param2)
```

结论如下：

- param0，make -f 调试用传参
- param1，导出为环境变量传参
- param2，传递失败

## 用法

```
paul@maz:~/study/kbuild-study/2.make-f-param/1.parameter-passing$ make
 --------------- top makefile print start ---------------
make -f scripts/Makefile.build param0=val0
make[1]: Entering directory '/home/paul/study/kbuild-study/2.make-f-param/1.parameter-passing'
echo val0
val0
echo val1
val1
echo 

make[1]: Leaving directory '/home/paul/study/kbuild-study/2.make-f-param/1.parameter-passing'
 ---------------- top makefile print end ----------------
paul@maz:~/study/kbuild-study/2.make-f-param/1.parameter-passing$
```

## 学习总结

### 1. Makefile 传参方式

可以通过 export 导出为环境变量的方式进行传参，但是这样会污染环境变量池，可以能会影响到其他应用。
也可以通过 make -f <makefile> <param_name=param_val> 的方式，在指定 Makefile 文件后，紧跟着传递参数名称和对应的值。
