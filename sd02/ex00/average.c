/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:26:41 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/11 17:18:42 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

float average(const int *arr, int size)
{
	int		i;
	int		valid_count;
	float	result;

	i = 0;
	valid_count = 0;
	result = 0;
	if (!arr || size <= 0)
		return (-1);
	while (i < size)
	{
		if (arr[i] < 0 || arr[i] > 100)
			i++;
		else
		{
			result += (float)arr[i];
			i++;
			valid_count++;
		}
	}
	if (valid_count > 0)
		return (result / (float)valid_count);
	else
		return (0);
}