#include "Fraction.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s, v1, v2;
	vector<Fraction> v;
	Fraction	Sum, equationresult;

	ifstream in("FractionList.txt");

	while (in >> v1)
	{
		in >> v2;
		Fraction A(stoi(v1), stoi(v2));
		v.push_back(A);
	}

	cout << "**** List of fraction extracted from file: ****" << endl;
	for (unsigned int i = 0; i < v.size(); i++)
		DisplayResult(v[i]);
	cout << "***********************************************" << endl;

	cout << "**** Sum of Fractions Result: ****" << endl;
	Sum = SumFraction(v);
	DisplayResult(Sum);
	cout << "**********************************" << endl;

	cout << "**** Equation Result: ****" << endl;
	equationresult = -((v[0] + v[1]) * v[2] - v[3]) / v[4];
	DisplayResult(equationresult);
	cout << "***************************" << endl;
	v[0].setNumerator(5);
	system("pause");
	return 0;
}
