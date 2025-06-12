/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:01:25 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/12 19:40:26 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recipe_generator.h"

void	ft_free_all(Ingredients *fridge, TasteProfile *user_preference, Recipe *recipe)
{
	free_ingredients(fridge);
	free_taste_profile(user_preference);
	if (recipe)
		free_recipe(recipe);
}

Recipe *create_custom_recipe(void)
{
	Ingredients	*fridge;
	TasteProfile	*user_preference;
	Recipe		*recipe;
	int			user_approval;

	user_approval = -1;
	recipe = NULL;
	user_preference = NULL;
	fridge = get_current_ingredients();
	if (!fridge)
		return (NULL);
	user_preference = get_user_taste_profile();
	if (!user_preference)
	{
		free_ingredients(fridge);
		return (NULL);
	}
	recipe = create_recipe(fridge, user_preference);
	if (!recipe)
	{
		ft_free_all(fridge, user_preference, NULL);
		return (NULL);
	}
	while (user_approval != 1)
	{
		user_approval = get_user_approval(recipe);
		if (user_approval == 1)
		{
			ft_free_all(fridge, user_preference, NULL);
			return (recipe);
		}
		free_recipe(recipe);
		recipe = create_recipe(fridge, user_preference);
		if (!recipe)
		{
			ft_free_all(fridge, user_preference, NULL);
			return (NULL);
		}
	}
	ft_free_all(fridge, user_preference, recipe);
	return (NULL);
}
