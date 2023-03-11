//Justin Ritchey. MP8. 12/19/2020. Fraction_Math_Program expanded: Adding in a few functions to read 2 files and convert those to vectors and lists and then merge the two checking for duplicates



#include "fraction.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void main()
{
	Fraction a;                                                                                                                         
	ifstream file1;
	file1.open("FractsToVector.txt");
	ofstream outFile;
	outFile.open("out.txt");
	vector<Fraction> vecFracs;
	list<Fraction> listFracs;
	ifstream file2;
	file2.open("FractsToLists.txt");
	vector<Fraction> mergeVec;
	int dupe=0;

	while (file1.good())
	{
		file1 >> a;
		a.lowTerms();
		vecFracs.push_back(a);
	}

	sort(vecFracs.begin(), vecFracs.end());

	cout << "Vector: \n";


	for (int i = 0; i < vecFracs.size(); i++)
	{
		cout << vecFracs.at(i) << endl;
	}

	while (file2.good())
	{
		file2 >> a;
		a.lowTerms();
		listFracs.push_back(a);
	}
	
	cout << "\n\nList: \n";

	listFracs.sort();

	for (auto j : listFracs)
	{
		cout << j << endl;
	}


	mergeVec=mergeTerms(vecFracs, listFracs, dupe);
	sort(mergeVec.begin(), mergeVec.end());

	cout << "\nThere were " << dupe << " duplicated numbers between the list and vector\n";
	cout << "\n\nMerged vector: \n";

	for (int i = 0; i < mergeVec.size(); i++)
	{
		cout << mergeVec.at(i) << endl;
	}
	
	system("PAUSE");
}