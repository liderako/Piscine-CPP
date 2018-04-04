#include <iostream>
#include "Pony.hpp"

int main(void)
{
	Pony heap = Pony("stack", "Hi, my name is ");
	Pony *stack = new Pony("heap", "Hi, my name is ");

	heap.ponyOnTheHeap();
	stack->ponyOnTheStack();
	delete stack;
}
