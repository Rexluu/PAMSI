class Link
{
    SL_List <unsigned int> **array;
    unsigned int length;

    public:
    Link(const unsigned int size);
    //~Link(); 
    void put(const unsigned int data);
    int get(const unsigned int data); //-1 if not found
    void remove(const unsigned int data);
    void show();
};

Link::Link(const unsigned int size)
{
    length = size;
    for (unsigned int i = 0; i < length; i++)
        array[i] = new SL_List <unsigned int>;
}

/*
Link::~Link()
{
    for (unsigned int i = 0; i < length; i++)
        delete array[i];
} */

void Link::put(const unsigned int data)
{
    unsigned int key = data%length;
    unsigned int pos = (array[key]->length())+1;
    array[key]->push(pos, data);
}

int Link::get(const unsigned int data)
{
     unsigned int key = data%length;
     for (unsigned int i = 1; i <= array[key]->length(); i++)
        if (array[key]->pop(i) == data) return i;

    return -1;
}

void Link::remove(const unsigned data)
{
    unsigned int key = data%length;
    int position = get(data);
    if (position != -1) array[key]->remove(position);
}

void Link::show()
{
    std::cout << "\n";

    for (unsigned int i = 0; i < length; i++) {
        std::cout << "Miejsce " << i << ": ";
        for (unsigned int j = 1; j <= array[i]->length(); j++)
            std::cout << "| " << array[i]->pop(j) << " ";
        std::cout << "|\n";
    }
}

