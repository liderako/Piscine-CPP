#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("defauld") {
	this->grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat const & Bureaucrat) {
	*this = Bureaucrat;
}

Bureaucrat::Bureaucrat(std::string const _name, int const grade) : name(_name) {
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & f) {
	this->grade = f.getGrade();
	return *this;
}

int 	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

std::string 	Bureaucrat::getName(void) const {
	return (this->name);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b) {
	return (o << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">\n");
}


/* math */
void 	Bureaucrat::operator+=(int num) {
	try {
		if ((this->grade - num) < 1) {
			throw Bureaucrat::GradeTooLowException();
		}
		this->grade-=num;
	}
	catch(std::exception &e) {
		std::cout << e.what() << "\n";
	}
}

void 	Bureaucrat::operator-=(int num){
	try {
		if ((this->grade + num) > 150) {
			throw Bureaucrat::GradeTooHighException();
		}
		this->grade+=num;
	}
	catch(std::exception &e) {
		std::cout << e.what() << "\n";
	}
}



Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & f) {
	*this = f;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &) {
	return (*this);
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: GradeTooHighException");
}


Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & f) {
	*this = f;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &) {
	return (*this);
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: GradeTooLowException");
}