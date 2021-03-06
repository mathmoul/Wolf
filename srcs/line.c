/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:06:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:51:40 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		line_to_pixel(t_mlx *mlx, t_l l, t_rgb rgb)
{
	put_color_to_pixel(mlx, l, rgb);
	if (l.dx > l.dy)
		line_1(mlx, l, rgb);
	else
		line_2(mlx, l, rgb);
}

void		ligne(t_e *e, t_rgb rgb)
{
	e->draw.l.x = e->draw.pts.x0;
	e->draw.l.y = e->draw.pts.y0;
	e->draw.l.dx = e->draw.pts.x1 - e->draw.pts.x0;
	e->draw.l.dy = e->draw.pts.y1 - e->draw.pts.y0;
	e->draw.l.xinc = (e->draw.l.dx > 0) ? 1 : -1;
	e->draw.l.yinc = (e->draw.l.dy > 0) ? 1 : -1;
	e->draw.l.dx = abs(e->draw.l.dx);
	e->draw.l.dy = abs(e->draw.l.dy);
	line_to_pixel(e->mlx, e->draw.l, rgb);
}
