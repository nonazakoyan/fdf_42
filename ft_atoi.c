/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:00:16 by nozakoya          #+#    #+#             */
/*   Updated: 2022/02/20 14:46:03 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_res(char *str, int i, int j)
{
	int		l;
	int		sign;
	int		num;

	sign = 1;
	l = 1;
	num = 0;
	while (str[j])
	{
		if (str[j] == '-')
			sign *= -1;
		--j;
	}
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num += (((unsigned int)str[i]) - 48) * l;
			l *= 10;
		}
		--i;
	}
	return (num * sign);
}

int	ft_atoi(char *s)
{
	int		i;
	int		res;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r' || ((str[i] >= '0' && str[i] <= '9')
					&& (str[i + 1] >= '0' && str[i + 1] <= '9'))))
			break ;
		else if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '\t'
				|| str[i + 1] == '\n' || str[i + 1] == '\v'
				|| str[i + 1] == '\f' || str[i + 1] == '\r'
				|| str[i + 1] == ' ' || str[i + 1] == '+'
				|| str[i + 1] == '-'))
			break ;
		else
			++i;
	}
	res = ft_res(str, i, i - 1);
	return (res);
}
