#include <stdio.h>

int main()
{
	int pocetopakovani;
	printf("zadej pocet opakovani: ");
	scanf_s("%d", &pocetopakovani);
	
	
	for (int i = 0; i < pocetopakovani; i++) {
		printf("ahoj svete!\n");
	}

	return 0;
}