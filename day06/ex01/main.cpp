#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

struct SerData {
	char 	s1[8];
	int n;
	char	s2[8];
};

void 	randomstring(char *s) {
	int i = 0;
	while (i < 8) {
		char c = 0;
		while (1) {
			c = static_cast<char>(rand() % 78 + 48);
			if (isalnum(c) != 0 && (c >= 32) && (c <= 126))
				break ;
		}
		s[i] = c;
		i++;
	}
	s[i] = '\0';
}

void * serialize(void) {
	SerData *data = new SerData;
	randomstring(data->s1);
	data->n = rand() % 3;
	randomstring(data->s2);
	// std::cout << data->s1 << std::endl;
	// std::cout << data->n << std::endl;
	// std::cout << data->s2 << std::endl;
	return (reinterpret_cast<void*>(data));
}

Data 	*deserialize( void * raw ) {
	Data *data = new Data();
	SerData  *ser;

	ser = reinterpret_cast<SerData*>(raw);
	data->s1 = static_cast<std::string>(ser->s1);
	data->s2 = static_cast<std::string>(ser->s2);
	data->n = ser->n;
	return (data);	
}

int 	main(void) {
	void * tmp;
	Data * data;
	std::srand(std::time(0));

	tmp = serialize();
	std::cout << tmp << std::endl;
	data = deserialize(tmp);
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
}