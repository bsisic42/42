/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:17:54 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:18:03 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*tmp;

	if (!s || !f)
		return (NULL);
	tmp = (char *)s;
	i = 0;
	while (tmp[i])
		++i;
	if ((str = (char *)malloc(i)) == NULL)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		str[i] = f(i, tmp[i]);
		++i;
	}
	return (str);
}
