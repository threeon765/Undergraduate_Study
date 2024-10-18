#include "QueType.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0))); //�ǽ� 5-1
	auto a = QueType(10);
	auto b = QueType(10);
	auto c = QueType(11);
	for (int i = 0; i < 10; i++) {
		int random = std::rand() % 10;
		std::cout << random << " ";
		a.Enqueue(random);
		b.Enqueue(random);
		c.Enqueue(random);
	}
	c.Enqueue(std::rand() % 10);
	std::cout << std::endl;

	
	ReplaceItem(a, 5, 7); //�ǽ� 5-2 ����
	b.ReplaceItem(5, 7); //������ �� 5�� ���� ��쿡�� �ڵ� ������ �����մϴ�
	c.ReplaceItem(5, 7);

	
	if (Identical(a, b) == 0) { //�ǽ� 5-3 ����
		std::cout << "a & b not identical" << std::endl;
	}
	else {
		std::cout << "a & b indentical" << std::endl;
	}
	if (a.Identical(c) == 0) { 
		std::cout << "a & c not identical" << std::endl;
	}
	else {
		std::cout << "a & c indentical" << std::endl;
	}
	
	
	std::cout << Length(a) << std::endl; //�ǽ� 5-4 ����

	int print; //�ǽ� 5-1
	for (int i = 0; i < 10; i++) {
		a.Dequeue(print);
		std::cout << print << " ";
	}
	std::cout << std::endl;
	b.MinDequeue(print); //�ǽ� 5-6 ����
	b.Enqueue(8);
	for (int i = 0; i < 10; i++) {
		b.Dequeue(print);
		std::cout << print << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 11; i++) {
		c.Dequeue(print);
		std::cout << print << " ";
	}
}