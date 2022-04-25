#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
using namespace Numeric_lib;

void ex04()
{
	int x = 0;
	do
	{
		cin >> x;
		if(x < 0)
		{
		cout << "no square root" << endl;
		}
		else
		{
		cout << sqrt(x) << endl;
		}
	}while(cin);
	
}

void ex05()
{
	    cin.clear();
    cin.ignore();
    cout << "\nEnter 10 floating point values: ";
    Matrix<double> m(10);
    double d;
    for (int i = 0; i<m.size(); ++i) {
        cin >> d;
        if (!cin) throw runtime_error("Problem reading from cin");
        m[i] = d;
    }
    cout << "Matrix:\n" << m << '\n';
}

void ex06()
{
    cout << "\nMultiplication table\nEnter n: ";
    int n;
    cin >> n;
    cout << "Enter m: ";
    int m;
    cin >> m;
    Matrix<int,2> mtable(n,m);
    for (Index i = 0; i<mtable.dim1(); ++i) {
        for (Index j = 0; j<mtable.dim2(); ++j) {
            mtable(i,j) = (i+1)*(j+1);
            cout << setw(5) << mtable(i,j);
        }
        cout << '\n';
    }
}



void ex08()
{
    Matrix<int,2> m(2,3);
    cout << "\nEnter six ints: ";
    int n;
    for (int i = 0; i<m.dim1(); ++i)
        for (int j = 0; j<m.dim2(); ++j) {
            cin >> n;
            m(i,j) = n;
        }
    cout << "Matrix:\n" << m << '\n';
}

int main()
{
	//1.
	cout << "Sizes: " << sizeof(char)<<' '<< sizeof(short)<<' '<< sizeof(int)<<' '<< sizeof(long)<<' '<< sizeof(float)<<' '<< sizeof(double)<<' '<< sizeof(int*)<<' '<< sizeof(double*)<<' '<< endl;
	
	//2.
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << sizeof(a) << ' ' << sizeof(b) << ' ' <<sizeof(c) << ' ' << sizeof(d) << ' ' <<sizeof(e) << endl;
	
	//3.
	cout << a.size() << ' ' << b.size() << ' ' << c.size() << ' ' << d.size() << ' ' << e.size() << endl;
	
	//4.
	//ex04();
	
	//5.
	ex05();
	
	//6.
	ex06();
	
	
	
	//8.
	ex08();
	
	keep_window_open();
}
