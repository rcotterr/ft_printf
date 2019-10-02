/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:54:43 by drestles          #+#    #+#             */
/*   Updated: 2019/02/03 20:25:06 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	pow_10(int n)
{
	long double	p;

	p = 1;
	while (n > 0)
	{
		p *= 10;
		n--;
	}
	return (p);
}

long int	abs_l(long int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int			handle_p(t_prt *prt)
{
	prt->flag->sharp = 1;
	prt->flag->l = 1;
	prt->flag->point = 1;
	handle_x(prt);
	return (0);
}
