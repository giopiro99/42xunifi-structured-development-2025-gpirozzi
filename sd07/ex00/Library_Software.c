/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Library_Software.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:44:41 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/06/20 11:06:33 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Library_Software.h"

void    free_list(t_book *head)
{
    t_book  *tmp = head;
    while (head)
    {
        tmp = head->next_book;
        if (head->author)
            free(head->author);
        if (head->book_id)
            free(head->book_id);
        if (head->title)
            free(head->title);
        free(head);
            head = tmp;
    }
}
int main(int ac, char **av)
{
    int     fd;
    t_book  *books;

    books = NULL;
    if (ac != 2)
        return -1;
    fd = open(av[1], O_RDONLY);
    if (fd < 0 || !ft_check_file(av[1]))
        return -1;
    books = ft_calloc(sizeof (t_book), 1);
    if (!books)
        return (close(fd), -1);
    data_init(books);
    if (load_and_fill_catalogue(fd, books))
        ft_handle_terminal_input(books);
    if (books)
        free_list(books);
}
