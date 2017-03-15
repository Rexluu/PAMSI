#include "libraries.hpp"

#include "Queue.hpp"

#define variable_type int

int menu()
{
	char option;
	Queue <variable_type> queue;
	

	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Program realizujący kolejke (FIFO)" << endl;
	cout << "Typ danych ustalony w kodzie zrodlowym programu" << endl;
	
	while(1){
		cout << endl;
		cout << "1. Dodaj element" << endl;
		cout << "2. Usun element" << endl;
		cout << "3. Wyswietl kolejke" << endl;
		cout << "4. Usun kolejke i wyjdz z programu" << endl << endl;
		
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
				queue.push(data);
			}
			break;

			case '2':
			{
				if(queue.length() > 0) {
					queue.pop();
				} else
					cout << "Kolejka jest pusta" << endl;
			}		
			break;

			case '3':
			if(queue.length() > 0)
				queue.show(); 
			else
				cout << "Kolejka jest pusta" << endl; 
			break;

			case '4':
			if(queue.length() > 0)
				queue.remove_all();
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
