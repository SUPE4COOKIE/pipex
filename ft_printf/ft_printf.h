/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:50:50 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/12/10 08:02:51 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define UP_HEXA "0123456789ABCDEF"
# define LOW_HEXA "0123456789abcdef"

int	ft_printf(const char *s, ...);
int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printhexa(unsigned long long n, char *base, int count);
int	ft_printint(long int n, int count);
int	ft_printuint(unsigned int n, int count);
int	ft_printptr(unsigned long long i);
#endif