#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Note {

private:
	string name;
	string surname;
	string number;
	short mas_Birth[3];
	Note *next_note;
public:
	Note();
	~Note();

	void vvod();//для ввода значений

	string get_name() { return name; }
	string get_surname() { return surname; }
	string get_number() { return number; }
	short get_mas_Birth_1() { return mas_Birth[0]; }
	short get_mas_Birth_2() { return mas_Birth[1]; }
	short get_mas_Birth_3() { return mas_Birth[2]; }

	Note* get_next_note() { return next_note; } //возвращает значение 
	void set_next_note(Note* next_note) { this->next_note = next_note; } // устанавливает значение

	void set_name(string name) { this->name = name; }
	void set_surname(string surname) { this->surname = surname; }
	void set_number(string number) { this->number = number; }
	void set_mas_Birth_1(short mas_Birth) { this->mas_Birth[0] = mas_Birth;}
	void set_mas_Birth_2(short mas_Birth) { this->mas_Birth[1] = mas_Birth; }
	void set_mas_Birth_3(short mas_Birth) { this->mas_Birth[2] = mas_Birth; }

	Note& operator= (const Note &other);
};