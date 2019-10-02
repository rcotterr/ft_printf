/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:34:39 by drestles          #+#    #+#             */
/*   Updated: 2019/02/03 20:24:18 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_flags(t_prt *prt)
{
	prt->flag = malloc(sizeof(t_flag));
	prt->flag->sharp = 0;
	prt->flag->nul = 0;
	prt->flag->minus = 0;
	prt->flag->plus = 0;
	prt->flag->space = 0;
	prt->flag->h = 0;
	prt->flag->hh = 0;
	prt->flag->l = 0;
	prt->flag->ll = 0;
	prt->flag->width = 0;
	prt->flag->dot = 0;
	prt->flag->toch = 0;
	prt->flag->num = 0;
	prt->flag->point = 0;
	prt->flag->nn = 0;
	return (0);
}

int	def_types(t_prt *prt)
{
	if (prt->format[prt->i] == TYPE[0])
		handle_s(prt);
	if (prt->format[prt->i] == TYPE[1])
		handle_ls(prt);
	if (prt->format[prt->i] == TYPE[2])
		handle_p(prt);
	if (prt->format[prt->i] == TYPE[3] ||
	prt->format[prt->i] == TYPE[5])
		handle_d(prt);
	if (prt->format[prt->i] == TYPE[6])
		handle_o(prt);
	if (prt->format[prt->i] == TYPE[8])
		handle_u(prt);
	if (prt->format[prt->i] == TYPE[10])
		handle_x(prt);
	if (prt->format[prt->i] == TYPE[11])
		handle_b_x(prt);
	if (prt->format[prt->i] == TYPE[12])
		handle_c(prt);
	if (prt->format[prt->i] == TYPE[13])
		handle_lc(prt);
	if (prt->format[prt->i] == TYPE[14])
		handle_f(prt);
	return (0);
}

int	types(t_prt *prt)
{
	if (prt->format[prt->i] == TYPE[0] || prt->format[prt->i] == TYPE[1] ||
	prt->format[prt->i] == TYPE[2] || prt->format[prt->i] == TYPE[3] ||
	prt->format[prt->i] == TYPE[4] || prt->format[prt->i] == TYPE[5] ||
	prt->format[prt->i] == TYPE[6] || prt->format[prt->i] == TYPE[8] ||
	prt->format[prt->i] == TYPE[10] || prt->format[prt->i] == TYPE[11] ||
	prt->format[prt->i] == TYPE[12] || prt->format[prt->i] == TYPE[13] ||
	prt->format[prt->i] == TYPE[14])
	{
		def_types(prt);
		prt->i++;
	}
	return (0);
}

int	def_percentage(t_prt *prt)
{
	while (prt->format[prt->i] == ' ')
		prt->i++;
	if (prt->format[prt->i] == '%')
	{
		if (prt->flag->width && prt->flag->num-- > 0 && !prt->flag->minus)
		{
			while (prt->flag->num-- > 0)
				prt->buff[prt->j++] = ' ';
			prt->buff[prt->j++] = prt->format[prt->i++];
		}
		else
			prt->buff[prt->j++] = prt->format[prt->i++];
		while (prt->flag->num-- > 0)
			prt->buff[prt->j++] = ' ';
	}
	return (0);
}
