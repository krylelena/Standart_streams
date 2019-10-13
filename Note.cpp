#include "Note.h"

Note::Note()
{
	cout << "Вызвался конструктор по умолчанию класса Note" << endl;
	name = "";
	surname = "";
	number = "";
	mas_Birth[0] = 0;
	mas_Birth[1] = 0;
	mas_Birth[2] = 0;
}

Note::~Note()
{
	cout << "Вызвался деструктор по умолчанию" << endl;
}

void Note::vvod()
{
	cout << "Введите имя: "; cin >> name;
	cout << "Введите фамилию: "; cin >> surname;
	cout << "Введите номер телефона: "; cin >> number;
	cout << "Введите день рождения: "; cin >> mas_Birth[0];
	cout << "Введите месяц рождения: "; cin >> mas_Birth[1];
	cout << "Введите год рождения: "; cin >> mas_Birth[2];
}

Note& Note::operator=(const Note& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->number = other.number;
	this->mas_Birth[0] = other.mas_Birth[0];
	this->mas_Birth[1] = other.mas_Birth[1];
	this->mas_Birth[2] = other.mas_Birth[2];
	
	return *this;//возвращаем объект
}
