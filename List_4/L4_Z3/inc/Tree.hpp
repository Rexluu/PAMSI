template <typename Type>
class Binary_Tree
{
	Data <Type> *root;
	unsigned long int size;

	void remove_all(Data<Type> *data);
public:
	Binary_Tree();
	~Binary_Tree();

	void push(Type n_data);
	const unsigned long int length();
	
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
	remove_all(root);
	root = nullptr;
}

template <typename Type>
void Binary_Tree<Type>::remove_all(Data<Type> *data)
{
	if(data != nullptr) {
		remove_all (data->return_l_branch());
		remove_all (data->return_r_branch());
		delete data;
	}
}

template <typename Type>
const unsigned long int Binary_Tree<Type>::length()
{
	return size;
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
	unsigned long int count = 1;

	if (root == nullptr){
		root = new_data;
		new_data = nullptr;
	} else {
		while (1) {
			if(n_data > pointer->return_data()) {
				if ( (pointer->return_r_branch()) == nullptr){
					pointer->set_r_branch(new_data);
					break;
				}
				pointer = pointer->return_r_branch();
				count++;
			} else {
				if(n_data < pointer->return_data()) {
					if ( (pointer->return_l_branch()) == nullptr){
						pointer->set_l_branch(new_data);
						break;
					}
				pointer = pointer->return_l_branch();
				count++;
				}
			} // else if equal throw (optional)
		}
	}

	if ( count > size ) size = count;	
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

