/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:24:19 by ychufist          #+#    #+#             */
/*   Updated: 2019/03/06 19:25:37 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"


int		main(int ac, char **av)
{
    int		i;
    int a;
    char	*line;

    i = 0;
    a = 0;
    while (get_next_line(0, &line) > 0)
    {
        ft_printf("%s\n", line);
        ft_strdel(&line);
    }
    return (i);
}

