#include <iostream>

using namespace std;

struct Vector
{
    int* m_pVect=NULL,
        m_nCount = 0,
        m_nMax = 0,
        m_nDelta = 10;
};

void Resize(Vector* pThis) {
    int* pTemp = new int[pThis->m_nMax + pThis->m_nDelta];

    for (size_t i = 0; i < pThis->m_nCount; ++i) {
        pTemp[i] = pThis->m_pVect[i];
    }

    delete [] pThis->m_pVect;

    pThis->m_pVect = pTemp;

    pThis->m_nMax += pThis->m_nDelta;


}

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax)
        Resize(pThis);

    pThis->m_pVect[pThis->m_nCount++] = elem;
}


int main()
{
    Vector a;
    Insert(&a, 5);
    Insert(&a, 4);
    Insert(&a, 2);
    Insert(&a, 7);

    for (int i = 0; i < a.m_nCount; i++)
        cout << a.m_pVect[i] << " ";
}
