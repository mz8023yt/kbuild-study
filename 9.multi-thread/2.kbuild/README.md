# 编译得到 conf 工具

```
sudo apt-get install libncursesw5-dev
```

## 用法

```
$ make clean && time make
real	0m0.539s
user	0m0.409s
sys	0m0.092s

$ make clean && time make -j12
real	0m0.104s
user	0m0.638s
sys	0m0.126s
```

## 说明

1. 使用 time 可以查看命令执行耗时, 一定要先执行 make clean。
2. 只要 Makefile 中依赖是清晰明确的, 那么就可以通过 make -j 多线程编译。

## 依赖关系说明

```
### 目标依赖当前目录下的 built-in.o
$(TARGET): built-in.o

### 当前目录下的 built-in.o 由于无法明确的给出它的依赖文件, 因此标记为伪目标
### 并且, 当前目录下的 built-in.o 需要通过 scripts/Makefile.build 脚本生成
.PHONY:built-in.o
built-in.o: 
	$(Q)$(MAKE) $(mbuild)=.

### 分析 scripts/Makefile.build 脚本
### scripts/Makefile.build 脚本的默认目标 build 也是一个伪目标
### 并且 build 这个伪目标的目的就是生成 built-in.o
.PHONY: build
build: $(cur_objs) $(subdir_objs)
	$(LD) -r -o $(src)/built-in.o $^

### cur_objs 是当前目录下的 xxx.o
### 使用通用规则可以将 xxx.c 编译为 xxx.o
### 因此 cur_objs 生成规则是以下几行
$(src)/%.o : $(src)/%.c
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

### subdir_objs 是当前目录的子目录整合的 built-in.o
### 通过地柜调用 Makefile.build 脚本生成
### 注意: subdir_objs 由于无法明确的给出它的依赖, 因此标记为伪目标
.PHONY: $(subdir_objs)
$(subdir_objs):
	$(Q)$(MAKE) $(mbuild)=$(@:/built-in.o=)
```


