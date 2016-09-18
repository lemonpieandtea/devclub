/*
Задача sliceReverse()

Условие задачи
Написать функцию:
void sliceReverse(int array[], int lo, int hi)

Осуществить реверс части массива от lo до hi включительно.

epic win
*/

void sliceReverse(int array[], int lo, int hi) {
    for ( ; lo < hi; lo++, hi-- ) {
        int temp = array[lo];
        
        array[lo] = array[hi];
        array[hi] = temp;
    }
}
