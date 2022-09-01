/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:03:52 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/13 20:11:03 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	i;

	i = nb;
	res = nb;
	if (nb > 0 && nb < 13)
	{
		while (i > 1)
		{
			i--;
			res = res * i;
		}
		return (res);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
