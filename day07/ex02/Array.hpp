#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class 	Array {
	public:
		T 		*array;
		size_t 	len;
		class OutLimits : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Element is out of the limits\n";
				}
		};
	public:
		Array<T>() {
			this->array = new T[0];
			this->len = 0;
		}
		Array<T>(Array<T> const & src) {
			*this = src;
		}
		Array<T>(unsigned int n) {
			this->array = new T[n];
			this->len = n;
			for (int i = 0; i < n; i++ {
				this->array[i] = T();
			}
		}
	Array<T> & operator=(Array<T> const & f) {
		delete [] this->array;
		this->len = f.len;
		this->array = new T[this->len];
		for (int i = 0; i < this->len; i++) {
			this->array[i] = f.array[i];
		}
		return (*this);
	}
	T & operator[](size_t i) {
		if (i > this->len) {
			throw OutLimits();
		}
		return (array[i]);
	}
	size_t 	size() const {
		return (this->len);
	}
};

#endif
