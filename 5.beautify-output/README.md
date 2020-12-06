# 目录结构说明

```
paul@maz:~/study/kbuild-study/5.beautify-output$ tree -Ld 1
.
├── 1.manual
├── 2.c2o
├── 3.clean-dyn-ctrl
└── 4.build-dyn-ctrl

4 directories
```

说明：

- 1.manual，手动美化。
- 2.c2o，简单改进，将c2o过程单独拎出来处理。
- 3.clean-dyn-ctrl， make clean 支持 V 变量控制打印输出的格式。
- 4.build-dyn-ctrl，make 和 make clean 都支持 V 变量控制打印输出的格式。