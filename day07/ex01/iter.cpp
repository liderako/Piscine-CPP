#include <iostream>

template<typename T>
void 	iter(T *a, size_t size, void (*f)(T)) {
	for (size_t i = 0; i < size; i++) {
		f(a[i]);
	}
}

template<typename T>
void 	test(T t) {
	std::cout << t << std::endl;
}

int 	main(void) {
	char a[] = "anton";
	int  b[] = {1, 141, 141, 0, 1, 5};
	float  c[] = {1.123, 141.31213, 141.01, 0.12313, 1.00005, 5.23131};
	std::string  s[] = {"asda", "asvirido"};
	::iter(a, 5, ::test);
	::iter(b, 6, ::test);
	::iter(c, 6, ::test);
	::iter(s, 2, ::test);
	return (0);
}