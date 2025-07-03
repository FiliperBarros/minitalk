/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:03 by frocha-b          #+#    #+#             */
/*   Updated: 2025/07/01 16:33:05 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*create_char_str(char c)
{
	char *str;
	
	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
void	print_message(char c)
{
	static char *new_str;
	char *char_str;
	char *temp;
	
	if (!new_str)
		new_str = calloc(1, 1);
	if (c == 0)
	{
		ft_printf("%s\n", new_str);
		free(char_str);
		free(new_str);
		return ;
	}
	char_str = create_char_str(c);
	temp = new_str;
	temp = ft_strjoin(new_str, char_str);
	ft_printf("after strjoin:%s\n", temp);
	if (!temp)
	{
		free(new_str);
		return ;
	}
	new_str = temp;
}
void	handler(int signal)
{	
	static int 	i = 0;
	static int 	c = 0;
	int 	bit = 0;
	
	if (signal == SIGUSR2)
		bit = 1;
	c = (c << 1) | bit;    
	i++;
	if (i == 8)
	{
		print_message((char)c);
		i = 0;
		c = 0;
	}
}
int main(void)
{
	int pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler);
		pause();
	}
	return (0);
}