#pragma once
#include "Note.h"

class List {

private:
	Note* head;
	int size;
public:
	List();
	List(const List& other);
	~List();
	
	int get_size() { return size; }

	int sravn(Note* current, Note* next);
	void search(string number);
	void sortBirth();
	void del(int index);
	void change(int index);
	Note* push_back();

	friend ostream& operator<< (ostream& out, List& ob);
};