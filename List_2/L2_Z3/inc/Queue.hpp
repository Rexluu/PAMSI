class Queue
{
	Data *first;
	Data *last;
	unsigned long int count;
public:
	Queue();
	~Queue();
	
	const unsigned int length();
	void push(variable_type data);
	void remove();
	void show();
	void remove_all();
};

Queue::Queue()
{
	first = NULL;
	last = NULL;
	count = 0;
}

Queue::~Queue()
{
	first = NULL;
	last = NULL;
}

const unsigned int Queue::length()
{
	return count;
}

void Queue::push(variable_type data)
{
	Data *new_data = new Data;	

	if (first==NULL){
		new_data->new_data(data);
		first=new_data;
		last=new_data;
	} else {
		new_data->new_data(data);
		last->change_p_next_data(new_data); // current last has null, so change to new adress
		last=new_data;	// change last
	}

	count++;
	new_data=NULL;
}

void Queue::show()
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

void Queue::remove_all()
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

void Queue::remove()
{
	Data *pointer = first;
	Data *temp = NULL;
	
	if (count==1) {
		delete pointer;
		first = NULL;
	} else {
		for(unsigned int i = 1; i < count-1; i++){
			pointer = pointer->return_p_next_data();
		}
	
		temp = pointer;
		pointer = pointer->return_p_next_data();
		delete pointer;

		temp->change_p_next_data(NULL);
		last = temp;
	}

	count --;
	temp = NULL;
	pointer = NULL;

}
