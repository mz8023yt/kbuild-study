# gcc -include 选项包含配置头文件

编写C和C++程序时，需要在代码中使用#include来引用头文件。除了这个方法外，gcc支持参数-include，可以在编译时直接向目标代码中添加头文件，而不需要在代码中加入include语句。

通过这个方式可以在不修改代码的情况下增加或改变头文件引用，在大量文件都要引用相同的公共头文件时减少代码量。

这里主要用在编译裁剪功能上，conf 工具解析 .config 文件会生成 auto.conf 文件和 autoconf.h 文件。
auto.conf 文件用于 Makefile 中编译裁剪，autoconf.h 定义了一系列的宏控用于代码中条件编译。

因此要使用条件编译功能，则必须要包含 autoconf.h 头文件，一旦漏包含了就会导致条件编译不生效，并且这个问题非常的隐蔽，不好发现和排查。最好是能在编译每个文件的时候，自动包含 autoconf.h 文件。

```
CFLAGS+= -include include/linux/autoconf.h
```

