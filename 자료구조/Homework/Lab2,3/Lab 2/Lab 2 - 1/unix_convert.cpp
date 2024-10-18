#include "file_convert.h" //�Լ��� ������Ÿ���� ������ ��������� ����

void unix_to_windows(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\n�� \r\n���� ��ȯ
		if (input_file.fail()) break;
		if (ch != '\n') {
			output_file << ch;
		}
		else {
			output_file << '\r' << '\n';
		}
	}
}

void unix_to_mac(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\n�� \r�� ��ȯ
		if (input_file.fail()) break;
		if (ch != '\n') {
			output_file << ch;
		}
		else {
			output_file << '\r';
		}
	}
}