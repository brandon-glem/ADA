#include <vector> 
#include <iostream>

using namespace std;

template <typename Container>
void Write(Container& ds, ostream& os)
{
	typename Container::iterator iter = ds.begin(); 
	for (; iter != ds.end(); iter++)
		os << *iter << "\n";
}

int main(int argc, char* argv[])
{
	vector<float> myvector;
	for (int i = 0; i < 10; i++)
	{
		myvector.push_back(i + 50);
	}

	Write(myvector, cout);
	return 0;
}

