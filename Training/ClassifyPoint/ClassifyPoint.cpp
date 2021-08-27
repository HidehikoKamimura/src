#include <iostream>

struct Area_L {
    const char* m_pName;
    double m_Min;
    double m_Max;
};

struct Area_H {
    const char* m_pName;
    double m_Min;
    double m_Max;
};

struct Point {
    double m_L;
    double m_H;
};

int main()
{
    Area_L pArea_L[] = {
        { "FR", -1000, 2400 },
        { "CTR", 2400, 3500 },
        { "RR",  3500, 6000 },
        { NULL,     0,    0 }
    };

    Area_H pArea_H[] = {
        { "LWR", -1000,  1000 },
        { "UPR",  1000,  3000 },
        { NULL,      0,     0 }
    };

    Point pPoint[] = {
        {  350,  800 },
        { 4200, 1200 },
        { 2800, 1600 },
        { 4100, 1100 },
        { 2100, 1150 },
        {    0,    0 }
    };

    for (int i = 0; pPoint[i].m_H != 0; i++) {
        
        const char* pName_L = NULL;
        for (int j = 0; pArea_L[j].m_pName != NULL ; j++ ) {
            if ( pPoint[i].m_L > pArea_L[j].m_Min && pPoint[i].m_L < pArea_L[j].m_Max ) {
                pName_L = pArea_L[j].m_pName;
                break;
            }
        }
        
        const char* pName_H = NULL;
        for (int j = 0; pArea_H[j].m_pName != NULL; j++) {
            if ( pPoint[i].m_H > pArea_H[j].m_Min && pPoint[i].m_H < pArea_H[j].m_Max ) {
                pName_H = pArea_H[j].m_pName;
                break;
            }
        }

        printf("(%f, %f) -> %s, %s\n", pPoint[i].m_L, pPoint[i].m_H, pName_L, pName_H);
    }

    return 0;
}
