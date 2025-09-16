/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:15:59 by frocha-b          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:55 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MAX_PID 4194304 

//Minitalk standard libraries
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>

//Libft
# include "../libft/libft.h"

//Minitalk functions
void	exit_error(char *message);

#endif