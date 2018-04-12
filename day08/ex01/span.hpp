#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
	private:
		size_t 	n;
		std::vector<int> 	container;
		size_t	countAddNumber;
		class Full : public std::exception {
			public:
				Full();
				Full(Full const & f);
				~Full() throw();
				Full & operator=(Full const & f);
				virtual const char * what() const throw();
		};
		class SmallContainer : public std::exception {
			public:
				SmallContainer();
				SmallContainer(SmallContainer const & f);
				~SmallContainer() throw();
				SmallContainer & operator=(SmallContainer const & f);
				virtual const char * what() const throw();
		};
	public:
		Span();
		Span(Span const & f);
		Span(size_t n);
		~Span();
		Span & operator=(Span const & f);
// actions
	void 	addNumber(int x);
	size_t 	longestSpan();
	size_t 	shortestSpan();
// test
	size_t 	getNumber(size_t i);
	size_t 	getSize();
};

#endif