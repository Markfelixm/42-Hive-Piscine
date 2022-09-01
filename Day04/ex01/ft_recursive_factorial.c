/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:43:44 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/13 17:26:11 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 1 && nb < 13)
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	else if (nb == 1 || nb == 0)
		return (1);
	else
		return (0);
}
