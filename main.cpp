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
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Удалить элемент" << endl;
		cout << "3 - Вывод людей на экран" << endl;
		cout << "4 - Поиск человека по номеру телефона" << endl;
		cout << "5 - Сортировка людей по дате рождения" << endl;
		cout << "6 - Редактирование персоны" << endl;
		cout << "7 - Выход" << endl;
		cin >> menu;

		switch (menu) {
		case 1: ob.push_back()->vvod(); break;
		case 2: cout << ob << endl; 
			if (ob.get_size() != 0) {
				cout << "Введите индекс элемента, который нужно удалить: ";
				cin >> index;
				ob.del(index);
			}
			break;
		case 3: cout << ob; system("pause"); break;
		case 4: cout << "Введите номер телефона: "; cin >> number; ob.search(number); system("pause"); break;
		case 5: ob.sortBirth(); break;
		case 6: 
			cout << ob;
			if (ob.get_size() != 0) {
				cout << "Введите индекс элемента, который изменить: ";
				cin >> index;
				ob.change(index);
			}
			break;
		case 7: flag = false; break;
		default: cout << "Введена некорректная команда" << endl << endl; system("pause");
		}
	}
	return 0;
}