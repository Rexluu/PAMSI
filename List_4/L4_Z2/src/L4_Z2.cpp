#include <iostream>
#include <stdlib.h>

#include "Data.hpp"
#include "List.hpp"
#include "Tree_Data.hpp"
#include "Tree.hpp"

int tree_test()
{
	Tree <int> tr;
	
	int array[9] = {5, 8, 1, 2, 3, 10, 11, 4};

	std::cout << std::endl;
	std::cout << "Liczby dodawane na drzewo: " << std::endl;
	for (int i = 0; i < 8; i++ )
		std::cout << array[i] << " ";
	
	tr.push(array[0], tr.return_root()); //height 1, add as root

	tr.push(array[1], tr.return_root()); //height 2
	tr.push(array[2], tr.return_root());

	tr.push(array[3], tr.return_branch(tr.return_root(),1)); //height 3
	tr.push(array[4], tr.return_branch(tr.return_root(),1)); 
	tr.push(array[5], tr.return_branch(tr.return_root(),1)); 
	tr.push(array[6], tr.return_branch(tr.return_root(),2));
	tr.push(array[7], tr.return_branch(tr.return_root(),2)); 

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Root data:  " << tr.root_data() << std::endl;
	std::cout << "Pre-order:  ";
	tr.Pre_order(tr.return_root());
	std::cout << std::endl;

	std::cout << "Post-order: ";
	tr.Post_order(tr.return_root());
	std::cout << std::endl;

	std::cout << "Rozmiar:    " << tr.height();
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Po usunieciu danej numer 8" << std::endl;
	tr.remove(tr.return_branch(tr.return_root(),1));
	std::cout << "Root data:  " << tr.root_data() << std::endl;
	std::cout << "Pre-order:  ";
	tr.Pre_order(tr.return_root());
	std::cout << std::endl;

	std::cout << "Post-order: ";
	tr.Post_order(tr.return_root());
	std::cout << std::endl;
	std::cout << "Rozmiar:    " << tr.height();
	std::cout << std::endl;
	std::cout << std::endl;
	
}

int main()
{	
	tree_test();
	return 0;
}
