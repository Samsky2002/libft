/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:03:30 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/16 11:04:38 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_list(int size, va_list args)
{
	t_list	*lst;
	int		i;
	char	*str;

	i = 0;
	lst = NULL;
	while (i < size)
	{
		str = va_arg(args, char *);
		ft_lstadd_back(&lst, ft_lstnew(str));
		i++;
	}
	return (lst);
}

static int	list_content_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (i);
}

static char	*put_arr(t_list *lst, int len)
{
	char	*result;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(len + 1);
	while (lst)
	{
		j = 0;
		str = lst->content;
		while (str[j])
		{
			result[i] = str[j];
			i++;
			j++;
		}
		lst = lst->next;
	}
	return (result);
}

char	*ft_var_strjoin(int size, ...)
{
	va_list	args;
	char	*result;
	t_list	*lst;
	int		len;

	lst = NULL;
	va_start(args, size);
	lst = get_list(size, args);
	len = list_content_size(lst);
	result = put_arr(lst, len);
	va_end(args);
	return (result);
}
