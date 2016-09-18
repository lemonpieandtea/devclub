/*
Задача pythagoras

Условие задачи
Нарисовать таблицу Пифагора (умножения) с форматированием и разметкой для заданных диапазонов по горизонтали и вертикали.
Расстояние от края экрана до чисел в заголовке строк - не менее одного пробела.
Расстояние от вертикальной черты до чисел - не менее одного пробела.
Расстояние между числами в таблице - не менее одного пробела.
Ширина всех колонок должна быть одинаковой.
В вопросе расставления пробелов руководствуйтесь здравым смыслом и примером.

Пример ввода
7 11 7 11
Пример вывода
    |   7   8   9  10  11
----+--------------------
  7 |  49  56  63  70  77
  8 |  56  64  72  80  88
  9 |  63  72  81  90  99
 10 |  70  80  90 100 110
 11 |  77  88  99 110 121

code works
*/

#include <stdio.h>

#define BASE 10

int abs(int a) {
    if ( a < 0 ) {
        return -a;
    }
    return a;
}

int max2(int x, int y) {
    if ( x > y ) {
        return x;
    }
    return y;
}

int places(int number) {
    int places = 0;
    
    if ( number < 1 ) {
        places += 1;
    }
    
    for ( ; number != 0; number /= BASE ) {
        places += 1;
    }
    
    return places;
}

int main() {
    int startX, lastX;
    int startY, lastY;
    int placesX, placesY;
    int maxAbsX, maxAbsY;
    
    scanf("%d %d %d %d", &startX, &lastX, &startY, &lastY);
    
    placesY = max2(places(startY), places(lastY));
    maxAbsX = max2(abs(startX), abs(lastX));
    maxAbsY = max2(abs(startY), abs(lastY));
    placesX = places(maxAbsX*maxAbsY);
    
    if ( startX < 0 || startY < 0 || lastX < 0 || lastY < 0 ) {
        placesX += 1;
    } else if ( startX < 0 && startY < 0 && lastX < 0 && lastY < 0 ) {
        placesX -= 1;
    }
    
    for ( int i = 0; i <= placesY; i++ ) {
        printf(" ");
    }
    printf(" |");
    for ( int i = startX; i < lastX; i++ ) {
        printf(" %*d", placesX, i);
    }
    printf(" %*d\n", placesX, lastX);
    
    for ( int i = 0; i <= placesY; i++ ) {
        printf("-");
    }
    printf("-+");
    for ( int i = startX; i <= lastX; i++ ) {
        for ( int j = 0; j <= placesX; j++ ) {
            printf("-");
        }
    }
    printf("\n");
    
    for ( int i = startY; i <= lastY; i++ ) {
        printf(" %*d |", placesY, i);
        for ( int j = startX; j < lastX; j++ ) {
            printf(" %*d", placesX, i*j);
        }
        printf(" %*d\n", placesX, i*lastX);
    }
    return 0;
}
