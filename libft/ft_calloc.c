/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:00:54 by lfabbian          #+#    #+#             */
/*   Updated: 2022/10/25 13:49:42 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_calloc(size_t count, size_t size)
{
    size_t  tab;
    
    tab = malloc(count * n)
    if (!tab)
        return (NULL);
    while (count > 0)
    {
        *tab++ = 0;
        count--;
    }
    return (tab);
}