/*
Задача arrayShiftRight()

Условие задачи
Написать функцию:
void arrayShiftRight(int array[], int size)

Реализовать циклический сдвиг массива на 1 элемент вправо.
Использование дополнительного массива не разрешается.

epic win
*/

void arrayShiftRight(int array[], int size) {
    int i = size - 1;
    int tmp = array[i];
    
    for ( int j = i - 1; i > 0; i--, j-- ) {
        array[i] = array[j];
    }
    array[0] = tmp;
}
