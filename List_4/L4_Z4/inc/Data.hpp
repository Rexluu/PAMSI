template <typename Type>
class Data
{
	Type data;  // variable, not class
	unsigned long int priority;

	Data <Type> *next_data;
	Data <Type> *previous_data;

public:
	Data();
	~Data();

	void new_data(const unsigned long int n_priority, const Type n_data);
	Type return_data();

	Data <Type> *return_p_next_data();
	Data <Type> *return_p_previous_data();
	const unsigned long int return_priority();
	void change_p_next_data(Data <Type> *next);
	void change_p_previous_data(Data <Type> *previous);
};

template <typename Type>
Data<Type>::Data()
{
	next_data = nullptr;
	previous_data = nullptr;
	priority = 0;
}

template <typename Type>
Data<Type>::~Data()
{
	next_data = nullptr;
}

template <typename Type>
void Data<Type>::new_data(const unsigned long int n_priority, const Type n_data)
{
	priority = n_priority;
	data = n_data;
}

template <typename Type>
Type Data<Type>::return_data()
{
	return data;
}

template <typename Type>
const unsigned long int Data<Type>::return_priority()
{
	return priority;
}

template <typename Type>
Data <Type> *Data<Type>::return_p_next_data()
{
	return next_data;
}

template <typename Type>
Data <Type> *Data<Type>::return_p_previous_data()
{
	return previous_data;
}

template <typename Type>
void Data<Type>::change_p_next_data(Data <Type> *next)
{
	next_data = next;
}

template <typename Type>
void Data<Type>::change_p_previous_data(Data <Type> *previous)
{
	previous_data = previous;
}

