/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:48:51 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/11 19:08:48 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"

void	plus_minimus_mapper()
{

}
void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	if (mapper == PLUSMINUS)
		ft_plusminus();
	else if (mapper == PASSFAIL)
		ft_passfail();
	else if (mapper == STANDARD)
		ft_standard_map();
	else
		return ;
}