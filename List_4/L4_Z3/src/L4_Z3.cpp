#include <iostream>
#include <stdlib.h>

#include "Data.hpp"
#include "Tree.hpp"

int tree_test()
{
	Binary_Tree <int> tr;
	
	tr.push(5);
	tr.push(2);
	tr.push(8);
	tr.push(1);
	tr.push(4);
	tr.push(6);
	tr.push(9);
	tr.push(3);
	
	
	std::cout << "Pre-order:  ";
	tr.Pre_order(tr.return_root());
	std::cout << std::endl;
	
	std::cout << "Post-order: ";
	tr.Post_order(tr.return_root());
	std::cout << std::endl;
	
	std::cout << "In-order:   ";
	tr.In_order(tr.return_root());
	std::cout << std::endl;

	std::cout << "Rozmiar:    " << tr.length() << std::endl;
}

int main()
{	
	tree_test();
	return 0;
}
