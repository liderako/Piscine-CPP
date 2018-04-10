#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>

class Convert {
	private:
		char	a;
		int		b;
		float 	c;
		double 	d;
	public:
		Convert();
		~Convert();
		void run(std::string s);
	private:
		void 	printChar(std::string);
		void 	printInt(std::string s);
		void	printDouble(std::string s);
		void	printFloat(std::string s);
		int 	getLenDecimals(std::string s);
};

#endif