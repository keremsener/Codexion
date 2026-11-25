/* *********************************************************************** */
/*                                                                         */
/*                                                     :::      ::::::::   */
/* parse.c                                           :+:      :+:    :+:   */
/*                                                 +:+ +:+         +:+     */
/* By: ksener <ksener@student.42kocaeli.com.tr   +#+  +:+       +#+        */
/*                                             +#+#+#+#+#+   +#+           */
/* Created: 2026/11/25 13:21:17 by ksener          #+#    #+#              */
/* Updated: 2026/11/25 14:22:26 by ksener          ###   ########.fr       */
/*                                                                         */
/* *********************************************************************** */

#include "codexion.h"
#include <stdio.h>

// void *checker(char **argv)
// {
        
// }

int main(int argc, char *argv[])
{
   
    if(argc == 9)
    {
        int i = 0;
        while(i < 8)
        {
            if(ft_atoi(argv[i]) < 0)
                return 1;
            i++;
        }
        int number_of_coders =  ft_atoi(argv[1]);
        if(number_of_coders <= 0)
            return 1;
        int time_to_burnout = ft_atoi(argv[2]);
        int time_to_compile = ft_atoi(argv[3]);
        int time_to_debug = ft_atoi(argv[4]);
        int time_to_refactor = ft_atoi(argv[5]);
        int number_of_compiles_required = ft_atoi(argv[6]);
        int dongle_cooldown = ft_atoi(argv[7]);
        char *scheduler = argv[8];
        printf("%d", number_of_coders);
    }
    else
        return(1);
}