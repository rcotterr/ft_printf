/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:12:51 by rcotter-          #+#    #+#             */
/*   Updated: 2018/12/06 11:12:55 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1 != '\0' && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (*s1 == '\0' && *s1 == *s2)
		return (1);
	else if (i == n)
		return (1);
	else
		return (0);
}
