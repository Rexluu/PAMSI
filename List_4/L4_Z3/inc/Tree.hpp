template <typename Type>
class Binary_Tree
{
	Data <Type> *root;

	void remove(Data<Type> *data);
	void find_data(const Type f_data, Data<Type> *data, Data<Type> **found_data);
	long int find_height(Data<Type> *data);
public:
	Binary_Tree();
	~Binary_Tree();

	void push(Type n_data);
	void remove_data(const Type r_data);
	const unsigned long int height();
	
	const Type root_data();
	Data <Type> *return_root();

	void Pre_order(Data <Type> *data);
	void Post_order(Data <Type> *data);
	void In_order(Data <Type> *data);
};

template <typename Type>
Binary_Tree<Type>::Binary_Tree()
{
	root = nullptr;
}

template <typename Type>
Binary_Tree<Type>::~Binary_Tree()
{
	remove(root);
	root = nullptr;
}

template <typename Type>
void Binary_Tree<Type>::remove(Data<Type> *data)
{
	if(data != nullptr) {
		remove (data->return_l_branch());
		remove (data->return_r_branch());
		delete data;
	}
}

template <typename Type>
long int Binary_Tree<Type>::find_height(Data<Type> *data)
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
const unsigned long int Binary_Tree<Type>::height()
{
	return find_height(root);
}


template <typename Type>
const Type Binary_Tree<Type>::root_data()
{
	return root->return_data();
}

template <typename Type>
void Binary_Tree<Type>::push(Type n_data)
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
	}
}

template <typename Type>
void Binary_Tree<Type>::remove_data(const Type r_data)
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
void Binary_Tree<Type>::find_data(const Type f_data, Data<Type> *data, Data<Type> **found_data)
{
	if(data != nullptr) {
		find_data (f_data, data->return_l_branch(), found_data);
		find_data (f_data, data->return_r_branch(), found_data);
		if(data->return_data() == f_data) *found_data = data;
	}
}

template <typename Type>
Data <Type> *Binary_Tree<Type>::return_root()
{
	return root;
}

template <typename Type>
void Binary_Tree<Type>::Pre_order(Data<Type> *data)
{
	if(data != nullptr) {
		std::cout << data->return_data() << " | ";
		Pre_order (data->return_l_branch());
		Pre_order (data->return_r_branch());
	}
}

template <typename Type>
void Binary_Tree<Type>::Post_order(Data<Type> *data)
{
	if(data != nullptr) {
		Post_order (data->return_l_branch());
		Post_order (data->return_r_branch());
		std::cout << data->return_data() << " | ";
	}
}

template <typename Type>
void Binary_Tree<Type>::In_order(Data<Type> *data)
{
	if(data != nullptr) {
		In_order (data->return_l_branch());
		std::cout << data->return_data() << " | ";
		In_order (data->return_r_branch());
		
	}
}

