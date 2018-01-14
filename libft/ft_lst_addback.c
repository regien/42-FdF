/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:42:32 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/13 18:44:39 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lst_addback(t_list **alst, t_list *new)
{
	t_list		*iter;

	if (!new || !alst)
		return ;
	iter = *alst;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = new;
}
