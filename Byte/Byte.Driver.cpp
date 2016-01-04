// ByteTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Byte.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	Byte b1, b2, b3;
	char * comp = "2\'s complement ";
	char * bias = "biased notation";

	ofstream out("sum.out", ios::out);
	ifstream in("byte.in", ios::in);

	while (b1.read(in) && b2.read(in))
	{
		b3 = b1.add(b2.biasTo2sComplement());
		out << "   " << b1 << "\t" << comp << "\t" << std::right << std::setw(8) << b1.toInteger() << endl;
		out << "+  " << b3 << "\t" << bias << "\t" << std::right << std::setw(8) << b2.biasTo2sComplement().toInteger() << endl;
		out << "-----------\t\t\t" << std::right << std::setw(8) << "----" << endl;
		out << "   " << b3 << "\t" << comp << "\t" << std::right << std::setw(8) << b3.toInteger() << endl << endl;
	}

	out.close();
	in.close();
}