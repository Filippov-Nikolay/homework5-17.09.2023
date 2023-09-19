#pragma once
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


	void MyStrCpy(MyString& obj);
	bool MyStrStr(const char* srd);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MysStrCmp(MyString& b);

	// Глубокое копирование
	MyString& operator=(const MyString& right);
};

// Есть длина через которую мы создаём размер массива переменной чар