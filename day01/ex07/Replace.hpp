/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:44:59 by asvirido          #+#    #+#             */
/*   Updated: 2018/04/02 20:45:00 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REPLACE_HPP
# define REPLACE_HPP
#include <iostream>
#define NO 18446744073709551615
class 	Replace {
	private:
		std::string fileName;
		std::string createFileName;
		std::string s1;
		std::string s2;
	public:
		Replace(void);
		Replace(std::string s1, std::string s2, std::string fileName);
		~Replace(void);

		void setS1(std::string s);
		void setS2(std::string s);
		void setFileName(std::string fileName);
		std::string getS1(void);
		std::string getS2(void);
		std::string getFileName(void);
		std::string getCreateFileName(void);
		void 		validation(void);
};

#endif