#include "List.h"

int main() {
	setlocale(LC_ALL, "");

	List ob;
	int menu;
	int index;
	string number;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "1 - �������� �������" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ����� ����� �� �����" << endl;
		cout << "4 - ����� �������� �� ������ ��������" << endl;
		cout << "5 - ���������� ����� �� ���� ��������" << endl;
		cout << "6 - �������������� �������" << endl;
		cout << "7 - �����" << endl;
		cin >> menu;

		switch (menu) {
		case 1: ob.push_back()->vvod(); break;
		case 2: cout << ob << endl; 
			if (ob.get_size() != 0) {
				cout << "������� ������ ��������, ������� ����� �������: ";
				cin >> index;
				ob.del(index);
			}
			break;
		case 3: cout << ob; system("pause"); break;
		case 4: cout << "������� ����� ��������: "; cin >> number; ob.search(number); system("pause"); break;
		case 5: ob.sortBirth(); break;
		case 6: 
			cout << ob;
			if (ob.get_size() != 0) {
				cout << "������� ������ ��������, ������� ��������: ";
				cin >> index;
				ob.change(index);
			}
			break;
		case 7: flag = false; break;
		default: cout << "������� ������������ �������" << endl << endl; system("pause");
		}
	}
	return 0;
}