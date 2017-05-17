#include <iostream>
#include <cstdlib>
#include "List.hpp"
#include "Double_hash.hpp"
#include "Linear.hpp"
#include "Link.hpp"

unsigned int test_data(unsigned int c)
{
    int array [8] = {18,41,22,44,59,32,31,73};
    if (c > 7) return std::rand()%99;

    return array[c];

    //return std::rand();
}

void linear_test(const unsigned int size)
{
    Linear test(size);
    const int number = 18;
    unsigned int c = 0;

    std::cout << "\nDodaje:\n";

    unsigned int data = test_data(c);
    unsigned int key = data%size;
    std::cout << "Dana: " << data << " o kluczu pierwotnym: " << key << "\n";
    while(test.put(data) != false)
    {
        c++;
        data = test_data(c);
        key = data%size;
        std::cout << "Dana: " << data << " o kluczu pierwotnym: " << key << "\n";
    }

    std::cout << "\nPo dodaniu: \n";
    test.show();

    std::cout << "\nPozycja danej " << number << " : " << test.get(number) << "\n";
    std::cout << "Po usunieciu " << number << ":\n";
    test.remove(number);

    test.show();

}

void link_test(const unsigned int size)
{
    Link test(size);
    const unsigned int number = 18;
    unsigned int c = 0;

    std::cout << "\nDodaje:\n";

    unsigned int data;
    for(unsigned int i = 0; i < size; i++)
    {
        data = test_data(c);
        c++;
        std::cout << "Dana: " << data << " o kluczu: ";
        std::cout << data%size << "\n";
        test.put(data);
    }

    std::cout << "\nPo dodaniu: \n";
    test.show();

    std::cout << "\nPozycja danej " << number << ": pos.";
    std::cout << number%size << " #";
    std::cout << test.get(number) << "\n";
    std::cout << "Po usunieciu " << number << ":\n";
    test.remove(number);

    test.show();
}

void double_hash_test(const unsigned int size)
{
    Double_hash test(size);
    const int number = 18;
    unsigned int c = 0;

    std::cout << "\nDodaje:\n";

    unsigned int data = test_data(c);
    unsigned int key = data%size;
    std::cout << "Dana: " << data << " o kluczu pierwotnym: " << key << "\n";
    while(test.put(data) != false)
    {
        c++;
        data = test_data(c);
        key = data%size;
        std::cout << "Dana: " << data << " o kluczu pierwotnym: " << key << "\n";
    }

    std::cout << "\nPo dodaniu: (dla q = 2) \n";
    test.show();

    std::cout << "\nPozycja danej " << number << " : " << test.get(number) << "\n";
    std::cout << "Po usunieciu " << number << ":\n";
    test.remove(number);

    test.show();

}

bool prime_test(const unsigned int size)
{
    if (size < 2) return false;

    for (unsigned int i = 2; i*i<=size; i++)
        if (size%i == 0) return false;
    return true;
}

int main()
{
    srand( time( NULL ) );

    unsigned int size;
    bool flag_prime = false;

    while (flag_prime == false) {
        std::cout << "\nPodaj ilosc elementow: " ;
        std::cin >> size;
        flag_prime = prime_test(size);
        if(flag_prime == false) std::cerr << "\nPodaj liczbe pierwsza!\n";
    }

    link_test(size);
    linear_test(size);
    double_hash_test(size);

    return 0;
}