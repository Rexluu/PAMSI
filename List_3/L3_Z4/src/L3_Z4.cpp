#include <iostream>
#include <ctime>
#include "Stack.hpp"

void show_stacks(Stack<int> &st1, Stack<int> &st2, Stack<int> &st3)
{
	std::cout << std::endl << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "Palik 1" << std::endl;
	st1.show();
	std::cout << std::endl << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "Palik 2" << std::endl;
	st2.show();
	std::cout << std::endl << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "Palik 3" << std::endl;
	st3.show();
	std::cout << std::endl << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
}

void solve_hanoi(int count, Stack<int> &st1, Stack<int> &st2, Stack<int> &st3, Stack<int> &s_st1, Stack<int> &s_st2 ,Stack<int> &s_st3) // s_st1 s_st2 s_st3 saved stacks (position) just to show steps in console
{
	if(count>0) {
		solve_hanoi(count-1, st1, st3, st2, s_st1, s_st2, s_st3);
		st3.push(st1.top());
		st1.pop();
		show_stacks(s_st1, s_st2, s_st3);
		solve_hanoi(count-1, st2, st1, st3, s_st1, s_st2, s_st3);
	}
}

void set_hanoi(const int amount)
{

	Stack<int> st1, st2, st3;

	for (int i = amount; i > 0; i--)
		st1.push(i);

// - - - - - - - - - - - - - - -

	time_t start,stop;
	double time;
	
	start = clock();
	
	show_stacks(st1, st2, st3);
	
	solve_hanoi(amount, st1, st2, st3, st1, st2, st3);

	stop = clock();

	time = double (stop-start)/CLOCKS_PER_SEC;
	std::cout << std::endl << "Czas rozwiazywania hanoi z uzyciem stosow: " << time << "[s]" << std::endl;
}


void menu()
{
	int amount;

	std::cout << "Podaj wysokosc wiezy hanoi [0-inf]: ";
	std::cin >> amount;
	std::cout << std::endl;

	set_hanoi(amount);
}

int main()
{	
	menu();
	return 0;
}
