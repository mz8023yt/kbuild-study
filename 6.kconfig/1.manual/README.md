# mconf 工具使用

## 用法

手动调用 mconf 工具解析 Kconfig 文件。将会弹出配置菜单界面。

```
./scripts/kconfig/mconf Kconfig
```

配置结束，配置结果保存在在 `.config` 文件中。

```
paul@maz:~/study/kbuild-study/6.kconfig/1.manual$ cat .config 
#
# Automatically generated make config: don't edit
# Linux kernel version: 
# Mon Dec  7 00:27:42 2020
#
CONFIG_MENU_FUNC_A=y
CONFIG_FUNC_A=y
CONFIG_FUNC_A1=y
CONFIG_MENU_FUNC_B=y
CONFIG_FUNC_B=y
paul@maz:~/study/kbuild-study/6.kconfig/1.manual$
```

