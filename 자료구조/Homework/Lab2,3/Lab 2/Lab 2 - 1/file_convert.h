#ifndef FILE_CONVERT_H //FILE_CONVERT_H�� define���� �ʾҴٸ� endif�� ������ �������� �κ��� ���Խ�ų ��
#define FILE_CONVERT_H //��������� �빮�� ���·� �ۼ�
#include <fstream>

void windows_to_mac(std::ifstream& input_file, std::ofstream& output_file); //�Լ� ������Ÿ�� ����
void windows_to_unix(std::ifstream& input_file, std::ofstream& output_file);
void mac_to_windows(std::ifstream& input_file, std::ofstream& output_file);
void mac_to_unix(std::ifstream& input_file, std::ofstream& output_file);
void unix_to_windows(std::ifstream& input_file, std::ofstream& output_file);
void unix_to_mac(std::ifstream& input_file, std::ofstream& output_file);

#endif
//�̷��� �ۼ��Ѵٸ� ��������� ~~_convert�� Lab2-1 �� 4���� �ҽ� ���Ͽ��� include �ȴ��ϴ��� 
//�ϳ��� ���Ͽ����� ifndef ~ endif ������ ������ �۵��ϹǷ� �Լ� ������ �ߺ����� �� �����ǵǴ� ������ ������ �� ����

//#pragma once
//ó�� �ѹ��� �������Ѵٴ� ȿ������, ifndef�� ��ó���� �������� �ݸ� pragma�� �����Ϸ� �������̰�, Ư�� �����Ϸ������� ������
