#include <iostream>
#include "StackType.h"

void ReplaceItem(StackType &stack, int olditem, int newitem) {
	StackType copy;
	while (!(stack.IsEmpty())) {
		if (stack.Top() == olditem) {
			copy.Push(newitem);
			stack.Pop();
		}
		else {
			copy.Push(stack.Top());
			stack.Pop();
		}
	}
	while (!(copy.IsEmpty())) {
		stack.Push(copy.Top());
		copy.Pop();
	}
}

void StackType::ReplaceItem(int olditem, int newitem) {
	for (int i = 0; i < (sizeof(items)/sizeof(int)); i++) {
		if (items[i] == olditem) {
			items[i] = newitem;
		}
	}
}

void Print(StackType stack) {
	while (!(stack.IsEmpty())) {
		std::cout << stack.Top() << std::endl;
		stack.Pop();
	}
}



int main() {
	StackType stack;
	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3);
	//���� �ڵ� - ReplaceItem�� �ϳ��� Ȱ��ȭ��Ű�� Print �Լ��� Ȱ��ȭ���� ����� Ȯ�����ּ���.
	//ReplaceItem(stack, 3, 5);
	//stack.StackType::ReplaceItem(3, 5);
	//Print(stack);
}