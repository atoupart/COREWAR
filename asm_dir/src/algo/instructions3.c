/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:56:30 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:56:32 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			zjmp(t_tool *tool, int instr, int total)
{
	char	*str;

	tool->spec = 4;
	str = tool->instr[instr] + 4;
	write_dir(tool, str, total);
	return (2);
}

int			ldi(t_tool *tool, int instr, int total)
{
	int		nbw;
	char	*str;
	int		i;

	nbw = print_fd(tool, tool->ocp[instr]);
	str = tool->instr[instr] + 3;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		tool->spec = 4;
		if (str[i] == 'r' && (nbw += write_reg(tool, str + i + 1)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		else if (str[i] == '%' && (nbw +=
			write_dir(tool, str + i, total)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		else if (((str[i] == ':' || str[i] == '-' || ft_isdigit(str[i]))
			&& (str[i - 1] != '%' || str[i - 1] != 'r')) && (tool->spec = 4)
			&& (nbw += write_ind(tool, str + i, total)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		i++;
	}
	return (nbw);
}

int			sti(t_tool *tool, int instr, int total)
{
	int		nbw;
	char	*str;
	int		i;

	nbw = print_fd(tool, tool->ocp[instr]);
	str = tool->instr[instr] + 3;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		tool->spec = 4;
		if (str[i] == 'r' && (nbw += write_reg(tool, str + i + 1)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		else if (str[i] == '%' && (nbw +=
			write_dir(tool, str + i, total)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		else if (((str[i] == ':' || str[i] == '-' || ft_isdigit(str[i]))
			&& (str[i - 1] != '%' || str[i - 1] != 'r')) && (tool->spec = 4)
			&& (nbw += write_ind(tool, str + i, total)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		i++;
	}
	return (nbw);
}

int			i_fork(t_tool *tool, int instr, int total)
{
	char	*str;

	tool->spec = 4;
	str = tool->instr[instr] + 4;
	write_dir(tool, str, total);
	return (2);
}