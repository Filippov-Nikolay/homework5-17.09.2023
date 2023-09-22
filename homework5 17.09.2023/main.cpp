#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
	setlocale(0, "");
	
	MyString testArr = { 'H','e','l','l','o' };
	testArr.Print();
	cout << endl << endl;

	MyString firstStr("Hello world - firstStr");
	firstStr.Print();
	cout << "\nfirstStr size: " << firstStr.MyStrLen() << endl << endl;
	
	cout << "MyStrcpy: (копирование строк)" << endl;
	MyString secondStr;
	secondStr.MyStrCpy(firstStr);
	secondStr.Print();
	cout << endl << endl;

	cout << "MyStrStr: (поиск подстроки в строке)" << endl;
	if (firstStr.MyStrStr("ello"))
		cout << "Подстрока найдена!" << endl << endl;
	else
		cout << "Подстрока не найдена!" << endl << endl;
	
	cout << "MyChr: (поиск символа в строке)" << endl;
	int position = firstStr.MyChr('d');
	if (position == -1)
		cout << "Ключ не найден!" << endl;
	else
		cout << "Ключ на позиции: " << position << endl << endl;
	
	cout << "MyStrCat (объединение строк): " << endl;
	firstStr.MyStrCat(secondStr);
	firstStr.Print();
	cout << endl;
	secondStr.Print();
	cout << endl << endl;

	
	cout << "MyDelChr (удаляет указанный символ): " << endl;
	secondStr.MyDelChr('f');
	secondStr.Print();
	cout << endl << endl;
	

	cout << "MyStrCmp (сравнение строк): " << endl;
	int rez = firstStr.MysStrCmp(secondStr);
	if (rez == -1)
		cout << "<" << endl;
	else if (rez == 1)
		cout << ">" << endl;
	else
		cout << "==" << endl;

	
	MyString test1("HELLO");
	MyString test2;
	test2 = test1;
	test2.Print();
	
	cout << test1 << endl;
	cin >> test1;

	cout << test1 << endl;
	
	// Перегрузка индексирования []
	cout << firstStr[0] << endl;
	for (int i = 0; i < firstStr.GetLength(); i++)
		cout << firstStr[i];
	cout << endl;


	// Перегрузка индексирования ()
	MyString thirdStr;
	thirdStr("Hello()");
	thirdStr.Print();
	cout << endl << endl;


	// obj + char
	MyString text("text");
	MyString text1 = text + 'a';
	text1.Print();
	cout << endl;


	// char + obj
	MyString text2("text");
	MyString text3 = 'a' + text2;
	text3.Print();
	cout << endl;

	
	// obj + int
	MyString text4("text");
	MyString text5 = 10 + text4;
	text5.Print();
	cout << endl;


	// int + obj
	MyString text6("text");
	MyString text7 = text6 + 10;
	text7.Print();
	cout << endl;


	// obj++
	cout << "obj++" << endl;
	MyString textT = text4++;
	textT.Print();
	cout << endl;
	text4.Print();
	cout << endl << endl;


	// ++obj
	cout << "++obj" << endl;
	textT = ++text6;
	textT.Print();
	cout << endl;
	text6.Print();
	cout << endl << endl;
	

	// Конструктор переноса
	cout << "Конструктор переноса: " << endl;
	MyString moveStr;
	moveStr = move(firstStr);
	moveStr.Print();
	cout << endl;
	// firstStr.Print();

	return 0;
}

