/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:43:33 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/26 10:59:29 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>

class RPN
{
private:
	std::stack<int>	_my_stack;
	static bool		_verbose;
	
public:
	RPN(void);
	RPN(RPN const & copy);
	~RPN(void);
	
	RPN & 	operator=(RPN const & rpn);

	void	rpn_add(std::string elem);
	int		result(void) const;

	class rpn_error : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif