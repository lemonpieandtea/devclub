/*
Задача arrayUnique()

Условие задачи
Написать функцию:
int arrayUnique(int array[], int size)

Удалить из массива дубликаты элементов. Вернуть новую длину массива.

Примечание: пример ввода и вывода показан для лучшего понимания условия задачи.
Выводить результат на печать не нужно.

Пример ввода
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 5 4 3 2 1
Пример вывода
array = 1 2 3 4 5 6 7 8 9 10
len = 10

code works
*/

#include <stdio.h>

int arrayUnique(int array[], int size) {
    int i = 0;
    
    for ( int j = 1, unique = array[0]; j < size; j++ ) {
        int temp = array[j];
        
        if ( temp != unique ) {
            i += 1;
            array[i] = temp;
            
            for ( int k = j + 1; k < size; k++ ) {
                if ( array[k] == temp ) {
                    array[k] = unique;
                }
            }
        }
    }
    
    return i + 1;
}

#define SIZE 10

int main() {
	int len = SIZE - 1;
	int array[SIZE] = {1, 1, 2, 2, 3, 3, 4, 4, 1, 1};

	printf("len: %d\n", len);
	for ( int i = 0; i < len; i++ ) {
		printf("%d ", array[i]);
	}
	printf("%d\n", array[len]);

	len = arrayUnique(array, SIZE);
	len -= 1;

	printf("len: %d\n", len);
	for ( int i = 0; i < len; i++ ) {
		printf("%d ", array[i]);
	}
	printf("%d\n", array[len]);

	return 0;
}
