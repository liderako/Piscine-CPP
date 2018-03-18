#include <iostream>

int 	main( int argc, char **argv ) {
	int j;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < argc; i++) {
			j = 0;
			while (argv[i][j]) {
				if (argv[i][j] >= 97 && argv[i][j] <= 122)
					argv[i][j] -= 32;
				std::cout << argv[i][j];
				j++;
			}
		}
		std::cout << '\n';
	}
}
