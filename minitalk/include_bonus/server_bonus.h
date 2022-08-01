/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgi <sgi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:37 by sgi               #+#    #+#             */
/*   Updated: 2022/07/15 18:26:07 by sgi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void		transmit(int sig, siginfo_t *info, void *uap);

#endif
