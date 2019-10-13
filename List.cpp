#include "List.h"

List::List()
{
	cout << "Вызвался конструктор односвязного списка List" << endl;
	size = 0;
	head = nullptr;
}

List::List(const List& other)
{
	cout << "Вызвался конструктор копирования класса Лист.";
	this->size = 0;
	for (int i = 0; i < other.size; i++) {
		this->push_back();//создали список с таким же количеством элементов
	}
	Note* otherp = other.head;
	Note* thisp = this->head;
	for (int i = 0; i < size; i++) {
		
		thisp = otherp;//ТУТ ИСПОЛЬЗУЕТСЯ ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР ПРИСВАИВАНИЯ
		otherp = otherp->get_next_note();//ПРОДВИГАЕМ УКАЗАТЕЛИ
		thisp = thisp->get_next_note();
	}
}

List::~List()
{
	cout << "Вызвался деструктор класса Лист.";
		Note* currentp = head;
	for (int i = 0; i < size; i++) {
		head = head->get_next_note();
		delete currentp;
		currentp = head;
	}
}

int List::sravn(Note* current, Note* next)
{
	if (current->get_mas_Birth_3() == next->get_mas_Birth_3()) {
		if (current->get_mas_Birth_2() == next->get_mas_Birth_2()) {
			if (current->get_mas_Birth_1() == next->get_mas_Birth_1()) {
				return 0;
			}
			else if (current->get_mas_Birth_1() > next->get_mas_Birth_1()) {
				return 1;
			}
			else return 0;
		}
		else if (current->get_mas_Birth_2() > next->get_mas_Birth_2()) {
			return 1;
		}
		else return 0;
	}
	else if (current->get_mas_Birth_3() > next->get_mas_Birth_3()) {
		return 1;
	}
	else return 0;
}

void List::search(string number)
{
	Note* currentp = head;
	int flag = 1;//не нашелся номер
	for (int i = 0; i < size; i++) {
		if (currentp->get_number() == number) {
			flag = 0;
			cout << "Имя: " << currentp->get_name() << endl;
			cout << "Фамилия: " << currentp->get_surname() << endl;
			cout << "Номер телефона: " << currentp->get_number() << endl;
			cout << "День Рождения: " << currentp->get_mas_Birth_1() << "." << currentp->get_mas_Birth_2() << "." << currentp->get_mas_Birth_3() << endl << endl << endl;
			break;
		}
		currentp = currentp->get_next_note();
	}
	if (flag) {
		cout << "Человека с введенным номером нет." << endl << endl;
	}
}

void List::sortBirth()
{
	for (int i = 0; i < size; i++) {
		Note* currentp = head;
		Note* tmp = head;//указатель на предыдущий элемент
		for (int j = 0; j < size - 1; j++) {
			if (sravn(currentp, currentp->get_next_note())) {
				//для первого элемента
				if (currentp == head) {
					head = currentp->get_next_note();//начало списка теперь 2 элемент
					currentp->set_next_note(head->get_next_note());//1-ый эл-т указывает на 3 элемент
					head->set_next_note(currentp);//2-ой элемент указывает на 1 эл-т
					currentp = head;//возврат на предыдущий элемент
				}
				//для остальных
				else {
					tmp->set_next_note(currentp->get_next_note());
					currentp->set_next_note(currentp->get_next_note()->get_next_note());//пропускаем один элемент
					tmp->get_next_note()->set_next_note(currentp);
					currentp = tmp->get_next_note();//возврат на предыдущий элемент
				}
			}
			tmp = currentp;//запоминаем предыдущее состояние current
			currentp = currentp->get_next_note();//cureent передвигаем на след элемент
		}

	}
	
}

void List::del(int index)
{
	try {
		if (index > size || index <= 0)
			throw exception("Неверный индекс");
		Note* currentp = head;
		Note* tmp = head;//указывает на предыдущий
		//поиск элемента по индексу, который нужно будет удалить
		for (int i = 1; i < index; i++) {
			tmp = currentp;
			currentp = currentp->get_next_note();
		}
		//удаление первого элемента 
		if (currentp == head) {
			head = head->get_next_note();
			delete currentp;
		}
		//удаление любого кроме первого
		else {
			tmp->set_next_note(currentp->get_next_note());
			delete currentp;
		}
		size--;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
		system("pause");
	}
}

void List::change(int index)
{
	try {
		if (index > size || index <= 0)
			throw exception("Неверный индекс");
		Note* currentp = head;
		for (int i = 1; i < index; i++) {
			currentp = currentp->get_next_note();
		}

		int menu;
		string tmp;
		short tmpsh;

		//меню
		cout << "1 - Изменение имени" << endl;
		cout << "2 - Изменение фамилии" << endl;
		cout << "3 - Изменение телефона" << endl;
		cout << "4 - Изменение Даты Рождения" << endl;
		cin >> menu;
		
		switch (menu) {
		case 1: cout << "Введите новое имя: "; cin >> tmp; currentp->set_name(tmp); break;
		case 2: cout << "Введите новую фамилию: "; cin >> tmp; currentp->set_surname(tmp); break;
		case 3: cout << "Введите новый номер телефона: "; cin >> tmp; currentp->set_number(tmp); break;

		case 4: cout << "Введите новый день: "; cin >> tmpsh; currentp->set_mas_Birth_1(tmpsh); 
				cout << "Введите новый месяц: "; cin >> tmpsh; currentp->set_mas_Birth_2(tmpsh); 
				cout << "Введите новый год: "; cin >> tmpsh; currentp->set_mas_Birth_3(tmpsh);
		}

	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
		system("pause");
	}
}

Note* List::push_back()
{
	Note *ptr = new Note;
	if (head == nullptr) {
		head = ptr;
	}
	else {
		Note* currentp = head;
		for (int i = 1; i < size; i++) {
			currentp = currentp->get_next_note();
		}
		currentp->set_next_note(ptr);
	}
	size++;

	return ptr;
}

ostream& operator<<(ostream& out, List& ob)
{
	try { 
		if (ob.size == 0)
			throw exception ("Элементов в списке нет.");
		Note* currentp = ob.head;
		for (int i = 0; i < ob.size; i++) {
			out << "Имя: " << currentp->get_name() << endl;
			out << "Фамилия: " << currentp->get_surname() << endl;
			out << "Номер телефона: " << currentp->get_number() << endl;
			out << "День Рождения: " << currentp->get_mas_Birth_1() << "." << currentp ->get_mas_Birth_2() << "." << currentp ->get_mas_Birth_3() << endl << endl << endl;
			currentp = currentp->get_next_note();
		}
	}
	catch (exception &ex){
		out << ex.what() << endl << endl;
	}
	return out;
}
