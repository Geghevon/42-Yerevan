/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:24:53 by geghevon          #+#    #+#             */
/*   Updated: 2022/07/05 21:31:17 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		format(va_list argc, const char format);
int		ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int c);
int		ft_percent(void);
int		ft_ptr(unsigned long long p);
void	ft_putchar_fd(char c, int fd);
int		ft_hex(unsigned int n, const char format);
void	ft_puthex(unsigned int n, const char format);
int		ft_hexlen(unsigned int n);
int		ft_numlen(unsigned int c);
char	*ft_unsigned_itoa(unsigned int c);
int		ft_unsigned_int(unsigned int c);
char	*ft_itoa(int n);
int		ft_len(int n);
#endif
