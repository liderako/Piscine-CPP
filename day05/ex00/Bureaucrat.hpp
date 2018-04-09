#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Bureaucrat {
	private:
		std::string const 	name;
		int 				grade;

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const & f);
				~GradeTooHighException() throw();
				GradeTooHighException & operator=(GradeTooHighException const & f);
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException  const & f);
				~GradeTooLowException() throw();
				GradeTooLowException  & operator=(GradeTooLowException  const & f);
				virtual const char *what() const throw();
		};

	public:
		Bureaucrat(); /* canonical */
		Bureaucrat(Bureaucrat const & f); /* canonical */
		Bureaucrat(std::string const name, int const grade);
		~Bureaucrat(); /* canonical */

		/* gets */
		std::string 	getName() const;
		int 			getGrade() const;

		/* operator */
		Bureaucrat & operator=(Bureaucrat const & f);
		void 			operator+=(int num);
		void 			operator-=(int num);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b);

#endif