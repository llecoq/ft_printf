/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:36:10 by llecoq            #+#    #+#             */
/*   Updated: 2021/01/29 15:25:58 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int return_value;
	int num;

//	return_value = printf("tripouille %nooooh\n", &num);
//	printf("\n1 printf    num = %d\n", num);
//	return_value = ft_printf("tripouille %nooooh\n", &num);
//	printf("\n1 ft_printf    num = %d\n", num);
//	return_value = ft_printf("%s%n", "tripouille");
//	printf("\n1 ft_printf return_value = %d\n", return_value);
/*	printf("-------------------------------------------------\n");*/
	return_value = printf(" %p ", -1);
	printf("\n1 printf    return_value = %d\n", return_value);
	return_value = ft_printf(" %p ", -1);
	printf("\n1 ft_printf return_value = %d\n", return_value);
	printf("-------------------------------------------------\n");/*
	return_value = printf("%.0f", 4.5);
	printf("\n1 printf    return_value = %d\n", return_value);
	return_value = ft_printf("%.0f", 4.5);
	printf("\n1 ft_printf return_value = %d\n", return_value);
	printf("-------------------------------------------------\n");
	return_value = printf("%.0f", -2.5);
	printf("\n1 printf    return_value = %d\n", return_value);
	return_value = ft_printf("%.0f", -2.5);
	printf("\n1 ft_printf return_value = %d\n", return_value);
	printf("-------------------------------------------------\n");
	return_value = printf("%f %f ", LONG_MIN * 1.0, LONG_MAX * 1.0);
	printf("\n1 printf    return_value = %d\n", return_value);
	return_value = ft_printf("%f %f ", LONG_MIN * 1.0, LONG_MAX * 1.0);
	printf("\n1 ft_printf return_value = %d\n", return_value);
	printf("-------------------------------------------------\n");
	return_value = printf("%10f ", 1.0 / 0);
	printf("\n1 printf    return_value = %d\n", return_value);
	return_value = ft_printf("%10f ", 1.0 / 0);
	printf("\n1 ft_printf return_value = %d\n", return_value);*/
}
/*
int		ft_printf(const char *, ...);
#include "includes/ft_printf.h"
#include <stdio.h>

typedef	struct		s_main
{
	int		count;
	int		count2;
}					t_main;

void	ft_return_val(int mine, int real, t_main *main)
{
	if (real == mine)
	{
		main->count++;
		main->count2++;
		printf("\033[1;32m%s\033[0m\n\n\n", "OK");
	}
	else
	{
		main->count2++;
		printf("\033[1;31m%s\033[0m\n\n\n", "KO");
	}
}

int	main()
{
	t_main	main[1];
	int		mine;
	int		real;
	char	*str = "astek";
	char	stre[] = {'a', 's', 10, 'E', 'k', 0, 3, 123, -15, 15};

	main->count = 0;
	main->count2 = 0;
	mine = 0;
	real = 0;

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("##### Tests [c] #####\n");
	real = printf("|%c|\n", stre[0]);
	mine = ft_printf("|%c|\n", stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [c] #####\n");
	real = printf("|%c|\n", 0);
	mine = ft_printf("|%c|\n", 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [-c] #####\n");
	real = printf("|%-c|\n", stre[0]);
	mine = ft_printf("|%-c|\n", stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*c] : 6 #####\n");
	real = printf("|%*c|\n", 6, stre[0]);
	mine = ft_printf("|%*c|\n", 6, stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*c] : 6#####\n");
	real = printf("|%-*c|\n", 6, stre[0]);
	mine = ft_printf("|%-*c|\n", 6, stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-------------*c] : 6#####\n");
	real = printf("|%-------------*c|\n", 6, stre[0]);
	mine = ft_printf("|%-------------*c|\n", 6, stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [1c] #####\n");
	real = printf("|%1c|\n", stre[0]);
	mine = ft_printf("|%1c|\n", stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10c] #####\n");
	real = printf("|%10c|\n", stre[0]);
	mine = ft_printf("|%10c|\n", stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-1c] #####\n");
	real = printf("|%-1c|\n", stre[0]);
	mine = ft_printf("|%-1c|\n", stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-10c] #####\n");
	real = printf("|%-10c|\n", stre[0]);
	mine = ft_printf("|%-10c|\n", stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-10c|-1c|*c] : a a 6 a #####\n");
	real = printf("|%-10c|%-1c|%*c|\n", stre[0], stre[0], 6, stre[0]);
	mine = ft_printf("|%-10c|%-1c|%*c|\n", stre[0], stre[0], 6, stre[0]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-10c] #####\n");
	real = printf("|%-10c|\n", stre[5]);
	mine = ft_printf("|%-10c|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*c] : -1000 #####\n");
	real = printf("|%*c|\n", -1000, stre[0]);
	mine = ft_printf("|%*c|\n", -1000, stre[0]);
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("##### Tests [s] #####\n");
	real = printf("|%s|\n", NULL);
	mine = ft_printf("|%s|\n", NULL);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] #####\n");
	real = printf("|%*.*s|\n", 10, 10, NULL);
	mine = ft_printf("|%*.*s|\n", 10, 10, NULL);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] #####\n");
	real = printf("|%*.*s|\n", 10, 3, NULL);
	mine = ft_printf("|%*.*s|\n", 10, 3, NULL);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.*s] : 10 3 #####\n");
	real = printf("|%-*.*s|\n", 10, 3, NULL);
	mine = ft_printf("|%-*.*s|\n", 10, 3, NULL);
	ft_return_val(mine, real, main);

	printf("##### Tests [s] #####\n");
	real = printf("|%s|\n", str);
	mine = ft_printf("|%s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-s] #####\n");
	real = printf("|%-s|\n", str);
	mine = ft_printf("|%-s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*s] : 6 #####\n");
	real = printf("|%*s|\n", 6, str);
	mine = ft_printf("|%*s|\n", 6, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*s] : 6 #####\n");
	real = printf("|%-*s|\n", 6, str);
	mine = ft_printf("|%-*s|\n", 6, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-------------*s] : 6 #####\n");
	real = printf("|%-------------*s|\n", 6, str);
	mine = ft_printf("|%-------------*s|\n", 6, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.3s] #####\n");
	real = printf("|%.3s|\n", str);
	mine = ft_printf("|%.3s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.10s] #####\n");
	real = printf("|%.10s|\n", str);
	mine = ft_printf("|%.10s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [3s] #####\n");
	real = printf("|%3s|\n", str);
	mine = ft_printf("|%3s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [10s] #####\n");
	real = printf("|%10s|\n", str);
	mine = ft_printf("|%10s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-3s] #####\n");
	real = printf("|%-3s|\n", str);
	mine = ft_printf("|%-3s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-10s] #####\n");
	real = printf("|%-10s|\n", str);
	mine = ft_printf("|%-10s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-20s] #####\n");
	real = printf("|%-20s|\n", "test");
	mine = ft_printf("|%-20s|\n", "test");
	ft_return_val(mine, real, main);

	printf("##### Tests [*s] : -3#####\n");
	real = printf("|%*s|\n", -3, str);
	mine = ft_printf("|%*s|\n", -3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*s] : -6#####\n");
	real = printf("|%*s|\n", -6, str);
	mine = ft_printf("|%*s|\n", -6, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*s] : 3#####\n");
	real = printf("|%.*s|\n", 3, str);
	mine = ft_printf("|%.*s|\n", 3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*s] : 6#####\n");
	real = printf("|%.*s|\n", 6, str);
	mine = ft_printf("|%.*s|\n", 6, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*s] : -3#####\n");
	real = printf("|%.*s|\n", -3, str);
	mine = ft_printf("|%.*s|\n", -3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*s] : -6#####\n");
	real = printf("|%.*s|\n", -6, str);
	mine = ft_printf("|%.*s|\n", -6, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [3.3s] #####\n");
	real = printf("|%3.3s|\n", str);
	mine = ft_printf("|%3.3s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.10s] #####\n");
	real = printf("|%10.10s|\n", str);
	mine = ft_printf("|%10.10s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-3.3s] #####\n");
	real = printf("|%-3.3s|\n", str);
	mine = ft_printf("|%-3.3s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-10.10s] #####\n");
	real = printf("|%-10.10s|\n", str);
	mine = ft_printf("|%-10.10s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : 3 3#####\n");
	real = printf("|%*.*s|\n", 3, 3, str);
	mine = ft_printf("|%*.*s|\n", 3, 3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : 10 10#####\n");
	real = printf("|%*.*s|\n", 10, 10, str);
	mine = ft_printf("|%*.*s|\n", 10, 10, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : -3 -3#####\n");
	real = printf("|%*.*s|\n", -3, -3, str);
	mine = ft_printf("|%*.*s|\n", -3, -3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : 10 -10#####\n");
	real = printf("|%*.*s|\n", 10, -10, str);
	mine = ft_printf("|%*.*s|\n", 10, -10, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : -10 10#####\n");
	real = printf("|%*.*s|\n", -10, 10, str);
	mine = ft_printf("|%*.*s|\n", -10, 10, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : -10 -10#####\n");
	real = printf("|%*.*s|\n", -10, -10, str);
	mine = ft_printf("|%*.*s|\n", -10, -10, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.*s] : -3 -3#####\n");
	real = printf("|%-*.*s|\n", -3, -3, str);
	mine = ft_printf("|%-*.*s|\n", -3, -3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.*s] : -10 -10#####\n");
	real = printf("|%-*.*s|\n", -10, -10, str);
	mine = ft_printf("|%-*.*s|\n", -10, -10, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0s] #####\n");
	real = printf("|%10.0s|\n", str);
	mine = ft_printf("|%10.0s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.1s] #####\n");
	real = printf("|%10.1s|\n", str);
	mine = ft_printf("|%10.1s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-10.1s] #####\n");
	real = printf("|%-10.1s|\n", str);
	mine = ft_printf("|%-10.1s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-10.3s] #####\n");
	real = printf("|%-10.3s|\n", str);
	mine = ft_printf("|%-10.3s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.3s] #####\n");
	real = printf("|%10.3s|\n", str);
	mine = ft_printf("|%10.3s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : 10 3 #####\n");
	real = printf("|%*.*s|\n", 10, 3, str);
	mine = ft_printf("|%*.*s|\n", 10, 3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.*s] : 10 3 #####\n");
	real = printf("|%-*.*s|\n", 10, 3, str);
	mine = ft_printf("|%-*.*s|\n", 10, 3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : -10 3 #####\n");
	real = printf("|%*.*s|\n", -10, 3, str);
	mine = ft_printf("|%*.*s|\n", -10, 3, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*s] : 10 0 #####\n");
	real = printf("|%*.*s|\n", 10, 0, str);
	mine = ft_printf("|%*.*s|\n", 10, 0, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0s] : 10 0 #####\n");
	real = printf("|%10.0s|\n", str);
	mine = ft_printf("|%10.0s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.s] #####\n");
	real = printf("|%.s|\n", str);
	mine = ft_printf("|%.s|\n", str);
	ft_return_val(mine, real, main);

	printf("##### Tests [---*s] #####\n");
	real = printf("|%---*s|\n", 0, "test");
	mine = ft_printf("|%---*s|\n", 0, "test");
	ft_return_val(mine, real, main);

	printf("##### Tests [*s] #####\n");
	real = printf("|%*s|\n", 0, "test");
	mine = ft_printf("|%*s|\n", 0, "test");
	ft_return_val(mine, real, main);

	printf("##### Tests [2.s] #####\n");
	real = printf("|%2.s|\n", "test");
	mine = ft_printf("|%2.s|\n", "test");
	ft_return_val(mine, real, main);

	printf("##### Tests [3.*s] : 10 #####\n");
	real = printf("|%3.*s|\n", 10, str);
	mine = ft_printf("|%3.*s|\n", 10, str);
	ft_return_val(mine, real, main);

	printf("##### Tests [.s] : 42 #####\n");
	real = printf("|%.s|\n", "42");
	mine = ft_printf("|%.s|\n", "42");
	ft_return_val(mine, real, main);

	printf("##### Tests [.015s] : 42 #####\n");
	real = printf("|%.015s|\n", "42");
	mine = ft_printf("|%.015s|\n", "42");
	ft_return_val(mine, real, main);

	printf("##### Tests [-150.15s] : 42 #####\n");
	real = printf("|%-150.15s|\n", "42");
	mine = ft_printf("|%-150.15s|\n", "42");
	ft_return_val(mine, real, main);

	printf("##### Tests [-150.*s] : 15 #####\n");
	real = printf("|%-150.*s|\n", 15, "42");
	mine = ft_printf("|%-150.*s|\n", 15, "42");
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.15s] : 150 #####\n");
	real = printf("|%-*.15s|\n", 150, "42");
	mine = ft_printf("|%-*.15s|\n", 150, "42");
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.*s] : 150 15 #####\n");
	real = printf("|%-*.*s|\n", 150, 15, "42");
	mine = ft_printf("|%-*.*s|\n", 150, 15, "42");
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("##### Tests [d] 10 #####\n");
	real = printf("|%d|\n", stre[2]);
	mine = ft_printf("|%d|\n", stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [d] 3 #####\n");
	real = printf("|%d|\n", stre[6]);
	mine = ft_printf("|%d|\n", stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-d] 10 #####\n");
	real = printf("|%-d|\n", stre[2]);
	mine = ft_printf("|%-d|\n", stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-d] 3 #####\n");
	real = printf("|%-d|\n", stre[6]);
	mine = ft_printf("|%-d|\n", stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*d] : 6 10 #####\n");
	real = printf("|%*d|\n", 6, stre[2]);
	mine = ft_printf("|%*d|\n", 6, stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*d] : 6 3 #####\n");
	real = printf("|%*d|\n", 6, stre[6]);
	mine = ft_printf("|%*d|\n", 6, stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*d] : 6 10 #####\n");
	real = printf("|%-*d|\n", 6, stre[2]);
	mine = ft_printf("|%-*d|\n", 6, stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*d] : 6 3 #####\n");
	real = printf("|%-*d|\n", 6, stre[6]);
	mine = ft_printf("|%-*d|\n", 6, stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-------------*d] : 6 10 #####\n");
	real = printf("|%-------------*d|\n", 6, stre[2]);
	mine = ft_printf("|%-------------*d|\n", 6, stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.10d] : 0 #####\n");
	real = printf("|%10.10d|\n", stre[5]);
	mine = ft_printf("|%10.10d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0d] : 0 #####\n");
	real = printf("|%10.0d|\n", stre[5]);
	mine = ft_printf("|%10.0d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.1d] : 0 #####\n");
	real = printf("|%10.1d|\n", stre[5]);
	mine = ft_printf("|%10.1d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.3d] : 0 #####\n");
	real = printf("|%10.3d|\n", stre[5]);
	mine = ft_printf("|%10.3d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0d] : 123 #####\n");
	real = printf("|%10.0d|\n", stre[7]);
	mine = ft_printf("|%10.0d|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.d] : 123 #####\n");
	real = printf("|%10.d|\n", stre[7]);
	mine = ft_printf("|%10.d|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.d] : 0 #####\n");
	real = printf("|%10.d|\n", stre[5]);
	mine = ft_printf("|%10.d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [d] -15#####\n");
	real = printf("|%d|\n", stre[8]);
	mine = ft_printf("|%d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [d] -15#####\n");
	real = printf("|%d|\n", stre[8]);
	mine = ft_printf("|%d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-d] -15#####\n");
	real = printf("|%-d|\n", stre[8]);
	mine = ft_printf("|%-d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-d] -15#####\n");
	real = printf("|%-d|\n", stre[8]);
	mine = ft_printf("|%-d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*d] : 6 -15 #####\n");
	real = printf("|%*d|\n", 6, stre[8]);
	mine = ft_printf("|%*d|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*d] : 6 -15 #####\n");
	real = printf("|%*d|\n", 6, stre[8]);
	mine = ft_printf("|%*d|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*d] : 6 -15 #####\n");
	real = printf("|%-*d|\n", 6, stre[8]);
	mine = ft_printf("|%-*d|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*d] : -15 #####\n");
	real = printf("|%-*d|\n", 6, stre[8]);
	mine = ft_printf("|%-*d|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-------------*d] : 6 -15 #####\n");
	real = printf("|%-------------*d|\n", 6, stre[8]);
	mine = ft_printf("|%-------------*d|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.10d] : -15 #####\n");
	real = printf("|%10.10d|\n", stre[8]);
	mine = ft_printf("|%10.10d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0d] : -15 #####\n");
	real = printf("|%10.0d|\n", stre[8]);
	mine = ft_printf("|%10.0d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0d] : -15 #####\n");
	real = printf("|%10.0d|\n", stre[8]);
	mine = ft_printf("|%10.0d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.d] : -15 #####\n");
	real = printf("|%10.d|\n", stre[8]);
	mine = ft_printf("|%10.d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.d] : -15 #####\n");
	real = printf("|%10.d|\n", stre[8]);
	mine = ft_printf("|%10.d|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 10 10 0 #####\n");
	real = printf("|%*.*d|\n", 10, 10, stre[5]);
	mine = ft_printf("|%10.10d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 10 0 0 #####\n");
	real = printf("|%*.*d|\n", 10, 0, stre[5]);
	mine = ft_printf("|%*.*d|\n", 10, 0, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 10 1 0 #####\n");
	real = printf("|%*.*d|\n", 10, 1, stre[5]);
	mine = ft_printf("|%*.*d|\n", 10, 1, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 10 3 0 #####\n");
	real = printf("|%*.*d|\n", 10, 3, stre[5]);
	mine = ft_printf("|%*.*d|\n", 10, 3, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 10 0 123 #####\n");
	real = printf("|%*.*d|\n", 10, 0, stre[7]);
	mine = ft_printf("|%*.*d|\n", 10, 0, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.d] : 10 123 #####\n");
	real = printf("|%*.d|\n", 10, stre[7]);
	mine = ft_printf("|%*.d|\n", 10, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.d] : 10 0 #####\n");
	real = printf("|%*.d|\n", 10, stre[5]);
	mine = ft_printf("|%*.d|\n", 10, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [0.*d] : 10 0 #####\n");
	real = printf("|%0.*d|\n", 10, stre[5]);
	mine = ft_printf("|%0.*d|\n", 10, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [020.0d] : 123 #####\n");
	real = printf("|%020.0d|\n", stre[7]);
	mine = ft_printf("|%020.0d|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [.d] : 0 #####\n");
	real = printf("|%.d|\n", stre[5]);
	mine = ft_printf("|%.d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*d] : -9 -87 #####\n");
	real = printf("|%*d|\n", -9, -87);
	mine = ft_printf("|%*d|\n", -9, -87);
	ft_return_val(mine, real, main);

	printf("##### Tests [0.*d] : -45 0 #####\n");
	real = printf("|%0.*d|\n", -45, stre[5]);
	mine = ft_printf("|%0.*d|\n", -45, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 0 -45 0 #####\n");
	real = printf("|%*.*d|\n", 0, -45, stre[5]);
	mine = ft_printf("|%*.*d|\n", 0, -45, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : -45 0 0 #####\n");
	real = printf("|%*.*d|\n", -45, 0, stre[5]);
	mine = ft_printf("|%*.*d|\n", -45, 0, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : -45 -45 0 #####\n");
	real = printf("|%*.*d|\n", -45, -45, stre[5]);
	mine = ft_printf("|%*.*d|\n", -45, -45, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [020.2d] :  -2147483648 - 1 #####\n");
	real = printf("|%020.2d|\n", INT_MIN - 1);
	mine = ft_printf("|%020.2d|\n", INT_MIN - 1);
	ft_return_val(mine, real, main);

	printf("##### Tests [020.2d] :  -2147483648 #####\n");
	real = printf("|%020.2d|\n", INT_MIN);
	mine = ft_printf("|%020.2d|\n", INT_MIN);
	ft_return_val(mine, real, main);

	printf("##### Tests [0.0d] : 0 #####\n");
	real = printf("|%0.0d|\n", stre[5]);
	mine = ft_printf("|%0.0d|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [012d] : 123 #####\n");
	real = printf("|%012d|\n", stre[7]);
	mine = ft_printf("|%012d|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*d] : 012 123 #####\n");
	real = printf("|%*d|\n", 012, stre[7]);
	mine = ft_printf("|%*d|\n", 012, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [0*d] : 012 123 #####\n");
	real = printf("|%0*d|\n", 012, stre[7]);
	mine = ft_printf("|%0*d|\n", 012, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [03d] : -1 #####\n");
	real = printf("|%03d|\n", -1);
	mine = ft_printf("|%03d|\n", -1);
	ft_return_val(mine, real, main);

	printf("##### Tests [.0d] : 0 #####\n");
	real = printf("|%.0d|\n", 0);
	mine = ft_printf("|%.0d|\n", 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [.1d] : 0 #####\n");
	real = printf("|%.1d|\n", 0);
	mine = ft_printf("|%.1d|\n", 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [.0d] : 5 #####\n");
	real = printf("|%.0d|\n", 5);
	mine = ft_printf("|%.0d|\n", 5);
	ft_return_val(mine, real, main);

	printf("##### Tests [.0d] : 42 #####\n");
	real = printf("|%.0d|\n", 42);
	mine = ft_printf("|%.0d|\n", 42);
	ft_return_val(mine, real, main);

	printf("##### Tests [-54d] : INT_MIN #####\n");
	real = printf("|%-54d|\n", INT_MIN);
	mine = ft_printf("|%-54d|\n", INT_MIN);
	ft_return_val(mine, real, main);

	printf("##### Tests [1d] : -1 #####\n");
	real = printf("|%1d|\n", -1);
	mine = ft_printf("|%1d|\n", -1);
	ft_return_val(mine, real, main);

	printf("##### Tests [.20d] : INT_MIN - 1 #####\n");
	real = printf("|%.20d|\n", INT_MIN - 1);
	mine = ft_printf("|%.20d|\n", INT_MIN - 1);
	ft_return_val(mine, real, main);

	printf("##### Tests [0*d] : -10 42 #####\n");
	real = printf("|%0*d|\n", -10, 42);
	mine = ft_printf("|%0*d|\n", -10, 42);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*d] : -10 42 #####\n");
	real = printf("|%-*d|\n", -10, 42);
	mine = ft_printf("|%-*d|\n", -10, 42);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*d] : 0 0 #####\n");
	real = printf("|%.*d|\n", 0, 0);
	mine = ft_printf("|%.*d|\n", 0, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*d] : -0 0 #####\n");
	real = printf("|%.*d|\n", -0, 0);
	mine = ft_printf("|%.*d|\n", -0, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*d] : 1 0 #####\n");
	real = printf("|%.*d|\n", 1, 0);
	mine = ft_printf("|%.*d|\n", 1, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [.*d] : 0 1 #####\n");
	real = printf("|%.*d|\n", 0, 1);
	mine = ft_printf("|%.*d|\n", 0, 1);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 0 0 0 #####\n");
	real = printf("|%*.*d|\n", 0, 0, 0);
	mine = ft_printf("|%*.*d|\n", 0, 0, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 0 1 0 #####\n");
	real = printf("|%*.*d|\n", 0, 1, 0);
	mine = ft_printf("|%*.*d|\n", 0, 1, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*d] : 0 0 1 #####\n");
	real = printf("|%*.*d|\n", 0, 0, 1);
	mine = ft_printf("|%*.*d|\n", 0, 0, 1);
	ft_return_val(mine, real, main);

	printf("##### Tests [00d] : 45 #####\n");
	real = printf("|%00d|\n", 45);
	mine = ft_printf("|%00d|\n", 45);
	ft_return_val(mine, real, main);

	printf("##### Tests [.046d] : 45 #####\n");
	real = printf("|%.046d|\n", 45);
	mine = ft_printf("|%.046d|\n", 45);
	ft_return_val(mine, real, main);

	printf("##### Tests [046d] : INT_MIN #####\n");
	real = printf("|%046d|\n", INT_MIN);
	mine = ft_printf("|%046d|\n", INT_MIN);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.0d] : -45 0 #####\n");
	real = printf("|%*.0d|\n", -45, 0);
	mine = ft_printf("|%*.0d|\n", -45, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [-11.0d] : INT_MAX #####\n");
	real = printf("|%-11.0d|\n", INT_MAX);
	mine = ft_printf("|%-11.0d|\n", INT_MAX);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.5d] : -15 INT_MAX #####\n");
	real = printf("|%*.5d|\n", -15, INT_MAX);
	mine = ft_printf("|%*.5d|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.5d] : -15 INT_MAX #####\n");
	real = printf("|%-*.5d|\n", -15, INT_MAX);
	mine = ft_printf("|%-*.5d|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);

	printf("##### Tests [-150.15d] : 12345 #####\n");
	real = printf("|%-150.15d|\n", 12345);
	mine = ft_printf("|%-150.15d|\n", 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [-150.*d] : 15 12345 #####\n");
	real = printf("|%-150.*d|\n", 15, 12345);
	mine = ft_printf("|%-150.*d|\n", 15, 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.15d] : 150 12345 #####\n");
	real = printf("|%-*.15d|\n", 150, 12345);
	mine = ft_printf("|%-*.15d|\n", 150, 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.*d] : 150 15 12345 #####\n");
	real = printf("|%-*.*d|\n", 150, 15, 12345);
	mine = ft_printf("|%-*.*d|\n", 150, 15, 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [0*.*d] : 5 -5 8 #####\n");
	real = printf("|%0*.*d|\n", 5, -5, 8);
	mine = ft_printf("|%0*.*d|\n", 5, -5, 8);
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("##### Tests [u] 10 #####\n");
	real = printf("|%u|\n", stre[2]);
	mine = ft_printf("|%u|\n", stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [u] 3 #####\n");
	real = printf("|%u|\n", stre[6]);
	mine = ft_printf("|%u|\n", stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-u] 10 #####\n");
	real = printf("|%-u|\n", stre[2]);
	mine = ft_printf("|%-u|\n", stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-u] 3 #####\n");
	real = printf("|%-u|\n", stre[6]);
	mine = ft_printf("|%-u|\n", stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*u] : 6 10 #####\n");
	real = printf("|%*u|\n", 6, stre[2]);
	mine = ft_printf("|%*u|\n", 6, stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*u] : 6 3 #####\n");
	real = printf("|%*u|\n", 6, stre[6]);
	mine = ft_printf("|%*u|\n", 6, stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*u] : 6 10 #####\n");
	real = printf("|%-*u|\n", 6, stre[2]);
	mine = ft_printf("|%-*u|\n", 6, stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*u] : 6 3 #####\n");
	real = printf("|%-*u|\n", 6, stre[6]);
	mine = ft_printf("|%-*u|\n", 6, stre[6]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-------------*u] : 6 10 #####\n");
	real = printf("|%-------------*u|\n", 6, stre[2]);
	mine = ft_printf("|%-------------*u|\n", 6, stre[2]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.10u] : 0 #####\n");
	real = printf("|%10.10u|\n", stre[5]);
	mine = ft_printf("|%10.10u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0u] : 0 #####\n");
	real = printf("|%10.0u|\n", stre[5]);
	mine = ft_printf("|%10.0u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.1u] : 0 #####\n");
	real = printf("|%10.1u|\n", stre[5]);
	mine = ft_printf("|%10.1u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.3u] : 0 #####\n");
	real = printf("|%10.3u|\n", stre[5]);
	mine = ft_printf("|%10.3u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0u] : 123 #####\n");
	real = printf("|%10.0u|\n", stre[7]);
	mine = ft_printf("|%10.0u|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.u] : 123 #####\n");
	real = printf("|%10.u|\n", stre[7]);
	mine = ft_printf("|%10.u|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.u] : 0 #####\n");
	real = printf("|%10.u|\n", stre[5]);
	mine = ft_printf("|%10.u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [u] -15#####\n");
	real = printf("|%u|\n", stre[8]);
	mine = ft_printf("|%u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [u] -15#####\n");
	real = printf("|%u|\n", stre[8]);
	mine = ft_printf("|%u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-u] -15#####\n");
	real = printf("|%-u|\n", stre[8]);
	mine = ft_printf("|%-u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-u] -15#####\n");
	real = printf("|%-u|\n", stre[8]);
	mine = ft_printf("|%-u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*u] : 6 -15 #####\n");
	real = printf("|%*u|\n", 6, stre[8]);
	mine = ft_printf("|%*u|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*u] : 6 -15 #####\n");
	real = printf("|%*u|\n", 6, stre[8]);
	mine = ft_printf("|%*u|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*u] : 6 -15 #####\n");
	real = printf("|%-*u|\n", 6, stre[8]);
	mine = ft_printf("|%-*u|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*u] : 6 -15 #####\n");
	real = printf("|%-*u|\n", 6, stre[8]);
	mine = ft_printf("|%-*u|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [-------------*u] : 6 -15 #####\n");
	real = printf("|%-------------*u|\n", 6, stre[8]);
	mine = ft_printf("|%-------------*u|\n", 6, stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.10u] : -15 #####\n");
	real = printf("|%10.10u|\n", stre[8]);
	mine = ft_printf("|%10.10u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0u] : -15 #####\n");
	real = printf("|%10.0u|\n", stre[8]);
	mine = ft_printf("|%10.0u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.0u] : -15 #####\n");
	real = printf("|%10.0u|\n", stre[8]);
	mine = ft_printf("|%10.0u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.u] : -15 #####\n");
	real = printf("|%10.u|\n", stre[8]);
	mine = ft_printf("|%10.u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [10.u] : -15 #####\n");
	real = printf("|%10.u|\n", stre[8]);
	mine = ft_printf("|%10.u|\n", stre[8]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 10 10 0 #####\n");
	real = printf("|%*.*u|\n", 10, 10, stre[5]);
	mine = ft_printf("|%10.10u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 10 0 0 #####\n");
	real = printf("|%*.*u|\n", 10, 0, stre[5]);
	mine = ft_printf("|%*.*u|\n", 10, 0, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 10 1 0 #####\n");
	real = printf("|%*.*u|\n", 10, 1, stre[5]);
	mine = ft_printf("|%*.*u|\n", 10, 1, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 10 3 0 #####\n");
	real = printf("|%*.*u|\n", 10, 3, stre[5]);
	mine = ft_printf("|%*.*u|\n", 10, 3, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 10 0 123 #####\n");
	real = printf("|%*.*u|\n", 10, 0, stre[7]);
	mine = ft_printf("|%*.*u|\n", 10, 0, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.u] : 10 123 #####\n");
	real = printf("|%*.u|\n", 10, stre[7]);
	mine = ft_printf("|%*.u|\n", 10, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.u] : 10 0 #####\n");
	real = printf("|%*.u|\n", 10, stre[5]);
	mine = ft_printf("|%*.u|\n", 10, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [0.*u] : 10 0 #####\n");
	real = printf("|%0.*u|\n", 10, stre[5]);
	mine = ft_printf("|%0.*u|\n", 10, stre[5]);
	ft_return_val(mine, real, main);


	printf("##### Tests [020.0u] : 123 #####\n");
	real = printf("|%020.0u|\n", stre[7]);
	mine = ft_printf("|%020.0u|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [.u] : 0 #####\n");
	real = printf("|%.u|\n", stre[5]);
	mine = ft_printf("|%.u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*u] : -9 -87 #####\n");
	real = printf("|%*u|\n", -9, -87);
	mine = ft_printf("|%*u|\n", -9, -87);
	ft_return_val(mine, real, main);

	printf("##### Tests [0.*u] : -45 0 #####\n");
	real = printf("|%0.*u|\n", -45, stre[5]);
	mine = ft_printf("|%0.*u|\n", -45, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 0 -45 0 #####\n");
	real = printf("|%*.*u|\n", 0, -45, stre[5]);
	mine = ft_printf("|%*.*u|\n", 0, -45, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : -45 0 0 #####\n");
	real = printf("|%*.*u|\n", -45, 0, stre[5]);
	mine = ft_printf("|%*.*u|\n", -45, 0, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : -45 -45 0 #####\n");
	real = printf("|%*.*u|\n", -45, -45, stre[5]);
	mine = ft_printf("|%*.*u|\n", -45, -45, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [020.2u] :  -2147483648 - 1 #####\n");
	real = printf("|%020.2u|\n", INT_MIN - 1);
	mine = ft_printf("|%020.2u|\n", INT_MIN - 1);
	ft_return_val(mine, real, main);

	printf("##### Tests [020.2u] :  -2147483648 #####\n");
	real = printf("|%020.2u|\n", INT_MIN);
	mine = ft_printf("|%020.2u|\n", INT_MIN);
	ft_return_val(mine, real, main);

	printf("##### Tests [0.0u] : 3 #####\n");
	real = printf("|%0.0u|\n", 3);
	mine = ft_printf("|%0.0u|\n", 3);
	ft_return_val(mine, real, main);

	printf("##### Tests [0.0u] : 0 #####\n");
	real = printf("|%0.0u|\n", stre[5]);
	mine = ft_printf("|%0.0u|\n", stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [012u] : 123 #####\n");
	real = printf("|%012u|\n", stre[7]);
	mine = ft_printf("|%012u|\n", stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*u] : 012 123 #####\n");
	real = printf("|%*u|\n", 012, stre[7]);
	mine = ft_printf("|%*u|\n", 012, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [0*u] : 12 123 #####\n");
	real = printf("|%0*u|\n", 12, stre[7]);
	mine = ft_printf("|%0*u|\n", 12, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*u] : 012 123 #####\n");
	real = printf("|%*u|\n", 012, stre[7]);
	mine = ft_printf("|%*u|\n", 012, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [0*u] : 012 123 #####\n");
	real = printf("|%0*u|\n", 012, stre[7]);
	mine = ft_printf("|%0*u|\n", 012, stre[7]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 0 1 0 #####\n");
	real = printf("|%*.*u|\n", 0, 1, 0);
	mine = ft_printf("|%*.*u|\n", 0, 1, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*u] : 0 0 1 #####\n");
	real = printf("|%*.*u|\n", 0, 0, 1);
	mine = ft_printf("|%*.*u|\n", 0, 0, 1);
	ft_return_val(mine, real, main);

	printf("##### Tests [.45u] : 0 #####\n");
	real = printf("|%.45u|\n", 0);
	mine = ft_printf("|%.45u|\n", 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [046u] : INT_MIN #####\n");
	real = printf("|%046u|\n", INT_MIN);
	mine = ft_printf("|%046u|\n", INT_MIN);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.0u] : -45 0 #####\n");
	real = printf("|%*.0u|\n", -45, 0);
	mine = ft_printf("|%*.0u|\n", -45, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.5u] : -15 INT_MAX #####\n");
	real = printf("|%*.5u|\n", -15, INT_MAX);
	mine = ft_printf("|%*.5u|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.5u] : -15 INT_MAX #####\n");
	real = printf("|%-*.5u|\n", -15, INT_MAX);
	mine = ft_printf("|%-*.5u|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);

	printf("##### Tests [-150.15u] : 12345 #####\n");
	real = printf("|%-150.15u|\n", 12345);
	mine = ft_printf("|%-150.15u|\n", 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [-150.*u] : 15 12345 #####\n");
	real = printf("|%-150.*u|\n", 15, 12345);
	mine = ft_printf("|%-150.*u|\n", 15, 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.15u] : 150 12345 #####\n");
	real = printf("|%-*.15u|\n", 150, 12345);
	mine = ft_printf("|%-*.15u|\n", 150, 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [-*.*u] : 150 15 12345 #####\n");
	real = printf("|%-*.*u|\n", 150, 15, 12345);
	mine = ft_printf("|%-*.*u|\n", 150, 15, 12345);
	ft_return_val(mine, real, main);

	printf("##### Tests [0*.*u] : 5 -5 8 #####\n");
	real = printf("|%0*.*u|\n", 5, -5, 8);
	mine = ft_printf("|%0*.*u|\n", 5, -5, 8);
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("##### Tests [x] 10 #####\n");
	real = printf("|%x|\n", stre[2]);
	mine = ft_printf("|%x|\n", stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [x] 3 #####\n");
	real = printf("|%x|\n", stre[6]);
	mine = ft_printf("|%x|\n", stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-x] 10 #####\n");
	real = printf("|%-x|\n", stre[2]);
	mine = ft_printf("|%-x|\n", stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-x] 3 #####\n");
	real = printf("|%-x|\n", stre[6]);
	mine = ft_printf("|%-x|\n", stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*x] : 6 10 #####\n");
	real = printf("|%*x|\n", 6, stre[2]);
	mine = ft_printf("|%*x|\n", 6, stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*x] : 6 3 #####\n");
	real = printf("|%*x|\n", 6, stre[6]);
	mine = ft_printf("|%*x|\n", 6, stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*x] : 6 10 #####\n");
	real = printf("|%-*x|\n", 6, stre[2]);
	mine = ft_printf("|%-*x|\n", 6, stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*x] : 6 3 #####\n");
	real = printf("|%-*x|\n", 6, stre[6]);
	mine = ft_printf("|%-*x|\n", 6, stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-------------*x] : 6 10 #####\n");
	real = printf("|%-------------*x|\n", 6, stre[2]);
	mine = ft_printf("|%-------------*x|\n", 6, stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.10x] : 0 #####\n");
	real = printf("|%10.10x|\n", stre[5]);
	mine = ft_printf("|%10.10x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0x] : 0 #####\n");
	real = printf("|%10.0x|\n", stre[5]);
	mine = ft_printf("|%10.0x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.1x] : 0 #####\n");
	real = printf("|%10.1x|\n", stre[5]);
	mine = ft_printf("|%10.1x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.3x] : 0 #####\n");
	real = printf("|%10.3x|\n", stre[5]);
	mine = ft_printf("|%10.3x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0x] : 123 #####\n");
	real = printf("|%10.0x|\n", stre[7]);
	mine = ft_printf("|%10.0x|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.x] : 123 #####\n");
	real = printf("|%10.x|\n", stre[7]);
	mine = ft_printf("|%10.x|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.x] : 0 #####\n");
	real = printf("|%10.x|\n", stre[5]);
	mine = ft_printf("|%10.x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [x] -15#####\n");
	real = printf("|%x|\n", stre[8]);
	mine = ft_printf("|%x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [x] -15#####\n");
	real = printf("|%x|\n", stre[8]);
	mine = ft_printf("|%x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-x] -15#####\n");
	real = printf("|%-x|\n", stre[8]);
	mine = ft_printf("|%-x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-x] -15#####\n");
	real = printf("|%-x|\n", stre[8]);
	mine = ft_printf("|%-x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*x] : 6 -15 #####\n");
	real = printf("|%*x|\n", 6, stre[8]);
	mine = ft_printf("|%*x|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*x] : 6 -15 #####\n");
	real = printf("|%*x|\n", 6, stre[8]);
	mine = ft_printf("|%*x|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*x] : 6 -15 #####\n");
	real = printf("|%-*x|\n", 6, stre[8]);
	mine = ft_printf("|%-*x|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*x] : 6 -15 #####\n");
	real = printf("|%-*x|\n", 6, stre[8]);
	mine = ft_printf("|%-*x|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-------------*x] : 6 -15 #####\n");
	real = printf("|%-------------*x|\n", 6, stre[8]);
	mine = ft_printf("|%-------------*x|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.10x] : -15 #####\n");
	real = printf("|%10.10x|\n", stre[8]);
	mine = ft_printf("|%10.10x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0x] : -15 #####\n");
	real = printf("|%10.0x|\n", stre[8]);
	mine = ft_printf("|%10.0x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0x] : -15 #####\n");
	real = printf("|%10.0x|\n", stre[8]);
	mine = ft_printf("|%10.0x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.x] : -15 #####\n");
	real = printf("|%10.x|\n", stre[8]);
	mine = ft_printf("|%10.x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.x] : -15 #####\n");
	real = printf("|%10.x|\n", stre[8]);
	mine = ft_printf("|%10.x|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 10 10 0 #####\n");
	real = printf("|%*.*x|\n", 10, 10, stre[5]);
	mine = ft_printf("|%10.10x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 10 0 0 #####\n");
	real = printf("|%*.*x|\n", 10, 0, stre[5]);
	mine = ft_printf("|%*.*x|\n", 10, 0, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 10 1 0 #####\n");
	real = printf("|%*.*x|\n", 10, 1, stre[5]);
	mine = ft_printf("|%*.*x|\n", 10, 1, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 10 3 0 #####\n");
	real = printf("|%*.*x|\n", 10, 3, stre[5]);
	mine = ft_printf("|%*.*x|\n", 10, 3, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 10 0 123 #####\n");
	real = printf("|%*.*x|\n", 10, 0, stre[7]);
	mine = ft_printf("|%*.*x|\n", 10, 0, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.x] : 10 123 #####\n");
	real = printf("|%*.x|\n", 10, stre[7]);
	mine = ft_printf("|%*.x|\n", 10, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.x] : 10 0 #####\n");
	real = printf("|%*.x|\n", 10, stre[5]);
	mine = ft_printf("|%*.x|\n", 10, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.*x] : 10 0 #####\n");
	real = printf("|%0.*x|\n", 10, stre[5]);
	mine = ft_printf("|%0.*x|\n", 10, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.0x] : 123 #####\n");
	real = printf("|%020.0x|\n", stre[7]);
	mine = ft_printf("|%020.0x|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [.x] : 0 #####\n");
	real = printf("|%.x|\n", stre[5]);
	mine = ft_printf("|%.x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*x] : -9 -87 #####\n");
	real = printf("|%*x|\n", -9, -87);
	mine = ft_printf("|%*x|\n", -9, -87);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.*x] : -45 0 #####\n");
	real = printf("|%0.*x|\n", -45, stre[5]);
	mine = ft_printf("|%0.*x|\n", -45, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 0 -45 0 #####\n");
	real = printf("|%*.*x|\n", 0, -45, stre[5]);
	mine = ft_printf("|%*.*x|\n", 0, -45, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : -45 0 0 #####\n");
	real = printf("|%*.*x|\n", -45, 0, stre[5]);
	mine = ft_printf("|%*.*x|\n", -45, 0, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : -45 -45 0 #####\n");
	real = printf("|%*.*x|\n", -45, -45, stre[5]);
	mine = ft_printf("|%*.*x|\n", -45, -45, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.2x] :  -2147483648 - 1 #####\n");
	real = printf("|%020.2x|\n", INT_MIN - 1);
	mine = ft_printf("|%020.2x|\n", INT_MIN - 1);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.2x] :  -2147483648 #####\n");
	real = printf("|%020.2x|\n", INT_MIN);
	mine = ft_printf("|%020.2x|\n", INT_MIN);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.0x] : 3 #####\n");
	real = printf("|%0.0x|\n", 3);
	mine = ft_printf("|%0.0x|\n", 3);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.0x] : 0 #####\n");
	real = printf("|%0.0x|\n", stre[5]);
	mine = ft_printf("|%0.0x|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [012x] : 123 #####\n");
	real = printf("|%012x|\n", stre[7]);
	mine = ft_printf("|%012x|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*x] : 012 123 #####\n");
	real = printf("|%*x|\n", 012, stre[7]);
	mine = ft_printf("|%*x|\n", 012, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*x] : 12 123 #####\n");
	real = printf("|%0*x|\n", 12, stre[7]);
	mine = ft_printf("|%0*x|\n", 12, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*x] : 012 123 #####\n");
	real = printf("|%*x|\n", 012, stre[7]);
	mine = ft_printf("|%*x|\n", 012, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*x] : 012 123 #####\n");
	real = printf("|%0*x|\n", 012, stre[7]);
	mine = ft_printf("|%0*x|\n", 012, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.2x] :  2147483647 #####\n");
	real = printf("|%020.2x|\n", INT_MAX);
	mine = ft_printf("|%020.2x|\n", INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 0 1 0 #####\n");
	real = printf("|%*.*x|\n", 0, 1, 0);
	mine = ft_printf("|%*.*x|\n", 0, 1, 0);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*x] : 0 0 1 #####\n");
	real = printf("|%*.*x|\n", 0, 0, 1);
	mine = ft_printf("|%*.*x|\n", 0, 0, 1);
	ft_return_val(mine, real, main);
	printf("##### Tests [.45x] :  #####\n");
	real = printf("|%.45x|\n", 0);
	mine = ft_printf("|%.45x|\n", 0);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.5x] : -15 INT_MAX #####\n");
	real = printf("|%*.5x|\n", -15, INT_MAX);
	mine = ft_printf("|%*.5x|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.5x] : -15 INT_MAX #####\n");
	real = printf("|%-*.5x|\n", -15, INT_MAX);
	mine = ft_printf("|%-*.5x|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [-150.15x] : 12345 #####\n");
	real = printf("|%-150.15x|\n", 12345);
	mine = ft_printf("|%-150.15x|\n", 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [-150.*x] : 15 12345 #####\n");
	real = printf("|%-150.*x|\n", 15, 12345);
	mine = ft_printf("|%-150.*x|\n", 15, 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.15x] : 150 12345 #####\n");
	real = printf("|%-*.15x|\n", 150, 12345);
	mine = ft_printf("|%-*.15x|\n", 150, 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.*x] : 150 15 12345 #####\n");
	real = printf("|%-*.*x|\n", 150, 15, 12345);
	mine = ft_printf("|%-*.*x|\n", 150, 15, 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*.*x] : 5 -5 8 #####\n");
	real = printf("|%0*.*x|\n", 5, -5, 8);
	mine = ft_printf("|%0*.*x|\n", 5, -5, 8);
	ft_return_val(mine, real, main);
	printf("\033[1;31m#######################################\033[0m\n\n\n");
	printf("##### Tests [X] 10 #####\n");
	real = printf("|%X|\n", stre[2]);
	mine = ft_printf("|%X|\n", stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [X] 3 #####\n");
	real = printf("|%X|\n", stre[6]);
	mine = ft_printf("|%X|\n", stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-X] 10 #####\n");
	real = printf("|%-X|\n", stre[2]);
	mine = ft_printf("|%-X|\n", stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-X] 3 #####\n");
	real = printf("|%-X|\n", stre[6]);
	mine = ft_printf("|%-X|\n", stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*X] : 6 10 #####\n");
	real = printf("|%*X|\n", 6, stre[2]);
	mine = ft_printf("|%*X|\n", 6, stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*X] : 6 3 #####\n");
	real = printf("|%*X|\n", 6, stre[6]);
	mine = ft_printf("|%*X|\n", 6, stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*X] : 6 10 #####\n");
	real = printf("|%-*X|\n", 6, stre[2]);
	mine = ft_printf("|%-*X|\n", 6, stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*X] : 6 3 #####\n");
	real = printf("|%-*X|\n", 6, stre[6]);
	mine = ft_printf("|%-*X|\n", 6, stre[6]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-------------*X] : 6 10 #####\n");
	real = printf("|%-------------*X|\n", 6, stre[2]);
	mine = ft_printf("|%-------------*X|\n", 6, stre[2]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.10X] : 0 #####\n");
	real = printf("|%10.10X|\n", stre[5]);
	mine = ft_printf("|%10.10X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0X] : 0 #####\n");
	real = printf("|%10.0X|\n", stre[5]);
	mine = ft_printf("|%10.0X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.1X] : 0 #####\n");
	real = printf("|%10.1X|\n", stre[5]);
	mine = ft_printf("|%10.1X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.3X] : 0 #####\n");
	real = printf("|%10.3X|\n", stre[5]);
	mine = ft_printf("|%10.3X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0X] : 123 #####\n");
	real = printf("|%10.0X|\n", stre[7]);
	mine = ft_printf("|%10.0X|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.X] : 123 #####\n");
	real = printf("|%10.X|\n", stre[7]);
	mine = ft_printf("|%10.X|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.X] : 0 #####\n");
	real = printf("|%10.X|\n", stre[5]);
	mine = ft_printf("|%10.X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [X] -15#####\n");
	real = printf("|%X|\n", stre[8]);
	mine = ft_printf("|%X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [X] -15#####\n");
	real = printf("|%X|\n", stre[8]);
	mine = ft_printf("|%X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-X] -15#####\n");
	real = printf("|%-X|\n", stre[8]);
	mine = ft_printf("|%-X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-X] -15#####\n");
	real = printf("|%-X|\n", stre[8]);
	mine = ft_printf("|%-X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*X] : 6 -15 #####\n");
	real = printf("|%*X|\n", 6, stre[8]);
	mine = ft_printf("|%*X|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*X] : 6 -15 #####\n");
	real = printf("|%*X|\n", 6, stre[8]);
	mine = ft_printf("|%*X|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*X] : 6 -15 #####\n");
	real = printf("|%-*X|\n", 6, stre[8]);
	mine = ft_printf("|%-*X|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*X] : 6 -15 #####\n");
	real = printf("|%-*X|\n", 6, stre[8]);
	mine = ft_printf("|%-*X|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [-------------*X] : 6 -15 #####\n");
	real = printf("|%-------------*X|\n", 6, stre[8]);
	mine = ft_printf("|%-------------*X|\n", 6, stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.10X] : -15 #####\n");
	real = printf("|%10.10X|\n", stre[8]);
	mine = ft_printf("|%10.10X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0X] : -15 #####\n");
	real = printf("|%10.0X|\n", stre[8]);
	mine = ft_printf("|%10.0X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0X] : -15 #####\n");
	real = printf("|%10.0X|\n", stre[8]);
	mine = ft_printf("|%10.0X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.X] : -15 #####\n");
	real = printf("|%10.X|\n", stre[8]);
	mine = ft_printf("|%10.X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.X] : -15 #####\n");
	real = printf("|%10.X|\n", stre[8]);
	mine = ft_printf("|%10.X|\n", stre[8]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : 10 10 0 #####\n");
	real = printf("|%*.*X|\n", 10, 10, stre[5]);
	mine = ft_printf("|%10.10X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : 10 0 0 #####\n");
	real = printf("|%*.*X|\n", 10, 0, stre[5]);
	mine = ft_printf("|%*.*X|\n", 10, 0, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : 10 1 0 #####\n");
	real = printf("|%*.*X|\n", 10, 1, stre[5]);
	mine = ft_printf("|%*.*X|\n", 10, 1, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : 10 3 0 #####\n");
	real = printf("|%*.*X|\n", 10, 3, stre[5]);
	mine = ft_printf("|%*.*X|\n", 10, 3, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : 10 0 123 #####\n");
	real = printf("|%*.*X|\n", 10, 0, stre[7]);
	mine = ft_printf("|%*.*X|\n", 10, 0, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.X] : 10 123 #####\n");
	real = printf("|%*.X|\n", 10, stre[7]);
	mine = ft_printf("|%*.X|\n", 10, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.X] : 10 0 #####\n");
	real = printf("|%*.X|\n", 10, stre[5]);
	mine = ft_printf("|%*.X|\n", 10, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.*X] : 10 0 #####\n");
	real = printf("|%0.*X|\n", 10, stre[5]);
	mine = ft_printf("|%0.*X|\n", 10, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.0X] : 123 #####\n");
	real = printf("|%020.0X|\n", stre[7]);
	mine = ft_printf("|%020.0X|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [.X] : 0 #####\n");
	real = printf("|%.X|\n", stre[5]);
	mine = ft_printf("|%.X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*X] : -9 -87 #####\n");
	real = printf("|%*X|\n", -9, -87);
	mine = ft_printf("|%*X|\n", -9, -87);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.*X] : -45 0 #####\n");
	real = printf("|%0.*X|\n", -45, stre[5]);
	mine = ft_printf("|%0.*X|\n", -45, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : 0 -45 0 #####\n");
	real = printf("|%*.*X|\n", 0, -45, stre[5]);
	mine = ft_printf("|%*.*X|\n", 0, -45, stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : -45 0 0 #####\n");
	real = printf("|%*.*X|\n", -45, 0, stre[5]);
	mine = ft_printf("|%*.*X|\n", -45, 0, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*X] : -45 -45 0 #####\n");
	real = printf("|%*.*X|\n", -45, -45, stre[5]);
	mine = ft_printf("|%*.*X|\n", -45, -45, stre[5]);
	ft_return_val(mine, real, main);

	printf("##### Tests [020.2X] :  -2147483648 - 1 #####\n");
	real = printf("|%020.2X|\n", INT_MIN - 1);
	mine = ft_printf("|%020.2X|\n", INT_MIN - 1);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.2X] :  2147483647 #####\n");
	real = printf("|%020.2X|\n", INT_MAX);
	mine = ft_printf("|%020.2X|\n", INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.2X] :  4294967296 #####\n");
	real = printf("|%020.2X|\n", UINT_MAX);
	mine = ft_printf("|%020.2X|\n", UINT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.0X] : 3 #####\n");
	real = printf("|%0.0X|\n", 3);
	mine = ft_printf("|%0.0X|\n", 3);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.0X] : 0 #####\n");
	real = printf("|%0.0X|\n", stre[5]);
	mine = ft_printf("|%0.0X|\n", stre[5]);
	ft_return_val(mine, real, main);
	printf("##### Tests [012X] : 123 #####\n");
	real = printf("|%012X|\n", stre[7]);
	mine = ft_printf("|%012X|\n", stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*X] : 012 123 #####\n");
	real = printf("|%*X|\n", 012, stre[7]);
	mine = ft_printf("|%*X|\n", 012, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*X] : 12 123 #####\n");
	real = printf("|%0*X|\n", 12, stre[7]);
	mine = ft_printf("|%0*X|\n", 12, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [*X] : 012 123 #####\n");
	real = printf("|%*X|\n", 012, stre[7]);
	mine = ft_printf("|%*X|\n", 012, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*X] : 012 123 #####\n");
	real = printf("|%0*X|\n", 012, stre[7]);
	mine = ft_printf("|%0*X|\n", 012, stre[7]);
	ft_return_val(mine, real, main);
	printf("##### Tests [2.2X] : 0 #####\n");
	real = printf("|%2.2X|\n", 0);
	mine = ft_printf("|%2.2X|\n", 0);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.5X] : -15 INT_MAX #####\n");
	real = printf("|%*.5X|\n", -15, INT_MAX);
	mine = ft_printf("|%*.5X|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.5X] : -15 INT_MAX #####\n");
	real = printf("|%-*.5X|\n", -15, INT_MAX);
	mine = ft_printf("|%-*.5X|\n", -15, INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*X] : -15 5 INT_MAX #####\n");
	real = printf("|%*.*X|\n", -15, 5, INT_MAX);
	mine = ft_printf("|%*.*X|\n", -15, 5, INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.*X] : -15 5 INT_MAX #####\n");
	real = printf("|%-*.*X|\n", -15, 5, INT_MAX);
	mine = ft_printf("|%-*.*X|\n", -15, 5, INT_MAX);
	ft_return_val(mine, real, main);
	printf("##### Tests [-150.15X] : 12345 #####\n");
	real = printf("|%-150.15X|\n", 12345);
	mine = ft_printf("|%-150.15X|\n", 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [-150.*X] : 15 12345 #####\n");
	real = printf("|%-150.*X|\n", 15, 12345);
	mine = ft_printf("|%-150.*X|\n", 15, 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.15X] : 150 12345 #####\n");
	real = printf("|%-*.15X|\n", 150, 12345);
	mine = ft_printf("|%-*.15X|\n", 150, 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.*X] : 150 15 12345 #####\n");
	real = printf("|%-*.*X|\n", 150, 15, 12345);
	mine = ft_printf("|%-*.*X|\n", 150, 15, 12345);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*.*X] : 5 -5 8 #####\n");
	real = printf("|%0*.*X|\n", 5, -5, 8);
	mine = ft_printf("|%0*.*X|\n", 5, -5, 8);
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("##### Tests ['percent'] #####\n");
	real = printf("|%%|\n");
	mine = ft_printf("|%%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10'percent's] #####\n");
	real = printf("|%10%s|\n");
	mine = ft_printf("|%10%s|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.10'percent's] #####\n");
	real = printf("|%10.10%s|\n");
	mine = ft_printf("|%10.10%s|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.3'percent's] #####\n");
	real = printf("|%10.3%s|\n");
	mine = ft_printf("|%10.3%s|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.'percent's] #####\n");
	real = printf("|%10.%s|\n");
	mine = ft_printf("|%10.%s|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [012'percent'] #####\n");
	real = printf("|%012%|\n");
	mine = ft_printf("|%012%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [*'percent'] : 12 #####\n");
	real = printf("|%*%|\n", 12);
	mine = ft_printf("|%*%|\n", 12);
	ft_return_val(mine, real, main);
	printf("##### Tests [*'percent'] : 012 #####\n");
	real = printf("|%*%|\n", 012);
	mine = ft_printf("|%*%|\n", 012);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*'percent'] : 12 #####\n");
	real = printf("|%0*%|\n", 12);
	mine = ft_printf("|%0*%|\n", 12);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*'percent'] : 012 #####\n");
	real = printf("|%0*%|\n", 012);
	mine = ft_printf("|%0*%|\n", 012);
	ft_return_val(mine, real, main);
	printf("##### Tests ['percent'*] #####\n");
	real = printf("|%%*|\n");
	mine = ft_printf("|%%*|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : 10 3 #####\n");
	real = printf("|%*.*%|\n", 10, 3);
	mine = ft_printf("|%*.*%|\n", 10, 3);
	ft_return_val(mine, real, main);
	printf("##### Tests [*'percent'] : 6 #####\n");
	real = printf("|%*%|\n", 6);
	mine = ft_printf("|%*%|\n", 6);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*'percent'] : 6 #####\n");
	real = printf("|%-*%|\n", 6);
	mine = ft_printf("|%-*%|\n", 6);
	ft_return_val(mine, real, main);
	printf("##### Tests [-------------*'percent'] : 6 #####\n");
	real = printf("|%-------------*%|\n", 6);
	mine = ft_printf("|%-------------*%|\n", 6);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.10'percent'] #####\n");
	real = printf("|%10.10%|\n");
	mine = ft_printf("|%10.10%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.1'percent'] #####\n");
	real = printf("|%10.1%|\n");
	mine = ft_printf("|%10.1%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.3'percent'] #####\n");
	real = printf("|%10.3%|\n");
	mine = ft_printf("|%10.3%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0'percent'] #####\n");
	real = printf("|%10.0%|\n");
	mine = ft_printf("|%10.0%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.'percent'] #####\n");
	real = printf("|%10.%|\n");
	mine = ft_printf("|%10.%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests ['percent'] #####\n");
	real = printf("|%%|\n");
	mine = ft_printf("|%%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [-'percent'] #####\n");
	real = printf("|%-%|\n");
	mine = ft_printf("|%-%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [*'percent'] : 6 #####\n");
	real = printf("|%*%|\n", 6);
	mine = ft_printf("|%*%|\n", 6);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*'percent'] : 6 #####\n");
	real = printf("|%-*%|\n", 6);
	mine = ft_printf("|%-*%|\n", 6);
	ft_return_val(mine, real, main);
	printf("##### Tests [-------------*'percent'] : 6 #####\n");
	real = printf("|%-------------*%|\n", 6);
	mine = ft_printf("|%-------------*%|\n", 6);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.10'percent'] #####\n");
	real = printf("|%10.10%|\n");
	mine = ft_printf("|%10.10%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.0'percent'] #####\n");
	real = printf("|%10.0%|\n");
	mine = ft_printf("|%10.0%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [10.'percent'] #####\n");
	real = printf("|%10.%|\n");
	mine = ft_printf("|%10.%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : 10 10 #####\n");
	real = printf("|%*.*%|\n", 10, 10);
	mine = ft_printf("|%*.*%|\n", 10, 10);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : 10 0 #####\n");
	real = printf("|%*.*%|\n", 10, 0);
	mine = ft_printf("|%*.*%|\n", 10, 0);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : 10 1 #####\n");
	real = printf("|%*.*%|\n", 10, 1);
	mine = ft_printf("|%*.*%|\n", 10, 1);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : 10 3 #####\n");
	real = printf("|%*.*%|\n", 10, 3);
	mine = ft_printf("|%*.*%|\n", 10, 3);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : 10 0 #####\n");
	real = printf("|%*.*%|\n", 10, 0);
	mine = ft_printf("|%*.*%|\n", 10, 0);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.'percent'] : 10 #####\n");
	real = printf("|%*.%|\n", 10);
	mine = ft_printf("|%*.%|\n", 10);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.*'percent'] : 10 #####\n");
	real = printf("|%0.*%|\n", 10);
	mine = ft_printf("|%0.*%|\n", 10);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.0'percent'] #####\n");
	real = printf("|%020.0%|\n");
	mine = ft_printf("|%020.0%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [.'percent'] #####\n");
	real = printf("|%.%|\n");
	mine = ft_printf("|%.%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [*'percent'] : -9 #####\n");
	real = printf("|%*%|\n", -9);
	mine = ft_printf("|%*%|\n", -9);
	ft_return_val(mine, real, main);
	printf("##### Tests [0.*'percent'] : -45 #####\n");
	real = printf("|%0.*%|\n", -45);
	mine = ft_printf("|%0.*%|\n", -45);
	ft_return_val(mine, real, main);
	printf("##### Tests [020.*'percent'] : -45 #####\n");
	real = printf("|%020.*%|\n", -45);
	mine = ft_printf("|%020.*%|\n", -45);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : 0 -45 #####\n");
	real = printf("|%*.*%|\n", 0, -45);
	mine = ft_printf("|%*.*%|\n", 0, -45);
	ft_return_val(mine, real, main);
	printf("##### Tests [*.*'percent'] : -45 0 #####\n");
	real = printf("|%*.*%|\n", -45, 0);
	mine = ft_printf("|%*.*%|\n", -45, 0);
	ft_return_val(mine, real, main);

	printf("##### Tests [*.*'percent'] : -45 -45 #####\n");
	real = printf("|%*.*%|\n", -45, -45);
	mine = ft_printf("|%*.*%|\n", -45, -45);
	ft_return_val(mine, real, main);

	printf("##### Tests [020.2'percent'] #####\n");
	real = printf("|%020.2%|\n");
	mine = ft_printf("|%020.2%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [0.0'percent'] #####\n");
	real = printf("|%0.0%|\n");
	mine = ft_printf("|%0.0%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [012'percent'] #####\n");
	real = printf("|%012%|\n");
	mine = ft_printf("|%012%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [*'percent'] : 012 #####\n");
	real = printf("|%*%|\n", 012);
	mine = ft_printf("|%*%|\n", 012);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*'percent'] : 12 #####\n");
	real = printf("|%0*%|\n", 12);
	mine = ft_printf("|%0*%|\n", 12);
	ft_return_val(mine, real, main);
	printf("##### Tests [*'percent'] : 012 #####\n");
	real = printf("|%*%|\n", 012);
	mine = ft_printf("|%*%|\n", 012);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*'percent'] : 12 #####\n");
	real = printf("|%0*%|\n", 12);
	mine = ft_printf("|%0*%|\n", 12);
	ft_return_val(mine, real, main);
	printf("##### Tests [00000-000002'percent'] #####\n");
	real = printf("|%00000-000002%|\n");
	mine = ft_printf("|%00000-000002%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [00000000002'percent'] #####\n");
	real = printf("|%00000000002%|\n");
	mine = ft_printf("|%00000000002%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [.0'percent'] #####\n");
	real = printf("|%.0%|\n");
	mine = ft_printf("|%.0%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [.1'percent'] #####\n");
	real = printf("|%.1%|\n");
	mine = ft_printf("|%.1%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [.2'percent'] #####\n");
	real = printf("|%.2%|\n");
	mine = ft_printf("|%.2%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [.10'percent'] #####\n");
	real = printf("|%.10%|\n");
	mine = ft_printf("|%.10%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [.010'percent'] #####\n");
	real = printf("|%.010%|\n");
	mine = ft_printf("|%.010%|\n");
	ft_return_val(mine, real, main);

	printf("##### Tests [--0--0--00-00-02.10'percent'] #####\n");
	real = printf("|%--0--0--00-00-02.10%|\n");
	mine = ft_printf("|%--0--0--00-00-02.10%|\n");
	ft_return_val(mine, real, main);

	printf("##### Tests [*.5'percent'] : -15 #####\n");
	real = printf("|%*.5%|\n", -15);
	mine = ft_printf("|%*.5%|\n", -15);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.5'percent'] : -15 #####\n");
	real = printf("|%-*.5%|\n", -15);
	mine = ft_printf("|%-*.5%|\n", -15);
	ft_return_val(mine, real, main);
	printf("##### Tests [-150.15'percent'] #####\n");
	real = printf("|%-150.15%|\n");
	mine = ft_printf("|%-150.15%|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [-150.*'percent'] : 15 #####\n");
	real = printf("|%-150.*%|\n", 15);
	mine = ft_printf("|%-150.*%|\n", 15);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.15'percent'] : 150 #####\n");
	real = printf("|%-*.15%|\n", 150);
	mine = ft_printf("|%-*.15%|\n", 150);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.*'percent'] : 150 15 #####\n");
	real = printf("|%-*.*%|\n", 150, 15);
	mine = ft_printf("|%-*.*%|\n", 150, 15);
	ft_return_val(mine, real, main);
	printf("##### Tests [0*.*'percent'] : 5 -5 #####\n");
	real = printf("|%0*.*%|\n", 5, -5);
	mine = ft_printf("|%0*.*%|\n", 5, -5);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.*'percent'] : 10 #####\n");
	real = printf("|%10.*%|\n", 10);
	mine = ft_printf("|%10.*%|\n", 10);
	ft_return_val(mine, real, main);
	printf("##### Tests [10.*'percent'] : -10 #####\n");
	real = printf("|%10.*%|\n", -10);
	mine = ft_printf("|%10.*%|\n", -10);
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("##### Tests [p] #####\n");
	real = printf("|%p|\n", NULL);
	mine = ft_printf("|%p|\n", NULL);
	ft_return_val(mine, real, main);
	printf("##### Tests [p] #####\n");
	real = printf("|%p|\n", str);
	mine = ft_printf("|%p|\n", str);
	ft_return_val(mine, real, main);
	printf("##### Tests [-p] #####\n");
	real = printf("|%-p|\n", str);
	mine = ft_printf("|%-p|\n", str);
	ft_return_val(mine, real, main);
	printf("##### Tests [*p] : 6 #####\n");
	real = printf("|%*p|\n", 6, str);
	mine = ft_printf("|%*p|\n", 6, str);
	ft_return_val(mine, real, main);
	printf("##### Tests [-*p] : 6 #####\n");
	real = printf("|%-*p|\n", 6, str);
	mine = ft_printf("|%-*p|\n", 6, str);
	ft_return_val(mine, real, main);
	printf("##### Tests [-------------*p] : 6 #####\n");
	real = printf("|%-------------*p|\n", 6, str);
	mine = ft_printf("|%-------------*p|\n", 6, str);
	ft_return_val(mine, real, main);
	printf("##### Tests [3p] #####\n");
	real = printf("|%3p|\n", str);
	mine = ft_printf("|%3p|\n", str);
	ft_return_val(mine, real, main);
	printf("##### Tests [10p] #####\n");
	real = printf("|%10p|\n", str);
	mine = ft_printf("|%10p|\n", str);
	ft_return_val(mine, real, main);
	printf("##### Tests [-3p] #####\n");
	real = printf("|%-3p|\n", str);
	mine = ft_printf("|%-3p|\n", str);
	ft_return_val(mine, real, main);
	printf("##### Tests [-10p] #####\n");
	real = printf("|%-10p|\n", str);
	mine = ft_printf("|%-10p|\n", str);
	ft_return_val(mine, real, main);
	printf("##### Tests [-20p] #####\n");
	real = printf("|%-20p|\n", "test");
	mine = ft_printf("|%-20p|\n", "test");
	ft_return_val(mine, real, main);
	printf("##### Tests [*p] : -3 #####\n");
	real = printf("|%*p|\n", -3, str);
	mine = ft_printf("|%*p|\n", -3, str);
	ft_return_val(mine, real, main);
	printf("##### Tests [*p] : -6 #####\n");
	real = printf("|%*p|\n", -6, str);
	mine = ft_printf("|%*p|\n", -6, str);
	ft_return_val(mine, real, main);
	printf("##### Tests [---*p] : 0 test #####\n");
	real = printf("|%---*p|\n", 0, "test");
	mine = ft_printf("|%---*p|\n", 0, "test");
	ft_return_val(mine, real, main);
	printf("##### Tests [*p] : 0 test #####\n");
	real = printf("|%*p|\n", 0, "test");
	mine = ft_printf("|%*p|\n", 0, "test");
	ft_return_val(mine, real, main);
	printf("##### Tests [*p] : 0 9 #####\n");
	real = printf("|%*p|\n", 0, "9");
	mine = ft_printf("|%*p|\n", 0, "9");
	ft_return_val(mine, real, main);
	printf("##### Tests [20.p] : test #####\n");
	real = printf("|%20.p|\n", "test");
	mine = ft_printf("|%20.p|\n", "test");
	ft_return_val(mine, real, main);
	printf("\n##### Tests [*.p] : 0 test #####\n");
	real = printf("|%*.p|\n", 0, "test");
	mine = ft_printf("|%*.p|\n", 0, "test");
	ft_return_val(mine, real, main);
	printf("##### Tests [*.p] : 0 NULL #####\n");
	real = printf("|%*.p|\n", 0, NULL);
	mine = ft_printf("|%*.p|\n", 0, NULL);
	ft_return_val(mine, real, main);
	printf("##### Tests [.p] : NULL #####\n");
	real = printf("|%.p|\n", NULL);
	mine = ft_printf("|%.p|\n", NULL);
	ft_return_val(mine, real, main);
	printf("##### Tests [*p] : 0 NULL #####\n");
	real = printf("|%*p|\n", 0, NULL);
	mine = ft_printf("|%*p|\n", 0, NULL);
	ft_return_val(mine, real, main);
	printf("##### Tests [54p] : NULL #####\n");
	real = printf("|%54p|\n", NULL);
	mine = ft_printf("|%54p|\n", NULL);
	ft_return_val(mine, real, main);
	printf("##### Tests [*p] : 20 afiojfjadsifjaiosjf #####\n");
	real = printf("|%*p|\n", 20, "afiojfjadsifjaiosjf");
	mine = ft_printf("|%*p|\n", 20, "afiojfjadsifjaiosjf");
	ft_return_val(mine, real, main);
	printf("##### Tests [*.p] : -15 oui #####\n");
	real = printf("|%*.p|\n", -15, "oui");
	mine = ft_printf("|%*.p|\n", -15, "oui");
	ft_return_val(mine, real, main);
	printf("##### Tests [-*.p] : -15 oui #####\n");
	real = printf("|%-*.p|\n", -15, "oui");
	mine = ft_printf("|%-*.p|\n", -15, "oui");
	ft_return_val(mine, real, main);

	printf("##### Tests [20.p] #####\n");
	real = printf("|%20.p|\n", NULL);
	mine = ft_printf("|%20.p|\n", NULL);
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");
	printf("##### Tests [s d p x X i u c] : bonjour, 50, bonjour, 168, -168, 54, 87, c #####\n");
	real = printf("|%s %d %p %x %X %i %u %c|\n", "bonjour", 50, "bonjour", 168, -168, 54, 87, 'c');
	mine = ft_printf("|%s %d %p %x %X %i %u %c|\n", "bonjour", 50, "bonjour", 168, -168, 54, 87, 'c');
	ft_return_val(mine, real, main);
	printf("##### Tests ['percent's'percent''percent'] : coucou #####\n");
	real = printf("|%s%%|\n", "coucou");
	mine = ft_printf("|%s%%|\n", "coucou");
	ft_return_val(mine, real, main);
	printf("##### Tests [54s 48c tg 50.d] : coucou k 184 #####\n");
	real = printf("|%54s %48c tg %50.d|\n", "coucou", 'k', 184);
	mine = ft_printf("|%54s %48c tg %50.d|\n", "coucou", 'k', 184);
	ft_return_val(mine, real, main);
	printf("##### Tests [48c 54s tg 50.d] : k coucou 184 #####\n");
	real = printf("|%48c %54s tg %50.d|\n", 'k', "coucou", 184);
	mine = ft_printf("|%48c %54s tg %50.d|\n", 'k', "coucou", 184);
	ft_return_val(mine, real, main);
	printf("##### Tests [***] #####\n");
	real = printf("|***|\n");
	mine = ft_printf("|***|\n");
	ft_return_val(mine, real, main);
	printf("##### Tests [...] #####\n");
	real = printf("|...|\n");
	mine = ft_printf("|...|\n");
	ft_return_val(mine, real, main);

	printf("\033[1;31m#######################################\033[0m\n\n\n");

	printf("\n\n\nT'AS %d BONNES REPONSES / %d TESTS", main->count, main->count2);

	while (1) {}
	return(0);
}

int	main(int ac, char **av)
{
  int	ret[2];
  char	*str = "astek";
  char	stre[] = {'a', 's', 10, 'e', 'k', 0};

  printf("##### Tests simple : 1 point par test reussi #####\n");
  printf(   "0) Modulo [%%] : {%%}\n");
  ft_printf("=> Modulo [%%] : {%%}\n");
  printf(   "1) Nombre signe [d] : {%d}\n", 42);
  ft_printf("=> Nombre signe [d] : {%d}\n", 42);
  printf(   "2) Nombre signe [i] : {%i}\n", 42);
  ft_printf("=> Nombre signe [i] : {%i}\n", 42);
  printf(   "3) Nombre octal [o] : {%o}\n", 012345);
  ft_printf("=> Nombre octal [o] : {%o}\n", 012345);
  printf(   "4) Nombre non signe [u] : {%u}\n", 42);
  ft_printf("=> Nombre non signe [u] : {%u}\n", 42);
  printf(   "5) Nombre hexadecimal [x] : {%x}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
  printf(   "6) Nombre hexadecimal [X] : {%X}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
  printf(   "7) Nombre binaire [b] : {101111101111110000001}\n");
  ft_printf("=> Nombre binaire [b] : {%b}\n", 1564545);
  printf(   "8) Caractere [c] : {%c}\n", 42);
  ft_printf("=> Caractere [c] : {%c}\n", 42);
  printf(   "9) Chaine [s] : {%s}\n", str);
  ft_printf("=> Chaine [s] : {%s}\n", str);
  printf(   "10) Chaine etendue [S] : as\\012ek\n");
  ft_printf("=>  Chaine etendue [S] : %S\n", stre);
  printf(   "11) Pointeur [p] : {%p}\n", str);
  ft_printf("=>  Pointeur [p] : {%p}\n", str);
  printf(   "12) Mauvais parametre [k] : {%k}\n", 42);
  ft_printf("=>  Mauvais parametre [k] : {%k}\n", 42);

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("\n##### Tests pour verifier : -1pt par resultat errone #####\n");
  printf(   "1) Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  printf(   "2) Affichage multiple [d d d] : {%d} {%d} {%ld}\n", -0, -42, -2147483648);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%ld}\n", -0, -42, -2147483648);
  printf(   "3) Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  ft_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  printf(   "4) Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  ft_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  printf(   "5) Affichage multiple [s S X] : {%s} {as\\012ek} {%X}\n", str, -1);
  ft_printf("=> Affichage multiple [s S X] : {%s} {%S} {%X}\n", str, stre, -1);
  printf(   "5) Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  ft_printf("=> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  printf(   "6) Affichage long [s S s ...] : %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek\n", str, str, str, str, str, str);
  ft_printf("=> Affichage long [s S s ...] : %s %S %s %S %s %S %s %S %s %S %s %S\n", str, stre, str, stre, str, stre, str, stre, str, stre, str, stre);

  printf("Appuyez sur une touche pour continuer...\n");
  getchar();

  printf("\n##### Formatage : 1pt pour 3 tests reussis  #####\n");
  printf(   "1) Formatage simple [#d] : {%#d}\n", 42);
  ft_printf("=> Formatage simple [#d] : {%#d}\n", 42);
  printf(   "2) Formatage simple [#x] : {%#x}\n", 0x12345);
  ft_printf("=> Formatage simple [#x] : {%#x}\n", 0x12345);
  printf(   "3) Formatage simple [#o] : {%#o}\n", 012345);
  ft_printf("=> Formatage simple [#o] : {%#o}\n", 012345);
  printf(   "4) Formatage simple [0d] : {%0d}\n", 42);
  ft_printf("=> Formatage simple [0d] : {%0d}\n", 42);
  printf(   "5) Formatage simple [5d] : {%5d}\n", 42);
  ft_printf("=> Formatage simple [5d] : {%5d}\n", 42);
  printf(   "6) Formatage simple [ d] : {% d}\n", 42);
  ft_printf("=> Formatage simple [ d] : {% d}\n", 42);
  printf(   "7) Formatage simple [-d] : {%-d}\n", 42);
  ft_printf("=> Formatage simple [-d] : {%-d}\n", 42);
  printf(   "8) Formatage simple [+d] : {%+d}\n", 42);
  ft_printf("=> Formatage simple [+d] : {%+d}\n", 42);
  printf(   "9) Formatage simple [+d] : {%+d}\n", -42);
  ft_printf("=> Formatage simple [+d] : {%+d}\n", -42);
  printf(   "10) Formatage multiple [ 5d] : {% 5d}\n", 42);
  ft_printf("=>  Formatage multiple [ 5d] : {% 5d}\n", 42);
  printf(   "11) Formatage multiple [-32o] : {%-32o}\n", 012345);
  ft_printf("=>  Formatage multiple [-32o] : {%-32o}\n", 012345);
  printf(   "12) Formatage multiple [-10+d] : {%+-10d}\n", 12345);
  ft_printf("=>  Formatage multiple [-10+d] : {%-10+d}\n", 12345);
  printf(   "13) Formatage compose [-5cP] : %-5cP\n", 42);
  ft_printf("=>  Formatage compose [-5cP] : %-5cP\n", 42);
  printf(   "14) Formatage compose [-30sP]: %-30sP\n", str);
  ft_printf("=> Formatage compose [-30sP]: %-30sP\n", str);
  printf(   "15) Formatage compose [-4SP] : as\\012ekP\n");
  ft_printf("=>  Formatage compose [-4SP] : %-4SP\n", stre);
  printf(   "16) Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  ft_printf("=>  Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  printf(   "17) Formatage ultracompose [#15.12b] : {101111101111110000001}\n");
  ft_printf("=>  Formatage ultracompose [#15.12b] : {%#15.12b}\n", 1564545);
  printf(   "18) Formatage ultracompose [#-6.3d] : {%#-6.3ld}\n", -2147483648);
  ft_printf("=>  Formatage ultracompose [#-6.3d] : {%#-6.3ld}\n", -2147483648);
  printf(   "19) Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  ft_printf("=>  Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  printf(   "20) Formatage pourcent [30%%] : {%30%}\n");
  ft_printf("=>  Formatage pourcent [30%%] : {%30%}\n");
  printf(   "21) Formatage pourcent [-30pourcent] : {%-30%}\n");
  ft_printf("=>  Formatage pourcent [-30pourcent] : {%-30%}\n");
  ret[0] = printf(   "22) Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  ret[1] = ft_printf("=>  Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  printf(   "23) Verification de la valeur de retour [d] : {%d}\n", ret[0]);
  ft_printf("=>  Verification de la valeur de retour [d] : {%d}\n", ret[1]);
  printf(   "24) Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
  ft_printf("=>  Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);

  ft_printf("Segmentation fault ;)\n");

  while (1) {}
  return(0);
}*/
