# 目录结构说明

```
paul@maz:~/study/kbuild-study/7.host-prog$ tree -Ld 1
.
├── 1.conf
├── 2.conf.optimize
├── 3.mconf
└── 4.conf_and_mconf

4 directories
paul@maz:~/study/kbuild-study/7.host-prog$
```

说明：

- 1.conf，编译得到 conf 工具。
- 2.conf.optimize，解决编译警告。
- 3.mconf，编译得到 mconf 工具。
- 4.conf_and_mconf，整合 conf 工具和 mconf 工具到一个工程中。