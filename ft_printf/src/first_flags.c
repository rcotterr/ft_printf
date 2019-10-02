/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:45:49 by drestles          #+#    #+#             */
/*   Updated: 2019/02/03 20:24:19 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	third_flags_two(t_prt *prt)
{
	if (prt->format[prt->i] == 'L')
		prt->flag->ll = 1;
	prt->i++;
	return (0);
}

int	third_flags_one(t_prt *prt)
{
	if (prt->format[prt->i] == 'h')
	{
		if (prt->format[prt->i + 1] == 'h')
		{
			prt->flag->hh = 1;
			prt->i++;
		}
		else
			prt->flag->h = 1;
	}
	if (prt->format[prt->i] == 'l')
	{
		if (prt->format[prt->i + 1] == 'l')
		{
			prt->flag->ll = 1;
			prt->i++;
		}
		else
			prt->flag->l = 1;
	}
	prt->i++;
	return (0);
}

int	third_flags(t_prt *prt)
{
	if (prt->format[prt->i] == 'h' || prt->format[prt->i] == 'l')
		third_flags_one(prt);
	if (prt->format[prt->i] == 'L')
		third_flags_two(prt);
	return (0);
}

int	second_flags(t_prt *prt)
{
	if (prt->format[prt->i] >= 48 && prt->format[prt->i] <= 57)
	{
		prt->flag->width = 1;
		prt->flag->num = ft_atoi(&(prt->format[prt->i]));
		while (prt->format[prt->i] >= 48 && prt->format[prt->i] <= 57
			&& prt->format[prt->i])
			prt->i++;
	}
	if (prt->format[prt->i] == '.')
	{
		prt->flag->dot = 1;
		prt->i++;
	}
	if (prt->format[prt->i] >= 48 && prt->format[prt->i] <= 57)
	{
		prt->flag->toch = ft_atoi(&(prt->format[prt->i]));
		while (prt->format[prt->i] >= 48 && prt->format[prt->i] <= 57
			&& prt->format[prt->i])
			prt->i++;
	}
	return (0);
}

int	first_flags(t_prt *prt)
{
	init_flags(prt);
	while (prt->format[prt->i] == '#' || prt->format[prt->i] == '0'
	|| prt->format[prt->i] == '-' || prt->format[prt->i] == '+'
	|| prt->format[prt->i] == ' ')
	{
		if (prt->format[prt->i] == '#')
			prt->flag->sharp = 1;
		if (prt->format[prt->i] == '0')
			prt->flag->nul = 1;
		if (prt->format[prt->i] == '-')
			prt->flag->minus = 1;
		if (prt->format[prt->i] == '+')
			prt->flag->plus = 1;
		if (prt->format[prt->i] == ' ')
			prt->flag->space = 1;
		prt->i++;
	}
	return (0);
}
