/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalyshi <tmalyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 03:40:41 by azieniuk          #+#    #+#             */
/*   Updated: 2026/09/06 18:10:58 by tmalyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_tokens(const char *arg, bool multiple_tokens, t_list **stack_a)
{
	char	**tokens;
	int		i;

	if (multiple_tokens)
	{
		tokens = split_arg(arg);
		i = 0;
		while (tokens[i])
		{
			if (!lst_add_new(tokens[i], stack_a))
				free(tokens[i++]);
			else
			{
				free(tokens[i]);
				free(tokens);
				return (1);
			}
		}
		free(tokens);
	}
	else
		if (lst_add_new(arg, stack_a))
			return (1);
	return (0);
}

int	parse_arg(const char *arg, t_list **stack_a)
{
	bool	multiple_tokens;
	int		i;

	i = 0;
	multiple_tokens = false;
	while (arg[i])
	{
		if (!is_whitespace(arg[i]))
		{
			i++;
			multiple_tokens = true;
			continue ;
		}
		if (is_num(arg[i]))
				return (1);
		i++;
	}
	if (parse_tokens(arg, multiple_tokens, stack_a))
		return (1);
	return (0);
}

int parse_input(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (check_flags(argv[i], &data->options))
				return (1);
			i++;
			continue ;
		}
		if (parse_arg(argv[i], &data->stack_a))
			return (1);
		i++;
	}
	return (0);
}

