#include <iostream>

template<typename T>
void 	iter(T *a, size_t size, void (*f)(T)) {
	for (size_t i = 0; i < size; i++) {
		f(a[i]);
	}
}

template<typename T>
void 	test(T t) {
	std::cout << t;
}

int 	main(void) {
	std::string a = "anton";
	::iter(a, a.length(), ::test);
	return (0);
}
