#include "ItemType.h"
#include "sorted.h"
#include <iostream>

void MergeList(SortedType list1, SortedType list2, SortedType& result);
//Function : 2���� Sorted List�� �����Ͽ� �ٸ� �ϳ��� Sorted List�� �����Ѵ�.
//     Pre : ���յǴ� list1�� list2�� �ʱ�ȭ�Ǿ��ְ�, ComparedTo �Լ��� ���� Ű�� ���� ���ĵǾ��ִ�.
//    Post : result�� list1�� list2�� ��� ��Ҹ� ���� Sorted List�̴�.

void MergeList(SortedType list1, SortedType list2, SortedType& result) {
	ItemType CheckItem;
	result.ResetList(); //�ܼ� ���� �����̹Ƿ� O(1)
	list1.ResetList(); //O(1)
	list2.ResetList(); //0(1)
	//LengthIs�� ����Ʈ�� ���� �����̹Ƿ� O(1)
	for (int i = 0; i < list1.LengthIs(); i++) { //�־��� ��� ����Ʈ�� ���� ��ŭ �ݺ��̹Ƿ� O(n), n�� list1�� ����.
		list1.GetNextItem(CheckItem); //�ܼ� ���� �� �����̹Ƿ� O(1)
		result.InsertItem(CheckItem); 
		//InsertItem �Լ��� �־��� ��� while���� for���� ����Ʈ�� ���� ��ŭ �ݺ��ϰ�, ����Ʈ�� ���̴� list1�� ����, �� n��ŭ�̹Ƿ� O(n).
	} //�ᱹ ���� �ݺ����� ������ ��� �����Ƿ� O(n^2)
	for (int i = 0; i < list2.LengthIs(); i++) { //������ ������ O(m), m�� list2�� ����.
		list2.GetNextItem(CheckItem); //O(1)
		result.InsertItem(CheckItem); //���⼭�� �־��� ��� ����Ʈ�� ���̰� list1�� list2�� ������ �����̹Ƿ� O(n+m).
	} //O(m*(n+m)
} //��������� MergeList�� �ð� ���⵵�� list1�� ���� n, list2�� ���� m�� ���� O(n^2+m*(n+m))�̴�.

int main() {
	SortedType s_list1, s_list2, s_list3;
	ItemType CheckItem;
	ItemType item1, item2, item3, item4, item5, item6, item7, item8;
	
	item1.Initialize(1);  //�ܼ� ���� �����̹Ƿ� O(1)
	item2.Initialize(2);
	item3.Initialize(3);
	item4.Initialize(4);
	item5.Initialize(5);
	item6.Initialize(6);
	item7.Initialize(7);
	item8.Initialize(8);

	s_list1.InsertItem(item3); //O(n)
	s_list1.InsertItem(item6);
	s_list1.InsertItem(item7);
	s_list1.InsertItem(item1);

	s_list1.ResetList(); //O(1)
	for (int i = 0; i < s_list1.LengthIs(); i++) { //O(n)
		s_list1.GetNextItem(CheckItem); //O(1)
		std::cout << CheckItem.GetValue() << ", "; //O(1)
	} //�ᱹ O(n)
	std::cout << std::endl; //O(1)

	s_list2.InsertItem(item2); //O(m)
	s_list2.InsertItem(item8);
	s_list2.InsertItem(item5);
	s_list2.InsertItem(item4);
	
	s_list2.ResetList(); //O(1)
	for (int i = 0; i < s_list2.LengthIs(); i++) { //O(m)
		s_list2.GetNextItem(CheckItem); //O(1)
		std::cout << CheckItem.GetValue() << ", "; //O(1)
	} //�ᱹ O(m)
	std::cout << std::endl; //O(1)
	
	MergeList(s_list1, s_list2, s_list3); //O(n^2+m*(n+m))

	s_list3.ResetList(); //O(1)
	for (int i = 0; i < s_list3.LengthIs(); i++) { //O(m+n)
		s_list3.GetNextItem(CheckItem); //O(1)
		std::cout << CheckItem.GetValue() << ", "; //O(1)
	} //�ᱹ O(m+n)
	std::cout << std::endl; //O(1)
} //��������� main�� �ð� ���⵵�� MergeList�� ���� O(n^2+m*(n+m))�̴�.
