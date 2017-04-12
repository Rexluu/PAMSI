template <typename Type>
class Tree_Data
{
	Type data;  // variable, not class
	Tree_Data <Type> *parent;
	SL_List <Tree_Data <Type>*> branch;

public:
	Tree_Data();
	~Tree_Data();
	
	void set_data(const Type n_data);
	const Type get_data();

	void set_parent(Tree_Data <Type> *pointer);
	Tree_Data <Type> *get_parent();	

	void set_branch(Tree_Data <Type> *pointer);
	Tree_Data <Type> *get_branch(const unsigned long int number);
	void remove(const unsigned long int number);

	const unsigned long int count_branches();
};

template <typename Type>
Tree_Data<Type>::Tree_Data()
{
	parent = nullptr;
}

template <typename Type>
Tree_Data<Type>::~Tree_Data()
{
	parent = nullptr;
	branch.remove_all();
}

template <typename Type>
void Tree_Data<Type>::set_data(const Type n_data)
{
	data = n_data;
}

template <typename Type>
const Type Tree_Data<Type>::get_data()
{
	return data;
}

template <typename Type>
void Tree_Data<Type>::set_parent(Tree_Data <Type> *pointer)
{
	parent = pointer;
}

template <typename Type>
Tree_Data <Type> *Tree_Data<Type>::get_parent()
{
	return parent;
}

template <typename Type>
void Tree_Data<Type>::set_branch(Tree_Data <Type> *pointer)
{
	
	branch.push(branch.length()+1, pointer);
}

template <typename Type>
void Tree_Data<Type>::remove(const unsigned long int number)
{
	branch.remove(number);
}

template <typename Type>
Tree_Data <Type> *Tree_Data<Type>::get_branch(const unsigned long int number)
{
	return branch.pop(number);
}

template <typename Type>
const unsigned long int Tree_Data<Type>::count_branches()
{
	return branch.length();
}
