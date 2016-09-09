/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:39:08 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/09 16:46:16 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
# define Q e->draw.d

void	mod_map2(t_line **line, int x, int cpt)
{
	t_line *l;
	l = *line;
	while (l)
	{
		if (l->x == x)
		{
			printf("cpt = %d\n", cpt);
			if (cpt == 0)
				l->wall *= -1;
			else
				l->wall *= -1;
		}
		l = l->next;
	}
}

void	mod_map(t_map **map, int x, int y, int cpt)
{
	printf("%d | %d\n", x, y);
	t_map *m;

	m = *map;
	while (m)
	{
		if (m->num_line == y)
			mod_map2(&m->line, x, cpt);
		m = m->next;
	}
}

void	open_door(t_e *e)
{
	printf("%d\n", mapping(&e->map, (int)(Q.pos.x + Q.dirx), \
						(int)(Q.pos.y + Q.diry)));
	if (((mapping(&e->map, (int)(Q.pos.x + Q.dirx), \
						(int)(Q.pos.y + Q.diry))) == 2))
		mod_map(&e->map, (int)(Q.pos.x + Q.dirx), (int)(Q.pos.y + Q.diry), 0);
	else if (((mapping(&e->map, (int)(Q.pos.x + Q.dirx), \
						(int)(Q.pos.y + Q.diry))) < 0))
		mod_map(&e->map, (int)(Q.pos.x + Q.dirx), (int)(Q.pos.y + Q.diry), 1);
	printf("%d\n", mapping(&e->map, (int)(Q.pos.x + Q.dirx), \
						(int)(Q.pos.y + Q.diry)));
	rd(e);
}
