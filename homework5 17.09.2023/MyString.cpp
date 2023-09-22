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
MyString::MyString(const MyString& obj) {
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);

	lenght = obj.lenght;
}
MyString::~MyString() {
	delete[] str;
}

// Конструктор переноса
MyString::MyString(MyString&& obj) {
	cout << "Move Constructor\n";
	
	str = obj.str;
	obj.str = nullptr;

	lenght = obj.lenght;
	obj.lenght = 0;
}


MyString::MyString(initializer_list<char> a) {
	cout << "Size -> " << a.size() << endl;
	lenght = a.size();
	str = new char[lenght + 1];
	
	for (auto x = a.begin(); x != a.end(); x++) {
		*str = *x;
		str++;
	}

	str -= lenght;
	str[lenght] = '\0';
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


// Глубокое копирование (оператор присвоения)
void MyString::MyStrCpy(MyString& obj) {
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);

	lenght = obj.lenght;
}
// Поиск подстроки в строке
bool MyString::MyStrStr(const char* str) {
	int i = 0, j = 0;

	while (this->str[i] != '\0') {
		if (this->str[i] == str[j]) {
			while (this->str[i] == str[j]) {
				i++;
				j++;
			}

			if (str[j] == '\0')
				return true;
		}
		else
			i++;
	}

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
	int newLenght = strlen(str) + strlen(b.str);
	char* newStr = new char[newLenght + 1];

	strcpy_s(newStr, strlen(str) + 1, str);

	for (int i = strlen(str), j = 0; i < newLenght; i++)
		newStr[i] = b.str[j++];

	newStr[newLenght] = '\0';

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


// Глубокое копирование (оператор присвоения)
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


// Аксессоры
// Сеттер
void MyString::SetStr(const char* st) {
	str = new char[strlen(st) + 1];
	strcpy_s(str, strlen(st) + 1, st);
}
void MyString::SetLength(int size) {
	if (size < 0) {
		cout << "Число должно быть больше 0" << endl;
		return;
	}
		
	lenght = size;
}

// Геттер
char* MyString::GetStr() const {
	return str;
}
int MyString::GetLength() const {
	return lenght;
}


// Перегрузки
// Перегрузка оператора индексирования []
char& MyString::operator[](const unsigned int index) {
	if (index >= 0 && index < lenght - 1)
		return str[index];
	return str[0];
}

// Перегрузка оператора вызова ()
void MyString::operator()(const char* input) {
	lenght = strlen(input) + 1;
	str = new char[lenght];
	strcpy_s(str, strlen(input) + 1, input);
}

// Перегрузка ввода-вывода
ostream& operator<<(ostream& os, const MyString& obj) {
	os << obj.GetStr() << endl;

	return os;
}
istream& operator>>(istream& is, MyString& obj) {
	cout << "istream& operator>>(istream& is, MyString& obj)" << endl;

	char buff[100];

	cin.getline(buff, strlen(buff) + 1);

	obj.SetStr(buff);

	return is;
}

// obj + char (перегрузка оператора +)
MyString operator+(const MyString obj1, const char obj2) {
	int newLenght = strlen(obj1.GetStr()) + 2;
    char* newStr = new char[newLenght];

    strcpy_s(newStr, newLenght - 1, obj1.GetStr());

    newStr[newLenght - 2] = obj2;
	newStr[newLenght - 1] = '\0';

	return MyString (newStr);
}
// char + obj (перегрузка оператора +)
MyString operator+(const char obj2, const MyString obj1) {
	int newLenght = strlen(obj1.GetStr()) + 2;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, newLenght - 1, obj1.GetStr());

	newStr[newLenght - 2] = obj2;
	newStr[newLenght - 1] = '\0';

	return MyString(newStr);
}
// obj + int (перегрузка оператора +)
MyString operator+(const MyString obj1, const int quantity) {
	int newLenght = strlen(obj1.GetStr()) + quantity + 1;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, strlen(obj1.GetStr()) + 1, obj1.GetStr());

	for (int i = strlen(obj1.GetStr()); i < newLenght - 1; i++)
		newStr[i] = 'a';

	newStr[newLenght - 1] = '\0';

	return MyString(newStr);
}
// int + obj (перегрузка оператора +)
MyString operator+(const int quantity, const MyString obj1) {
	int newLenght = strlen(obj1.GetStr()) + quantity + 1;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, strlen(obj1.GetStr()) + 1, obj1.GetStr());

	for (int i = strlen(obj1.GetStr()); i < newLenght - 1; i++)
		newStr[i] = 'a';
		
	newStr[newLenght - 1] = '\0';

	return MyString(newStr);
}
// obj++
MyString operator++(MyString& obj, int) {
	MyString temp(obj);

	int newLenght = strlen(obj.GetStr()) + 2;
	char* newStr = new char[newLenght];

	strcpy_s(newStr, newLenght - 1, obj.GetStr());

	newStr[newLenght - 2] = 'b';
	newStr[newLenght - 1] = '\0';

	obj.SetStr(newStr);
	obj.SetLength(newLenght);

	return temp;
}
// ++obj
MyString& operator++(MyString& obj) {
	int newLenght = strlen(obj.GetStr()) + 2;
	char* newStr = new char[newLenght];

	for (int i = 1; i < newLenght - 1; i++)
		newStr[i] = obj.GetStr()[i - 1];

	// strcpy_s(newStr, newLenght - 1, obj.GetStr());

	newStr[0] = 'b';
	newStr[newLenght - 1] = '\0';

	obj.SetStr(newStr);
	obj.SetLength(newLenght);

	return obj;
}