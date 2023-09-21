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
	MyString(const MyString& obj);
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
	void SetLength(int );

	// Геттер
	char* GetStr() const;
	int GetLength() const;


	// Перегрузки
	// Перегрузка индексирования []
	char& operator[](const unsigned int);

	// Перегрузка оператора вызова ()
	void operator()(const char*);
};

// Перегрузка ввода-вывода
ostream& operator<<(ostream&, const MyString&);
istream& operator>>(istream&, MyString&);

MyString operator+(const MyString, const char);
MyString operator+(const char, const MyString);
MyString operator+(const int, const MyString);
MyString operator+(const MyString, const int);
MyString operator++(MyString& obj, int);
MyString& operator++(MyString& obj);