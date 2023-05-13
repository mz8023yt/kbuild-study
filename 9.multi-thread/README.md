# 如何实现多线程编译

在实际编译过程中，经常会使用到 make -j12 启用多线程编译加快编译速度，本小节研究如何让 kbuild 支持多线程。

其实多线程编译不需要额外的配置，只要 Makefile 中依赖是清晰明确的，那么就可以通过 make -j 多线程编译。

## 如何统计编译耗时

使用 time 可以查看命令执行耗时, 在要执行的命令前增加 time 命令即可。
正常查看当前目录的文件是 ls 命令，使用 time ls 则可以在 ls 命令执行结束后打印 ls 执行的耗时。

通过 `make clean && time make` 和 `make clean && time make -j12` 执行耗时的对比，则可以确认到是否有真正的实现多线程编译。

## Ubuntu 查看 CPU 核心数和线程数

以我使用的 AMD Ryzen™ 5 5600 处理器为例，规格为6核心12线程。

使用下面的命令可以查询：

```
$ cat /proc/cpuinfo | grep -e "cpu cores" -e "siblings" | sort | uniq
cpu cores	: 6
siblings	: 12
```

可以查询到 AMD Ryzen™ 5 5600 处理器有12个线程，也就是12个逻辑CPU。因此我一般使用 make -j12 进行多线程编译。