#include "Note.h"

Note::Note()
{
	cout << "�������� ����������� �� ��������� ������ Note" << endl;
	name = "";
	surname = "";
	number = "";
	mas_Birth[0] = 0;
	mas_Birth[1] = 0;
	mas_Birth[2] = 0;
}

Note::~Note()
{
	cout << "�������� ���������� �� ���������" << endl;
}

void Note::vvod()
{
	cout << "������� ���: "; cin >> name;
	cout << "������� �������: "; cin >> surname;
	cout << "������� ����� ��������: "; cin >> number;
	cout << "������� ���� ��������: "; cin >> mas_Birth[0];
	cout << "������� ����� ��������: "; cin >> mas_Birth[1];
	cout << "������� ��� ��������: "; cin >> mas_Birth[2];
}

Note& Note::operator=(const Note& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->number = other.number;
	this->mas_Birth[0] = other.mas_Birth[0];
	this->mas_Birth[1] = other.mas_Birth[1];
	this->mas_Birth[2] = other.mas_Birth[2];
	
	return *this;//���������� ������
}
