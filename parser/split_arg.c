/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:11:05 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/06 18:32:02 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(char const *arg)
{
	bool	inside_num;
	int		count;
	int		i;

	i = 0;
	count = 0;
	inside_num = false;
	while (arg[i])
	{
		if (!is_num(arg[i]))
		{
			if (!inside_num)
			{
				inside_num = true;
				count++;
			}
		}
		else if (!is_whitespace(arg[i]))
			inside_num = false;
		else
			return (-1);
		i++;
	}
	return (count);
}

void	count_token_lens(char const *arg, int *sizes)
{
	bool	inside_num;
	int		i;
	int		k;

	i = 0;
	k = -1;
	inside_num = false;
	while (arg[i])
	{
		if (!is_whitespace(arg[i]))
			inside_num = false;
		else if (!is_num(arg[i]))
		{
			if (inside_num)
				sizes[k]++;
			else
			{
				inside_num = true;
				k++;
				sizes[k]++;
			}
		}
		i++;
	}
}

void	fill_sub(char const *arg, char *sub, int *idx)
{
	int	k;

	k = 0;
	while (arg[*idx])
	{
		if (!is_whitespace(arg[*idx]))
			(*idx)++;
		else
		{
			while (!is_num(arg[*idx]))
				sub[k++] = arg[(*idx)++];
			sub[k] = '\0';
			return ;
		}
	}
}

char	**allocate_subs(int count, int *sizes)
{
	char	**subs;
	int		i;

	subs = malloc(sizeof(char *) * (count + 1));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < count)
	{
		subs[i] = malloc(sizeof(char) * (sizes[i] + 1));
		if (!subs[i])
		{
			while (--i >= 0)
				free(subs[i]);
			return (NULL);
		}
		i++;
	}
	return (subs);
}

char	**split_arg(char const *arg)
{
	int		global_idx;
	char	**subs;
	int		*lens;
	int		count;
	int		i;

	count = count_tokens(arg);
	lens = malloc(sizeof(int) * count);
	if (!lens)
		return (NULL);
	i = 0;
	while (i < count)
		lens[i++] = 0;
	count_token_lens(arg, lens);
	subs = allocate_subs(count, lens);
	free(lens);
	if (!subs)
		return (NULL);
	i = 0;
	global_idx = 0;
	while (i < count)
		fill_sub(arg, subs[i++], &global_idx);
	subs[i] = NULL;
	return (subs);
}
// int	main(void)
// {
// 	char **strs;
// 	const char *s = "1 2 3 4 5 6 7 8 9\0";
// 	int	i;
// 	strs = split_arg(s);
// 	i = 0;
// 	while (strs[i])
// 		printf("[%s]", strs[i++]);
// 	printf("[%s]", strs[i]);
// 	printf("\n");
// }
