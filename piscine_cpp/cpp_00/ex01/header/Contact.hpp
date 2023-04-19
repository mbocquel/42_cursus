/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:44:35 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/19 15:56:05 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
private:
	std::string	_phone;
	std::string _secret;
	std::string _firstname;
	std::string _lastname;
	std::string	_nickname;
	
public:
	Contact(void);
	~Contact(void);
	void	set_contact(void);
	void	display_contact(void);
	std::string	get_info(std::string info);
};

#endif