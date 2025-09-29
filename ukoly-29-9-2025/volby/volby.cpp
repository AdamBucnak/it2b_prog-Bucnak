#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int pocet_stran = 8;
	char strany[][14] = { "ANO", "SPOLU", "SPD", "STAN", "Piráti", "Motoristé", "Stačilo", "Jiné" };

	for (int i = 0; i < pocet_stran; i++) {
		printf("%s\n", strany[i]);
	}
    int hlasy[8] = { 0 };
	float preference[] = { 27.3, 23.5, 12.4, 11.1, 10, 6, 5.5,  4.2 };
	
	srand(time(NULL));  // inicializace generátoru náhodných čísel

	int procento = rand() % 31 + 50; // 0-30 + 50 = 50-80
	printf("Náhodne procento volicu: %d%%\n", procento);
	
	int pocet_volicu = 100000;
    float kumulativni[8];
    kumulativni[0] = preference[0];
    for (int i = 1; i < pocet_stran; i++) {
        kumulativni[i] = kumulativni[i - 1] + preference[i];
    }

    // simulace hlasování
    for (int i = 0; i < pocet_volicu; i++) {
        float r = (float)rand() / RAND_MAX * 100.0;  // číslo od 0 do 100
        for (int j = 0; j < pocet_stran; j++) {
            if (r < kumulativni[j]) {
                hlasy[j]++;
                break;
            }
        }
    }

    // výpočet procent z hlasů
    printf("Výsledky simulace (%d volicu):\n", pocet_volicu);
    for (int i = 0; i < pocet_stran; i++) {
        float procenta = (hlasy[i] * 100.0) / pocet_volicu;
        printf("%-10s : %6.2f%% (%d hlasů)\n", strany[i], procenta, hlasy[i]);
    }

    
	return 0;
}