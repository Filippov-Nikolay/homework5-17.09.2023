#include <iostream>
#include "MyString.h"

using namespace std;


// Конструкторы / Деструктор
// Создаёт строку длиной 80 символов
MyString::MyString() {
	lenght = 80;
	str = new char[lenght];
}
// Создаёт строку произвольного размера
MyString::MyString(int size) {
	lenght = size;
	str = new char[lenght];
}
// Создаёт строку и инициализирует её строкой от пользователя
MyString::MyString(const char* input) {
	lenght = strlen(input) + 1;
	str = new char[lenght];
	strcpy_s(str, strlen(input) + 1, input);
}
MyString::~MyString() {
	delete[] str;
}

void MyString::Input() {
	char buff[100];
	
	cout << "> ";
	cin.getline(buff, sizeof(buff));

	str = new char[strlen(buff) + 1];
	strcpy_s(str, strlen(buff) + 1, buff);
}

void MyString::Print() const {
	cout << str;
}

// Копирование строки
void MyString::MyStrCpy(MyString& obj) {
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);

	lenght = obj.lenght;
}

// Поиск подстроки в строке (РАЗОБРАТЬ)
bool MyString::MyStrStr(const char* str) {
	

	return false;
}

// Поиск символа в строке
int MyString::MyChr(char c) {
	for (int i = 0, j = 0; i < strlen(str) + 1; i++)
		if (str[i] == c)
			return i;
	return -1;
}

// Возвращает длину строки
int MyString::MyStrLen() {
	return strlen(str);
}

// Объединение строк
void MyString::MyStrCat(MyString& b) {
	int newLenght = lenght + b.lenght;
	char* newStr = new char[newLenght + 1];

	for (int i = 0; i < lenght; i++)
		newStr[i] = str[i];

	for (int i = 0; i < b.lenght; i++)
		newStr[lenght + i] = b.str[i];

	lenght = newLenght;
	str = newStr;
}

// Удаляет указанный символ
void MyString::MyDelChr(char c) {
	char* NewStr = new char[strlen(str)];
	
	for (int i = 0, j = 0; i < strlen(str) + 1; i++)
		if (str[i] != c)
			NewStr[j++] = str[i];


	lenght = strlen(str);
	str = NewStr;
}

// Сравнение строк
int MyString::MysStrCmp(MyString& b) {
	if (strlen(str) < strlen(b.str))
		return -1;
	else if (strlen(str) > strlen(b.str))
		return 1;
	else
		return 0;
}

MyString& MyString::operator=(const MyString& right) {
	if (this != &right) {
		delete[] str; // 1

		str = new char[right.lenght]; // 2
		lenght = right.lenght;

		for (int i = 0; i < lenght; ++i)
			str[i] = right.str[i];
	}

	return *this; // 3
}
