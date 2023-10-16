/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_twod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:12:46 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/16 11:15:06 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_list_to_twod(t_list *lst)
{
	int		len;
	int		i;
	char	**arr;

	i = 0;
	len = ft_lstsize(lst);
	arr = malloc((len + 1) * sizeof(char *));
	while (lst)
	{
		arr[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}
