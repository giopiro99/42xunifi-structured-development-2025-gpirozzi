/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:54:51 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/11 12:52:37 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int count_segments(const int *arr, int size)
{
    int i;
    int validator_segment;
    int count_valid_segment;

    i = 0;
    validator_segment = 0;
    count_valid_segment = 0;
    while (i < size)
    {
        while (i < size && arr[i] != -1)
        {
            if ((i + 1 < size) && arr[i] < arr[i + 1])
                validator_segment++;
            if (validator_segment >= 2)
            {
                count_valid_segment++;
                break;
            }
            i++;
        }
        validator_segment = 0;
        i++;
    }
    return (count_valid_segment);
}
