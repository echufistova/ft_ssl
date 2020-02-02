#include "ft_ssl.h"

void errors(int i, t_ssl ssl, char *line)
{
    if (i == 0)
        ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n"
                  "Standard commands:\n\nMessage Digest commands:\n"
                  "md5\nsha256\n\nCipher commands:", ssl.md5, ssl.sha256, line);
    else if (i == 1)
        ft_printf("we have problems with flags\n");
    exit(0);
}

void init(t_ssl *ssl)
{
    ssl->sha256 = 0;
    ssl->md5 = 0;
    ssl->flag_p = 0;
    ssl->flag_q = 0;
    ssl->flag_r = 0;
    ssl->flag_s = 0;
}

void check_commands(t_ssl *ssl, char *line)
{
    if (!ft_strcmp(line, "sha256"))
        ssl->sha256 = 1;
    else if (ft_strcmp(line, "sha256") && !ft_strcmp(line, "md5"))
        ssl->md5 = 1;
    else if (ssl->sha256 == 0 && ssl->md5 == 0)
        errors(0, *ssl, line);
}

void check_flags(int ac, char **av, t_ssl *ssl)
{
    int i = 2;

    while (i < ac)
    {
        ft_printf("arg%d %s\n", i, av[i]);
        if (ft_strlen(av[i]) == 2 && av[i][0] == '-')
        {
            if (av[i][1] == 'p')
                ssl->flag_p = 1;
            else if (av[i][1] == 'q')
                ssl->flag_q = 1;
            else if (av[i][1] == 'r')
                ssl->flag_r = 1;
            else if (av[i][1] == 's')
                ssl->flag_s = 1;
            else
                errors(1, *ssl, NULL);
        }
        i++;
    }
}

void check_ssl(t_ssl ssl)
{
    ft_printf("ssl->sha256: %d", ssl.sha256);
    ft_printf("ssl->sha256: %d", ssl.md5);
    ft_printf("ssl->flag_p: %d", ssl.flag_p);
    ft_printf("ssl->flag_q: %d", ssl.flag_q);
    ft_printf("ssl->flag_r: %d", ssl.flag_r);
    ft_printf("ssl->flag_s: %d", ssl.flag_s);
}

int		main(int ac, char **av)
{
    int		i;
    int fd;
    char	*line;
    t_ssl ssl;

    i = 0;
    ft_printf("%s\n", av[1]);
    init(&ssl);
    if (ac < 2)// || (fd = open(av[1], O_RDONLY)) < 0)
    {
        ft_printf("ac: %d\n", ac);
        ft_printf("1 usage: ft_ssl command [command opts] [command args]\n");
        return (0);
    }
    check_commands(&ssl, av[1]);
    check_flags(ac, av, &ssl);
    check_ssl(ssl);
//    while (get_next_line(0, &line) > 0)
//    {
//        ft_printf("%s\n", line);
//        ft_strdel(&line);
//    }
    return (i);
}

