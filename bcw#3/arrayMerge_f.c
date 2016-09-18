/*
Задача arrayMerge()

Условие задачи
Написать функцию
void arrayMerge(int target[], int src1[], int len1, int src2[], int len2)

Массивы src1[] и src2[] (длиной len1 и len2 соответственно) отсортированы по
неубыванию.
Произвести слияние этих массивов в массив target[], также отсортированный по
неубыванию.
В случае равенства предпочтение отдаётся элементам из первого массива.
Требуемая сложность: O(N)

code works
*/

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int size = len1 + len2;
    
    for ( int i = 0, j = 0, k = 0; i < size; i++ ) {
        if ( src1[j] <= src2[k] && j < len1 ) {
            target[i] = src1[j];
            j += 1;
        } else {
            target[i] = src2[k];
            k += 1;
        }
    }
}
