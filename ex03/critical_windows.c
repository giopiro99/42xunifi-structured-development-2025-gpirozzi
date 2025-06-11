/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:53:03 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/11 14:48:12 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

bool    ft_check_window(int i, int *readings, int *valid_number, int *average)
{
    int j;

    j = 0;
    while (j < 5)
    {
        if (readings[i + j] > 150)
        {
            return (true);
            break;
        }
        if (readings[i + j] >= 70)
            (*valid_number)++;
        (*average) += readings[i + j];
        j++;
    }
    return (false);
}

int count_critical_windows(const int *readings, int size)
{
    int     i;
    int     average;
    int     valid_number;
    bool    invalid_n_detected;
    int     critical_w;

    i = 0;
    average = 0;
    invalid_n_detected = false;
    critical_w = 0;
    valid_number = 0;
    while (i <= size - 5)
    {
        invalid_n_detected = ft_check_window(i, readings, &valid_number, &average);
        if (valid_number >= 3 && !invalid_n_detected)
            if (average / 5 >= 90)
                critical_w++;
        valid_number = 0;
        average = 0;
        i++;
    }
    return (critical_w);
}