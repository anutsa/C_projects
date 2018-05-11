/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:37:40 by anutsa            #+#    #+#             */
/*   Updated: 2017/02/28 15:41:39 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include "libft.h"
# include <unistd.h>

typedef struct				s_fdlist
{
	char					*line;
	int						fd;
	struct s_fdlist			*next;
}							t_fdlist;
int							get_next_line(const int fd, char **line);
#endif
