/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:46:46 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/09 21:00:59 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{	
	int	index;
	int	words;
	int	len;

	index = 0;
	words = 0;
	len = ft_strlen(s);
	while (index < len)
	{
		if (s[index] == c)
			index++;
		else
		{
			while (s[index] != c && s[index] != '\0')
			{
				index++;
			}
			words++;
		}
	}
	return (words);
}

static int	ft_lenght(char const *s, char c)
{	
	int	index;
	int	lenght;
	int	len;

	index = 0;
	lenght = 0;
	len = ft_strlen(s);
	while (index < len)
	{
		if (s[index] == c)
			index++;
		else
		{
			while (s[index] != c && s[index] != '\0')
			{
				index++;
				lenght++;
			}
			return (lenght);
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**str;
	int		cut;	
	int		words;

	words = ft_count_words(s, c);
	index = 0;
	str = (char **)malloc((words + 1) * sizeof (char *));
	if (!str)
		return (NULL);
	cut = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			index++;
		else
		{
			str[cut] = ft_substr(s, index, ft_lenght(s + index, c));
			index = index + ft_lenght(&s[index], c);
			cut++;
		}
	}
	str[cut] = NULL;
	return (str);
}
