/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Library_Software.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:44:41 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/06/19 19:58:54 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Library_Software.h"

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
    books = malloc(sizeof (t_book));
    if (!books)
        return (close(fd), -1);
    data_init(books);
    if (load_and_fill_catalogue(fd, books))
        ft_handle_terminal_input(books);

}
