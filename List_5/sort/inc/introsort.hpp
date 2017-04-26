#include <cmath>


template <typename Type>
void heapify (Type *array, unsigned int i, const unsigned int length)
{
    unsigned int j;

    while (i <= length/2) {
    
    j = 2*i;
    
    if (j+1 <= length && array[j+1] > array[j])
        j = j+1;
    
    if (array[i]<array[j]) 
        swap(array,i,j); //swap function from quicksort.hpp
    else break;

    i = j;
    }
}

template <typename Type>
void heapsort (Type *array, const unsigned int length)
{
    unsigned int i;

    for (i = length/2; i > 0; i--)
        heapify(array-1, i, length);

    for (i = length-1; i > 0; i--){
        swap(array,0,i); //swap function from quicksort.hpp
        heapify(array-1, 1, i);
    }
}

template <typename Type>
void insertsort (Type *array, const unsigned int length)
{
    Type temp;
    unsigned int j;

    for (unsigned int i = 1; i < length; i++) {
    temp = array[i];
    for (j = i; j > 0; j--)
        if (temp < array[j-1]) 
            array[j] = array[j-1];
        else break;

    array[j] = temp;
    }
}

template <typename Type>
void isort (Type *array, const unsigned int length, unsigned int number)
{
    unsigned int pivot;

    if (number <= 0){
        heapsort(array, length);
    } else {
    
    pivot = split_and_sort(array, 0, length-1); //split_and_sort as partition from quicksort.hpp

    if (pivot > 9)
        isort(array,pivot,number-1);
    if (length-1-pivot > 9)
        isort(array+pivot+1,length-1-pivot,number-1);
    }
} 

template <typename Type>
void introsort(Type *array, const unsigned int length)
{
    isort (array, length, (unsigned int)floor(2*log(length)/M_LN2));
    insertsort (array, length);
}