/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:56:52 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/23 10:24:42 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbrhex(unsigned int nbr, const char c);
int		ft_putptr(void *nbr);
int		ft_uitoa(unsigned int nbr);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);

#endif