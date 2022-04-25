#include "std_lib_facilities.h"

#include <map>
#include <type_traits>

template<typename T, typename T2>
void printMap(const map<T, T2>& m)
{
	for (const auto& p : m)
		cout << "{ " << p.first << ", " << p.second << " }" << endl;
}

template<typename T, typename T2>
void readIntoMap(map<T, T2>& m)
{
	while (cin.good())
	{
		cout << "Irja be az elem nevét: ";
		T s;
		if (getline(cin, s))
		{
			cout << "\n Írja be az azonosítót: ";
			T2 n = 0;
			if (cin >> n)
			{
				cin.ignore(1000, '\n');
				m.insert({ s , n });
			}
		}
	}
}


template<typename T, typename T2>
ostream& operator<<(ostream& output, const map<T, T2>& m)
{
	for (const auto& p : m)
		output << "{ " << p.first << ", " << p.second << " }" << endl;

	return output;
}


template<typename T, typename T2>
void copySwapMapElements(const map<T, T2>& m1, map<T2, T>& m2)
{
	for (const auto& p : m1)
		m2.insert({ p.second, p.first });
}

void Eljaras()
{
	map<string, int> msi{
		{"Huawei", 1},
		{"Apple", 2},
		{"Samsung", 3},
		{"Motorola", 4},
		{"Xiaomi", 5},
		{"ZTE", 6},
		{"Nokia", 7},
		{"LG", 8},
		{"Blackberry", 9},
		{"HTC", 10}
	};

	printMap(msi);

	int sum = 0;
	for (const auto& p : msi)
		sum += p.second;
	cout << sum;

	msi.clear();
	cout << "\nA map mérete, törlés után: " << msi.size() << endl;

	readIntoMap(msi);
	printMap(msi);

	cout << msi;

	map<int, string> mis;
	copySwapMapElements(msi, mis);

	cout << mis;

	cout << "Map vége" << endl;
}


int main()
{
	Eljaras();

	keep_window_open();
	return 0;
}
