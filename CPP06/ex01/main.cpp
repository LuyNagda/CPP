/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:18:24 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/17 14:20:27 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->name = "Luy";
	data->age = 24;
	data->surname = "Nagda";

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->name << std::endl;
	std::cout << serialized->age << std::endl;
	std::cout << serialized->surname << std::endl;

	delete data;
	return (0);
}