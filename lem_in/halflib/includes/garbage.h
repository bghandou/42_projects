#ifndef GARBAGE_H
# define GARBAGE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_malloc
{
	struct s_malloc	*next;
	void			*elem;
}				t_malloc;

void			*malloc_garbage(size_t size);

#endif
