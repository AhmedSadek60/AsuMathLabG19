#ifndef HEADER
#define HEADER
#include <string>
#include <fstream>
#include "stdarg.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

class CMatrix {
	int nR, nC;
	double * * values;
	string name;
public:
	CMatrix();
	~CMatrix();
	enum MI {
		MI_ZEROS,
		MI_ONES,
		MI_EYE,
		MI_RAND,
		MI_VALUE
	};
	CMatrix(string name,int nR, int nC, int initialization = MI_ZEROS, double initializationValue = 0.0);
	CMatrix(int nR, int nC, int initialization = MI_ZEROS, double initializationValue = 0.0);
	CMatrix(int nR, int nC, double first, ...);
	CMatrix(string name,int nR, int nC, double first, ...);
	CMatrix(const CMatrix & m);
	CMatrix(double d);
	CMatrix(string s);
	CMatrix(string data,string s);
	void copy(const CMatrix & m);
	void copy(double d);
	void copy(string s);
	void reset();
	void getValues();
	string getString();
	string getName();
	void setName(string s);

	CMatrix operator = (const CMatrix & m);
	CMatrix operator = (double d);
	CMatrix operator = (string s);
	void add(const CMatrix & m);
	void operator += (const CMatrix & m);
	void operator += (double d);
	CMatrix operator + (const CMatrix & m);
	CMatrix operator + (double d);
	void sub(const CMatrix & m);
	void operator -= (const CMatrix & m);
	void operator -= (double d);
	CMatrix operator - (const CMatrix & m);
	CMatrix operator - (double d);
	void mul(const CMatrix & m);
	void operator *= (const CMatrix & m);
	void operator *= (double d);
	CMatrix operator * (const CMatrix & m);
	CMatrix operator * (double d);
	CMatrix elementWiseDiv(const CMatrix& m);
	/*void div(CMatrix & m);
	void operator /= (cmatrix & m);
	void operator /= (double d);
	cmatrix operator / (cmatrix & m);
	cmatrix operator / (double d);*/
	CMatrix operator++(); //Pre Increment
	CMatrix operator++(int); //Post Increment, int is not used
	CMatrix operator--(); //Pre Increment
	CMatrix operator--(int); //Post Increment, int is not used
	CMatrix operator - ();
	CMatrix operator + ();
	friend istream & operator >> (istream & is, CMatrix & C); //Stream
	friend ostream & operator << (ostream & os, CMatrix & C); //Stream
	void setSubMatrix(int iR, int iC, const CMatrix & m);
	CMatrix getSubMatrix(int r, int c, int nr, int nc);
	CMatrix getCofactor(int r, int c);
	void addColumn(const CMatrix & m);
	void addRow(const CMatrix & m);
	double & operator[](int i) {
		return values[i / nC][i % nC];
	}
	double & operator()(int i) {
		return values[i / nC][i % nC];
	}
	double & operator()(int r, int c) {
		return values[r][c];
	}
	int getn() {
		return nR * nC;
	};
	int getnR() {
		return nR;
	};
	int getnC() {
		return nC;
	};
	double getDeterminant();
	CMatrix getTranspose();
	CMatrix getInverse();
};

#endif
