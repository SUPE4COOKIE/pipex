/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:57:11 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/03/06 08:23:56 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int is_in_quote(char c, char *in_quote)
{
	if (c == '\'' || c == '"')
	{
		if (*in_quote == 0)
			*in_quote = c;
		else if (*in_quote == c)
			*in_quote = 0;
		return (1);
	}
	return (0);
}

static char	*copy_str(const char *str, size_t start, size_t len)
{
	char	*str_copy;
	size_t	i;
	size_t	j;

	str_copy = malloc(len + 1);
	if (str_copy == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[start + i] != '\'' && str[start + i] != '"')
		{
			str_copy[j] = str[start + i];
			j++;
		}
		i++;
	}
	str_copy[j] = '\0';
	return (str_copy);
}

static void	free_str(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	fill_remain(size_t i, size_t start, char **s, const char *str)
{
	size_t	j;

	j = 0;
	if (i > start)
	{
		s[j] = copy_str(str, start, i - start);
		if (!s[j])
			return (-1);
		j++;
	}
	return (0);
}

static char	**fill(char **split, char const *str, char sep)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	in_quote;

	i = 0;
	j = 0;
	start = 0;
	in_quote = 0;
	while (str[i])
	{
		is_in_quote(str[i], &in_quote);
		if (str[i] == (const char)sep && !in_quote)
		{
			if (i > start)
			{
				split[j] = copy_str(str, start, i - start);
				if (!split[j++])
					return (NULL);
			}
			start = i + 1;
		}
		i++;
	}
	if (fill_remain(i, start, &split[j], (char *)str) == -1)
		return (NULL);
	return (split);
}

char	**ft_split_args(char const *str, char sep)
{
	char	**split;
	size_t	count;
	size_t	i;
	char	in_quote;

	count = 0;
	i = 0;
	in_quote = 0;
	if (str[i] && str[i] != sep)
		count++;
	while (str[i])
	{
		is_in_quote(str[i], &in_quote);
		if (str[i] == sep && (str[i + 1] && str[i + 1] != sep) && !in_quote)
			count++;
		i++;
	}
	split = malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	split[count] = NULL;
	if (!fill(split, str, sep))
	{
		free_str(split);
		return (NULL);
	}
	return (split);
}
//int main(void)
//{
//	char *str = "awk '{count++} END {print count}'";
//	char **split = ft_split_args(str, ' ');
//	int i = 0;
//	while (split[i])
//	{
//		printf("%s\n", split[i]);
//		i++;
//	}
//	return (0);
//}
