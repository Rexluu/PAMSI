template <typename Type>
class Data_pq
{
	Type data;  // variable, not class
	unsigned long int priority;

	Data_pq <Type> *next_data;
	Data_pq <Type> *previous_data;

public:
	Data_pq();
	~Data_pq();

	void new_data(const unsigned long int n_priority, const Type n_data);
	Type return_data();

	Data_pq <Type> *return_p_next_data();
	Data_pq <Type> *return_p_previous_data();
	const unsigned long int return_priority();
	void change_p_next_data(Data_pq <Type> *next);
	void change_p_previous_data(Data_pq <Type> *previous);
};

template <typename Type>
Data_pq<Type>::Data_pq()
{
	next_data = nullptr;
	previous_data = nullptr;
	priority = 0;
}

template <typename Type>
Data_pq<Type>::~Data_pq()
{
	next_data = nullptr;
}

template <typename Type>
void Data_pq<Type>::new_data(const unsigned long int n_priority, const Type n_data)
{
	priority = n_priority;
	data = n_data;
}

template <typename Type>
Type Data_pq<Type>::return_data()
{
	return data;
}

template <typename Type>
const unsigned long int Data_pq<Type>::return_priority()
{
	return priority;
}

template <typename Type>
Data_pq <Type> *Data_pq<Type>::return_p_next_data()
{
	return next_data;
}

template <typename Type>
Data_pq <Type> *Data_pq<Type>::return_p_previous_data()
{
	return previous_data;
}

template <typename Type>
void Data_pq<Type>::change_p_next_data(Data_pq <Type> *next)
{
	next_data = next;
}

template <typename Type>
void Data_pq<Type>::change_p_previous_data(Data_pq <Type> *previous)
{
	previous_data = previous;
}

