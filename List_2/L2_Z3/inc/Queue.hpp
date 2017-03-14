template <typename Type>
class Queue
{
	Data <Type> *first;
	Data <Type> *last;
	unsigned long int count;
public:
	Queue();
	~Queue();
	
	const unsigned int length();
	void push(Type data);
	void remove();
	void show();
	void remove_all();
};

template <typename Type>
Queue<Type>::Queue()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <typename Type>
Queue<Type>::~Queue()
{
	first = nullptr;
	last = nullptr;
}

template <typename Type>
const unsigned int Queue<Type>::length()
{
	return count;
}

template <typename Type>
void Queue<Type>::push(Type data)
{
	Data <Type> *new_data = new Data <Type>;	

	if (first==nullptr){
		new_data->new_data(data);
		first=new_data;
		last=new_data;
	} else {
		new_data->new_data(data);
		last->change_p_next_data(new_data); // current last has nullptr, so change to new adress
		last=new_data;	// change last
	}

	count++;
	new_data=nullptr;
}

template <typename Type>
void Queue<Type>::show()
{
	Data <Type> *pointer = first;
	unsigned int counter = 0;

	while(pointer!=nullptr)
	{
		cout << "Nr " << ++counter << " : " << pointer->return_data() << endl;
		pointer = pointer->return_p_next_data();
	}
	pointer = nullptr;
}

template <typename Type>
void Queue<Type>::remove_all()
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
}

template <typename Type>
void Queue<Type>::remove()
{
	Data <Type> *pointer = first;
	Data <Type> *temp = nullptr;
	
	if (count==1) {
		delete pointer;
		first = nullptr;
	} else {
		for(unsigned int i = 1; i < count-1; i++){
			pointer = pointer->return_p_next_data();
		}
	
		temp = pointer;
		pointer = pointer->return_p_next_data();
		delete pointer;

		temp->change_p_next_data(nullptr);
		last = temp;
	}

	count --;
	temp = nullptr;
	pointer = nullptr;

}
