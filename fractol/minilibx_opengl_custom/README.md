# minilibx_opengl_custom  
[한국어](./README_KO.md)

> A custom functions for 42 projects that use minilibx (opengl ver.)
> 
> This project add custom function like "mlx_get_screen_size" to minilibx.

Tested on "minilibx_opengl_20191021"

You can test whether it works by
```
$ make test
```

When you `make all`,
Makefile compiles custom functions,
and add object files to "libmlx.a"

Add following line to your project source header.

```
int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
```
OR

```
#include "mlx_custom.h"
```

You can view object files in archive
by using

```
$ ar t libmlx.a
```

*.m files are objective c files.

[How to change Mac resolution on cluster](https://support.apple.com/guide/mac-help/change-your-displays-resolution-mchl86d72b76/10.15/mac/10.15)

References
- [AR commands](https://www.thegeekstuff.com/2010/08/ar-command-examples/)

- [How to get screen size on MacOS](https://stackoverflow.com/a/16634349/9276699)
