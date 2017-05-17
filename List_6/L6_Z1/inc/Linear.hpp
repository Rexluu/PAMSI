class Linear
{
    unsigned int *array;
    unsigned int length;
    void clean();

    public:
    Linear(const unsigned int size);
    ~Linear();
    bool put(const unsigned int data); //false if array is full
    int get(const unsigned int data); //-1 if not found
    void remove(const unsigned int data);
    void show();
};

Linear::Linear(const unsigned int size)
{
    length = size;
    array = new unsigned int[length];
    clean();
}

Linear::~Linear()
{
    delete [] array;
}

void Linear::clean()
{
    for(unsigned int i = 0; i < length; i++)
        array[i] = 0;
}

bool Linear::put(const unsigned int data) 
{
    unsigned int key = data%length;
    bool flag = false;
    for (unsigned int i = key; i < length; i++ )
        if(array[i] == 0) {array[i] = data; flag = true; break;}
    if (flag == false)
        for (unsigned int i = 0; i < key; i++ )
            if(array[i] == 0) {array[i] = data; flag = true; break;}
    return flag;
}

void Linear::remove(const unsigned int data)
{
    int position = get(data);
    if (position != -1) array[position] = 0; 
}

int Linear::get(const unsigned int data)
{
    for (unsigned int i = 0; i < length; i++ )
        if (array[i]==data) return i;
    
    return -1;
}

void Linear::show()
{
    std::cout << "\n";

    for (unsigned int i = 0; i < length; i++)
        if (i < 10) std::cout << " | " << i << ".";
        else std::cout << " | " << i;

    std::cout << "\n";

    for (unsigned int i = 0; i < length; i++)
        if (array[i] < 10) std::cout << " | " << array[i] << " ";
        else std::cout << " | " << array[i];

     std::cout << "\n";
}