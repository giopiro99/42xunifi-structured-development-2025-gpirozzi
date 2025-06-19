/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:51 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/12 16:34:16 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

void	free_all(MovieList *film_list, Plan *plan)
{
	MovieList	*tmp;

	while (film_list)
	{
		tmp = film_list->next_film;
		free(film_list->title);
		free(film_list);
		film_list = tmp;
	}
	if (plan)
		free(plan);
}

Plan	*create_movie_night_plan(void)
{
	Preferences	*my_preference;
	MovieList	*movies;
	Plan		*night_plan;

	movies = NULL;
	night_plan = NULL;
	my_preference = get_user_preferences();
	if (!my_preference)
		return (NULL);
	movies = find_movies(my_preference);
	free(my_preference);
	if (!movies)
		return (NULL);
	night_plan = build_plan(movies);
	if (!night_plan)
	{
		free_all(movies, NULL);
		return (NULL);
	}
	return (night_plan);
}
