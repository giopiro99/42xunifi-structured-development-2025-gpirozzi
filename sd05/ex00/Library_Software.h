/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Library_Software.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:43:34 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/06/19 19:15:01 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_SOFTWARE_H
#define LIBRARY_SOFTWARE_H

# include <stddef.h>
# include <stdbool.h>
# include "./libft.h"

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