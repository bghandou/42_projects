#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;

	if (*alst == NULL)
		return ;
	else
	{
		temp = *alst;
		while (temp)
		{
			del(temp->content, temp->content_size);
			free(temp);
			temp = temp->next;
		}
		*alst = NULL;
	}
}
