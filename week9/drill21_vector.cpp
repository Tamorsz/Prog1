#include "std_lib_facilities.h"

struct Item
{
	Item() : name(), value(), id() {}
	Item(string pName, double pValue1, int pID) : name(pName), value(pValue1), id(pID) {}

	string name;
	double value;
	int id;

	friend istream& operator>>(istream& input, Item& item)
	{
		string line;
		getline(input, line);
		if(!line.empty())
		{
			size_t comma1 = line.find(',');
			item.name = line.substr(2, comma1 - 2);

			size_t comma2 = line.find(',', comma1 + 1);
			size_t diff = comma2 - (comma1 + 2);
			item.value = stod(line.substr(comma1 + 2, diff));

			size_t endBracket = line.find('}', comma2);
			diff = endBracket - (comma2 + 2);
			item.id = stoi(line.substr(comma2 + 2, diff));
		}

		return input;
	}

	friend ostream& operator<<(ostream& output, Item& item)
	{
		output << "{ " << item.name << ",\t" << item.value << ",\t" << item.id << " }" ;
		return output;
	}
};


bool lexicographicalCompare(char a, char b)
{
	return tolower(a) < tolower(b);
}

struct SortByName
{
	bool operator()(const Item& pItem1, const Item& pItem2) const
	{
		return std::lexicographical_compare(
			pItem1.name.begin(), pItem1.name.end(),
			pItem2.name.begin(), pItem2.name.end(),
			lexicographicalCompare);
	}
};

struct SortByID
{
	bool operator()(const Item& pItem1, const Item& pItem2) const
	{
		return pItem1.id < pItem2.id;
	}
};

struct SortByValue
{
	SortByValue(bool pOrder) : order(pOrder) {}

	bool operator()(const Item& pItem1, const Item& pItem2) const
	{
		return order ? (pItem1.value < pItem2.value) : (pItem1.value > pItem2.value);
	}

	bool order;
};

struct RemoveByName
{
	RemoveByName(string pName) : s(pName) {}
	bool operator()(const Item& pItem1)
	{
		return pItem1.name == s;
	}
	string s;
};

struct RemoveByID
{
	RemoveByID(int pID) : i(pID) {}
	bool operator()(const Item& pItem1)
	{
		return pItem1.id == i;
	}
	int i;
};

void Eljaras()
{
	string fromFile = "Lista.txt";
	string toFile = "ÚjLista.txt";

	ifstream is{ fromFile };
	ofstream os{ toFile };

	istream_iterator<Item> ii{ is };
	istream_iterator<Item> eos;
	ostream_iterator<Item> oo{ os, "\n" };

	list<Item> v{ ii, eos };

	cout << "\n 2 elem beillesztése" << endl;
	auto listIt = v.begin();
	advance(listIt, 2);
	v.insert(listIt, Item{ "Nike póló", 3.3, 21 });
	advance(listIt, 5);
	v.insert(listIt, Item{ "Samsung telefon", 612, 32 });
	for (Item i : v)
		cout << i << endl;

	cout << "\n Név szerinti rendezés" << endl;
	v.sort(SortByName());
	for (Item i : v)
		cout << i << endl;

	cout << "\n Azonosító szerinti rendezés" << endl;
	v.sort(SortByID());
	for (Item i : v)
		cout << i << endl;

	cout << "\n Csökkenő sorrendbe rendezés érték szerint" << endl;
	v.sort(SortByValue(false));
	for (Item i : v)
		cout << i << endl;

	cout << "\n 2 elem eltávolítás név szerint:" << endl;
	auto It = std::find_if(v.begin(), v.end(), RemoveByName("chilis bab"));
	v.erase(It);
	It = std::find_if(v.begin(), v.end(), RemoveByName("pizza"));
	v.erase(It);
	for (Item i : v)
		cout << i << endl;

	cout << "\n 2 elem eltávolítása azonosító alapján" << endl;
	It = std::find_if(v.begin(), v.end(), RemoveByID(32));
	v.erase(It);
	It = std::find_if(v.begin(), v.end(), RemoveByID(3));
	v.erase(It);
	for (Item i : v)
		cout << i << endl;

}


int main()
{
	Eljaras();

	keep_window_open();
	return 0;
}
