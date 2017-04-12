template <typename Type>
class Data
{
	Type data;  // variable, not class
	Data *left_branch;
	Data *right_branch;
	Data *parent;

public:
	Data();
	~Data();
	
	void set_data(const Type data);
	const Type return_data();

	void set_l_branch(Data <Type> *pointer);
	Data <Type> *return_l_branch();

	void set_r_branch(Data <Type> *pointer);
	Data <Type> *return_r_branch();

	void set_parent(Data <Type> *pointer);
	Data <Type> *return_parent();	
};

template <typename Type>
Data<Type>::Data()
{
	left_branch = nullptr;
	right_branch = nullptr;
	parent = nullptr;
}

template <typename Type>
Data<Type>::~Data()
{
	left_branch = nullptr;
	right_branch = nullptr;
	parent = nullptr;
}

template <typename Type>
void Data<Type>::set_data(const Type n_data)
{
	data = n_data;
}

template <typename Type>
const Type Data<Type>::return_data()
{
	return data;
}

template <typename Type>
void Data<Type>::set_l_branch(Data <Type> *pointer)
{
	left_branch = pointer;
}

template <typename Type>
Data <Type> *Data<Type>::return_l_branch()
{
	return left_branch;
}

template <typename Type>
void Data<Type>::set_r_branch(Data <Type> *pointer)
{
	right_branch = pointer;
}

template <typename Type>
Data <Type> *Data<Type>::return_r_branch()
{
	return right_branch;
}

template <typename Type>
void Data<Type>::set_parent(Data <Type> *pointer)
{
	parent = pointer;
}

template <typename Type>
Data <Type> *Data<Type>::return_parent()
{
	return parent;
}
