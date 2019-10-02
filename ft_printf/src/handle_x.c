/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 10:41:50 by drestles          #+#    #+#             */
/*   Updated: 2019/02/03 20:25:03 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_nuls_for_numbers(t_prt *prt, char *digits, int sp, int d)
{
	if (d >= 0 && prt->flag->sharp == 0)
		while (sp > 0)
		{
			digits = ft_strjoin_right("0", digits);
			sp--;
		}
	if (prt->flag->sharp == 1)
	{
		digits = ft_strdup(&digits[2]);
		while (sp > 0)
		{
			digits = ft_strjoin_right("0", digits);
			sp--;
		}
		digits = ft_strjoin_right("0x", digits);
	}
	return (digits);
}

static char	*add_for_numbers(t_prt *prt, char *digits, unsigned int d)
{
	int sp;

	sp = prt->flag->num - ft_strlen(digits);
	if (prt->flag->minus == 1)
		while (sp > 0)
		{
			digits = ft_strjoin_left(digits, " ");
			sp--;
		}
	else if (prt->flag->nul == 1 && prt->flag->dot == 0)
		digits = add_nuls_for_numbers(prt, digits, sp, d);
	else
		while (sp > 0)
		{
			digits = ft_strjoin_right(" ", digits);
			sp--;
		}
	return (digits);
}

static char	*translate_x(char *digits, unsigned long int ld)
{
	digits = ft_strnew(0);
	if (ld == 0)
		digits = ft_strjoin_right("0", digits);
	while (ld > 0)
	{
		if (ld % 16 > 9)
		{
			if (ld % 16 == 10)
				digits = ft_strjoin_right("a", digits);
			if (ld % 16 == 11)
				digits = ft_strjoin_right("b", digits);
			if (ld % 16 == 12)
				digits = ft_strjoin_right("c", digits);
			if (ld % 16 == 13)
				digits = ft_strjoin_right("d", digits);
			if (ld % 16 == 14)
				digits = ft_strjoin_right("e", digits);
			if (ld % 16 == 15)
				digits = ft_strjoin_right("f", digits);
		}
		else
			digits = ft_strjoin_all(ft_itoa(ld % 16), digits);
		ld /= 16;
	}
	return (digits);
}

static char	*precision(t_prt *prt, char *digits, unsigned long int ld_a)
{
	if (!(prt->flag->toch == 0 && prt->flag->dot == 1 && ld_a == 0))
		digits = translate_x(digits, ld_a);
	else
		digits = ft_strnew(0);
	while (ft_strlen(digits) < prt->flag->toch)
		digits = ft_strjoin_right("0", digits);
	return (digits);
}

int			handle_x(t_prt *prt)
{
	unsigned long int	ld;
	char				*digits;
	char				*free_digits;

	ld = assignment_u(prt);
	digits = precision(prt, digits, ld);
	if ((prt->flag->sharp == 1 && ld != 0) || prt->flag->point == 1)
		digits = ft_strjoin_right("0x", digits);
	if (prt->flag->num > ft_strlen(digits))
		digits = add_for_numbers(prt, digits, (unsigned int)ld);
	free_digits = digits;
	while (*digits)
	{
		(prt->buff[prt->j]) = *digits;
		prt->j++;
		digits++;
	}
	free(free_digits);
	return (0);
}
