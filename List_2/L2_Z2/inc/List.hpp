class SL_List // Single-linked List
{
	Data *first;
	Data *last;
	unsigned long int count;
public:
	SL_List();
	~SL_List();
	
	const unsigned int length();
	void push(unsigned int number, variable_type data);
	void remove(unsigned int number);
	void show();
	void remove_all();
};

SL_List::SL_List()
{
	first = NULL;
	last = NULL;
	count = 0;
}

SL_List::~SL_List()
{
	first = NULL;
	last = NULL;
}

const unsigned int SL_List::length()
{
	return count;
}

void SL_List::push(unsigned int number, variable_type data)
{
	Data *new_data = new Data;

	
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
		
			Data *pointer = first;
			Data *temp = NULL;
		
			for(unsigned int i=1; i < number-1; i++){
				pointer = pointer->return_p_next_data();
			}

			temp = pointer;
			pointer = pointer->return_p_next_data();
			new_data->new_data(data);
			new_data->change_p_next_data(pointer);
			temp->change_p_next_data(new_data);
			
			pointer=NULL;
			temp=NULL;
		}

	count++;
}

void SL_List::show()
{
	Data *pointer = first;
	unsigned int counter = 0;

	while(pointer!=NULL)
	{
		cout << "Nr " << ++counter << " : " << pointer->return_data() << endl;
		pointer = pointer->return_p_next_data();
	}
	pointer = NULL;
}

void SL_List::remove_all()
{
	Data *pointer = first;
	Data *temp = NULL;

	while(pointer!=NULL)
	{
		temp = pointer->return_p_next_data();
		delete pointer;
		pointer = temp;
	}

	pointer = NULL;
	temp = NULL;
	count = 0;
}

void SL_List::remove(unsigned int number)
{
	Data *pointer = first;
	Data *temp = NULL;
	Data *rem_data = NULL;
	
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
		pointer = pointer->return_p_next_data(); // if last it will return NULL, so everything fine
		if(pointer==NULL) last = temp; // new last if removed last
		delete rem_data;
		temp->change_p_next_data(pointer);
	}

	pointer = NULL;
	temp = NULL;
	rem_data = NULL;

	count--;
}
