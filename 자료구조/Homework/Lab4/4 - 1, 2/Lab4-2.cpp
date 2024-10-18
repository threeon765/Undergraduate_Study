#include "StackTType.h"
#include "MaxItem.h"
#include <iostream>

int main() {
	StackType<int> stackA;
	StackType<int> stackB;
	StackType<int> stackC;

	stackA.Push(9);
	stackA.Push(8);
	stackA.Push(4);
	stackA.Push(7);
	stackA.Push(5);
	stackA.Push(3);

	stackC.Push(stackA.Top());
	stackA.Pop();
	stackC.Push(stackA.Top());
	stackA.Pop();
	stackC.Push(stackA.Top());
	stackA.Pop();
	stackC.Push(stackA.Top());
	stackA.Pop();
	stackC.Push(stackA.Top());
	stackA.Pop();
	stackC.Push(stackA.Top());
	stackA.Pop();

	stackA.Push(stackC.Top());
	stackB.Push(stackC.Top());
	stackC.Pop();
	stackA.Push(stackC.Top());
	stackB.Push(stackC.Top());
	stackC.Pop();
	stackA.Push(stackC.Top());
	stackB.Push(stackC.Top());
	stackC.Pop();
	stackA.Push(stackC.Top());
	stackB.Push(stackC.Top());
	stackC.Pop();
	stackA.Push(stackC.Top());
	stackB.Push(stackC.Top());
	stackC.Pop();
	stackA.Push(stackC.Top());
	stackB.Push(stackC.Top());
	stackC.Pop();

/*	������ ���� ��� �ڵ�
	std::cout << stackA.Top() << std::endl;
	stackA.Pop();
	std::cout << stackA.Top() << std::endl;
	stackA.Pop();
	std::cout << stackA.Top() << std::endl;
	stackA.Pop();
	std::cout << stackA.Top() << std::endl;
	stackA.Pop();
	std::cout << stackA.Top() << std::endl;
	stackA.Pop();
	std::cout << stackA.Top() << std::endl;
	stackA.Pop();

	std::cout << stackB.Top() << std::endl;
	stackB.Pop();
	std::cout << stackB.Top() << std::endl;
	stackB.Pop();
	std::cout << stackB.Top() << std::endl;
	stackB.Pop();
	std::cout << stackB.Top() << std::endl;
	stackB.Pop();
	std::cout << stackB.Top() << std::endl;
	stackB.Pop();
	std::cout << stackB.Top() << std::endl;
	stackB.Pop();
*/
}