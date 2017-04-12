#include "libraries.hpp"
#include "Data.hpp"
#include "Priority_queue.hpp"
#define var_type unsigned long int

int sort()
{
	Priority_queue <var_type> pq;
	
	srand( time(NULL) );
	unsigned long int numbers[20];
	
	std::cout << "Liczby do posortowania: " << std::endl;

	for (unsigned int i = 0; i < 20; i++) {
		numbers[i] = (std::rand() % 50);
		std::cout << numbers[i] << " ";
	}

	std::cout << std::endl << std::endl;

	for (unsigned int i = 0; i < 20; i++) {
		pq.push(numbers[i], numbers[i]);
	}

	pq.show();
	
	
}

int main()
{	
	sort();
	return 0;
}
