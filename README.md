
# 从零开始构建 Kbuild 编译框架

## 目标

- 使用简单，make config + make 即可编译。可以通过 menuconfig 图像配置，或者加载defconfig 配置。
- 配置项统一使用功能宏控，避免出现产品宏。产品功能裁剪支持源码层面裁剪和编译层面裁剪。
- 美化编译打印输出，可以通过make V=1 选项控制编译打印输出。
- 美化编译成果输出，可以通过make O=dir 选项指定编译中间临时文件输出路。(主要是方便svn忽略)。
- 添加子功能时，链接库、编译新功能、功能裁剪时。Makefile修改简单(需要支持Kbuild Makefile语法)。。

## 规划

- 【完成100%】实现多个o文件链接为built-in.o。
- 【完成100%】实现递归各级子目录将所有的o全部编译链接，支持Kbuild Makefile语法。
- 【完成100%】实现编译输出打印美化，支持V=1动态控制。
- 【完成100%】实现编译成果物输出到单独的目录。
- 【完成100%】熟悉Kconconfig语法，菜单，功能项，依赖关系等。
- 【完成100%】实现编译工具源码得到 conf、mconf 等主机程序。
- 【完成100%】移植并使用mconf工具生成 .config 配置文件，支持make menuconfig配置。
- 【完成100%】实现 .config 文件自动创建 auto.conf 和 autoconf.h 配置文件。
- 【完成 50%】基于 auto.conf 和 autoconf.h 文件实现功能裁剪。
- 【未完成】优化依赖关系。
- 一步一步整合上述功能，实现一个类似于 Kernel 的编译框架。

## 目录结构说明

目前已经实现的 Kbuild 编译框架 demo 工程如下。

```
paul@maz:~/study/kbuild-study$ tree -Ld 2
.
├── ld-built-in			// 多个o文件链接为一个built-in.o文件
│   ├── 1					// 最简单的编译方式
│   └── 2					// 编译过程拆解 c->o; 多个o->built-in.o; built-in.o->app
├── make-f-param			// make -f 方式下参数传递形式
│   └── 1					// 环境变量和动态参数方式可传递
├── recursive-link		// 递归子目录进行编译, 实现 Kconfig Makefile 语法支持
│   ├── 1					// make -C && make -f 方式实现递归编译
│   ├── 2					// 删除 make -C 和 make -f 提示进入目录，离开目录的编译打印信息
│   ├── 3					// make -f scripts/Makefile.build obj=(dir) 方式实现递归编译(Kernel同款实现)
│   └── 4					// make clean 支持递归删除编译中间
├── 4.kconfig			// 编译层面进行功能裁剪
│   ├── 1					// 实现解析 Kconfig 文件生成 .config 配置文件
│   ├── 2					// 实现 make menuconfig 目标, 支持图形界面配置裁剪功能项
│   ├── 3					// 实现通过 .config 配置文件自动创建 auto.conf 和 autoconf.h 文件
│   └── 4					// 实现 Makefile 通过包含 auto.conf 配置文件, 基于 Kconfig Makefile 语法进行功能裁剪
└── 5.beautify-output	// 美化编译输出
    ├── 1					// 基于最简单的 Makefile, 手动美化输出, 未进行封装
    ├── 2					// 基于改进版的 Makefile, 手动美化输出, 未进行封装
    ├── 3					// 针对 make clean 输出美化功能进行封装, 支持 make clean V=1 显示未美化命令
    └── 4					// 针对 make 命令输出美化功能进行封装, 支持 make V=1

20 directories
paul@maz:~/study/kbuild-study$
```


