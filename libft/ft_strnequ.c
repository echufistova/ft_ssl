/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:39:41 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/06 20:26:31 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
	}
	return (1);
}