#include "ft_ssl.h"

void check_commands(t_ssl *ssl, char *line)
{
    if (!ft_strcmp(line, "sha256"))
    {
        ssl->sha256 = 1;
        ssl->md5 = 0;
    }
    else if (!ft_strcmp(line, "sha256"))
    {
        ssl->sha256 = 0;
        ssl->md5 = 1;
    }
    exit;
}

int		main(int ac, char **av)
{
    int		i;
    int fd;
    char	*line;
    t_ssl ssl;

    i = 0;
//    ft_printf("%s\n", av[0]);
    if (ac != 4 || (fd = open(av[1], O_RDONLY)) < 0)
    {
        ft_printf("usage: ft_ssl command [command opts] [command args]\n");
        return (0);
    }
    check_commands(&ssl, av[2]);
    while (get_next_line(fd, &line) > 0)
    {
        ft_printf("%s\n", line);
        ft_strdel(&line);
    }
    return (i);
}

