#include "Human.hpp"

void Human::meleeAttack(std::string const & target) {
	std::cout << "meleeAttack " << target << std::endl;
}
void Human::rangedAttack(std::string const & target) {
	std::cout << "rangedAttack " << target << std::endl;
}
void Human::intimidatingShout(std::string const & target) {
	std::cout << "intimidatingShout " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {
	typedef void (Human::*arrrayAction)(std::string const & target);

	std::string list[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	arrrayAction actions[] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

	for (int i = 0; i < 3; ++i) {
		if (list[i].compare(action_name) == 0)
			(this->*actions[i])(target);
	}
}