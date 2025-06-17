/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:03 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/10 17:13:29 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


// void	bits_to_string(int *bits_array)
// {
// 	static int i = 0;
// 	static char *string;
	
// 	while (!bits_array_is_null(bits_array))
// 	{
		
// 	}
	
	
// }
void	handler(int signal)
{
	static int 	i = 0;
	static int bits_array [8];
	
	while (i < 8)
	{
		if (signal == SIGUSR1)
		{
			bits_array[i++] = 0;
			ft_printf("bit 0 recebido\n");
		}
		else 
		{
			bits_array[i++] = 1;
			ft_printf("bit 1 recebido\n");
		}
	}
	// bits_to_string(bits_array);
	i = 0;
}
int main(void)
{
	int pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}