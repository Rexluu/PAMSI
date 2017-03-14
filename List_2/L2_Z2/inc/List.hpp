template <typename Type>
class SL_List // Single-linked List
{
	Data <Type> *first;
	Data <Type> *last;
	unsigned long int count;
public:
	SL_List();
	~SL_List();
	
	const unsigned int length();
	void push(unsigned int number, Type data);
	void remove(unsigned int number);
	void show();
	void remove_all();
};

template <typename Type>
SL_List<Type>::SL_List()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <typename Type>
SL_List<Type>::~SL_List()
{
	first = nullptr;
	last = nullptr;
}

template <typename Type>
const unsigned int SL_List<Type>::length()
{
	return count;
}

template <typename Type>
void SL_List<Type>::push(unsigned int number, Type data)
{
	Data <Type> *new_data = new Data <Type>;

	
	if(number==1) {	// add at first position
		new_data->new_data(data);
		new_data->change_p_next_data(first);
		first = new_data;
		if(count==0) last=first;
	} else if (number>count) { // add at (new) last position
			new_data->new_data(data);
			last->change_p_next_data(new_data);
			last = new_data;
		} else { // add at middle
		
			Data <Type> *pointer = first;
			Data <Type> *temp = nullptr;
		
			for(unsigned int i=1; i < number-1; i++){
				pointer = pointer->return_p_next_data();
			}

			temp = pointer;
			pointer = pointer->return_p_next_data();
			new_data->new_data(data);
			new_data->change_p_next_data(pointer);
			temp->change_p_next_data(new_data);
			
			pointer=nullptr;
			temp=nullptr;
		}

	count++;
}

template <typename Type>
void SL_List<Type>::show()
{
	Data <Type> *pointer = first;
	unsigned int long counter = 0;

	while(pointer!=nullptr)
	{
		cout << "Nr " << ++counter << " : " << pointer->return_data() << endl;
		pointer = pointer->return_p_next_data();
	}
	pointer = nullptr;
}

template <typename Type>
void SL_List<Type>::remove_all()
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
void SL_List<Type>::remove(unsigned int number)
{
	Data <Type> *pointer = first;
	Data <Type> *temp = nullptr;
	Data <Type> *rem_data = nullptr;
	
	if(number==1) {	// remove first element of List
		pointer = pointer->return_p_next_data();
		rem_data = first;
		first = pointer; // new first
		delete rem_data;
	} else { // remove middle or last element
		for(unsigned int i=1; i < number-1; i++){
			pointer = pointer->return_p_next_data();
		}
	
		temp = pointer;
		pointer = pointer->return_p_next_data();
		rem_data = pointer;
		pointer = pointer->return_p_next_data(); // if last it will return nullptr, so everything fine
		if(pointer==nullptr) last = temp; // new last if removed last
		delete rem_data;
		temp->change_p_next_data(pointer);
	}

	pointer = nullptr;
	temp = nullptr;
	rem_data = nullptr;

	count--;
}
