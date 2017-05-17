#include "Data.hpp"

template <typename Type>
class AVL_tree
{
	Data <Type> *root;

	void remove(Data<Type> *data);
	long int find_height(Data<Type> *data);
	void find_data(const Type f_data, Data<Type> *data, Data<Type> **found_data);
	void RR(Data <Type> *A);
	void LL(Data <Type> *A);
	void RL(Data <Type> *A);
	void LR(Data <Type> *A);
public:
	AVL_tree();
	~AVL_tree();

	void push(Type n_data);
	void remove_data(const Type r_data);
	const unsigned long int height();
	
	const Type root_data();
	Data <Type> *return_root();

	void Pre_order(Data <Type> *data);
	void Pre_order_avl(Data <Type> *data);
	void Post_order(Data <Type> *data);
	void In_order(Data <Type> *data);
};

template <typename Type>
AVL_tree<Type>::AVL_tree()
{
	root = nullptr;
}

template <typename Type>
AVL_tree<Type>::~AVL_tree()
{
	remove(root);
	root = nullptr;
}

template <typename Type>
void AVL_tree<Type>::remove(Data<Type> *data)
{
	if(data != nullptr) {
		remove (data->return_l_branch());
		remove (data->return_r_branch());
		delete data;
	}
}

template <typename Type>
long int AVL_tree<Type>::find_height(Data<Type> *data)
{
	if (data == nullptr) return 0;
	
	long int l_height = find_height(data->return_l_branch());
	long int r_height = find_height(data->return_r_branch());

	if (l_height >= r_height) 
		return l_height+1; 
	else 
		return r_height+1; // if equal it is doesn't matter
}

template <typename Type>
const unsigned long int AVL_tree<Type>::height()
{
	return find_height(root);
}


template <typename Type>
const Type AVL_tree<Type>::root_data()
{
	return root->return_data();
}

template <typename Type>
void AVL_tree<Type>::push(Type n_data)
{
	Data <Type> *new_data = new Data <Type>;
	Data <Type> *pointer = root;
	new_data->set_data(n_data);

	if (root == nullptr){
		root = new_data;
		new_data = nullptr;
	} else {
		while (1) {
			if(n_data > pointer->return_data()) {
				if ( (pointer->return_r_branch()) == nullptr){
					pointer->set_r_branch(new_data);
					new_data->set_parent(pointer);
					break;
				}
				pointer = pointer->return_r_branch();
			} else {
				if(n_data < pointer->return_data()) {
					if ( (pointer->return_l_branch()) == nullptr){
						pointer->set_l_branch(new_data);
						new_data->set_parent(pointer);
						break;
					}
				pointer = pointer->return_l_branch();
				}
			} // else if equal throw (optional)
		}
		// stage 2
		if (pointer->return_bf() != 0){
			pointer->set_bf(0);
		} else {
			if (pointer->return_l_branch() == new_data)
				pointer->set_bf(1);
			else
				pointer->set_bf(-1);

			Data <Type> *reverse = pointer->return_parent();
			bool flag = false;

			while(reverse != nullptr) {
				if (reverse->return_bf() != 0) {
					flag = true;
					break;
				}

				if (reverse->return_l_branch() == pointer) 
					reverse->set_bf(1);
				else 
					reverse->set_bf(-1);

				pointer = reverse;
				reverse = reverse->return_parent();

				}

			if(flag) {
				if(reverse->return_bf() == 1) {
					if(reverse->return_r_branch() == pointer) {
						reverse->set_bf(0);
					} else { 
						if (pointer->return_bf() == -1)
							LR(reverse);
						else
							LL(reverse);
					}
				} else {
					if (reverse->return_l_branch() == pointer) {
						reverse->set_bf(0);
					} else {
						if (pointer->return_bf() == 1)
							RL(reverse);
						else
							RR(reverse);
					}
				}
			}
		}
	}
}

template <typename Type>
void AVL_tree<Type>::remove_data(const Type r_data)
{
	Data <Type> *found_data;
	Data <Type> *parent;
	find_data(r_data, root, &found_data);

	parent = found_data->return_parent();
	if (parent != nullptr) {
		if (parent->return_l_branch() == found_data) parent->set_l_branch(nullptr);
		if (parent->return_r_branch() == found_data) parent->set_r_branch(nullptr);
	}
	
	remove(found_data);
}

template <typename Type>
void AVL_tree<Type>::find_data(const Type f_data, Data<Type> *data, Data<Type> **found_data)
{
	if(data != nullptr) {
		find_data (f_data, data->return_l_branch(), found_data);
		find_data (f_data, data->return_r_branch(), found_data);
		if(data->return_data() == f_data) *found_data = data;
	}
}

template <typename Type>
Data <Type> *AVL_tree<Type>::return_root()
{
	return root;
}

template <typename Type>
void AVL_tree<Type>::Pre_order(Data<Type> *data)
{
	if(data != nullptr) {
		std::cout << data->return_data() << "| ";
		Pre_order (data->return_l_branch());
		Pre_order (data->return_r_branch());
	}
}

template <typename Type>
void AVL_tree<Type>::Pre_order_avl(Data<Type> *data)
{
	int l_h, r_h;
	if(data != nullptr) {
		std::cout << "\n- - - - - - - - - - - - - - - - - - - - ";
		std::cout << "\nDla wartosci: " << data->return_data();
		l_h = find_height(data->return_l_branch());
		std::cout << "\nWysokosc lewego poddrzewa: " << l_h;
		r_h = find_height(data->return_r_branch());
		std::cout << "\nWysokosc prawego poddrzewa: " << r_h;
		std::cout << "\nRoznica wysokosci poddrzew: " << abs(l_h-r_h);
		Pre_order_avl (data->return_l_branch());
		Pre_order_avl (data->return_r_branch());
	}
}

template <typename Type>
void AVL_tree<Type>::Post_order(Data<Type> *data)
{
	if(data != nullptr) {
		Post_order (data->return_l_branch());
		Post_order (data->return_r_branch());
		std::cout << data->return_data() << " | ";
	}
}

template <typename Type>
void AVL_tree<Type>::In_order(Data<Type> *data)
{
	if(data != nullptr) {
		In_order (data->return_l_branch());
		std::cout << data->return_data() << " | ";
		In_order (data->return_r_branch());
		
	}
}

template <typename Type>
void AVL_tree<Type>::RR(Data <Type> *A)
{
	std::cout << "\n-->Wykonuje rotacja RR";
	Data<Type> *B = A->return_r_branch();
	Data<Type> *p = A->return_parent();

	A->set_r_branch(B->return_l_branch());
	if (A->return_r_branch()!=nullptr) A->return_r_branch()->set_parent(A);
	B->set_l_branch(A);
	B->set_parent(p);
	A->set_parent(B);
	if (p!=nullptr) {
		if(p->return_l_branch() == A) 
			p->set_l_branch(B);
		else
			p->set_r_branch(B);
	} else {
		root = B;
	}

	if(B->return_bf() == -1) {
		B->set_bf(0);
		A->set_bf(0);
	} else {
		A->set_bf(-1);
		B->set_bf(1);
	}

}

template <typename Type>
void AVL_tree<Type>::LL(Data <Type> *A)
{
	std::cout << "\n-->Wykonuje rotacja LL";
	Data<Type> *B = A->return_l_branch();
	Data<Type> *p = A->return_parent();

	A->set_l_branch(B->return_r_branch());
	if (A->return_l_branch()!=nullptr) A->return_l_branch()->set_parent(A);
	B->set_r_branch(A);
	B->set_parent(p);
	A->set_parent(B);
	if (p!=nullptr) {
		if(p->return_l_branch() == A) 
			p->set_l_branch(B);
		else
			p->set_r_branch(B);
	} else {
		root = B;
	}

	if(B->return_bf() == 1) {
		B->set_bf(0);
		A->set_bf(0);
	} else {
		A->set_bf(1);
		B->set_bf(-1);
	}

}

template <typename Type>
void AVL_tree<Type>::RL(Data <Type> *A)
{
	std::cout << "\n-->Wykonuje rotacja RL";
	Data<Type> *B = A->return_r_branch();
	Data<Type> *C = B->return_l_branch();
	Data<Type> *p = A->return_parent();

	B->set_l_branch(C->return_r_branch());
	if (B->return_l_branch()!=nullptr) B->return_l_branch()->set_parent(B);

	A->set_r_branch(C->return_l_branch());
	if (A->return_r_branch()!=nullptr) A->return_r_branch()->set_parent(A);

	C->set_l_branch(A);
	C->set_r_branch(B);
	A->set_parent(C);
	B->set_parent(C);
	C->set_parent(p);

	if (p!=nullptr) {
		if(p->return_l_branch() == A) 
			p->set_l_branch(C);
		else
			p->set_r_branch(C);
	} else {
		root = C;
	}

	if(C->return_bf() == -1) A->set_bf(1); else A->set_bf(0);
	if(C->return_bf() == 1) B->set_bf(-1); else B->set_bf(0);

	C->set_bf(0);
}

template <typename Type>
void AVL_tree<Type>::LR(Data <Type> *A)
{
	std::cout << "\n-->Wykonuje rotacja LR";
	Data<Type> *B = A->return_l_branch();
	Data<Type> *C = B->return_r_branch();
	Data<Type> *p = A->return_parent();

	B->set_r_branch(C->return_l_branch());
	if (B->return_r_branch()!=nullptr) B->return_r_branch()->set_parent(B);

	A->set_l_branch(C->return_r_branch());
	if (A->return_l_branch()!=nullptr) A->return_l_branch()->set_parent(A);

	C->set_r_branch(A);
	C->set_l_branch(B);
	A->set_parent(C);
	B->set_parent(C);
	C->set_parent(p);

	if (p!=nullptr) {
		if(p->return_l_branch() == A) 
			p->set_l_branch(C);
		else
			p->set_r_branch(C);
	} else {
		root = C;
	}

	if(C->return_bf() == 1) A->set_bf(-1); else A->set_bf(0);
	if(C->return_bf() == -1) B->set_bf(1); else B->set_bf(0);

	C->set_bf(0);
}