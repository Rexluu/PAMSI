template <typename Type>
class Data
{
	Type data;  // variable, not class
	Data <Type> *next_data;

public:
	Data();
	~Data();

	void new_data(Type n_data);
	const Type return_data();

	Data <Type> *return_p_next_data();
	void change_p_next_data(Data <Type> *next);
	
};

template <typename Type>
Data<Type>::Data()
{
	next_data = nullptr;
}

template <typename Type>
Data<Type>::~Data()
{
	next_data = nullptr;
}

template <typename Type>
void Data<Type>::new_data(Type n_data)
{
	data = n_data;
}

template <typename Type>
const Type Data<Type>::return_data()
{
	return data;
}

template <typename Type>
Data <Type> *Data<Type>::return_p_next_data()
{
	return next_data;
}

template <typename Type>
void Data<Type>::change_p_next_data(Data <Type> *next)
{
	next_data = next;
}
