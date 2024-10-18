/*             Object-Oriented Programming, Midterm exam (2024-1, CSE103-00)                       */
#include <iostream>
#include <vector>

// 답안 코드 (함수) 작성 영역
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
	// 전역 변수 및 static 변수 사용 금지
	// 채점 기준:		1. 실행되지 않으면 0점 처리
	//				2. 주어진 제한 조건을 위반하면 0점 처리
	//				3. 문제(main 함수의 내용)를 수정하면 0점 처리
	//				4. 일반적인 동작이 불가능한 경우 0점 처리 또는 감점(일반적인 입력에 대한 처리 등)
	//				5. 연산자의 사용이 부정확한 경우 감점(예, &&를 사용할 위치에 &를 사용 등)
	//				6. 필요없는 파라메터나 반환이 있으면 감점
	//				7. 답안지에 코드 동작에 대한 설명이 없으면 0점 처리

	/**********
	1. 모든 문제는 한 개의 함수만 정의(function overloading 불가, 추가적인 사용자 함수를 정의할 수 없음)
	2. 모든 문제에서 표준 함수는 사용할 수 없음, vector의 method는 사용가능
	3. 모든 문제에서 recursive call 사용할 수 없음
	**********/
	
	// 1. 아래 코드에서 두 번째 인수로 첫 번째 인수를 나눈 결과가 출력되도록 Ex1 함수를 정의하라.
	// 두 번째 인수가 0이면 0을 출력, 인수가 실수인 경우도 정수 부분만 전달되며, 나눗셈은 실수 나눗셈이다. 
	// if문을 사용할 수 없으며, 조건 연산자(conditional operator, ?:) 등과 같은 연산자만을 이용하여 한 개의 return 문장으로 작성하라.
	std::cout << "\n### 1 ###" << std::endl;
////////	std::cout << Ex1(1, 3) << ", " << Ex1(1, 0) << ", " << Ex1(7.2, 7) << ", " << Ex1(3.9, 2.5) << ", " << std::endl;
	// Print: 0.333333, 0, 1, 1.5,

	// 2. 아래의 코드에서 앞의 두 인수(자연수)의 최대 공약수(gcd)와 공약수의 개수가 출력되도록 Ex2 함수를 정의하라.
	// 앞의 두 인수가 자연수가 아니면(1보다 작으면), 모두 0을 출력한다.
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

	// 3. 아래의 코드에서 인수의 cosine값이 출력되도록 Ex3 함수를 정의하라.
	// sine(x) = x - (x*x*x/3!) + (x*x*x*x*x/5!) - (x*x*x*x*x*x*x/7!) + ...의 수식을 사용하며, 더해주는 항의 절댓값이 1.E-15보다 클때까지 계산한다. 인수는 [0, 2pi] 범위만 입력된다고 가정.
	// Hint 1: 분자, 분모를 구분하여 계산, 누적 계산
	// Hint 2: sign * = -1을 이용하여 덧샘항의 부호 판별
	std::cout << "\n### 3 ###" << std::endl;
////////	std::cout << Ex3(30 * 3.14159 / 180.) << ", " << Ex3(60 * 3.14159 / 180.) << ", " << Ex3(90 * 3.14159 / 180.) << ", " << Ex3(180 * 3.14159 / 180.) << std::endl;
	std::cout << sin(30 * 3.14159 / 180.) << ", " << sin(60 * 3.14159 / 180.) << ", " << sin(90 * 3.14159 / 180.) << ", " << sin(180 * 3.14159 / 180.) << std::endl;
	// Print:	0.5, 0.866025, 1, 2.65359e-06
	//		    0.5, 0.866025, 1, 2.65359e-06
			

	// 4. 아래의 코드에서 앞의 두 인수(양의 정수, [0, 0xFF] 범위)를 비트 단위 연산자(bitwise operator)를 이용하여 비트 단위로 연결하여 아래와 같이 출력되도록 한 개의 Ex4 함수를 정의하라.
	// 세 번째 인수가 없거나 0이면 첫 번째 인수가 상위 16-9비트로 되어 결합되며, 0이 아니면 두 번째 인수가 상위 16-9비트로 결합된다.
	// + 와 - 연산자는 사용할 수 없다.
	// std::hex와 std::dec는 각각 16진수 출력과 10진수 출력을 지정한다. 
	std::cout << "\n### 4 ###" << std::endl;
////////	std::cout << std::hex << Ex4(0xFF1, 0xF9A) << ", "<<  Ex4(0xF1, 0x9A, 1) << ", " << Ex4(0xF1, 0x9A, 0) << std::dec << std::endl;
	// Print: f19a, 9af1, f19a
	// Hint: (0xFF1, 0xF9A) -> (0xF1, 0x9A) -> (0xF100, 0x9A) -> 0xF19A

	// 5. 아래의 코드에서 인수로 전달된 벡터(std::vector<int>)에서 양수인 요소만 출력하도록 Ex5 함수를 정의하라.
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

	
	// 6. 아래의 코드에서 인수로 전달된 2차원 벡터(std::vector<std::vector<int>>)의 2차원 요소(int)가 제곱으로 출력되도록 Ex6함수를 정의하라.
	std::cout << "\n### 6 ###" << std::endl;
	std::vector<std::vector<int>> v3{{1, 2, 3, -1, 7}, {9, -4, 2}, {3, -2, 9}};
////////	Ex6(&v3);
	Print(v3); 
	// Print:	1, 4, 9, 1, 49,
	//          81, 16, 4,
	//          9, 4, 81,

	// 7. 아래의 코드에서 인수로 전달된 2차원 벡터(std::vector<std::vector<int>>)의 요소(std::vector<int>)의 개수가 출력되도록 Ex7 함수를 정의하라.
	// 단, 요소가 없는 1차원 벡터는 출력되지 않는다.
	std::cout << "\n### 7 ###" << std::endl;
	const std::vector<std::vector<int>> v4{ {1, 2, 3, -1, 7}, {}, {19}, {3, -2, 7} };
	std::vector<int> v5;
////////	v5 = Ex7(v4);
	Print(v5);
	// Print: 5, 1, 3,

	// 8. 아래 코드에서 std::vector<int>의 포인터(pointer)가 요소인 벡터에 두 개의 std::vector<int>의 주소를 저장하는 Ex8 함수를 정의하라.
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