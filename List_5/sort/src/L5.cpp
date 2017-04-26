#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <array>
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "introsort.hpp"
using namespace std;

void revert(int *array, unsigned int length)
{
    unsigned int index2 = length-1;

    for (unsigned int i = 0; i < length/2; i++) {
        int temp = array[i];
        array[i] = array[index2];
        array[index2] = temp;
        index2--;
    }    
}

double average_time(double *array, int number)
{
    double sum = array[0];
    for (int i = 1; i < number; i++)
        sum+=array[i];

    return sum/number;
}

void random_fill(int *array, unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
        array[i] = rand();
}

double test(unsigned int length, double percentage, bool rev, char type)
{
    double time[100];
    time_t start,stop;
    int array[length];

    for (int i = 0; i < 100; i++){
        random_fill(array, length);
        if (percentage > 0) quicksort(array,length*percentage); // only for sorted_out arrays
        if (rev) revert(array, length); //only for revert test
       
        switch (type) {
            case 'q':
                start = clock(); 
                quicksort(array,length); 
                break;

            case 'm':
                start = clock(); 
                mergesort(array,length); 
                break;

            case 'i':
                start = clock(); 
                introsort(array,length);
                break;

            case 's':
                start = clock(); 
                sort(array, array+length);
                break;
        }

        stop = clock();
        time[i] = double (stop-start)/CLOCKS_PER_SEC;
    }
    return average_time(time, 100);
}

void time_test()
{
    char array_type[4] = {'q','m','i','s'}; // in order: quicksort, mergesort, introspective (or something like that)
    for (unsigned ml = 0; ml < 4; ml++) { // ml - main loop

    cout << endl; 

        switch (array_type[ml]) {
            case 'q':
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "Quicksort" << endl;
                cout << "- - - - - - - - - - - - - -" << endl;
                break;

            case 'm':
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "Mergesort" << endl;
                cout << "- - - - - - - - - - - - - -" << endl; 
                break;

            case 'i':
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "Introspective" << endl;
                cout << "- - - - - - - - - - - - - -" << endl;
                break;

            case 's':
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "std::sort" << endl;
                cout << "- - - - - - - - - - - - - -" << endl;
                break;
        }

        // one section have 8 pos of time: random, 25%, 50%, 75%, 95%, 99%, 99,7%, revert(1)
        double array10k_time[8];
        double array50k_time[8];
        double array100k_time[8];
        double array500k_time[8];
        double array1M_time[8]; 

        double percentage_array[8] = {0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997, 1};
        for (unsigned int i = 0; i < 8; i++) {
            array10k_time[i] = test(10000, percentage_array[i], [](unsigned int i)->bool{if (i==7) return true; else return false;}(i), array_type[ml]);
            array50k_time[i] = test(50000, percentage_array[i], [](unsigned int i)->bool{if (i==7) return true; else return false;}(i), array_type[ml]);
            array100k_time[i] = test(100000, percentage_array[i], [](unsigned int i)->bool{if (i==7) return true; else return false;}(i), array_type[ml]);
            array500k_time[i] = test(500000, percentage_array[i], [](unsigned int i)->bool{if (i==7) return true; else return false;}(i), array_type[ml]);
            array1M_time[i] = test(1000000, percentage_array[i], [](unsigned int i)->bool{if (i==7) return true; else return false;}(i), array_type[ml]);  
        }


        string titles[8] = {"Czas sortowania losowych elementów: ", "Czas sortowania przy wstępnym posortowaniu 25%: ", "Czas sortowania przy wstępnym posortowaniu 50%: ", 
        "Czas sortowania przy wstępnym posortowaniu 75%: ", "Czas sortowania przy wstępnym posortowaniu 95%: ", "Czas sortowania przy wstępnym posortowaniu 99%: ", 
        "Czas sortowania przy wstępnym posortowaniu 99,7%: ", "Czas sortowania elementow posortowanych odwrotnie: "};
        for (unsigned int i = 0; i < 8; i++)
        {
            cout << titles[i] << endl;
            cout << "> 10k:  " << array10k_time[i] << "[s]" << endl;
            cout << "> 50k:  " << array50k_time[i] << "[s]" << endl;
            cout << "> 100k: " << array100k_time[i] << "[s]" << endl;
            cout << "> 500k: " << array500k_time[i] << "[s]" << endl;
            cout << "> 1M:   " << array1M_time[i] << "[s]" << endl << endl;
        }
    }
}   

void simple_test()
{
    const unsigned int length = 10;
                int array[length];
                
    char array_type[4] = {'q','m','i','s'}; // in order: quicksort, mergesort, introspective (or something like that)
    for (unsigned ml = 0; ml < 4; ml++) { // ml - main loop

    cout << endl; 

        switch (array_type[ml]) {
            case 'q': 
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "Quicksort" << endl;
                cout << "- - - - - - - - - - - - - -" << endl;
                for (unsigned int i = 0; i < length; i++)
                    array[i] = rand()%50;
                for (unsigned int i = 0; i < length; i++)
                    cout << " | " << array[i];
                quicksort(array, length);
                break;

            case 'm':
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "Mergesort" << endl;
                cout << "- - - - - - - - - - - - - -" << endl; 
                for (unsigned int i = 0; i < length; i++)
                    array[i] = rand()%50;
                for (unsigned int i = 0; i < length; i++)
                    cout << " | " << array[i];
                mergesort(array, length);
                break;

            case 'i':
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "Introspective" << endl;
                cout << "- - - - - - - - - - - - - -" << endl;
                for (unsigned int i = 0; i < length; i++)
                    array[i] = rand()%50;
                for (unsigned int i = 0; i < length; i++)
                    cout << " | " << array[i];
                introsort(array, length);
                break;

            case 's':
                cout << "- - - - - - - - - - - - - -" << endl;
                cout << "std::sort" << endl;
                cout << "- - - - - - - - - - - - - -" << endl;
                for (unsigned int i = 0; i < length; i++)
                    array[i] = rand()%50;
                for (unsigned int i = 0; i < length; i++)
                    cout << " | " << array[i];
                sort(array, array+length);
                break;
        }

    cout << endl;
    for (unsigned int i = 0; i < length; i++) {
        cout << " | " << array[i];
    }

    cout << endl;
    cout << endl;

    }
}


int main()
{
    srand(time(NULL));
    simple_test();
    time_test();
    return 0;
}
 