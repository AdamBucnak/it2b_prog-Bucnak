// aaaaa.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e' };
    

    srand(time(NULL)); 

    int nahodnyIndex = rand() % 4;

    printf("Náhodný index: %d\n", nahodnyIndex);
    printf("Znak na tomto indexu: %c\n", arr[nahodnyIndex]);

    return 0;
}