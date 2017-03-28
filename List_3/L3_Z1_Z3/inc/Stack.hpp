#include "Data.hpp"

template <typename Type>
class Stack
{
	Data <Type> *first;
	unsigned long int count;
public:
	Stack();
	~Stack();
	
	const unsigned int length();
	const bool empty();
	const Type top();
	void push(Type data);
	void pop();
	void show();
};

template <typename Type>
Stack<Type>::Stack()
{
	first = nullptr;
	count = 0;
}

template <typename Type>
Stack<Type>::~Stack()
{
	Data <Type> *pointer = first;
	Data <Type> *temp = nullptr;

	while(pointer!=nullptr)
	{
		temp = pointer->return_p_next_data();
		delete pointer;
		pointer = temp;
	}

	pointer = nullptr;
	temp = nullptr;
	count = 0;

	first = nullptr;
}

template <typename Type>
const unsigned int Stack<Type>::length()
{
	return count;
}

template <typename Type>
const bool Stack<Type>::empty()
{
	if (count == 0) 
		return true;

	return false;
}

template <typename Type>
const Type Stack<Type>::top()
{
	if (empty()) {
		std::string ExcEmpty = "Stos jest pusty";
		throw ExcEmpty;
	} else
		return first->return_data();
}

template <typename Type>
void Stack<Type>::push(Type data)
{
	Data <Type> *new_data = new Data <Type>;

	new_data->new_data(data);
	new_data->change_p_next_data(first);
	first = new_data;

	count++;
}

template <typename Type>
void Stack<Type>::show()
{
	Data <Type> *pointer = first;
	unsigned int long counter = 0;

	while(pointer!=nullptr)
	{
		std::cout << "Nr " << ++counter << " : " << pointer->return_data() << std::endl;
		pointer = pointer->return_p_next_data();
	}
	pointer = nullptr;
}

template <typename Type>
void Stack<Type>::pop()
{
	
	if (empty()) {
		std::string ExcEmpty = "Stos jest pusty";
		throw ExcEmpty;
	} else {
		Data <Type> *pointer = first;
	
		pointer = pointer->return_p_next_data();
		delete first;
		first = pointer; // new first

		pointer = nullptr;
		count--;
	}
}
