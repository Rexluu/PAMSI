template <typename Type>
void swap(Type *array, const unsigned int index1, const unsigned int index2)
{
    Type temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

template <typename Type>
const unsigned int find_pivot (Type *array, const unsigned int middle_index)
{
    unsigned int mid = middle_index;

    if (array[middle_index] < array[middle_index-1] && array[middle_index+1] > array[middle_index-1]) mid = middle_index-1;
    if (array[middle_index] < array[middle_index+1] && array[middle_index-1] > array[middle_index+1]) mid = middle_index+1;

    return mid;
}

template <typename Type>
unsigned int split_and_sort(Type *array, const unsigned int first_index, const unsigned int last_index)
{
    unsigned int pivot;

    if ((last_index-first_index)>1) 
        pivot = find_pivot (array, (last_index + first_index)/2);
    else
        pivot = (last_index + first_index)/2; // there is a lot of tactic of select pivot
    
    Type middle_value = array[pivot];
    swap(array, pivot, last_index); // we know the middle value already, we dont wanna sort it;

    unsigned int counter = first_index;
    for (unsigned int i = first_index; i < last_index; i++)
        if (array[i] <= middle_value) { // if equal pivot (middle_element) do job too. (equal should boost algorithm, less time need to sort)
            swap (array, counter, i);
            counter++;
    }
    swap(array, counter, last_index); //we want back our pivot (middle element (pivot)). It will be on right(correct) place.
    return counter; // our new mid_point, now we need to sort left side and right side
}

template <typename Type>
void qsort(Type *array, const int first_index, const int last_index) // in this implementation can't be unsigned look at next condition if.
{
    if (first_index < last_index){
        unsigned int pivot = split_and_sort(array, first_index, last_index);
        qsort (array, first_index, pivot-1);
        qsort (array, pivot+1, last_index);
    }
}

template <typename Type>
void quicksort(Type *array, const unsigned int length)
{
    qsort (array, 0, length-1); // number-1 because start from 0
}