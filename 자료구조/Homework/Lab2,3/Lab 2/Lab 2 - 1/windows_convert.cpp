#include "file_convert.h" //�Լ��� ������Ÿ���� ������ ��������� ����

void windows_to_mac(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r\n�� \r�� ��ȯ
		if (input_file.fail()) break;
		if (ch != '\n') {
			output_file << ch;
		}
	}
}

void windows_to_unix(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r\n�� \n���� ��ȯ
		if (input_file.fail()) break;
		if (ch != '\r') {
			output_file << ch;
		}
	}
}