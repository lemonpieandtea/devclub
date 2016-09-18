/*
Игральные карты

Создать struct для игры в карты. Понадобится пара enum-ов.
Обеспечить соответствие между достоинством карты и его числовым эквивалентом,
т.е., к примеру, числовой эквивалент "девятки" должен быть равен 9.
*/

#define OFFSET 2
#define NUMBER_OF_CARDS 6

enum Suit { Spaders, Hearts, Diamonds, Clubes };
enum Rank { Ace = 1, 2, 3, 4, 5, 6, 7, 8, 9, Jack, Queen, King };

typedef struct {
    Suit suit;
    Rank rank;
} Card;

char *nameSuit[] = { "Spaders", "Hearts", "Diamonds", "Clubes" }
char *nameRank[] = { "2", "3", "4", "5", "6", "7", "8", "9", "Jack", "Queen", "King", "Ace" }

typedef struct {
    char *name = "Def name";
    Card cards[NUMBER_OF_CARDS];
} Player;
