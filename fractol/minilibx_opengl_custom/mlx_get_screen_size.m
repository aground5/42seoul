#import <AppKit/NSOpenGLView.h>
#import "mlx_custom.h"

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	NSRect e = [[NSScreen mainScreen] frame];
	*sizex = (int)e.size.width;
	*sizey = (int)e.size.height;
	return (0);
}

/*
** NSRect = [(id)(mlx_win->winid) frame];
*/
