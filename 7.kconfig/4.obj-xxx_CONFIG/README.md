# Makefile 根据 auto.conf 配置项进行编译控制

参考内核编译规则，根据配置项决定文件是否被编译。

```
paul@maz:~/study/kbuild-study/6.kconfig/4.obj-xxx_CONFIG$ cat a/Makefile 
obj-$(CONFIG_FUNC_A) += a.o
obj-$(CONFIG_FUNC_A1) += a1/
paul@maz:~/study/kbuild-study/6.kconfig/4.obj-xxx_CONFIG$
```

