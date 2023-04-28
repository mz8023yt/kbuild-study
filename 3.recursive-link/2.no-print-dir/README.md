# 子目录递归编译

基于 `/kbuild-study/3.recursive-link/1.subdir` 工程基础上，make 时增加 `--no-print-directory` 选项，不显示目录信息。

## 用法

```
$ make
gcc -Wall -O2 -g -Wp,-MD,.keypad.o.d -c -o keypad.o keypad.c
gcc -Wall -O2 -g -Wp,-MD,.touchpad.o.d -c -o touchpad.o touchpad.c
ld -r -o built-in.o keypad.o touchpad.o
gcc -Wall -O2 -g -Wp,-MD,.st7735.o.d -c -o st7735.o st7735.c
gcc -Wall -O2 -g -Wp,-MD,.st7789.o.d -c -o st7789.o st7789.c
ld -r -o built-in.o st7735.o st7789.o
gcc -Wall -O2 -g -Wp,-MD,.sensor.o.d -c -o sensor.o sensor.c
ld -r -o built-in.o sensor.o input/built-in.o lcd/built-in.o
gcc -Wall -O2 -g -Wp,-MD,.cmd.o.d -c -o cmd.o cmd.c
gcc -Wall -O2 -g -Wp,-MD,.list.o.d -c -o list.o list.c
ld -r -o built-in.o cmd.o list.o
gcc -Wall -O2 -g -Wp,-MD,.main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o drivers/built-in.o modules/built-in.o
gcc  -o app built-in.o
```

这是没有添加 `--no-print-directory` 选项的打印输出。

```
$ make
make[1]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir'
make[2]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/drivers'
make[3]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/drivers/input'
gcc -Wall -O2 -g -Wp,-MD,.keypad.o.d -c -o keypad.o keypad.c
gcc -Wall -O2 -g -Wp,-MD,.touchpad.o.d -c -o touchpad.o touchpad.c
ld -r -o built-in.o keypad.o touchpad.o
make[3]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/drivers/input'
make[3]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/drivers/lcd'
gcc -Wall -O2 -g -Wp,-MD,.st7735.o.d -c -o st7735.o st7735.c
gcc -Wall -O2 -g -Wp,-MD,.st7789.o.d -c -o st7789.o st7789.c
ld -r -o built-in.o st7735.o st7789.o
make[3]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/drivers/lcd'
gcc -Wall -O2 -g -Wp,-MD,.sensor.o.d -c -o sensor.o sensor.c
ld -r -o built-in.o sensor.o input/built-in.o lcd/built-in.o
make[2]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/drivers'
make[2]: Entering directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/modules'
gcc -Wall -O2 -g -Wp,-MD,.cmd.o.d -c -o cmd.o cmd.c
gcc -Wall -O2 -g -Wp,-MD,.list.o.d -c -o list.o list.c
ld -r -o built-in.o cmd.o list.o
make[2]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir/modules'
gcc -Wall -O2 -g -Wp,-MD,.main.o.d -c -o main.o main.c
ld -r -o built-in.o main.o drivers/built-in.o modules/built-in.o
make[1]: Leaving directory '/home/paul/work/kbuild-system/3.recursive-link/2.no-print-dir'
gcc  -o app built-in.o
```
