# 支持 make xxx_defconfig 加载默认配置文件

用法：

```
paul@maz:~/study/kbuild-study/kconfig/5$ ls configs/
kbuild_demo_defconfig
paul@maz:~/study/kbuild-study/kconfig/5$ make kbuild_demo_defconfig
scripts/kconfig/conf -D configs/kbuild_demo_defconfig Kconfig
*
* Linux Kernel Configuration
*
*
* MENU_FUNC_A
*
MENU_FUNC_A (MENU_FUNC_A) [Y/n] y
  FUNC_A (FUNC_A) [Y/n] y
    FUNC_A1 (FUNC_A1) [N/y] n
*
* MENU_FUNC_B
*
MENU_FUNC_B (MENU_FUNC_B) [Y/n] y
  FUNC_B (FUNC_B) [Y/n] y
#
# configuration written to .config
#
```

