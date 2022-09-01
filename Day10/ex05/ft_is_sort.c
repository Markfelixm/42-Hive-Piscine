/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:05:51 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/23 18:10:45 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 0;
	if (length <= 2)
		return (1);
	while (i < length)
	{
		i++;
		if (tab[i - 1] != tab[i])
		{
			order = f(tab[i - 1], tab[i]);
			i++;
			break ;
		}
	}
	if (order == 0)
		return (1);
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) != order)
			if (f(tab[i - 1], tab[i]) != 0)
				return (0);
		i++;
	}
	return (1);
}
