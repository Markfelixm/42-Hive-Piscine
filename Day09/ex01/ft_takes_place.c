/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:27:20 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/18 13:36:11 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_hours_am(int hour);

void	ft_hours_pm(int hour);

void	ft_takes_place(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour >= 0 && hour < 12)
	{
		ft_hours_am(hour);
	}
	else
	{
		ft_hours_pm(hour);
	}
	printf("\n\n");
}

void	ft_hours_am(int hour)
{
	if (hour == 0)
		printf("12.00 A.M.");
	else
		printf("%d.00 A.M.", hour);
	printf(" AND ");
	if (hour == 11)
		printf("12.00 P.M.");
	else
		printf("%d.00 A.M.", hour + 1);
}

void	ft_hours_pm(int hour)
{
	if (hour == 24)
		printf("12.00 A.M.");
	else if (hour == 12)
		printf("12.00 P.M.");
	else
		printf("%d.00 P.M.", hour - 12);
	printf(" AND ");
	if (hour == 24)
		printf("1.00 A.M.");
	else if (hour == 23)
		printf("12.00 A.M.");
	else
		printf("%d.00 P.M.", hour - 12 + 1);
}
