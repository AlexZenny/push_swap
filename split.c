/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:59:54 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/09/02 12:17:44 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			i;
	unsigned int	s_len;
	size_t			subs_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		subs = malloc(1);
		subs[0] = '\0';
		return (subs);
	}
	subs_len = ft_strlen(&s[start]);
	if (subs_len > len)
		subs = malloc(len + 1);
	else
		subs = malloc(subs_len + 1);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

static size_t count_word(char const *s, char c)
{
    int i;
    int inside_word;
    size_t count;

    i = 0;
    inside_word = 0;
    count = 0;
    while (s[i])
    {
        if(s[i] != c && inside_word == 0)
        {
            inside_word = 1;
            count++;
        }
        else if (s[i] == c )
            inside_word = 0;
        i++;
    }     
    return(count);
}

static char **ft_free(char **str, int i)
{
    while (i-- > 0)
        free(str[i]);
    free(str);
    return(NULL);
}

char **ft_split(char const *s, char c)
{
    char **str_split;
    int w_len;
    int str_split_i;

    str_split_i = 0;
    str_split = malloc(sizeof(char *) * (count_word(s, c) + 1));
    if (!str_split)
        return(NULL);
    while (*s)
    {
        w_len = 0;
        while (*s && *s == c)
            s++;
        if(*s)
        {
            while (s[w_len] && s[w_len] != c)
                w_len++;
            str_split[str_split_i] = ft_substr(s, 0, w_len);
            if (!str_split[str_split_i++])
                return(ft_free(str_split, str_split_i -1));
            s += w_len;
        }
    }
    str_split[str_split_i] = NULL;
    return(str_split);
} 