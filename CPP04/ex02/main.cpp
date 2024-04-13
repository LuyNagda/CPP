/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:22:11 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/13 16:21:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	//const Animal* meta = new Animal();
	Dog* k = new Dog();
	Dog* j = new Dog();
	//const Animal* i = new Cat();
	//const WrongAnimal* wrong = new WrongAnimal();
	//const WrongAnimal* wrong2 = new WrongCat();
	
	//std::cout << "Should be a cat: " << i->getType() << " " << std::endl;
	//std::cout << "Should be a dog: " << j->getType() << " " << std::endl;
	//std::cout << "Should be a wrongcat: " << wrong2->getType() << " " << std::endl;
	//std::cout << "Should be a empty cause it's an animal: " << meta->getType() << " " << std::endl;
	//std::cout << "Should be a empty cause it's an wronganimal: " << wrong->getType() << " " << std::endl;
	
	//i->makeSound(); //will output the cat sound!
	//j->makeSound(); //will output the dog sound!
	//wrong2->makeSound(); //will output the wrongcat sound!
	//meta->makeSound(); //will output the animal sound!
	//wrong->makeSound(); //will output the wronganimal sound!

	std::cout << "////" << std::endl;
	*k = *j;
	delete k;
	delete j;
	//delete i;
	//delete j;
	//delete meta;
	//delete wrong;
	//delete wrong2;

	return 0;
}
