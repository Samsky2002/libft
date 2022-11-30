/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 07:54:42 by oakerkao          #+#    #+#             */
/*   Updated: 2022/10/31 16:44:01 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!set || !s1)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len >= 0 && ft_strchr(set, s1[len]) && i < len)
		len--;
	return (ft_substr(s1, i, (len - i) + 1));
}
