/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:10:28 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/25 10:09:26 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibikand <aibikand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:47:15 by aibikand          #+#    #+#             */
/*   Updated: 2022/04/25 09:46:20 by aibikand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_check_rows(char const *s, char c)
{
	int	rows;
	int	i;

	i = 0;
	rows = 0;
	while (s[i])
	{
		if (s[i] != c)
			rows++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i])
			i++;
	}
	return (rows);
}

char	*ft_split_check_chars(char const *s, char c, int row)
{
	int		i;
	int		counter;
	char	*str_row;

	str_row = NULL;
	i = -1;
	counter = -1;
	while (++i < (int)ft_strlen(s) && s[i])
	{
		if (s[i] != c)
			counter++;
		if (counter == row && s[i] != c)
		{
			counter = i;
			while (s[counter] && s[counter] != c)
				counter++;
			str_row = ft_substr(s, i, counter - i);
			if (!str_row)
				return (NULL);
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (str_row);
}

char	**ft_split(char const *s, char c)
{
	char	**bi_str;
	int		rows;
	int		i;

	if (!s)
		return (NULL);
	rows = ft_split_check_rows(s, c);
	if (c == '\0' && ft_strlen(s) > 0)
		rows = 1;
	bi_str = (char **)ft_calloc(rows + 1, sizeof(char *));
	if (bi_str == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		bi_str[i] = ft_split_check_chars(s, c, i);
		if (bi_str[i] == NULL)
			return (NULL);
		i++;
	}
	bi_str[i] = NULL;
	return (bi_str);
}
