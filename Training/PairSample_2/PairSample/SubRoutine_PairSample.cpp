#include <stdio.h>
#include <math.h>

int main()
{
    const char* pVegetableName[] = { "トマト", "キュウリ", "レタス", NULL };
    const int pVegetablePrice[] = { 350, 180, 200, -1 };

    int nVegetable = 0;
    for (int i = 0; pVegetableName[i] != NULL; i++) {
        ++nVegetable;
    }

    int nVegetablePrice = 0;
    for (int i = 0; pVegetablePrice[i] != -1; i++) {
        ++nVegetablePrice;
    }

    if (nVegetable != nVegetablePrice || nVegetable == 0) return -1;

    for (int i = 0; i < nVegetable; i++) {
        for (int j = i+1; j < nVegetable; j++) {

            float discount_price_0 = 0.8 * (pVegetablePrice[i] + pVegetablePrice[j]);
            int discount_price = round(discount_price_0);
            
            printf("%s + %s = %d\n", pVegetableName[i], pVegetableName[j], discount_price);
        }
    }

    const char* pBreadName[] = { "食パン", "クリームパン", "メロンパン", "クロワッサン", NULL};
    const int pBreadPrice[] = { 70, 100, 130, 150, -1 };

    int nBread = 0;
    for (int i = 0; pBreadName[i] != NULL; i++) {
        ++nBread;
    }

    int nBreadPrice = 0;
    for (int i = 0; pBreadPrice[i] != -1; i++) {
        ++nBreadPrice;
    }

    if (nBread != nBreadPrice || nBread == 0) return -1;

    for (int i = 0; i < nBread; i++) {
        for (int j = i + 1; j < nBread; j++) {

            float discount_price_0 = 0.8 * (pBreadPrice[i] + pBreadPrice[j]);
            int discount_price = round(discount_price_0);

            printf("%s + %s = %d\n", pBreadName[i], pBreadName[j], discount_price);
        }
    }

    return 0;
}
