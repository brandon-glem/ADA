#include <iostream>

using namespace std;

template <typename Type> class CVector{
private:
    Type* m_pVect = NULL;
    int m_nCount = 0, 
        m_nMax=0,
        m_nDelta; 
    void Resize(); 
public:
    CVector(int delta) {
        m_nDelta = delta;
    };
    void Insert(Type elem); 
    void mostrar();
};

template <typename Type> void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) 
        Resize();
    m_pVect[m_nCount++] = elem; 
}

template <typename Type> void CVector<Type>::Resize() {
    Type* pTemp = new int[m_nMax + m_nDelta];
    for (size_t i = 0; i < m_nCount; ++i) {
        pTemp[i] = m_pVect[i];
    }
    delete m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

template <typename Type> void CVector<Type>::mostrar(){
    for (int i = 0; i < m_nCount; i++)
        cout << m_pVect[i] << " ";
}

int main()
{
    CVector<int> a(10);
    a.Insert(5);
    a.Insert(7);
    a.Insert(8);
    a.Insert(6);
    a.Insert(1);
    a.mostrar();
    
}
