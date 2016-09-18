/*
Задача abcz2

Условие задачи
Считать с клавиатуры целое число.
- Если число четное, вывести alpha
- Если число кратно трем, вывести bravo
- Если число кратно пяти, вывести charlie
- Если число не кратно ни одному из них, вывести zulu

Пример ввода
8
Пример вывода
alpha

code works
*/

#include <stdio.h>

int main() {
    int a;
    int event = 0;
    
    scanf("%d", &a);
    
    if ( a % 2 == 0 ) {
        printf("alpha\n");
        event = 1;
    }
    if ( a % 3 == 0 ) {
        printf("bravo\n");
        event = 1;
    }
    if ( a % 5 == 0 ) {
        printf("charlie\n");
        event = 1;
    }
    if ( event != 1 ) {
        printf("zulu\n");
    }
    
    return 0;
}
