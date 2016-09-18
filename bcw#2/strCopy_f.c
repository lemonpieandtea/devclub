/*
Задача strCopy()
Условие задачи
void strCopy(char target[], char source[])

Гарантируется, что строка target не короче строки source.

epic win
*/

void strCopy(char target[], char source[]) {
    int position;
    
    for ( position = 0; source[position] != 0; position++ ) {
        target[position] = source[position];
    }
    target[position] = 0;
}
