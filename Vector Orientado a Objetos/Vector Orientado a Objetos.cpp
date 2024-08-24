#include <iostream>

using namespace std;

class CVector {
private:
    int* m_pVect=NULL, 
        m_nCount=0, // Control how many elements are actually used
        m_nMax=0, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(int delta) {
        m_nDelta = delta;
    }; // Constructor
    void Insert(int elem); // Insert a new element
    void mostrar();
};

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) 
        Resize();
    m_pVect[m_nCount++] = elem; 
}

void CVector::Resize() {
    int* pTemp = new int[m_nMax + m_nDelta];
    for (size_t i = 0; i < m_nCount; ++i) {
        pTemp[i] = m_pVect[i];
    }
    delete m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

void CVector::mostrar(){
    for (int i = 0; i < m_nCount; i++)
        cout << m_pVect[i] << " ";
}

int main()
{
    CVector a(10);
    a.Insert(5);
    a.Insert(7);
    a.Insert(8);
    a.Insert(6);
    a.Insert(1);
    a.mostrar();
    
}
