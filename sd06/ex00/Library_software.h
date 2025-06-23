/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Library_software.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:35:09 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 10:59:05 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_SOFTWARE_H
# define LIBRARY_SOFTWARE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct	s_book
{
	char			*book_id;
	char			*title;
	char			*author;
	struct	s_book	*next_book;
}				t_book;

bool    ft_check_file(char *filename);
char    **ft_get_books_value(const char *line);
void	append_node (t_book *book);
t_book	*find_last_node(t_book *book);
void    ft_handle_terminal_input(t_book *books);
void    ft_free_all(t_book *books);
void    data_init(t_book *books);

int		load_and_fill_catalogue(int fd, t_book *books);
void    search_books_by_title(t_book *books);
void    search_books_by_author(t_book *books);
int		ft_strncasecmp(char *str1, char *str2, size_t n);
int     str_case_insensitive_match(const char *search, const char *in_catalogue);

#endif