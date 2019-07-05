/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 09:00:11 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/22 18:13:46 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;
	void	*data;

	if (!(head = (t_list*)malloc(sizeof(*head))))
		return (NULL);
	if (!(data = malloc(sizeof(*content) * content_size)))
	{
		free(head);
		return (NULL);
	}
	if (content == NULL)
	{
		free(data);
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		data = ft_memcpy(data, content, content_size);
		head->content = data;
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
