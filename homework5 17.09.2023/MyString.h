#pragma once
class MyString {
	char* str;
	int lenght;

	// ����������� ����
	static unsigned int numberOfObj;
public:
	// ������������ / ����������
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

	// �������� �����������
	MyString& operator=(const MyString& right);
};

// ���� ����� ����� ������� �� ������ ������ ������� ���������� ���