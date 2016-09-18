/*
Задача arrayReverse()

Условие задачи
Написать функцию:
void arrayReverse(int array[], int size)

Использование дополнительного массива не разрешается.

almost win
*/

void arrayReverse(int array[], int size) {
    for ( int i = 0, j = size - 1; i < j; i++, j-- ) {
        int tmp = array[i];
        
        array[i] = array[j];
        array[j] = tmp;
    }
}
