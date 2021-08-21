#include <stdio.h>
#include <math.h>
int main()
{
    const char* pVegetable[] = { "トマト", "キュウリ", "レタス", NULL };
    const int pPrice[] = { 350, 180, 200, -1 };

    int nVegetable = 0;
    for (int i = 0; pVegetable[i] != NULL; i++) {
        ++nVegetable;
    }

    int nPrice = 0;
    for (int i = 0; pPrice[i] != -1; i++) {
        ++nPrice;
    }

    if (nVegetable != nPrice || nVegetable == 0) return -1;

    for (int i = 0; i < nVegetable; i++) {
        for (int j = i+1; j < nVegetable; j++) {

            float set_price_0 = 0.8 * (pPrice[i] + pPrice[j]);
            int set_price = round(set_price_0);
            
            printf("%s + %s = %d(%f)\n", pVegetable[i], pVegetable[j], set_price, set_price_0);
        }
    }

    return 0;
}
