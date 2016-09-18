/*
Задача arraySort()

Условие задачи
Написать функцию:
void arraySort(int array[], int size)

Отсортировать элементы в порядке неубывания.
Настоятельно рекомендуется разработать алгоритм самостоятельно, без помощи гугла.

code works
*/

void arraySort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int temp;
        int min = i;
        
        for ( int j = i; j < size; j++ ) {
            if ( array[j] < array[min] ) {
                min = j;
            }
        }
        
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}
