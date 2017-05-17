#include <iostream>
#include <stdlib.h>
#include "AVL_tree.hpp"
#define v_type int

int tree_test()
{
	AVL_tree <v_type> tr;
	int l_h, r_h;
	unsigned int array[11] = {10, 3, 20, 2, 6, 30, 1, 4, 7, 23};

	std::cout << "\nProcedura powstawania drzewa wraz z restrukturyzacja: \n";
	for (unsigned int i = 0; i < 10; i++) {
		std::cout << "\nDodawana wartosc: " << array[i];
		tr.push(array[i]);
		std::cout << "\nPre-order:  ";
		tr.Pre_order(tr.return_root());
		std::cout << "\n- - - - - - - - - - - - - - - - - - - - ";
	}

	std::cout << "\n\n\nPotwierdzenie prawidłowej restrukturyzacji, poszczegolne wysokosci poddrzew: \n";
	tr.Pre_order_avl(tr.return_root());
		
	std::cout << std::endl << std::endl;
	tr.remove_data(1);
	std::cout << "Pre-order po usunieciu 1: ";
	std::cout << "\nPre-order:  ";
	tr.Pre_order(tr.return_root());
	std::cout << std::endl << std::endl;
}

int main()
{	
	tree_test();
	return 0;
}
