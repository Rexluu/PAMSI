template <typename Type>
class Tree
{
	Tree_Data <Type> *root;
	void remove_data(Tree_Data <Type> *data);
	unsigned long int find_height(Tree_Data<Type> *data);
public:
	Tree();
	~Tree();

	const Type root_data();
	Tree_Data <Type> *return_root();
	Tree_Data <Type> *return_branch(Tree_Data <Type> *pointer, const unsigned long int number);

	void push(Type n_data, Tree_Data <Type> *pointer);
	void remove(Tree_Data <Type> *data);

	void Pre_order(Tree_Data <Type> *data);
	void Post_order(Tree_Data <Type> *data);
	
	const unsigned long int height();
};

template <typename Type>
Tree<Type>::Tree()
{
	root = nullptr;
}

template <typename Type>
Tree<Type>::~Tree()
{
	remove_data(root);
	root = nullptr;
}


template <typename Type>
const Type Tree<Type>::root_data()
{
	return root->get_data();
}

template <typename Type>
Tree_Data <Type> *Tree<Type>::return_root()
{
	return root;
}


template <typename Type>
void Tree<Type>::push(Type n_data, Tree_Data <Type> *pointer)
{
	Tree_Data <Type> *new_data = new Tree_Data <Type>;
	new_data->set_data(n_data);

	if (root == nullptr){
		root = new_data;
		new_data = nullptr;
	} else {
		new_data->set_parent(pointer);
		pointer->set_branch(new_data);
	}
}

template <typename Type>
void Tree<Type>::remove(Tree_Data <Type> *data)
{
	for (unsigned long int i = 1; i <= data->count_branches(); i++)
		remove_data(data->get_branch(i));
	

	unsigned long int number = 1;
	for (unsigned long int i = 1; i <= ((data->get_parent())->count_branches()); i++)
		if ( ((data->get_parent())->get_branch(i))->get_data() != data->get_data()) 
			number++;
		else 
			break;
	(data->get_parent())->remove(number);
	delete data;
	
}

template <typename Type>
void Tree<Type>::remove_data(Tree_Data <Type> *data)
{
	for (unsigned long int i=1; i <= data->count_branches(); i++){
		remove_data(data->get_branch(i));	
	}

	delete data;
}

template <typename Type>
Tree_Data <Type> *Tree<Type>::return_branch(Tree_Data <Type> *pointer, const unsigned long int number)
{
	return pointer->get_branch(number);
}

template <typename Type>
void Tree<Type>::Pre_order(Tree_Data <Type> *data)
{
	std::cout << data->get_data() << " | ";
	for (unsigned long int i=1; i <= data->count_branches(); i++){
		Pre_order(data->get_branch(i));	
	}
		
}

template <typename Type>
void Tree<Type>::Post_order(Tree_Data <Type> *data)
{
	for (unsigned long int i=1; i <= data->count_branches(); i++){
		Post_order(data->get_branch(i));	
	}
	std::cout << data->get_data() << " | ";
}

template <typename Type>
unsigned long int Tree<Type>::find_height(Tree_Data<Type> *data)
{
	if (data == nullptr) return 0;
	
	unsigned long int height = 0;
	for (unsigned long int i=1; i <= data->count_branches(); i++){
		unsigned long int h2 = find_height(data->get_branch(i));
		if ( height < h2 ) height = h2;
	}
	
	return height+1;
}

template <typename Type>
const unsigned long int Tree<Type>::height()
{
	return find_height(root);
}

