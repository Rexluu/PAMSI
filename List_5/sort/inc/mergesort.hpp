template <typename Type>
void copyarray(Type *from_array, Type *to_array, const unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
        to_array[i] = from_array[i];
}

template <typename Type>
void msort (Type *arrayA, Type *arrayB, unsigned int first_index, unsigned int middle_index, const unsigned int last_index)
{
    unsigned int index1 = first_index;
    unsigned int index2 = middle_index;

    for (unsigned int i = first_index; i < last_index; i++) {
        if ( (index1 < middle_index) && ( (index2 >= last_index) || (arrayA[index1] <= arrayA[index2]))) {
            arrayB[i] = arrayA[index1];
            index1++;
        } else {
            arrayB[i] = arrayA[index2];
            index2++;
        }
    }
}

template <typename Type>
void split (Type *arrayA, Type *arrayB, const unsigned int first_index, const unsigned int last_index)
{
    if ((last_index - first_index) >= 2) { // check if there is something to split
        unsigned int middle_index = (last_index + first_index)/2;
        split (arrayB, arrayA, first_index, middle_index);
        split (arrayB, arrayA, middle_index, last_index);
        msort(arrayA, arrayB, first_index, middle_index, last_index);
    }
}

template <typename Type>
void mergesort(Type *arrayA, const unsigned int length)
{
    Type arrayB[length];
    copyarray(arrayA, arrayB, length);
    split(arrayB, arrayA, 0, length);
}