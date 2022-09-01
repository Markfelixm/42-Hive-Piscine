/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:08:39 by ptaimi            #+#    #+#             */
/*   Updated: 2022/08/14 16:51:42 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	parse_pos(int l, int w, int x, int y);

void	rush(int x, int y)
{
	char	p;
	int		w;
	int		l;

	w = 1;
	l = 1;
	while (l <= y)
	{
		while (w <= x)
		{
			p = parse_pos(l, w, x, y);
			ft_putchar(p);
			w++;
		}
		w = 1;
		if (!(x < 1 || y < 1))
			ft_putchar('\n');
		l++;
	}
}

char	parse_pos(int l, int w, int x, int y)
{
	if (l == 1)
	{
		if (w == 1 || w == x)
			return ('A');
		else
			return ('B');
	}
	if (l == y)
	{
		if (w == 1 || w == x)
			return ('C');
		else
			return ('B');
	}
	else if (l > 1 && l < y)
	{
		if (w == 1 || w == x)
			return ('B');
		else if (w > 1)
			return (' ');
		else
			return ('X');
	}
	else
		return ('X');
}
