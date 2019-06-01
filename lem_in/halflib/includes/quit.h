#ifndef QUIT_H
# define QUIT_H

# include <unistd.h>

void				exit_free(char *msg, int format, ...);
void				exit_(char *msg);
size_t				return_free(char *msg, int format, ...);
size_t				return_(char *msg);

#endif
