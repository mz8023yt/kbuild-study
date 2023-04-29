# 编译得到 conf 工具

```
sudo apt-get install libncursesw5-dev
```

## 用法

```
$ make clean && time make
real	0m0.479s
user	0m0.422s
sys	0m0.055s

$ make clean && time make -j8
real	0m0.104s
user	0m0.489s
sys	0m0.129s
```

## 说明

1. 使用 time 可以查看命令执行耗时, 一定要先执行 make clean。
2. 只要 Makefile 中依赖是清晰明确的，那么就可以通过 make -j 多线程编译。
