/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:22:40 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/03 12:35:14 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_list		*ft_lstnew(void const *content, size_t content_size)
{
	void	*new_content;

	if (content == 0)
	{
		content = NULL;
		content_size = (size_t)0;
	}
	new_content = (void *)malloc(content_size);
	if (!new_content)
		return (NULL);
	s_list->content = ft_memcpy(new_content, content, content_size);
	s_list->next = NULL;
	free(new_content);
}
