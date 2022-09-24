# minilibx_opengl_custom

> minilibx (opengl ver.)을 사용하는 42프로젝트를 위한 커스텀 함수들입니다..
> 
> 이  프로젝트는 "mlx_get_screen_size" 같은 커스텀 함수를 minilibx에 추가 해줍니다.

"minilibx_opengl_20191021"에서 테스트 됨.

`make all`을 하면 Makefile이 커스텀 함수를 컴파일 해주고,  "libmlx.a"에 오프젝트 파일들을 추가해줍니다.



다음 명령어로 작동을 확인 해 볼 수 있습니다.
```
$ make test
```

다음 라인을 당신의 프로젝트 소스 헤더에 추가하세요.

```
int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
```

또는

```
#include "mlx_custom.h"
```

아카이브 안의 오브젝트파일을 보려면
다음을 실행 하십시오
```
$ ar t libmlx.a
```

*.m 파일들은 objective c 파일들 입니다.

[클러스터에서 맥 해상도 바꾸기](https://support.apple.com/ko-kr/guide/mac-help/mchl86d72b76/10.15/mac/10.15)

References
- [AR command](https://www.thegeekstuff.com/2010/08/ar-command-examples/)

- [How to get screen size on MacOS](https://stackoverflow.com/a/16634349/9276699)
