/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:50:54 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/11 10:52:57 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
    int i;
    int j;

    i = 0;
    j = 0;
    *first = -1;
    *last = -1;
    while (i < size)
    {
        if (arr[i] == target)
        {
            if (*first == -1)
                *first = i;
            *last = i;
        }
        i++;
    }
}