template <typename Type>
class Priority_queue // priority queue on two-way list
{
	Data <Type> *first;
	unsigned long int count;

public:
	Priority_queue();
	~Priority_queue();
	
	const unsigned int length();
	void push(const unsigned long int priority, const Type data);
	void remove_min();
	void show();
	const Type min();
};

template <typename Type>
Priority_queue<Type>::Priority_queue()
{
	first = nullptr;
	count = 0;
}

template <typename Type>
Priority_queue<Type>::~Priority_queue()
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
const unsigned int Priority_queue<Type>::length()
{
	return count;
}

template <typename Type>
void Priority_queue<Type>::push(const unsigned long int priority, const Type data)  // not my best
{
	Data <Type> *new_data = new Data <Type>;
	Data <Type> *pointer = first;
	Data <Type> *prev_pointer = nullptr;

	new_data->new_data(priority, data);

	if (count == 0 ) { 					// first element
		first = new_data;
	} else {
		while((pointer != nullptr) && (pointer->return_priority() <= priority)){
			prev_pointer = pointer;
			pointer = pointer->return_p_next_data();
		}
		
		if (pointer == nullptr){ 			// last element
			new_data -> change_p_previous_data(prev_pointer);
			prev_pointer -> change_p_next_data(new_data);
		} else {					// middle element
			new_data->change_p_next_data(pointer);	
			new_data->change_p_previous_data(prev_pointer);

			pointer->change_p_previous_data(new_data);

			if(prev_pointer != nullptr) //if it isin't new first
				prev_pointer -> change_p_next_data(new_data);
			else
				first = new_data;
		}
	}


	pointer = nullptr;
	prev_pointer = nullptr;
	count++;
}

template <typename Type>
void Priority_queue<Type>::show()
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
const Type Priority_queue<Type>::min()
{
	return first->return_data();
}


template <typename Type>
void Priority_queue<Type>::remove_min()
{
	Data <Type> *pointer = first->return_p_next_data();
	pointer->change_p_previous_data(nullptr);

	delete first;
	first = pointer;

	count--;
}
