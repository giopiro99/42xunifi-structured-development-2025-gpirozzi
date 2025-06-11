/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:57:14 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/11 19:07:55 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_MAP_H
# define GRADE_MAP_H

#define A "A+"
#define A1 "A"
#define A2 "A-"
#define B "B+"
#define B1 "B"
#define B2 "B-"
#define C "C+"
#define C1 "C"
#define C2 "C-"
#define D "D+"
#define D1 "D"
#define D2 "D-"
#define F "F"

typedef	enum	s_GradeMapper
{
	PLUSMINUS,
	PASSFAIL,
	STANDARD,
}	GradeMapper;
void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif