/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:58:28 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/13 12:23:39 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	parse_pos(int l, int w, int x, int y);

//	rush(x, y)
//	char p contains character to print at position w, l
//	Iterate through each row (l) until y, then column (w) until x
//		inner loop:
//			finds correct character depending on w, l, x, y
//			puts character to stdout
//			increments w
//		outer loop
//			resets w to first column
//			puts newline character
//			increments l
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
		ft_putchar('\n');
		l++;
	}
}

//	parse_pos(l, w, x, y)
//	Isolate position and return char
//	Consider the row (l), then the column (w)
//	if
//		first or last row
//			first column -> A
//			last column -> C
//			intermediate column -> B
//
//		intermediate row
//			first or last column -> B
//			intermediate column -> (space)
//	(else's included to make compiler happy)
//	else
//		out or range or error -> X
char	parse_pos(int l, int w, int x, int y)
{
	if (l == 1 || l == y)
	{
		if (w == 1)
			return ('A');
		else if (w == x)
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
