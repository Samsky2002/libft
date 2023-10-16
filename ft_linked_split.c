/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:02:46 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/16 11:05:51 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

static char	*join_char(char	*str, char c)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	i = 0;
	if (str)
		len = ft_strlen(str);
	result = malloc(len + 2);
	while (str && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = '\0';
	if (str)
		free(str);
	return (result);
}

t_list	*ft_linked_split(char *str, char c)
{
	int		i;
	int		quotes;
	char	*result;
	t_list	*lst;

	i = 0;
	quotes = 0;
	result = NULL;
	lst = NULL;
	while (str && str[i])
	{
		if (is_quote(str[i]) && quotes == 0)
			quotes = str[i];
		else if (str[i] == quotes && quotes)
			quotes = 0;
		else if (quotes || (str[i] != c && quotes == 0))
			result = join_char(result, str[i]);
		if ((str[i] == c && quotes == 0 && result) || str[i + 1] == '\0')
		{
			ft_lstadd_back(&lst, ft_lstnew(result));
			result = NULL;
		}
		i++;
	}
	return (lst);
}
