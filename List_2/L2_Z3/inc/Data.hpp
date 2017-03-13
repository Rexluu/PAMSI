class Data
{
	variable_type data;
	Data *next_data;

public:
	Data();
	~Data();

	void new_data(variable_type n_data);
	const variable_type return_data();

	Data *return_p_next_data();
	void change_p_next_data(Data *next);
};

Data::Data()
{
	next_data = NULL;
}

Data::~Data()
{
	next_data = NULL;
}

void Data::new_data(variable_type n_data)
{
	data = n_data;
}

const variable_type Data::return_data()
{
	return data;
}


Data *Data::return_p_next_data()
{
	return next_data;
}

void Data::change_p_next_data(Data *next)
{
	next_data = next;
}
