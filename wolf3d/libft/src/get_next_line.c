/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:49:21 by anutsa            #+#    #+#             */
/*   Updated: 2017/02/13 12:47:33 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void		ft_listadd(t_fdlist **lst, int fd)
{
	t_fdlist	*tmp;

	tmp = (t_fdlist *)malloc(sizeof(t_fdlist));
	tmp->fd = fd;
	tmp->line = ft_strnew(0);
	tmp->next = *lst;
	*lst = tmp;
}

t_fdlist	*ft_findfd(t_fdlist **lst, int fd)
{
	t_fdlist	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	ft_listadd(lst, fd);
	tmp = *lst;
	return (tmp);
}

void		ft_write(t_fdlist *lst, char **line)
{
	char	*tmp;

	tmp = 0;
	*line = ft_strsub(lst->line, 0, (ft_strchr(lst->line, '\n') - lst->line));
	tmp = ft_strsub(lst->line,
		((ft_strchr(lst->line, '\n') - lst->line) + 1),
		ft_strlen(lst->line) - (ft_strchr(lst->line, '\n') - lst->line) - 1);
	free(lst->line);
	lst->line = ft_strdup(tmp);
	free(tmp);
}

int			ft_read(int fd, t_fdlist *lst, char **line, char *str)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		str[ret] = '\0';
		tmp = lst->line;
		lst->line = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		if (ft_strchr(lst->line, '\n'))
			break ;
	}
	if (!ret && (!(lst->line) || !(lst->line[0])))
		return (0);
	else if (ft_strchr(lst->line, '\n'))
	{
		ft_write(lst, line);
		return (1);
	}
	*line = ft_strdup(lst->line);
	ft_strdel(&(lst->line));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			*str;
	int				res;
	static t_fdlist	*lst = NULL;

	if (read(fd, 0, 0) || BUFF_SIZE < 1 || !line)
		return (-1);
	if (lst == NULL)
		ft_listadd(&lst, fd);
	str = ft_strnew(BUFF_SIZE);
	res = (ft_read(fd, ft_findfd(&lst, fd), line, str));
	ft_strdel(&str);
	return (res);
}
