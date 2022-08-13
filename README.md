
# 从零开始构建 Kbuild 编译框架

## 目标

- 使用简单，make config + make 即可编译。可以通过 menuconfig 图像配置，或者加载defconfig 配置。
- 配置项统一使用功能宏控，避免出现产品宏。产品功能裁剪支持源码层面裁剪和编译层面裁剪。
- 美化编译打印输出，可以通过make V=1 选项控制编译打印输出。
- 美化编译成果输出，可以通过make O=dir 选项指定编译中间临时文件输出路。(主要是方便svn忽略)。
- 添加子功能时，链接库、编译新功能、功能裁剪时。Makefile修改简单(需要支持Kbuild Makefile语法)。

## 规划

- 【完成100%】实现多个o文件链接为built-in.o。
- 【完成100%】实现递归各级子目录将所有的o全部编译链接，支持Kbuild Makefile语法。
- 【完成100%】实现编译输出打印美化，支持V=1动态控制。
- 【完成100%】实现编译成果物输出到单独的目录。
- 【完成100%】熟悉Kconconfig语法，菜单，功能项，依赖关系等。
- 【完成100%】移植并使用mconf工具生成 .config 配置文件，支持make menuconfig配置。
- 【完成100%】实现 .config 文件自动创建 auto.conf 和 autoconf.h 配置文件。
- 【完成100%】基于 auto.conf 和 autoconf.h 文件实现功能裁剪。
- 【完成100%】实现编译工具源码得到 conf、mconf 等主机程序。
- 【完成100%】优化依赖关系。
- 【完成100%】支持库链接。
- 【未完成】支持某一个目录下子模块封装接口给其他模块使用。（产生依赖关系，并且需要导出符号）
- 【完成100%】一步一步整合上述功能，实现一个类似于 Kernel 的编译框架。
- 【未完成】编译控制验收后，运行态控制实现。（kernel 实现机制是 dts 方式）

## 目录结构说明

目前已经实现的 Kbuild 编译框架 demo 工程如下。

```
paul@maz:~/study/kbuild-study$ tree -Ld 1
.
├── 1.ld-built-in               // 多个o文件链接为一个built-in.o文件
├── 2.make-f-param              // 调用其他 Makefile 时传参方式验证
├── 3.recursive-link            // 递归子目录进行编译, 实现 Kconfig Makefile 语法支持
├── 4.output-separate           // 中间产物和成果物输出到指定路径
├── 5.beautify-output           // 美化编译输出
├── 6.host-prog                 // 主机程序源码，编译得到 conf 和 mconf 主机程序
└── 7.kconfig                   // 编译层面进行功能裁剪，实现 Kconfig 语法解析，menuconfig 支持
```

一级目录说明如上，其下的二级目录都附有对应的目录结构说明。请进入子目录查阅。


