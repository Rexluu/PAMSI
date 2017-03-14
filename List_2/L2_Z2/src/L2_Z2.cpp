#include "libraries.hpp"
#include "Data.hpp"
#include "List.hpp"
#define variable_type string

int menu()
{
	char option;
	SL_List <variable_type> list;
	

	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Program realizujący liste jednokierunkowa (FIFO)" << endl;
	cout << "Typ danych ustalony w kodzie zrodlowym programu" << endl;
	
	while(1){
		cout << endl;
		cout << "1. Dodaj element" << endl;
		cout << "2. Usun element" << endl;
		cout << "3. Wyswietl liste" << endl;
		cout << "4. Usun liste i wyjdz z programu" << endl << endl;
		
		cout << "Opcja [1-4]: ";
		cin >> option;
		cout << endl;

		switch(option)
		{
			case '1':
			{	
				variable_type data;
				long int number;
				cout << "Dodaj [nr_elem][dana]: "; 
				cin >> number;
				cin >> data;
				if(number>list.length()+1 || number<1)
					cerr << "Niepraw. nr_elem, praw. zakres[1-" << list.length()+1 << "]" << endl; 
				else
					list.push(number, data);
			}
			break;

			case '2':
			{
				if(list.length() > 0) {
					long int number;
					cout << "Podaj numer elementu [1-" << list.length() << "]: ";
					cin >> number;
					if (number <= list.length()) 
						list.remove(number);
					else {
						cerr << "Podano nieistniejacy element: " << number << endl;
						cerr << "Prawidlowa wartosc [1-" << list.length() << "]" << endl; 
					}
				} else
					cout << "Lista jest pusta" << endl;
			}		
			break;

			case '3':
			if(list.length() > 0)
				list.show(); 
			else
				cout << "Lista jest pusta" << endl; 
			break;

			case '4':
			if(list.length() > 0)
				list.remove_all();
			exit(0);
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
