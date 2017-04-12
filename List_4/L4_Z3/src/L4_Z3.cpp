#include <iostream>
#include <stdlib.h>

#include "Data.hpp"
#include "Tree.hpp"

int tree_test()
{
	Binary_Tree <int> tr;
	unsigned int array[10] = {5, 2, 8, 1, 4, 6, 9};
	
	std::cout << "Elementy do dodania na drzewo: " << std::endl;
	for (unsigned int i = 0; i < 7; i++) {
		std::cout << array[i] << " ";
		tr.push(array[i]);
	}

	
	std::cout << std::endl;
	std::cout << "Pre-order:  ";
	tr.Pre_order(tr.return_root());
	std::cout << std::endl;
	
	std::cout << "Post-order: ";
	tr.Post_order(tr.return_root());
	std::cout << std::endl;
	
	std::cout << "In-order:   ";
	tr.In_order(tr.return_root());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Rozmiar:   " << tr.height() << std::endl;
	std::cout << "Dana root: " << tr.root_data() << std::endl;
	std::cout << std::endl;


	tr.remove_data(2);
	std::cout << "Post-order po usunieciu numeru 2: ";
	tr.Post_order(tr.return_root());
	std::cout << std::endl;
	std::cout << "Rozmiar:   " << tr.height() << std::endl;
	std::cout << std::endl;
}

int main()
{	
	tree_test();
	return 0;
}
