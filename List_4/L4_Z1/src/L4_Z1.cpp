#include "libraries.hpp"
#include "Data.hpp"
#include "Priority_queue.hpp"
#define variable_type int

int menu()
{
	char option;
	Priority_queue <variable_type> pq;
	

	std::cout << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "Program realizujący kolejke priorytetowa" << std::endl;
	std::cout << "Typ danych ustalony w kodzie zrodlowym programu" << std::endl;
	
	while(1){
		std::cout << std::endl;
		std::cout << "1. Dodaj element" << std::endl;
		std::cout << "2. Usun element z najmniejszym priorytetem" << std::endl;
		std::cout << "3. Wyswietl element z najmniejszym priorytetem" << std::endl;
		std::cout << "4. Wyswietl kolejke" << std::endl;
		std::cout << "5. Usun kolejke i wyjdz z programu" << std::endl << std::endl;
		
		std::cout << "Opcja [1-4]: ";
		std::cin >> option;
		std::cout << std::endl;

		switch(option)
		{
			case '1':
			{	
				std::cout << "[priorytet, dana]: ";
				unsigned long int priority;
				variable_type data;
				std::cin >> priority;
				std::cin >> data;
				pq.push(priority, data);
			}
			break;

			case '2':
			{
				pq.remove_min();
			}		
			break;

			case '3':
			{
				std::cout << pq.min();
			}	
			break;

			case '4':
			{
				pq.show();
			}	
			break;

			case '5':
				return 0;
			break;
			
			default:
				std::cerr << "Brak takiej opcji w menu programu" << std::endl;
			break;
		}
	}
}

int main()
{	
	menu();
	return 0;
}
