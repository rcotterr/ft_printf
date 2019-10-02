/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:24:58 by rcotter-          #+#    #+#             */
/*   Updated: 2019/02/08 21:54:43 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_s_flags(t_prt *prt, char *s, size_t len)
{
	prt->flag->num -= (prt->flag->toch > len) ? len : prt->flag->toch;
	if (prt->flag->minus)
	{
		while (*s && prt->flag->toch--)
			(prt->buff[prt->j++]) = *s++;
		while (prt->flag->num--)
			prt->buff[prt->j++] = ' ';
	}
	else
	{
		while (prt->flag->num--)
			prt->buff[prt->j++] = ' ';
		while (*s && prt->flag->toch--)
			(prt->buff[prt->j++]) = *s++;
	}
	return (0);
}

int	handle_s(t_prt *prt)
{
	char	*s;
	size_t	len;

	if (prt->flag->l && !prt->flag->h)
		handle_ls(prt);
	else
	{
		s = va_arg(*(prt->ap), char *);
		if (s == 0)
			s = "(null)";
		len = ft_strlen(s);
		if (!prt->flag->dot)
			prt->flag->toch = (prt->flag->num < len) ? len : prt->flag->num;
		if (prt->flag->width && (prt->flag->num > len
		|| prt->flag->num > prt->flag->toch))
			handle_s_flags(prt, s, len);
		else
			while (*s && prt->flag->toch--)
				(prt->buff[prt->j++]) = *s++;
	}
	return (0);
}

int	handle_zero(t_prt *prt)
{
	ft_putstr(prt->buff);
	prt->count_zero += ft_strlen(prt->buff);
	ft_bzero(prt->buff, BUFF_SIZE);
	write(1, "\0", 1);
	prt->count_zero++;
	prt->j = 0;
	return (0);
}

int	handle_c(t_prt *prt)
{
	char c;

	if (prt->flag->l && !prt->flag->h)
		handle_lc(prt);
	else
	{
		c = va_arg(*(prt->ap), int);
		if (prt->flag->width)
			handle_c_flags(prt, &c);
		else
		{
			if (c)
				prt->buff[prt->j] = c;
			else
				handle_zero(prt);
		}
		if (c)
			prt->j++;
	}
	return (0);
}

int	handle_c_flags(t_prt *prt, char *c)
{
	if (prt->flag->minus)
	{
		if (*c)
			prt->buff[prt->j] = *c;
		else
			handle_zero(prt);
		while (--prt->flag->num)
			prt->buff[++prt->j] = ' ';
	}
	else
	{
		while (--prt->flag->num)
			prt->buff[prt->j++] = ' ';
		if (*c)
			prt->buff[prt->j] = *c;
		else
			handle_zero(prt);
	}
	return (0);
}
