/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_rush_parse_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:31:14 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/28 20:53:13 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	rush00_parse_pos(t_pos *pos)
{
	if (pos->l == 1 || pos->l == pos->y)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('o');
		else
			return ('-');
	}
	else if (pos->l > 1 && pos->l < pos->y)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('|');
		else if (pos->w > 1)
			return (' ');
		else
			return ('X');
	}
	else
		return ('X');
}

char	rush01_parse_pos(t_pos *pos)
{
	if (pos->l == 1 || pos->l == pos->y)
	{
		if (pos->w == 1 && pos->l == 1)
			return ('/');
		else if (pos->w == pos->x && pos->l == 1)
			return ('\\');
		else if (pos->w == 1 && pos->l == pos->y)
			return ('\\');
		else if (pos->w == pos->x && pos->l == pos->y)
			return ('/');
		else
			return ('*');
	}
	else if (pos->l > 1 && pos->l < pos->y)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('*');
		else if (pos->w > 1)
			return (' ');
		else
			return ('X');
	}
	else
		return ('X');
}

char	rush02_parse_pos(t_pos *pos)
{
	if (pos->l == 1)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('A');
		else
			return ('B');
	}
	if (pos->l == pos->y)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('C');
		else
			return ('B');
	}
	else if (pos->l > 1 && pos->l < pos->y)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('B');
		else if (pos->w > 1)
			return (' ');
		else
			return ('X');
	}
	else
		return ('X');
}

char	rush03_parse_pos(t_pos *pos)
{
	if (pos->l == 1 || pos->l == pos->y)
	{
		if (pos->w == 1)
			return ('A');
		else if (pos->w == pos->x)
			return ('C');
		else
			return ('B');
	}
	else if (pos->l > 1 && pos->l < pos->y)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('B');
		else if (pos->w > 1)
			return (' ');
		else
			return ('X');
	}
	else
		return ('X');
}

char	rush04_parse_pos(t_pos *pos)
{
	if (pos->l == 1 || pos->l == pos->y)
	{
		if (pos->w == 1 && pos->l == 1)
			return ('A');
		else if (pos->w == pos->x && pos->l == 1)
			return ('C');
		else if (pos->w == 1 && pos->l == pos->y)
			return ('C');
		else if (pos->w == pos->x && pos->l == pos->y)
			return ('A');
		else
			return ('B');
	}
	else if (pos->l > 1 && pos->l < pos->y)
	{
		if (pos->w == 1 || pos->w == pos->x)
			return ('B');
		else if (pos->w > 1)
			return (' ');
		else
			return ('X');
	}
	else
		return ('X');
}
