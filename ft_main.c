/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 21:43:06 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/30 13:58:59 by azieniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	run_sort(t_list **stack_a, t_list **stack_b, t_options *options)
// {
// 	float	disorder;
//
// 	disorder = calculate_disorder(stack_a);
// 	if (options->mode == SIMPLE)
// 		simple_sort(&stack_a, &stack_b);
// 	if else (options->mode == MEDIUM)
// 		medium_sort(&stack_a, &stack_b, stack_len(*stack_a));
// 	if else (options->mode == COMPLEX)
// 		complex_sort(&stack_a, &stack_b);
// 	else
// 		adaptive_sort(&stack_a, &stack_b, disorder);
// }

int	ft_mode_status(t_options *options, t_mode mode)
{
	if (options->mode_status == 1)
		return (1);
	options->mode = mode;
	options->mode_status = 1;
	return (0);
}

int	ft_flags(const char *cursor, t_options *options)
{
	if ((ft_strncmp(cursor, "--simple", 9) == 0))
		return (ft_mode_status(options, SIMPLE));
	else if ((ft_strncmp(cursor, "--medium", 9) == 0))
		options->mode = MEDIUM;
	else if ((ft_strncmp(cursor, "--complex", 10) == 0)
		&& (options->mode_status == 0))
		options->mode = COMPLEX;
	else if ((ft_strncmp(cursor, "--adaptive", 11) == 0)
		&& (options->mode_status == 0))
		options->mode = ADAPTIVE;
	else if (ft_strncmp(cursor, "--bench", 8) == 0)
		options->bench = true;
	else
		return (1);
	return (0);
}

int	input_parser(int argc, char *argv[], t_options *options)
{
	char	*cursor;
	int		i;

	i = 1;
	while (i < argc)
	{
		cursor = argv[i];
		if (cursor[0] == '-' && cursor[1] == '-' )
		{
			if (ft_flags(cursor, options) == 1)
				return (1);
		}
		else if (ft_is_number(cursor) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	initialize_data(t_data *data)
{
	data->options.mode = ADAPTIVE;
	data->options.mode_status = 0;
	data->options.bench = false;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	float	disorder;

	initialize_data(&data);
	if (input_parser(argc, argv, &data.options))
	{
		ft_printf_fd(2, "Error\n");
		return (1);
	}
	if (ft_create_stack(argc, argv, &data.stack_a))
	{
		ft_printf_fd(2, "Error\n");
		ft_deallocate(&data.stack_a);
		return (1);
	}
	disorder = calculate_disorder(&data.stack_a);
	select_sort(&data, disorder);
	if (data.options.bench == true)
		benchmark_mode(&data, disorder);
}

// int main(int argc, char* argv[])
// {
//     t_options   options;
//     int           status;
//     t_list       *stack_a;
//     t_list       *stack_b;
//     
//     options.mode = ADAPTIVE;
//     options.mode_status = 0;
//     options.bench = false;
//     stack_a = NULL;
//     stack_b = NULL;
//     
//     status = input_parser(argc, argv, &options);
//     if (status == 1)
//         printf("Error\n");
//     else if (status == 0)
//     {
//         status = ft_create_stack(argc, argv, &stack_a);
//         if (status == 1)
//         {
//             printf("Error\n");
//             ft_deallocate(&stack_a);
//             return(1);
//         }
//     }
//     simple_sorting(&stack_a, &stack_b);
//     ft_print_stacks(2, &stack_a, &stack_b);
// }
