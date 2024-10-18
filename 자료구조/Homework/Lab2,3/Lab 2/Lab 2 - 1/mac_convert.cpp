#include "file_convert.h" //�Լ��� ������Ÿ���� ������ ��������� ����

void mac_to_windows(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r�� \r\n���� ��ȯ
		if (input_file.fail()) break;
		if (ch != '\r') {
			output_file << ch;
		}
		else {
			output_file << '\r' << '\n';
		}
	}
}

void mac_to_unix(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r�� \n���� ��ȯ
		if (input_file.fail()) break;
		if (ch != '\r') {
			output_file << ch;
		}
		else {
			output_file << '\n';
		}
	}
}