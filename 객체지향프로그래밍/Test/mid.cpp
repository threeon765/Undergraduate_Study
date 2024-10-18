/*             Object-Oriented Programming, Midterm exam (2024-1, CSE103-00)                       */
#include <iostream>
#include <vector>

// ��� �ڵ� (�Լ�) �ۼ� ����
double Ex1(int a, int b) {
	double c = (b == 0) ? 0 : static_cast<double>(a) / static_cast<double>(b);
	return c;
}
void Ex2(int a, int b, int* c, int& d) {
	if ((a < 1) || (b < 1)) {
		c = 0;
		d = 0;
	}
	for (int i = 1; i <= std::min(a, b); i++) {
		if (((a % i) == 0) && ((b % i) == 0)) {
			*c = i;
			d++;
		}
	}
}
double Ex3(long double a) {
	long double sign = 1, upper = a, lower = 1, plus = 0, sine = a;
	for (int i = 1;; i++) {
		if (fabs(plus) <= 1.E-15) {
			break;
		}
		upper *= (a * a);
		for (int k = 1; k <= (2 * i) + 1; k++) {
			lower *= k;
		}
		sign *= (-1);
		plus = sign * upper / lower;
		sine += plus;
	}
	return sine;
}
int Ex4(int a, int b, int c = 0) {
	if (a > 0xFF) {
		Ex4(a - 0xF00, b, 0);
	}
	if (b > 0xFF) {
		Ex4(a, b - 0xF00, 0);
	}
	if (a <= 0xFF && b <= 0xFF) {
		double d = 0;
		if (c == 0) {
			d = (a << 8) + b;
		}
		if (c == 1) {
			d = a + (b << 8);
		}
		return d;
	}
void Print(const std::vector<int>& v) {
	for (auto x : v)
		std::cout << x << ", ";
	std::cout << std::endl;
}

void Print(const std::vector<std::vector<int>>& v) {
	for (auto row : v) {
		for (auto x : row)
			std::cout << x << ", ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Print(const std::vector<std::vector<int> *>& v) {
	for (auto pRow : v) {
		for (auto x : *pRow)
			std::cout << x << ", ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	// ���� ���� �� static ���� ��� ����
	// ä�� ����:		1. ������� ������ 0�� ó��
	//				2. �־��� ���� ������ �����ϸ� 0�� ó��
	//				3. ����(main �Լ��� ����)�� �����ϸ� 0�� ó��
	//				4. �Ϲ����� ������ �Ұ����� ��� 0�� ó�� �Ǵ� ����(�Ϲ����� �Է¿� ���� ó�� ��)
	//				5. �������� ����� ����Ȯ�� ��� ����(��, &&�� ����� ��ġ�� &�� ��� ��)
	//				6. �ʿ���� �Ķ���ͳ� ��ȯ�� ������ ����
	//				7. ������� �ڵ� ���ۿ� ���� ������ ������ 0�� ó��

	/**********
	1. ��� ������ �� ���� �Լ��� ����(function overloading �Ұ�, �߰����� ����� �Լ��� ������ �� ����)
	2. ��� �������� ǥ�� �Լ��� ����� �� ����, vector�� method�� ��밡��
	3. ��� �������� recursive call ����� �� ����
	**********/
	
	// 1. �Ʒ� �ڵ忡�� �� ��° �μ��� ù ��° �μ��� ���� ����� ��µǵ��� Ex1 �Լ��� �����϶�.
	// �� ��° �μ��� 0�̸� 0�� ���, �μ��� �Ǽ��� ��쵵 ���� �κи� ���޵Ǹ�, �������� �Ǽ� �������̴�. 
	// if���� ����� �� ������, ���� ������(conditional operator, ?:) ��� ���� �����ڸ��� �̿��Ͽ� �� ���� return �������� �ۼ��϶�.
	std::cout << "\n### 1 ###" << std::endl;
////////	std::cout << Ex1(1, 3) << ", " << Ex1(1, 0) << ", " << Ex1(7.2, 7) << ", " << Ex1(3.9, 2.5) << ", " << std::endl;
	// Print: 0.333333, 0, 1, 1.5,

	// 2. �Ʒ��� �ڵ忡�� ���� �� �μ�(�ڿ���)�� �ִ� �����(gcd)�� ������� ������ ��µǵ��� Ex2 �Լ��� �����϶�.
	// ���� �� �μ��� �ڿ����� �ƴϸ�(1���� ������), ��� 0�� ����Ѵ�.
	std::cout << "\n### 2 ###" << std::endl;
	int cdCnt = 0, gcd = 0;
////////	Ex2(4, 16, &gcd, cdCnt);
	std::cout << "(" << gcd << ", " << cdCnt << "), "; // Print: (4, 3),
////////	Ex2(0, 15, &gcd, cdCnt);
	std::cout << "(" << gcd << ", " << cdCnt << "), "; // Print: (0, 0),
////////	Ex2(12, 0, &gcd, cdCnt);
	std::cout << "(" << gcd << ", " << cdCnt << "), "; // Print: (0, 0)
////////	Ex2(24, 36, &gcd, cdCnt);
	std::cout << "(" << gcd << ", " << cdCnt << ")" << std::endl;; // Print: (12, 6)

	// 3. �Ʒ��� �ڵ忡�� �μ��� cosine���� ��µǵ��� Ex3 �Լ��� �����϶�.
	// sine(x) = x - (x*x*x/3!) + (x*x*x*x*x/5!) - (x*x*x*x*x*x*x/7!) + ...�� ������ ����ϸ�, �����ִ� ���� ������ 1.E-15���� Ŭ������ ����Ѵ�. �μ��� [0, 2pi] ������ �Էµȴٰ� ����.
	// Hint 1: ����, �и� �����Ͽ� ���, ���� ���
	// Hint 2: sign * = -1�� �̿��Ͽ� �������� ��ȣ �Ǻ�
	std::cout << "\n### 3 ###" << std::endl;
////////	std::cout << Ex3(30 * 3.14159 / 180.) << ", " << Ex3(60 * 3.14159 / 180.) << ", " << Ex3(90 * 3.14159 / 180.) << ", " << Ex3(180 * 3.14159 / 180.) << std::endl;
	std::cout << sin(30 * 3.14159 / 180.) << ", " << sin(60 * 3.14159 / 180.) << ", " << sin(90 * 3.14159 / 180.) << ", " << sin(180 * 3.14159 / 180.) << std::endl;
	// Print:	0.5, 0.866025, 1, 2.65359e-06
	//		    0.5, 0.866025, 1, 2.65359e-06
			

	// 4. �Ʒ��� �ڵ忡�� ���� �� �μ�(���� ����, [0, 0xFF] ����)�� ��Ʈ ���� ������(bitwise operator)�� �̿��Ͽ� ��Ʈ ������ �����Ͽ� �Ʒ��� ���� ��µǵ��� �� ���� Ex4 �Լ��� �����϶�.
	// �� ��° �μ��� ���ų� 0�̸� ù ��° �μ��� ���� 16-9��Ʈ�� �Ǿ� ���յǸ�, 0�� �ƴϸ� �� ��° �μ��� ���� 16-9��Ʈ�� ���յȴ�.
	// + �� - �����ڴ� ����� �� ����.
	// std::hex�� std::dec�� ���� 16���� ��°� 10���� ����� �����Ѵ�. 
	std::cout << "\n### 4 ###" << std::endl;
////////	std::cout << std::hex << Ex4(0xFF1, 0xF9A) << ", "<<  Ex4(0xF1, 0x9A, 1) << ", " << Ex4(0xF1, 0x9A, 0) << std::dec << std::endl;
	// Print: f19a, 9af1, f19a
	// Hint: (0xFF1, 0xF9A) -> (0xF1, 0x9A) -> (0xF100, 0x9A) -> 0xF19A

	// 5. �Ʒ��� �ڵ忡�� �μ��� ���޵� ����(std::vector<int>)���� ����� ��Ҹ� ����ϵ��� Ex5 �Լ��� �����϶�.
	std::cout << "\n### 5 ###" << std::endl;
	std::vector<int> v1{ 10, 3, 0, -2, -30 }, v2{ 1, -3, 0, 2, -30 };
	std::vector<std::vector<int>> v0;
////////	v0 = Ex5(v1, v2);
	Print(v0);	
	// Print: 10, 3,
	//        1, 2,
////////	v0 = Ex5(std::vector<int>{1, 4, -4, -2, 7}, std::vector<int>{-2, -3, 4, -2, 9});
	Print(v0);	
	// Print: 1, 4, 7,
	//        4, 9,

////////	v0 = Ex5(std::vector<int>{-1, -4, -4, -2, -7}, std::vector<int>{-2, -3, 4, -2, 9});
	Print(v0);
	// Print: [blank]
	//        4, 9,

	
	// 6. �Ʒ��� �ڵ忡�� �μ��� ���޵� 2���� ����(std::vector<std::vector<int>>)�� 2���� ���(int)�� �������� ��µǵ��� Ex6�Լ��� �����϶�.
	std::cout << "\n### 6 ###" << std::endl;
	std::vector<std::vector<int>> v3{{1, 2, 3, -1, 7}, {9, -4, 2}, {3, -2, 9}};
////////	Ex6(&v3);
	Print(v3); 
	// Print:	1, 4, 9, 1, 49,
	//          81, 16, 4,
	//          9, 4, 81,

	// 7. �Ʒ��� �ڵ忡�� �μ��� ���޵� 2���� ����(std::vector<std::vector<int>>)�� ���(std::vector<int>)�� ������ ��µǵ��� Ex7 �Լ��� �����϶�.
	// ��, ��Ұ� ���� 1���� ���ʹ� ��µ��� �ʴ´�.
	std::cout << "\n### 7 ###" << std::endl;
	const std::vector<std::vector<int>> v4{ {1, 2, 3, -1, 7}, {}, {19}, {3, -2, 7} };
	std::vector<int> v5;
////////	v5 = Ex7(v4);
	Print(v5);
	// Print: 5, 1, 3,

	// 8. �Ʒ� �ڵ忡�� std::vector<int>�� ������(pointer)�� ����� ���Ϳ� �� ���� std::vector<int>�� �ּҸ� �����ϴ� Ex8 �Լ��� �����϶�.
	std::cout << "\n### 8 ###" << std::endl;
	std::vector <std::vector<int> *> v6;
	std::vector<int> row1{ 1, 2, 3, 4 };
	std::vector<int> row2{ 5, 6, 7, 8 };
////////	Ex8(&v6, &row1, &row2);

	Print(v6);
	// Print: 1, 2, 3, 4,
	//        5, 6, 7, 8,
	row2.push_back(9);
	Print(v6);
	// Print: 1, 2, 3, 4,
	//        5, 6, 7, 8, 9,
}