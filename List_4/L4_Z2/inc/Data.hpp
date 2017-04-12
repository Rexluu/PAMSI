template <typename Type>
class Data
{
	Type data;  // variable, not class
	Data <Type> **branch;
	size;

public:
	Data(const unsigned int size);
	~Data();
	
	void new_data(const Type data);
	Type return_data();
	void change_p_branch(Data <type> *n_data, unsigned int number);
};

template <typename Type>
Data<Type>::Data(const unsigned int in_size)
{
	branch = new Data <Type> *[in_size];
	size = in_size;
	for (unsigned int i = 0; i < size; i++)
		branch[number] = nullptr;
}

template <typename Type>
Data<Type>::~Data()
{
	delete [] branch;
}

template <typename Type>
void Data<Type>::new_data(const Type n_data)
{
	data = n_data;
}

template <typename Type>
Type Data<Type>::return_data()
{
	return data;
}

template <typename Type>
void Data<Type>::change_p_branch(Data <type> *n_data, unsigned int number)
{
	branch[number] = n_data;
}


