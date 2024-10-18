#include "unsorted.h"
#include "ItemType.h"
#include <iostream>
//���� �ڵ���� ���� ���� ��ȯ �ʿ� (�ڵ� ���� ���� �Ʒ�)
//������ ���� ������ ���� ��� ������ ��ó���� �۾� �ʿ�

int main() {
    UnsortedType list;

    ItemType item0;
    item0.Initialize(0);
    ItemType item1;
    item1.Initialize(1);
    ItemType item2;
    item2.Initialize(2);
    ItemType item3;
    item3.Initialize(3);
    ItemType item4;
    item4.Initialize(4);

    list.InsertItem(item0);
    list.InsertItem(item1);
    list.InsertItem(item3);
    list.InsertItem(item2);
    list.InsertItem(item3);

    list.DeleteItem_a(item4); // item4�� ����Ʈ�� �����Ƿ� ��ȭ ����
    for (int i = 0; i < list.LengthIs(); i++) {
        std::cout << list.info[i].GetValue() << ", ";
    }
    std::cout << std::endl;

    list.DeleteItem_a(item2); // item2�� ����Ʈ���� ����
    for (int i = 0; i < list.LengthIs(); i++) {
        std::cout << list.info[i].GetValue() << ", ";
    }
    std::cout << std::endl;

    list.DeleteItem_c(item3); // item3�� ����Ʈ���� ���� ����
    for (int i = 0; i < list.LengthIs(); i++) {
        std::cout << list.info[i].GetValue() << ", ";
    }
    std::cout << std::endl;

    return 0; // ���α׷� ���� ����
}
