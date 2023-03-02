#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "BigDecimal.h"

int main(){
    printf("Hallo zur Liste!\n");

    LNode* grosseZahlEiner = append_val(NULL, 5);
    LNode* grosseZahlZehner = append_val(grosseZahlEiner, 9);
    LNode* grosseZahlHunderter = append_val(grosseZahlZehner, 1);

    print(grosseZahlHunderter);
    printf("\n");
    print_reverse(grosseZahlHunderter);
    printf("\n");

    unsigned long long int i = 3132654565432322;
    int k = 16;

   LNode* longZahlMSD = NULL;
    while (k > 0)
    {
        k--;
        int mod = i / pow(10.0f, k);
        i = i % (unsigned long long int)pow(10.0f, k);

        //printf("%d", mod);
        longZahlMSD = prepend_val(longZahlMSD, mod);
    }

    print(longZahlMSD);
    printf("\n");
    print_reverse(longZahlMSD);    
    printf("\n");

    LNode* ziffgMSD = NULL;
    LNode* ziffgLSD = NULL;

    ziffgLSD = add_list(get_LSD(longZahlMSD), grosseZahlEiner);
    ziffgMSD = get_at_LSD(ziffgLSD, len_list(ziffgLSD) - 1);

    print(ziffgLSD);
    printf("\n");
    print_reverse(ziffgMSD);    
    printf("\n");

    delete_list(ziffgLSD);
    delete_list(longZahlMSD);
    delete_list(grosseZahlEiner);

    return 0;
}