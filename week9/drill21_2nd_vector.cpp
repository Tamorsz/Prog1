#include "std_lib_facilities.h"

#include <numeric>


ostream& operator<<(ostream& pOutput, const vector<double>& pVec)
{
	for (double d : pVec)
		pOutput << d << ", ";
	return pOutput;
}


struct LessThan
{
	LessThan(double pD) : d(pD) {}

	bool operator()(const double d1)
	{
		return d1 < d;
	}

	double d;
};


void Eljaras()
{	
	const string fromFile = "values.txt";

	ifstream inputStream{ fromFile };
	istream_iterator<double> istreamIterator{ inputStream };
	istream_iterator<double> endOfStream;

	vector<double> vd{ istreamIterator, endOfStream };

	cout << vd << endl;

	vector<int> vi(vd.size());
	for (int i = 0; i < vi.size(); ++i)
		vi[i] = static_cast<int>(vd[i]);

	for (int i = 0; i < vi.size(); ++i)
		cout << vi[i] << ",\t" << vd[i] << endl;

	const double sumVD = std::accumulate(vd.begin(), vd.end(), 0.0);
	cout << "vd összeg: " << sumVD << endl;

	const int sumVI = std::accumulate(vi.begin(), vi.end(), 0);
	cout << "a vd összegének és a vi-nek különbsége: " << sumVD - sumVI << endl;

	std::reverse(vd.begin(), vd.end());
	cout << vd << endl;

	const double meanVD = sumVD / vd.size();
	cout << "meanvd:: " << meanVD << endl;

	vector<double> vd2;
	std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2), LessThan(meanVD));
	cout << vd2 << endl;

	sort(vd.begin(), vd.end());
	cout << vd << endl;
}


int main()
{
	Eljaras();

	keep_window_open();
	return 0;
}
