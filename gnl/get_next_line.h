#ifndef _GET_NEXT_LINE_
# define _GET_NEXT_LINE_
# define BUFFER_SIZE 42 // TODO: DELETE

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_one_buffer(int fd);

#endif
