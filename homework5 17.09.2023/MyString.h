#pragma once
#include <iostream>

using namespace std;

class MyString {
	char* str;
	int lenght;

	// Статическое поле
	static unsigned int numberOfObj;
public:
	// Конструкторы / Деструктор
	MyString();
	MyString(int);
	MyString(const char*);
	~MyString();


	void Input();
	void Print() const;


	void MyStrCpy(MyString& obj); // Копирование строки
	bool MyStrStr(const char* srd); // Поиск подстроки в строке
	int MyChr(char c); // Поиск символа в строке
	int MyStrLen(); // Возвращает длину строки
	void MyStrCat(MyString& b); // Объединение строк
	void MyDelChr(char c); // Удаляет указанный символ
	int MysStrCmp(MyString& b); // Сравнение строк


	// Глубокое копирование (оператор присвоения)
	MyString& operator=(const MyString& right);


	// Аксессоры
	// Сеттер
	void SetStr(const char*);

	// Геттер
	char* GetStr() const;
};

// Перегрузка ввода-вывода
ostream& operator<<(ostream&, const MyString&);
istream& operator>>(istream&, MyString&);