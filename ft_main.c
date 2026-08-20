/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buhankalinux <buhankalinux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 21:43:06 by buhankalinu       #+#    #+#             */
/*   Updated: 2026/08/20 23:16:51 by buhankalinu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ft_is_dublicate(t_list **stack_a, int value)
{
    t_list *curr;
    t_list *head;

    head = *stack_a;
    curr = head;
    if (*stack_a == NULL || stack_a == NULL)
        return(0);
    while (1)
    {
       if (curr->value == value)
        return (1);
        curr = curr->next; 
        if (curr == head)
            break ;
    }
    return(0);
}
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
        {
            i++;
            continue ;
        }
        value = atol(argv[i]);
        if (value > INT_MAX || value < INT_MIN)
            return (1);
        if (ft_is_dublicate(stack_a, value) == 1)
            return(1);
        ft_addback(stack_a,(int ) value);
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
int ft_mode_status(t_options *options, t_mode mode)
{
    if (options->mode_status == 1)
        return(1);
    options->mode = mode;
    options->mode_status = 1; 
    return(0);
}
int ft_flags(const char *cursor, t_options *options)
{   
    if ((ft_strncmp(cursor, "--simple", 9) == 0))
        return(ft_mode_status(options, SIMPLE));
    else if ((ft_strncmp(cursor, "--medium", 9) == 0))
        options->mode = MEDIUM;
    else if ((ft_strncmp(cursor, "--complex", 10) == 0) && (options->mode_status == 0))
        options->mode = COMPLEX;
    else if ((ft_strncmp(cursor, "--adaptive", 11) == 0) && (options->mode_status == 0))
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
    options.mode_status = 0;
    options.bench = false;
    stack_a = NULL;
    //stack_b = NULL;
    
    status = input_parser(argc, argv, &options);
    if (status == 1)
        printf("Error\n");
    else if (status == 0)
    {
        status = ft_create_stack(argc, argv, &stack_a);
        if (status == 1)
            printf("Error\n");
    }

 t_list	*temp;

    temp = stack_a;
    if (temp != NULL)
    {
        while (1)
        {
            printf("%d, ", temp->value);
            temp = temp->next;
            if (temp == stack_a)
            break ;
        }
    }
    printf("\n");
    return (0);
}
