/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:39:14 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/15 11:42:42 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

class Base
{
public:
	virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif