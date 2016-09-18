/*
Задача milk

Условие задачи
Молочная компания каждый день покупает молоко у фермеров. У каждого из
<farmerQuantity> фермеров есть <amount> литров молока по цене <price>. Найти
минимальную стоимость <minPrice>, за которую возможно приобрести <amountNeeded>
литров молока. В случае, если у фермеров недостаточно молока, вывести в качестве
<minPrice> значение 0.

В файле task.in заданы целые числа:
<farmerQuantity> <amountNeeded>
<amount1> <price1>
<amount2> <price2>
.....
<amountN> <priceN>

Вывести minPrice в task.out.

Ограничения:
0 <= farmerQuantity <= 100 000 000
0 <= amountNeeded <= 300 000 000
0 <= amount <= 300 000 000
1 <= price <= 1 000

Пример ввода
3 10
5 1
8 2
8 3
Пример вывода
15

code works
*/

#include <stdio.h>

#define PRICE_AMOUNT 1000

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int prices[PRICE_AMOUNT+1];
    int farmerQuantity;
    unsigned long long amountNeeded;
    unsigned long long quantity = 0;
    unsigned long long lastPrice = 0;
    unsigned long long minPrice = 0;
    
    for ( unsigned int i = 0; i < PRICE_AMOUNT; i++ ) {
        prices[i] = 0;
    }
    
    fscanf(in, "%d %llu", &farmerQuantity, &amountNeeded);
    
    for ( unsigned int amount, price; farmerQuantity > 0; farmerQuantity-- ) {
        fscanf(in, "%d %d", &amount, &price);
        prices[price] += amount;
    }
    fclose(in);
    
    for ( ; quantity < amountNeeded && lastPrice < PRICE_AMOUNT; lastPrice++ ) {
        unsigned long long amount = prices[lastPrice];
        
        if ( amount > 0 ) {
            quantity += amount;
            minPrice += amount * lastPrice;
        }
    }
    
    if ( quantity < amountNeeded ) {
        minPrice = 0;
    } else {
        minPrice -= (lastPrice - 1) * (quantity - amountNeeded);
    }
    
    fprintf(out, "%llu\n", minPrice);
    fclose(out);
    
    return 0;
}
