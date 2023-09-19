#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
	setlocale(0, "");

   cout << "Hello World!\n";

   MyString firstStr("Hello world - firstStr");
   MyString secondStr;
   firstStr.Print();
   cout << "\nfirstStr size: " << firstStr.MyStrLen() << endl << endl;

   cout << "MyStrcpy: (копирование строк)" << endl;
   secondStr.MyStrCpy(firstStr);
   secondStr.Print();
   cout << endl << endl;

   cout << "MyStrStr (поиск подстроки в строке): " << endl;
   bool rezStr = firstStr.MyStrStr("llo");
   if (rezStr)
	   cout << "Строка найдена!" << endl << endl;
   else
	   cout << "Стройка не найдена!" << endl << endl;

   cout << "MyChr: (поиск символа в строке)" << endl;
   int position = firstStr.MyChr('d');
   if (position == -1)
	   cout << "Ключ не найден!" << endl;
   else
	   cout << "Ключ на позиции: " << position << endl << endl;

   cout << "MyStrCat (объединение строк): " << endl;
   firstStr.MyStrCat(secondStr);
   firstStr.Print();
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

   return 0;
}

