/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:40:34 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/24 14:40:38 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf.h"

int		ft_set_walls(int x, int y)
{
	if (y == 0 || x == 0 || x == (MAP_W - 1) || y == (MAP_H - 1))
		return (1);
	if (y == 3 && x == 15)
		return (2);
	if (y == 12 && x == 6)
		return (2);
	if (y == 3 && x < 21 && x > 5)
		return (1);
	if (y == 6 && x < 18 && x > 8)
		return (1);
	if (y == 14 && x < 14 && x > 8)
		return (1);
	if (x == 3 && y > 8 && y < 16)
		return (1);
	if (x == 6 && y > 8 && y < 19)
		return (1);
	if (x == 9 && y > 12 && y < 15)
		return (1);
	if (x == 17 && y > 6 && y < 17)
		return (1);
	if (x == 20 && y > 16 && y < 21)
		return (1);
	return (0);
}

void	ft_generate_map(t_e *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < MAP_H)
	{
		x = -1;
		while (++x < MAP_W)
			e->map.map[y][x] = ft_set_walls(x, y);
	}
}

void	ft_help(void)
{
	write(1, "\n>♛<===========================================>♛<\n", 55);
	write(1, ">♛<=============  W E L C O M E  =============>♛<", 53);
	write(1, "\n>♛<===========================================>♛<\n", 55);
	write(1, "\n❇❇  In order to play, please use the           ❇❇", 58);
	write(1, "\n❇❇                       following keys:       ❇❇\n", 60);
	write(1, "❇❇                                             ❇❇\n", 58);
	write(1, "❇❇  - ESC to leave                             ❇❇\n", 58);
	write(1, "❇❇  - W, S, A, D to MOVE                       ❇❇\n", 58);
	write(1, "❇❇  - ◀, ▶, to turn camera                     ❇❇\n", 62);
	write(1, "❇❇  - E to open/close the doors                ❇❇\n", 58);
	write(1, "❇❇  - NUMPAD 5 to play the music               ❇❇\n", 58);
	write(1, "❇❇  - NUMPAD 6 to stop it                      ❇❇\n", 58);
	write(1, "❇❇                                             ❇❇\n", 58);
	write(1, "❇❇                                             ❇❇\n", 58);
	write(1, "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n", 149);
}

void	ft_play_music(void)
{
	system("killall afplay 2&>/dev/null >/dev/null");
	system("afplay assets/wlfsound.mp3&");
}

void	ft_stop_music(void)
{
	system("killall afplay 2&>/dev/null >/dev/null");
}
