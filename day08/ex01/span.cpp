#include "span.hpp"
#include <numeric>

Span::Span() {
	this->n = 0;
}

Span::Span(Span const & f) {
	*this = f;
}

Span::Span(size_t n) {
	this->n = n;
}

Span::~Span() {}

Span & Span::operator=(Span const & f) {
	this->n = f.n;
	this->container.clear();
	for (size_t i = 0; i < f.n; ++i) {
		this->container.push_back(f.container[i]);
	}
	return (*this);
}
// gets

size_t 	Span::getNumber(size_t i) {
	if (i < this->n) {
		return (this->container[i]);
	}
	return (-1);
}

size_t 	Span::getSize() {
	return (this->n);
}

// actions

void 	Span::addNumber(int x){
	if (this->countAddNumber == n) {
		throw Full();
	}
	container.push_back(x);
	this->countAddNumber++;
}

size_t 	Span::longestSpan() {
	std::vector<int> tmp = this->container;
	if (this->countAddNumber <= 1) {
		throw SmallContainer();
	}
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator begin = tmp.begin();
	std::vector<int>::iterator end = tmp.end() - 1;
	return (*end - *begin);
}

size_t 	Span::shortestSpan() {
	std::vector<int> tmp = this->container;
	if (this->countAddNumber <= 1) {
		throw SmallContainer();
	}
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	std::sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); ++i)
	{
		std::cout << tmp[i] << std::endl;
	}
	std::cout << "dasdad\n";
	// std::vector<int>::iterator end = tmp.begin() + this->container.size() + 1;
	std::cout << "END " << *end << std::endl; 
	return (-1);
}

/*
* 	Exceptions
*/

Span::Full::Full() {}

Span::Full::Full(Full const & f) {
	*this = f;
}

Span::Full::~Full() throw() {}

Span::Full & Span::Full::operator=(Span::Full const &) {
	return (*this);
}

const char * Span::Full::what() const throw() {
	return ("container is full");
}


Span::SmallContainer::SmallContainer() {}

Span::SmallContainer::SmallContainer(SmallContainer const & f) {
	*this = f;
}

Span::SmallContainer::~SmallContainer() throw() {}

Span::SmallContainer & Span::SmallContainer::operator=(Span::SmallContainer const &) {
	return (*this);
}

const char * Span::SmallContainer::what() const throw() {
	return ("container is small");
}