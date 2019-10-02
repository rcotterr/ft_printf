/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoal_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:26:00 by drestles          #+#    #+#             */
/*   Updated: 2019/02/03 20:24:17 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	ft_pow(size_t a, unsigned long int n)
{
	while (n--)
		a = a * 10;
	return (a);
}

char			*ft_itoal_u(unsigned long int n)
{
	size_t				j;
	size_t				i;
	unsigned long int	num;
	char				*s;

	i = 0;
	j = 0;
	num = n;
	while ((num = num / 10))
		i++;
	if (!(s = (char *)(malloc(sizeof(char) * (i + 2)))))
		return (NULL);
	i++;
	if (n == -2147483648 && (s[j++] = '2') && (i--))
		n = 147483648;
	while (--i && (s[j++] = (n / ft_pow(10, i - 1)) + '0'))
		n = n % ft_pow(10, i - 1);
	s[j] = n + '0';
	s[j + 1] = '\0';
	return (s);
}
