/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:38:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/19 17:06:35 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
private:
	Contact _tab_contact[8];
	int		_index;
	int		_nb_contact;
	void	_print_info_contact(int index);
	
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact();
	void	search();
};

#endif