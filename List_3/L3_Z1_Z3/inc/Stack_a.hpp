template <typename Type> // Stack using dynamic array
class Stack_a
{
	unsigned long int length_array;
	unsigned long int count;
	Type *array = new Type[1];

public:
	Stack_a();
	~Stack_a();
	void remove();
	void pop();
	Type show(const unsigned long int number);
	void show_all();
	void push_inc(const Type element);
	void push(const Type element);
	const int length();
	void expand(const unsigned long int new_length);
};

template <typename Type>
Stack_a<Type>::Stack_a()
{
	length_array = 1;	
	count = 0;
}

template <typename Type>
Stack_a<Type>::~Stack_a()
{
	delete [] array;
}

template <typename Type>
void Stack_a<Type>::remove()
{
	delete [] array;
}

template <typename Type>
void Stack_a<Type>::pop()
{
	if (count==0) throw
	array[count]=NULL;
	count--;
}

template <typename Type>
Type Stack_a<Type>::show(const unsigned long int number)
{
	return array[number];
}

template <typename Type>
void Stack_a<Type>::show_all()
{
	for (unsigned int i = 0; i < count; i++)
		std::cout << i << ": " << array[i] << "\n";
}

template <typename Type>
void Stack_a<Type>::push_inc(const Type element) // optimised for memory
{
	count++;
	if (count > length_array) expand(length_array+1); 
	array[count-1] = element;
}

template <typename Type>
void Stack_a<Type>::push(const Type element) // optimised for efficiency/time
{
	count++;
	if (count > length_array) expand(length_array*2); 
	array[count-1] = element;
}

template <typename Type>
const int Stack_a<Type>::length()
{
	return length_array;
}

template <typename Type>
void Stack_a<Type>::expand(const unsigned long int new_length)
{
	Type *temp_array = new Type[new_length];
	
	for (unsigned int i = 0; i < length_array; i++)
		temp_array[i] = array[i];  // it isint the best way, better use memcpy or new_n

	remove();
	array = temp_array;
	length_array = new_length;
}
