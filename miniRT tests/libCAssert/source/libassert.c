/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libassert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:00:15 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/22 17:42:00 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libassert.h"

t_inst	init_instance_default(t_inst *self)
{
	t_inst	dflt;

	dflt = (t_inst){\
		.title = {DEFAULT_T_TEXT, DEFAULT_T_COLOR}, \
		.desc = {DEFAULT_D_TEXT, DEFAULT_D_COLOR}, \
		.ok = {DEFAULT_O_TEXT, DEFAULT_O_COLOR}, \
		.ko = {DEFAULT_K_TEXT, DEFAULT_K_COLOR}, \
		.comp_type = EQUAL \
	};
	if (self == NULL)
		return (dflt);
	*self = dflt;
	return (*self);
}

t_inst	set_instance(t_inst *self, t_text infos[4], t_comp comp)
{
	t_inst	temp;

	temp.title = infos[0];
	temp.desc = infos[1];
	temp.ok = infos[2];
	temp.ko = infos[3];
	temp.comp_type = comp;
	if (self == NULL)
		return (temp);
	self[0] = temp;
	return (self[0]);
}
