# 支持 make menuconfig

## 用法

```
paul@maz:~/study/kbuild-study/6.kconfig/2.menuconfig$ make menuconfig
scripts/kconfig/mconf Kconfig


*** End of Linux kernel configuration.
*** Execute 'make' to build the kernel or try 'make help'.

paul@maz:~/study/kbuild-study/6.kconfig/2.menuconfig$
```

配置结束，配置结果保存在在 `.config` 文件中。

```
paul@maz:~/study/kbuild-study/6.kconfig/2.menuconfig$ cat .config 
#
# Automatically generated make config: don't edit
# Linux kernel version: 
# Mon Dec  7 00:09:52 2020
#
CONFIG_MENU_FUNC_A=y
CONFIG_FUNC_A=y
CONFIG_FUNC_A1=y
CONFIG_MENU_FUNC_B=y
CONFIG_FUNC_B=y
paul@maz:~/study/kbuild-study/6.kconfig/2.menuconfig$
```

