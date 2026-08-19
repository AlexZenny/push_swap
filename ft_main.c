/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 21:43:06 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/19 21:22:01 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* keeping all functions here by now so it easier to compile everything and handle
 bugs. Main idea is to create an from terminal arguments, then I'll be able to 
 transform it into list using my ft_listsconv.c function and needed stack_a with numbers. 
 Working on handling a dublicate numbers in input, dublicate mode flags (-- simple 
 --complex 1 2 3...),also need to copy atoi from Libft, use our printf. Hope this makes 
 sense, maybe you have some comments, ideas if my flow is right actually.*/
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int is_number(char *str)
{
    int i;

    i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[i] == '\0')
        return(1);
    while(str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return(1);
        i++;
    }
    return(0);
}
int ft_create_stack( int argc, char *argv[], t_list **stack_a)
{
    long value;
    int      i;

    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-' && argv[i][1] == '-')
            i++;
        if ((is_number(argv[i])) == 0)
        {
            value = atol(argv[i]);
            if (value > INT_MAX || value < INT_MIN)
                return (1);
            if (stack->value != value)
                stack_a = ft_addback(&stack_a,(int ) value)
        }
        else
            return(1);
        i++;
    }
    return(0);
}
int ft_strncmp(const char *s1, const char *s2, size_t size)
{
    size_t i;
    
    i = 0;
    while (i < size && s1[i] == s2[i] && s1[i] != '\0')
        i++;
    if (i == size)
        return (0);
    return((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int ft_flags(const char *cursor, t_options *options)
{ 
    if (ft_strncmp(cursor, "--simple", 9) == 0)
        options->mode = SIMPLE;
    else if (ft_strncmp(cursor, "--medium", 9) == 0)
        options->mode = MEDIUM;
    else if (ft_strncmp(cursor, "--complex", 10) == 0)
        options->mode = COMPLEX;
    else if (ft_strncmp(cursor, "--adaptive", 11) == 0)
        options->mode = ADAPTIVE;
    else if (ft_strncmp(cursor, "--bench", 8) == 0)
        options->bench = true;
    else
        return(1);
    return(0);
}
int input_parser(int argc, char *argv[], t_options *options)
{
    char *cursor;
    int i;
    
    i = 1;
    while ( i < argc)
    {
        cursor = argv[i];
        if (cursor[0] == '-' && cursor[1] == '-' )
        {   
            if(ft_flags(cursor, options) == 1)
                return(1);
        }
        else if (is_number(cursor) == 1)
            return(1);
        i++;
    } 
    return(0);
}
int main(int argc, char* argv[])
{
    t_options   options;
    int           status;
    t_list       *stack_a;
    
    options.mode = ADAPTIVE;
    options.bench = false;
    stack_a = NULL;
    stack_b = NULL;
    
    status = input_parser(argc, argv, &options);
    if (status == 1)
        printf("Error\n");
    if (status == 0)
        ft_create_stack(argc, argv, &stack_a);
    printf("%d\n", count);
    int i = 0;
    while (i < count)
    {
        printf("%d, ", array[i]);
        i++;
    }
    printf("\n");
    return (0);
}
