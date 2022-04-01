#include "std_lib_facilities.h"

template<class T> struct S
{
	S() {}
	
	S(T t): val(t){}
	
	S& operator=(const T& newValue) { val = newValue; return *this; }
	istream operator>>(T t) {cin >> val;}
	
	const T& get() const {return val;}
	
	void set(T t) {val = t;}
	
	T& getRef() {return val;}
	
//private:
	T val;
};

template<typename T>
const T& get(S<T>& s)
{
	return s.val;
}

template<typename T> void read_val(T& v)
{
	cin >> v;
}

int main()
{
	/* // 3
	S<int> si(56);
	cout << si.val << endl;
	
	S<char> sc('k');
	cout << sc.val << endl;
	
	S<double> sd(14.5);
	cout << sd.val << endl;
	
	S<string> ss("asdf");
	cout << ss.val << endl;
	
	S<vector<int>> svi(vector<int>(10,100));
	for(int i : svi.val)
		cout << i << ", ";

	cout << endl;
	*/
	/*  // 4
	S<int> si;
	cout << "Enter int: ";
	cin >> si.val;
	cout << si.val << endl;
	
	S<char> sc;
	cout << "Enter char: ";
	cin >> sc.val;
	cout << sc.val << endl;
	
	S<double> sd;
	cout << "Enter double: ";
	cin >> sd.val;
	cout << sd.val << endl;
	
	S<string> ss;
	cout << "Enter string: ";
	cin >> ss.val;
	cout << ss.val << endl;
	
	S<vector<int>> svi(vector<int>(10,19));
	cout << "Enter 10 ints: ";
	for(int i = 0; i < 10; ++i)
		cin >> svi.val[i];
	for(int i : svi.val)
		cout << i << ", ";


	cout << endl;
	*/
	/* // 5
	S<int> si(56);
	cout << get(si) << endl;

	S<char> sc('k');
	cout << get(sc) << endl;

	S<double> sd(14.5);
	cout << get(sd) << endl;

	S<string> ss("asdf");
	cout << get(ss) << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	for (int i : get(svi))
		cout << i << ", ";

	cout << endl;
	*/
	/*  // 9
	S<int> si(56);
	si.set(10);
	cout << get(si) << endl;

	S<char> sc('k');
	sc.set('a');
	cout << get(sc) << endl;

	S<double> sd(14.5);
	sd.set(80.5);
	cout << get(sd) << endl;

	S<string> ss("asdf");
	ss.set("fdsa");
	cout << get(ss) << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	svi.set(vector<int>(10, 23));
	for (int i : get(svi))
		cout << i << ", ";

	cout << endl;
	*/
	/*  // 11
	S<int> si(56);
	si = 10;
	cout << si.getRef() << endl;

	S<char> sc('k');
	sc = 'a';
	cout << get(sc) << endl;

	S<double> sd(14.5);
	sd = 80.5;
	cout << get(sd) << endl;

	S<string> ss("asdf");
	ss = "fdsa";
	cout << get(ss) << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	svi = vector<int>(10, 23);
	for (int i : get(svi))
		cout << i << ", ";

	cout << endl;
	*/
	// 12
	S<int> si;
	cout << "Enter int: "; read_val(si.getRef());
	cout << si.get() << endl;

	S<char> sc;
	cout << "Enter char: "; read_val(sc.getRef());
	cout << sc.get() << endl;

	S<double> sd;
	cout << "Enter double: "; read_val(sd.getRef());
	cout << sd.get() << endl;

	S<string> ss;
	cout << "Enter string: "; read_val(ss.getRef());
	cout << ss.get() << endl;

	S<vector<int>> svi(vector<int>(10, 19));
	cout << "Enter 10 ints: ";
	for (int i = 0; i < 10; ++i)
		read_val(svi.getRef()[i]);
	for (int i : svi.get())
		cout << i << ", ";

	cout << endl;


	keep_window_open();
	return 0;
	
}
