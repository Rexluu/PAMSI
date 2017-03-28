#include <iostream>
#include <stdlib.h>

#include "Stack.hpp"
#define variable_type int

using namespace std;

int menu()
{
	char option;
	Stack <variable_type> stack;
	

	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Program realizujący stos (LIFO)" << endl;
	cout << "Typ danych ustalony w kodzie zrodlowym programu" << endl;
	
	while(1){
		cout << endl;
		cout << "1. Dodaj element" << endl;
		cout << "2. Usun element" << endl;
		cout << "3. Pokaz pierwszy element stosu" << endl;
		cout << "4. Wyswietl stos" << endl;
		cout << "5. Usun stos i wyjdz z programu" << endl << endl;
		
		cout << "Opcja [1-4]: ";
		cin >> option;
		cout << endl;

		switch(option)
		{
			case '1':
			{	
				variable_type data;
				cout << "Dodaj [dana]: "; 
				cin >> data;
				stack.push(data);
			}
			break;

			case '2':
			{
				try {
					stack.pop();
				} catch (string s) {
					cout << "Wyjatek: " << s << endl;
				}
			}		
			break;

			case '3':
			{
				try {
					cout << stack.top() << endl;
				} catch (string s) {
					cout << "Wyjatek: " << s << endl;
				}
			}
			break;


			case '4':
			{
				stack.show(); 
			}
			break;

			case '5':
			{
				stack.~Stack();
				exit(0);
			}
			break;
			
			default:
				cerr << "Brak takiej opcji w menu programu" << endl;
			break;
		}
	}
}

int main()
{	
	
	menu();
	return 0;
}
