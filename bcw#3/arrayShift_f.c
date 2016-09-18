/*
Задача arrayShift()

Условие задачи
Написать функцию:
void arrayShift(int array[], int size, int shift)
Реализовать циклический сдвиг массива на shift элементов вправо. Максимизировать
производительность при оптимальном использовании памяти.
Требуемая сложность: O(N)

code works
*/

void arrayShift(int array[], int size, int shift) {
    int delimiter;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    delimiter = size - shift;
    
    if ( delimiter > shift ) {
        int arrayBuff[shift];
        
        for ( int i = 0, j = delimiter; j < size; i++, j++ ) {
            arrayBuff[i] = array[j];
        }
        for ( int i = size - 1, j = delimiter - 1; j >= 0; i--, j-- ) {
            array[i] = array[j];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = arrayBuff[i];
        }
    } else {
        int arrayBuff[delimiter];
        
        for ( int i = 0; i < delimiter; i++ ) {
            arrayBuff[i] = array[i];
        }
        for ( int i = 0, j = delimiter; j < size; i++, j++ ) {
            array[i] = array[j];
        }
        for ( int i = shift, j = 0; j < delimiter; i++, j++ ) {
            array[i] = arrayBuff[j];
        }
    }
}
