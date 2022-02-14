/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:23:47 by nozakoya          #+#    #+#             */
/*   Updated: 2021/06/19 12:38:14 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(join))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
			join[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] != '\0')
			join[j++] = s2[i++];
	join[j] = '\0';
	free(s1);
	return (join);
}

int	get_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_before_str(char *buf)
{
	char	*ptr;
	int		i;

	i = 0;
	while (buf && buf[i] != '\0' && buf[i] != '\n')
		i++;
	ptr = malloc(i + 1);
	if (!(ptr))
		return (NULL);
	i = 0;
	while (buf && buf[i] != '\0' && buf[i] != '\n')
	{
		ptr[i] = buf[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*del(char *memory)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	if (!memory)
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\0')
	{
		free(memory);
		return (NULL);
	}
	temp = malloc(ft_strlen(memory) - i + 1);
	if (!(temp))
		return (NULL);
	i++;
	j = 0;
	while (memory[i] != '\0')
		temp[j++] = memory[i++];
	temp[j] = '\0';
	free(memory);
	return (temp);
}
