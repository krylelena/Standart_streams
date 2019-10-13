#include "List.h"

List::List()
{
	cout << "�������� ����������� ������������ ������ List" << endl;
	size = 0;
	head = nullptr;
}

List::List(const List& other)
{
	cout << "�������� ����������� ����������� ������ ����.";
	this->size = 0;
	for (int i = 0; i < other.size; i++) {
		this->push_back();//������� ������ � ����� �� ����������� ���������
	}
	Note* otherp = other.head;
	Note* thisp = this->head;
	for (int i = 0; i < size; i++) {
		
		thisp = otherp;//��� ������������ ������������� �������� ������������
		otherp = otherp->get_next_note();//���������� ���������
		thisp = thisp->get_next_note();
	}
}

List::~List()
{
	cout << "�������� ���������� ������ ����.";
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
	int flag = 1;//�� ������� �����
	for (int i = 0; i < size; i++) {
		if (currentp->get_number() == number) {
			flag = 0;
			cout << "���: " << currentp->get_name() << endl;
			cout << "�������: " << currentp->get_surname() << endl;
			cout << "����� ��������: " << currentp->get_number() << endl;
			cout << "���� ��������: " << currentp->get_mas_Birth_1() << "." << currentp->get_mas_Birth_2() << "." << currentp->get_mas_Birth_3() << endl << endl << endl;
			break;
		}
		currentp = currentp->get_next_note();
	}
	if (flag) {
		cout << "�������� � ��������� ������� ���." << endl << endl;
	}
}

void List::sortBirth()
{
	for (int i = 0; i < size; i++) {
		Note* currentp = head;
		Note* tmp = head;//��������� �� ���������� �������
		for (int j = 0; j < size - 1; j++) {
			if (sravn(currentp, currentp->get_next_note())) {
				//��� ������� ��������
				if (currentp == head) {
					head = currentp->get_next_note();//������ ������ ������ 2 �������
					currentp->set_next_note(head->get_next_note());//1-�� ��-� ��������� �� 3 �������
					head->set_next_note(currentp);//2-�� ������� ��������� �� 1 ��-�
					currentp = head;//������� �� ���������� �������
				}
				//��� ���������
				else {
					tmp->set_next_note(currentp->get_next_note());
					currentp->set_next_note(currentp->get_next_note()->get_next_note());//���������� ���� �������
					tmp->get_next_note()->set_next_note(currentp);
					currentp = tmp->get_next_note();//������� �� ���������� �������
				}
			}
			tmp = currentp;//���������� ���������� ��������� current
			currentp = currentp->get_next_note();//cureent ����������� �� ���� �������
		}

	}
	
}

void List::del(int index)
{
	try {
		if (index > size || index <= 0)
			throw exception("�������� ������");
		Note* currentp = head;
		Note* tmp = head;//��������� �� ����������
		//����� �������� �� �������, ������� ����� ����� �������
		for (int i = 1; i < index; i++) {
			tmp = currentp;
			currentp = currentp->get_next_note();
		}
		//�������� ������� �������� 
		if (currentp == head) {
			head = head->get_next_note();
			delete currentp;
		}
		//�������� ������ ����� �������
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
			throw exception("�������� ������");
		Note* currentp = head;
		for (int i = 1; i < index; i++) {
			currentp = currentp->get_next_note();
		}

		int menu;
		string tmp;
		short tmpsh;

		//����
		cout << "1 - ��������� �����" << endl;
		cout << "2 - ��������� �������" << endl;
		cout << "3 - ��������� ��������" << endl;
		cout << "4 - ��������� ���� ��������" << endl;
		cin >> menu;
		
		switch (menu) {
		case 1: cout << "������� ����� ���: "; cin >> tmp; currentp->set_name(tmp); break;
		case 2: cout << "������� ����� �������: "; cin >> tmp; currentp->set_surname(tmp); break;
		case 3: cout << "������� ����� ����� ��������: "; cin >> tmp; currentp->set_number(tmp); break;

		case 4: cout << "������� ����� ����: "; cin >> tmpsh; currentp->set_mas_Birth_1(tmpsh); 
				cout << "������� ����� �����: "; cin >> tmpsh; currentp->set_mas_Birth_2(tmpsh); 
				cout << "������� ����� ���: "; cin >> tmpsh; currentp->set_mas_Birth_3(tmpsh);
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
			throw exception ("��������� � ������ ���.");
		Note* currentp = ob.head;
		for (int i = 0; i < ob.size; i++) {
			out << "���: " << currentp->get_name() << endl;
			out << "�������: " << currentp->get_surname() << endl;
			out << "����� ��������: " << currentp->get_number() << endl;
			out << "���� ��������: " << currentp->get_mas_Birth_1() << "." << currentp ->get_mas_Birth_2() << "." << currentp ->get_mas_Birth_3() << endl << endl << endl;
			currentp = currentp->get_next_note();
		}
	}
	catch (exception &ex){
		out << ex.what() << endl << endl;
	}
	return out;
}
