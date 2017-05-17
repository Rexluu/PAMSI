class Double_hash
{
    unsigned int *array;
    unsigned int length;
    void clean();

    public:
    Double_hash(const unsigned int size);
    ~Double_hash();
    bool put(const unsigned int data); //false if array is full
    int get(const unsigned int data); //-1 if not found
    void remove(const unsigned int data);
    void show();
};

Double_hash::Double_hash(const unsigned int size)
{
    length = size;
    array = new unsigned int[length];
    clean();

}

Double_hash::~Double_hash()
{
    delete [] array;
}

void Double_hash::clean()
{
    for(unsigned int i = 0; i < length; i++)
        array[i] = 0;
}

bool Double_hash::put(const unsigned int data) 
{
    unsigned int key = data%length;
    bool flag = false;

    if (array[key] == 0) {
        array[key] = data; 
        flag = true; 
    } else {
        const unsigned int q = 2; //always true, not need to find prime number < length
        unsigned int function = q - (data % q);
        unsigned free_cell;
        for (unsigned int j = 0; j < length-1; j++) {
            free_cell = (key + j*function) % length;
            if(array[free_cell] == 0) {array[free_cell] = data; flag = true; break;}
        }

    }

    return flag;
}

void Double_hash::remove(const unsigned int data)
{
    int position = get(data);
    if (position != -1) array[position] = 0; 
}

int Double_hash::get(const unsigned int data)
{
    for (unsigned int i = 0; i < length; i++ )
        if (array[i]==data) return i;
    
    return -1;
}

void Double_hash::show()
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