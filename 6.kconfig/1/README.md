### mconf 工具使用

```
./scripts/kconfig/mconf Kconfig
```

配置结束，配置结果保存在在 `.config` 文件中。

```
paul@maz:~/study/kbuild/Kconfig/1$ cat .config
#
# Automatically generated make config: don't edit
# Linux kernel version: 
# Sun Nov 22 22:03:50 2020
#
CONFIG_MENU_FUNC_A=y
CONFIG_FUNC_A=y
# CONFIG_FUNC_A1 is not set
CONFIG_MENU_FUNC_B=y
CONFIG_FUNC_B=y
```

