/*
Задача comparison

Условие задачи
Вывести результаты, возвращаемые разными операторами сравнения, используя два
введенных числа.

Пример ввода
1 2
Пример вывода
1<2 is 1
1>2 is 0
1<=2 is 1
1>=2 is 0
1==2 is 0
1!=2 is 1

epic win
*/

#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d<%d is %d\n", a, b, a<b);
    printf("%d>%d is %d\n", a, b, a>b);
    printf("%d<=%d is %d\n", a, b, a<=b);
    printf("%d>=%d is %d\n", a, b, a>=b);
    printf("%d==%d is %d\n", a, b, a==b);
    printf("%d!=%d is %d\n", a, b, a!=b);
    
    return 0;
}
