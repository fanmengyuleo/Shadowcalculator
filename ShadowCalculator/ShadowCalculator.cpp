// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <limits>
#include <math.h>

using namespace std;

typedef std::numeric_limits< double > dbl;

int userchoice = 0;
double l[10] = { 0,0,0,0,0,0,0,0,0,0 };
double e[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
double r[10] = { 0,0,0,0,0,0,0,0,0,0 };
double c[10] = { 0,0,0,0,0,0,0,0,0,0 };
double lchance = 0.015;
double echance = 0.06;
double rchance = 0.25;
double cchance = 0.675;
double xrchance = 0.925;
double chance[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
double xchance[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
double avg;
double scoreChance[11];
double CalcChance(double L, double E, double R, double C);
double CalcChance(double L, double E, double R);
bool eighteen = false;


void GenStandard() {
	l[9] = (double)1 / (double)24;
	l[8] = (double)3 / (double)24;
	l[7] = (double)6 / (double)24;
	l[6] = (double)2 / (double)24;
	l[5] = (double)6 / (double)24;
	l[4] = (double)3 / (double)24;
	l[3] = (double)2 / (double)24;
	l[2] = (double)1 / (double)24;
	e[10] = (double)1 / (double)69;
	e[9] = (double)1 / (double)69;
	e[8] = (double)4 / (double)69;
	e[7] = (double)5 / (double)69;
	e[6] = (double)5 / (double)69;
	e[5] = (double)12 / (double)69;
	e[4] = (double)12 / (double)69;
	e[3] = (double)13 / (double)69;
	e[2] = (double)6 / (double)69;
	e[1] = (double)7 / (double)69;
	e[0] = (double)3 / (double)69;
	r[7] = (double)4 / (double)99;
	r[6] = (double)5 / (double)99;
	r[5] = (double)8 / (double)99;
	r[4] = (double)15 / (double)99;
	r[3] = (double)16 / (double)99;
	r[2] = (double)25 / (double)99;
	r[1] = (double)19 / (double)99;
	r[0] = (double)7 / (double)99;
	c[7] = (double)2 / (double)126;
	c[6] = (double)5 / (double)126;
	c[5] = (double)6 / (double)126;
	c[4] = (double)9 / (double)126;
	c[3] = (double)17 / (double)126;
	c[2] = (double)36 / (double)126;
	c[1] = (double)39 / (double)126;
	c[0] = (double)12 / (double)126;
}
void GenDE() {
	l[8] = (double)1 / (double)9;
	l[7] = (double)3 / (double)9;
	l[6] = (double)1 / (double)9;
	l[4] = (double)3 / (double)9;
	l[2] = (double)1 / (double)9;
	e[8] = (double)2 / (double)23;
	e[7] = (double)2 / (double)23;
	e[6] = (double)1 / (double)23;
	e[5] = (double)5 / (double)23;
	e[4] = (double)2 / (double)23;
	e[2] = (double)6 / (double)23;
	e[1] = (double)5 / (double)23;
	r[8] = (double)1 / (double)31;
	r[6] = (double)4 / (double)31;
	r[5] = (double)2 / (double)31;
	r[4] = (double)3 / (double)31;
	r[3] = (double)6 / (double)31;
	r[2] = (double)7 / (double)31;
	r[1] = (double)7 / (double)31;
	r[0] = (double)1 / (double)31;
	c[6] = (double)1 / (double)46;
	c[5] = (double)4 / (double)46;
	c[4] = (double)9 / (double)46;
	c[3] = (double)6 / (double)46;
	c[2] = (double)10 / (double)46;
	c[1] = (double)14 / (double)46;
	c[0] = (double)2 / (double)46;
}
void GenRoB() {
	l[9] = (double)1 / (double)9;
	l[8] = (double)1 / (double)9;
	l[7] = (double)1 / (double)9;
	l[6] = (double)1 / (double)9;
	l[4] = (double)1 / (double)9;
	e[7] = (double)3 / (double)24;
	e[6] = (double)2 / (double)24;
	e[5] = (double)4 / (double)24;
	e[4] = (double)3 / (double)24;
	e[3] = (double)4 / (double)24;
	e[2] = (double)5 / (double)24;
	e[1] = (double)3 / (double)24;
	r[6] = (double)1 / (double)32;
	r[5] = (double)3 / (double)32;
	r[4] = (double)10 / (double)32;
	r[3] = (double)4 / (double)32;
	r[2] = (double)7 / (double)32;
	r[1] = (double)7 / (double)32;
	c[6] = (double)3 / (double)40;
	c[5] = (double)3 / (double)40;
	c[4] = (double)2 / (double)40;
	c[3] = (double)4 / (double)40;
	c[2] = (double)15 / (double)40;
	c[1] = (double)10 / (double)40;
	c[0] = (double)3 / (double)40;
}
void GenChance() {
	for (int i = 0; i < 10; i++) {
		chance[i] = CalcChance(l[i], e[i], r[i], c[i]);
		xchance[i] = CalcChance(l[i], e[i], r[i]);
	}
	chance[10] = e[10] * echance;
	xchance[10] = chance[10];
}
double CalcChance(double L, double E, double R, double C) {
	double Chance = L*lchance + E*echance + R*rchance + C*cchance;
	return Chance;
}

double CalcChance(double L, double E, double R) {
	double Chance = L*lchance + E*echance + R*xrchance;
	return Chance;
}

void CalcAvg(){
	avg = ((chance[0] * 1 + chance[1] * 2 + chance[2] * 3 + chance[3] * 4 + chance[4] * 5 + chance[5] * 6 + chance[6] * 7 + chance[7] * 8 
		+ chance[8] * 9 + chance[9] * 10 + chance[10] * 18) * 7 + (xchance[0] * 1 + xchance[1] * 2 + xchance[2] * 3 + xchance[3] * 4 
		+ xchance[4] * 5 + xchance[5] * 6 + xchance[6] * 7 + xchance[7] * 8 + xchance[8] * 9 + xchance[9] * 10 + xchance[10] * 18)) / (double)8;
}

void CalcScore() {
	scoreChance[1] = pow(1 - chance[0], 7)*(1 - xchance[0]);
	scoreChance[2] = pow(1 - chance[0] - chance[1], 7)*(1 - xchance[0] - xchance[1]);
	scoreChance[3] = pow(1 - chance[0] - chance[1] - chance[2], 7)*(1 - xchance[0] - xchance[1] - xchance[2]);
	scoreChance[4] = pow(1 - chance[0] - chance[1] - chance[2] - chance[3], 7)*(1 - xchance[0] - xchance[1] - xchance[2] - xchance[3]);
	scoreChance[5] = pow(1 - chance[0] - chance[1] - chance[2] - chance[3] - chance[4], 7)*(1 - xchance[0] - xchance[1] - xchance[2] - xchance[3] - xchance[4]);
	scoreChance[6] = pow(1 - chance[0] - chance[1] - chance[2] - chance[3] - chance[4] - chance[5], 7)*(1 - xchance[0] - xchance[1] - xchance[2] - xchance[3] - xchance[4] - xchance[5]);
	scoreChance[7] = pow(1 - chance[0] - chance[1] - chance[2] - chance[3] - chance[4] - chance[5] - chance[6], 7)*(1 - xchance[0] - xchance[1] - xchance[2] - xchance[3] - xchance[4] - xchance[5] - xchance[6]);
	scoreChance[8] = pow(1 - chance[0] - chance[1] - chance[2] - chance[3] - chance[4] - chance[5] - chance[6] - chance[7], 7)*(1 - xchance[0] - xchance[1] - xchance[2] - xchance[3] - xchance[4] - xchance[5] - xchance[6] - xchance[7]);
	scoreChance[9] = pow(1 - chance[0] - chance[1] - chance[2] - chance[3] - chance[4] - chance[5] - chance[6] - chance[7] - chance[8], 7)*(1 - xchance[0] - xchance[1] - xchance[2] - xchance[3] - xchance[4] - xchance[5] - xchance[6] - xchance[7] - xchance[8]);
	scoreChance[10] = pow(chance[10], 8);
	scoreChance[0] = 1 - scoreChance[1] - scoreChance[2] - scoreChance[3] - scoreChance[4] - scoreChance[5] - scoreChance[6] - scoreChance[7] - scoreChance[8] - scoreChance[9] - scoreChance[10];
}

void PrintResult() {
	cout.precision(dbl::max_digits10);
	for (int i = 0; i < 10; i++) {
		cout << "Chance for " << i + 1 << " cost is " << fixed << chance[i] << endl;
	}
	if (eighteen) {
		cout << "Chance for " << 18 << " cost is " << fixed << chance[10] << endl;
	}
		cout << "the average cost is " << fixed << avg << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Chance for " << i + 1 << " score is " << fixed << scoreChance[i] << endl;
	}
	if (eighteen) {
		cout << "Chance for " << 18 << " score is " << fixed << scoreChance[10] << endl;
	}
}
int _tmain(int argc, _TCHAR argv)
{
	cout << "welcome to shadowverse calculator!" << endl;
	cout << "Choose the pack you want to calculate:" << endl;
			cout << "1.Standard" << endl;
			cout << "2.Darkness Evolved" << endl;
			cout << "3.Rise of Bahamut" << endl;
			cin >> userchoice;
			switch (userchoice) {
			case 1:
				cout << "you chose Standard" << endl;
				eighteen = true;
				GenStandard();
				break;
			case 2:
				cout << "you chose Darkness Evolved" << endl;
				GenDE();
				break;
			case 3:
				cout << "you chose Rise of Bahamut" << endl;
				GenRoB();
				break;
			default:
				cout << "Invalid Input" << endl;
			}
	GenChance();
	CalcAvg();
	CalcScore();
	PrintResult();
    return 0;
}

