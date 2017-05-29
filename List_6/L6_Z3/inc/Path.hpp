class Path
{
    int value;
    unsigned int priority;

    public:
    Path();

    void set_value(const int v);
    const int get_value();

    void set_priority(const unsigned int p);
    const unsigned int get_priority();
};

Path::Path()
{
    value = 0;
    priority = 0;
}

void Path::set_value(const int v)
{
    value = v;
}

const int Path::get_value()
{
    return value;
}

void Path::set_priority(const unsigned int p)
{
    priority = p;
}

const unsigned int Path::get_priority()
{
    return priority;
}