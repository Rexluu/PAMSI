#include <iostream>
#include <ctime>
#include <stack>
#include "Stack_a.hpp"
#include "Stack.hpp"

#define variable_type unsigned long int

int main()
{
	time_t start,stop;
	double time;
	unsigned long int amount;

	Stack_a<variable_type> stack1,stack2;
	Stack<variable_type> stack3;
	std::stack<variable_type> stl_st;

	std::cout << "Podaj ilosc danych do testu: ";
	std::cin >> amount;
	std::cout << std::endl;

// - - - - - - - - - - - - - - - -
	
	start = clock();

	for (variable_type i = 0; i < amount; i++)
		stack1.push_inc(i);

	stop = clock();

	time = double (stop-start)/CLOCKS_PER_SEC;
	std::cout << std::endl << "Czas tablicy(stosu) powiekszanej o 1: " << time << "[s]" << std::endl;

// - - - - - - - - - - - - - - - -

	start = clock();

	for (variable_type i = 0; i < amount; i++)
		stack2.push(i);

	stop = clock();

	time = double (stop-start)/CLOCKS_PER_SEC;
	std::cout << std::endl << "Czas tablicy(stosu) powiekszanej dwukrotnie: " << time << "[s]" << std::endl;

	
// - - - - - - - - - - - - - - - - 

	start = clock();

	for (variable_type i = 0; i < amount; i++)
		stl_st.push(i);

	stop = clock();

	time = double (stop-start)/CLOCKS_PER_SEC;
	std::cout << std::endl << "Czas stosu z STL: " << time << "[s]" << std::endl;

// - - - - - - - - - - - - - - - -

	start = clock();

	for (variable_type i = 0; i < amount; i++)
		stack3.push(i);

	stop = clock();

	time = double (stop-start)/CLOCKS_PER_SEC;
	std::cout << std::endl << "Czas wlasnego stosu: " << time << "[s]" << std::endl << std::endl;

	
// - - - - - - - - - - - - - - - - 

	return 0;
}
