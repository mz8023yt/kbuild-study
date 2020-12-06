# 目录结构说明

```
paul@maz:~/study/kbuild-study/6.kconfig$ tree -Ld 1
.
├── 1.manual
├── 2.menuconfig
├── 3.autoconf
├── 4.obj-xxx_CONFIG
└── 5.defconfig

5 directories
paul@maz:~/study/kbuild-study/6.kconfig$
```

说明：

- 1.manual，手动调用 mconf 工具进入配置界面，生成 .config 文件。
- 2.menuconfig，支持 make menuconfig 进入配置界面，生成 .config 文件。
- 3.autoconf，根据 .config 文件生成 auto.conf 和 autoconf.h 文件。
- 4.obj-xxx_CONFIG，根据 auto.conf 文件中配置项的值控制编译哪些文件。
- 5.defconfig，支持 make xxx_defconfig 加载默认配置文件。