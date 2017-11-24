#include "CMatrix.h"
#include "stdarg.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

	CMatrix::CMatrix() {
		nR = nC = 0;
		values = NULL;
		this -> name = "none";
	}
	CMatrix::~CMatrix() {
			 reset();
		 }

		 CMatrix::CMatrix(string name,int nR, int nC, int initialization = MI_ZEROS, double initializationValue = 0.0) {
								 this -> nR = nR;
								 this -> nC = nC;
								 this -> name = name;
								 if((nR * nC) == 0) {
									 values = NULL;
									 return;
								 }
								 values = new double *[nR];
								 for (int iR = 0; iR < nR; iR++) {
									 values[iR] = new double[nC];
									 for (int iC = 0; iC < nC; iC++) {
										 switch (initialization) {
										 case MI_ZEROS :
					 values[iR][iC] = 0;
					 break;
										 case MI_ONES :
					 values[iR][iC] = 1;
					 break;
										 case MI_EYE :
					 values[iR][iC] = (iR == iC) ? 1 : 0;
					 break;
										 case MI_RAND :
					 values[iR][iC] = (rand() % 1000000) / 1000000.0;
					 break;
										 case MI_VALUE :
					 values[iR][iC] = initializationValue;
					 break;
										 }
									 }
								 }



		 }


	CMatrix::CMatrix(int nR, int nC, int initialization, double initializationValue) {
				  this -> nR = nR;
				  this -> nC = nC;
					this -> name = "none";
				  if((nR * nC) == 0) {
					  values = NULL;
					  return;
				  }
				  values = new double *[nR];
				  for (int iR = 0; iR < nR; iR++) {
					  values[iR] = new double[nC];
					  for (int iC = 0; iC < nC; iC++) {
						  switch (initialization) {
						  case MI_ZEROS :
	  values[iR][iC] = 0;
	  break;
						  case MI_ONES :
	  values[iR][iC] = 1;
	  break;
						  case MI_EYE :
	  values[iR][iC] = (iR == iC) ? 1 : 0;
	  break;
						  case MI_RAND :
	  values[iR][iC] = (rand() % 1000000) / 1000000.0;
	  break;
						  case MI_VALUE :
	  values[iR][iC] = initializationValue;
	  break;
						  }
					  }
				  }
			  }
	CMatrix ::CMatrix(int nR, int nC, double first, ...) {
		this -> nR = nR;
	   this -> nC = nC;
		 this -> name = "none";
	   if((nR * nC) == 0) {
		   values = NULL;
		   return;
	   }
	   values = new double *[nR];
		   va_list va;

		   va_start(va, first);
   for (int iR = 0; iR < nR; iR++) {
	   values[iR] = new double[nC];
	   for (int iC = 0; iC < nC; iC++) {
		   values[iR][iC] = (iC == 0 && iR == 0) ? first : va_arg(va, double);
	   }
	}
	va_end(va);
		}
		CMatrix ::CMatrix(string name,int nR, int nC, double first, ...) {
			this -> nR = nR;
			 this -> nC = nC;
			 this -> name = name;
			 if((nR * nC) == 0) {
				 values = NULL;
				 return;
			 }
			 values = new double *[nR];
				 va_list va;

				 va_start(va, first);
		 for (int iR = 0; iR < nR; iR++) {
			 values[iR] = new double[nC];
			 for (int iC = 0; iC < nC; iC++) {
				 values[iR][iC] = (iC == 0 && iR == 0) ? first : va_arg(va, double);
			 }
		}
		va_end(va);
			}

	CMatrix ::CMatrix(const CMatrix & m) {
		nR = nC = 0;
		values = NULL;
		this -> name = "none";
		copy(m);
		}
	CMatrix::CMatrix(string s) {
		 nR = nC = 0;
		 values = NULL;
		 this -> name = "none";
	    	 copy(s);
		 }
	CMatrix::CMatrix(string data,string s) {
		nR = nC = 0;
		values = NULL;
		name = data;
		copy(s);
	}

	/* ############################################################################# */

	/*

	[ function name] : copy
	[ return type] : void
	[ inherited function/operation ] : none
	[ functionality ] : copies the contents of the passed matrix into the caller matrix.

	*/

	void CMatrix ::copy(const CMatrix & m) {
		reset();
		this -> nR = m.nR;
		this -> nC = m.nC;
		this -> name = m.name;
		if((nR * nC) == 0) {
			values = NULL;
			return;
		}
		values = new double *[nR];
		for (int iR = 0; iR < nR; iR++) {
			values[iR] = new double[nC];
			for (int iC = 0; iC < nC; iC++) {
				values[iR][iC] = m.values[iR][iC];
			}
		}
	}
	/* ############################################################################# */

	/*

	[ function name] : getName
	[ return type] : string
	[ inherited function/operation ] : none
	[ functionality ] : returns the matrix name

	*/
	string CMatrix:: getName() {
		string data = this -> name;
			return data;
		}
		/* ############################################################################# */

		/*

		[ function name] : setName
		[ return type] : void
		[ inherited function/operation ] : none
		[ functionality ] : sets the matrix name

		*/
	void CMatrix:: setName(string s) {
			this->name = s;
		}

	CMatrix::CMatrix(double d) {
		nR = nC = 0;
		values = NULL;
		this -> name = "none";
		copy(d);
	}


	void CMatrix::copy(double d) {
		reset();
		this -> nR = 1;
		this -> nC = 1;
		this -> name = "none";
		values = new double *[1];
		values[0] = new double[1];
		values[0][0] = d;
	}

/* ############################################################################# */

/*

[ function name] : copy
[ return type] : void
[ inherited function/operation ] : -resest [CMatrix.cpp, line: ]
																	 -addColumn [CMatrix.cpp, line: ]
																	 -addRow [CMatrix.cpp, line: ]
[ functionality ] : creates a matrix and deduces its elements from the passed string matrix,
										then copies the contents into the caller matrix.

*/
void CMatrix ::copy(string s) {
	reset();
	char * buffer = new char[s.length() + 1];
	strcpy(buffer, s.c_str());
	const char * lineSeparators = ";";
	char * line = strtok(buffer, lineSeparators);
	while (line) {
			CMatrix row;
			string s;
			for(int i = 0 ; i < strlen(line) + 1;i++) {
				if(line[i] == ' ' || i == strlen(line)) {
					if(s == "") {
						s = "";
					} else {
					CMatrix item = atof(s.c_str());
					row.addColumn(item);
					s = "";
					}
				} else if(line[i] == '[' || line[i] == ']') {
					continue;
				} else {
					s += line[i];
				}
			}

			if(row.nC > 0 && (row.nC == nC || nR == 0))
				addRow(row);
			line = strtok(NULL, lineSeparators);
		}
	delete[] buffer;
}
/* ############################################################################# */

/*

[ function name] : reset
[ return type] : void
[ inherited function/operation ] : none
[ functionality ] : deletes elements of the member variable values, if any existed,
										and resets all member variables

*/
	void CMatrix ::reset() {
		if(values) {
			for (int i = 0; i < nR; i++)
				delete[] values[i];
			delete[] values;
		}
		nR = nC = 0;
		values = NULL;
	}
	/* ############################################################################# */

	/*

	[ function name] : getString
	[ return type] : string
	[ inherited function/operation ] : none
	[ functionality ] : returns and displays the caller matrix in string form

	*/
	string CMatrix ::getString() {
		string s;
		for (int iR = 0; iR < nR; iR++) {
			for (int iC = 0; iC < nC; iC++) {
				char buffer[50];
				double n = values[iR][iC];
				//sprintf(buffer, 50, " %g\t", values[iR][iC]);
				sprintf(buffer, "%g\t", n);
				s += buffer;
			}
			s += "\r\n";
		}
		return s;
	}

	/* ############################################################################# */

	/*

	[ function name] : getValues
	[ return type] : void
	[ inherited function/operation ] : none
	[ functionality ] : displays the caller matrix values

	*/

	void CMatrix::getValues() {

		int lengthValues = sizeof(this->values) / sizeof(double);
		for(int i = 0 ; i < nR;i++) {
			for(int j = 0;j< nC ;j++) {

				printf("%g\t",values[i][j]);

			}
			printf("\n");
		}
		cout << endl;
		cout << "Number of Rows : " << nR << endl;
		cout << "Number of Columns : " << nC << endl;


	}

	/* ############################################################################# */

	/*

	[ function name] : =
	[ return type] : CMatrix
	[ inherited function/operation ] : copy(const CMatrix&) [CMatrix.cpp, line: ]
	[ functionality ] : overrides the = operator to operate on CMatrix objects,
											returns by value the copy of the passed matrix.

	*/

	CMatrix CMatrix ::operator = (const CMatrix & m) {
		copy(m);
		return *this;
	}
	/* ############################################################################# */

	/*

	[ function name] : =
	[ return type] : CMatrix
	[ inherited function/operation ] : copy(double) [CMatrix.cpp, line: ]
	[ functionality ] : overrides the = operator to operate on double type values,
											returns by value the copy of the passed matrix.

	*/
	CMatrix CMatrix ::operator = (double d) {
		copy(d);
		return *this;
	}
	/* ############################################################################# */

	/*

	[ function name] : =
	[ return type] : CMatrix
	[ inherited function/operation ] : copy(string) [CMatrix.cpp, line: ]
	[ functionality ] : overrides the = operator to operate on string type values,
											returns by value the copy of the passed matrix.

	*/
	CMatrix CMatrix ::operator = (string s) {
		copy(s);
		return *this;
	}

	/* ############################################################################# */

	/*

	[ function name] : add
	[ return type] : void
	[ inherited function/operation ] : none
	[ functionality ] : adds the passed matrix to the caller matrix.

	*/
	void CMatrix ::add(const CMatrix & m) {
		if(nR!= m.nR || nC!= m.nC)
			throw ("Invalid matrix dimension");
		for (int iR = 0; iR < nR; iR++)
			for (int iC = 0; iC < nC; iC++)
				values[iR][iC] += m.values[iR][iC];
	}
	/* ############################################################################# */

	/*

	[ function name] : +=
	[ return type] : void
	[ inherited function/operation ] : add [CMatrix.cpp, line: ]
	[ functionality ] : overrides the += operator to operate on CMatrix objects,
											adds the passed matrix to the caller matrix.

	*/
	void CMatrix ::operator += (const CMatrix & m) {
		add(m);
	}
	/* ############################################################################# */

	/*

	[ function name] : +=
	[ return type] : void
	[ inherited function/operation ] : add [CMatrix.cpp, line: ]
	[ functionality ] : overrides the += operator to operate on double type values by constructing a matrix with that value,
											then adds the passed matrix to the caller matrix.

	*/
	void CMatrix ::operator += (double d) {
		add(CMatrix(nR, nC, MI_VALUE, d));
	}
	/* ############################################################################# */

	/*

	[ function name] : +
	[ return type] : CMatrix
	[ inherited function/operation ] : = [CMatrix.cpp, line: ]
																		+= [CMatrix.cpp, line: ]
	[ functionality ] : overrides the + operator to operate on CMatrix objects,
											returns by value the summation of the passed matrix with the caller matrix.

	*/
	CMatrix CMatrix ::operator + (const CMatrix & m) {
		CMatrix r = *this;
		r += m;
		return r;
	}
	/* ############################################################################# */

	/*

	[ function name] : +
	[ return type] : CMatrix
	[ inherited function/operation ] : = [CMatrix.cpp, line: ]
																		+= [CMatrix.cpp, line: ]
	[ functionality ] : overrides the + operator to operate on double type values by constructing a matrix with that value,
											returns by value the summation of the passed matrix with the caller matrix.

	*/
	CMatrix CMatrix ::operator + (double d) {
		CMatrix r = *this;
		r += d;
		return r;
	}
	/* ############################################################################# */

	/*

	[ function name] : sub
	[ return type] : CMatrix
	[ inherited function/operation ] : none
	[ functionality ] : subtracts the passed matrix from the caller matrix

	*/
	void CMatrix ::sub(const CMatrix & m) {
		if(nR!= m.nR || nC!= m.nC)
			throw ("Invalid matrix dimension");
		for (int iR = 0; iR < nR; iR++)
			for (int iC = 0; iC < nC; iC++)
				values[iR][iC] -= m.values[iR][iC];
	}
	/* ############################################################################# */

	/*

	[ function name] : -=
	[ return type] : void
	[ inherited function/operation ] : sub [CMatrix.cpp, line: ]
	[ functionality ] : overrides the -= operator to operate on CMatrix objects,
											then subtracts the passed matrix from the caller matrix.

	*/
	void CMatrix ::operator -= (const CMatrix & m) {
		sub(m);
	}
	/* ############################################################################# */

	/*

	[ function name] : -=
	[ return type] : void
	[ inherited function/operation ] : sub [CMatrix.cpp, line: ]
	[ functionality ] : overrides the -= operator to operate on double type values by constructing a matrix with that value,
											then subtracts the passed matrix from the caller matrix.

	*/
	void CMatrix ::operator -= (double d) {
		sub(CMatrix(nR, nC, MI_VALUE, d));
	}
	/* ############################################################################# */

	/*

	[ function name] : -
	[ return type] : CMatrix
	[ inherited function/operation ] : none
	[ functionality ] : overrides the - operator to operate on CMatrix objects,
											then returns by value the subtraction of the passed matrix from the caller matrix.

	*/
	CMatrix CMatrix ::operator - (const CMatrix & m) {
		CMatrix r = *this;
		r -= m;
		return r;
	}
	/* ############################################################################# */

	/*

	[ function name] : -
	[ return type] : void
	[ inherited function/operation ] : none
	[ functionality ] : overrides the -= operator to operate on double type values by constructing a matrix with that value,
											then returns by value the subtraction of the passed matrix from the caller matrix.

	*/
	CMatrix CMatrix ::operator - (double d) {
		CMatrix r = *this;
		r -= d;
		return r;
	}
	/* ############################################################################# */

	/*

	[ function name] : elementWiseDiv
	[ return type] : void
	[ inherited function/operation ] : copy(const CMatrix&) [CMatrix.cpp, line: ]
	[ functionality ] : performs element wise operation, and returns a pointer to the caller matrix.

	*/
	CMatrix CMatrix ::elementWiseDiv(const CMatrix & m){

		if(nR != m.nR && nC != m.nC)
			throw("Invalid matrix dimension");
		CMatrix r(nR, nC);
		for (int iR = 0; iR < r.nR; iR++) {
			for (int iC = 0; iC < r.nC; iC++) {
				r.values[iR][iC] = values[iR][iC] / m.values[iR][iC];
			}
		}
		copy(r);

		return *this;
	}
	/* ############################################################################# */

	/*

	[ function name] : mul
	[ return type] : void
	[ inherited function/operation ] : copy(const CMatrix&) [CMatrix.cpp, line: ]
	[ functionality ] : multiplies the passed matrix with the caller matrix, then copies the result into the caller matrix.

	*/
	void CMatrix ::mul(const CMatrix & m) {
		if(nC!= m.nR)
			throw ("Invalid matrix dimension");
		CMatrix r(nR, m.nC);
		for (int iR = 0; iR < r.nR; iR++) {
			for (int iC = 0; iC < r.nC; iC++) {
				r.values[iR][iC] = 0;
				for (int k = 0; k < m.nR; k++) {
					r.values[iR][iC] += values[iR][k] * m.values[k][iC];
				}
			}
		}
		copy(r);
	}
	/* ############################################################################# */

	/*

	[ function name] : *=
	[ return type] : void
	[ inherited function/operation ] : mul [CMatrix.cpp, line: ]
	[ functionality ] : overrides the *= operator to operate on CMatrix objects, and multiplies the passed matrix with the caller matrix

	*/
	void CMatrix ::operator *= (const CMatrix & m) {
		mul(m);
	}
	/* ############################################################################# */

	/*

	[ function name] : *=
	[ return type] : void
	[ inherited function/operation ] : none
	[ functionality ] : overrides the *= operator to operate on double type values,
										and multiplies the caller matrix elemets with that scalar value.
	*/
	void CMatrix ::operator *= (double d) {
		for (int iR = 0; iR < nR; iR++)
			for (int iC = 0; iC < nC; iC++)
				values[iR][iC] *= d;
	}
	/* ############################################################################# */

	/*

	[ function name] : *
	[ return type] : CMatrix
	[ inherited function/operation ] : *= [CMatrix.cpp, line: ]
																			= [CMatrix.cpp, line: ]
	[ functionality ] : overrides the * operator to operate on CMatrix objects,
											then returns by value the multiplication of the passed matrix with the caller matrix.

	*/
	CMatrix CMatrix ::operator * (const CMatrix & m) {
		CMatrix r = *this;
		r *= m;
		return r;
	}
	/* ############################################################################# */

	/*

	[ function name] : *
	[ return type] : CMatrix
	[ inherited function/operation ] : *= [CMatrix.cpp, line: ]
																			= [CMatrix.cpp, line: ]
	[ functionality ] : overrides the * operator to operate on double type values,
											then returns by value the multiplication of that scalar value with the elements of the caller matrix.

	*/
	CMatrix CMatrix ::operator * (double d) {
		CMatrix r = *this;
		r *= d;
		return r;
	}
	/* ############################################################################# */

	/*

	[ function name] : ++
	[ return type] : CMatrix
	[ inherited function/operation ] : add [CMatrix.cpp, line: ]
	[ functionality ] : overrides the ++ operator to operate on CMatrix objects,
											returns by value the caller matrix after adding 1 to its elemets.

	*/
	CMatrix CMatrix ::operator++() {
		add(CMatrix(nR, nC, MI_VALUE, 1.0));
		return *this;
	}
	/* ############################################################################# */

	/*

	[ function name] : ++
	[ return type] : CMatrix
	[ inherited function/operation ] : add [CMatrix.cpp, line: ]
	[ functionality ] : overrides the ++ operator to operate on CMatrix objects,
											returns by value the caller matrix after adding 1 to its elemets.

	*/
	CMatrix CMatrix ::operator++(int) {
		CMatrix C = *this;
		add(CMatrix(nR, nC, MI_VALUE, 1.0));
		return C;
	}
	/* ############################################################################# */

	/*

	[ function name] : --
	[ return type] : CMatrix
	[ inherited function/operation ] : add [CMatrix.cpp, line: ]
	[ functionality ] : overrides the -- operator to operate on CMatrix objects,
											returns by value the caller matrix after adding -1 to its elemets.

	*/
	CMatrix CMatrix ::operator --() {
		add(CMatrix(nR, nC, MI_VALUE, -1.0));
		return *this;
	}
	/* ############################################################################# */

	/*

	[ function name] : --
	[ return type] : CMatrix
	[ inherited function/operation ] : add [CMatrix.cpp, line: ]
	[ functionality ] : overrides the -- operator to operate on CMatrix objects,
											returns by value the caller matrix after adding -1 to its elemets.

	*/
	CMatrix CMatrix ::operator --(int) {
		CMatrix r = *this;
		add(CMatrix(nR, nC, MI_VALUE, -1.0));
		return r;
	}
	/* ############################################################################# */

	/*

	[ function name] : -
	[ return type] : CMatrix
	[ inherited function/operation ] : none
	[ functionality ] : overrides the - operator to return the negated caller matrix.

	*/
	CMatrix CMatrix ::operator - () {
		for (int iR = 0; iR < nR; iR++)
			for (int iC = 0; iC < nC; iC++)
				values[iR][iC] = -values[iR][iC];
		return *this;
	}
	/* ############################################################################# */

	/*

	[ function name] : +
	[ return type] : CMatrix
	[ inherited function/operation ] : none
	[ functionality ] : overrides the + to return the caller matrix unchanged!

	*/
	CMatrix CMatrix ::operator + () {
		return *this;
	}
	/* ############################################################################# */

	/*

	[ function name] : setSubMatrix
	[ return type] : void
	[ inherited function/operation ] : none
	[ functionality ] : sets the passed matrix into the called matrix where indicated by the passed values r and c.

	*/
	void CMatrix ::setSubMatrix(int r, int c,const CMatrix & m) {
		if((r + m.nR) > nR || (c + m.nC) > nC) throw ("Invalid matrix dimension");
		for (int iR = 0; iR < m.nR; iR++)
			for (int iC = 0; iC < m.nC; iC++)
				values[r + iR][c + iC] = m.values[iR][iC];
	}
	/* ############################################################################# */

	/*

	[ function name] : getSubMatrix
	[ return type] : CMatrix
	[ inherited function/operation ] : none
	[ functionality ] : returns by value the sub matrix nR x nC from the caller matrix where indicated by the values r and c.

	*/
	CMatrix CMatrix ::getSubMatrix(int r, int c, int nR, int nC) {
		if((r + nR) > nR || (c + nC) > nC) throw ("Invalid matrix dimension");
		CMatrix m(nR, nC);
		for (int iR = 0; iR < m.nR; iR++)
			for (int iC = 0; iC < m.nC; iC++)
				m.values[iR][iC] = values[r + iR][c + iC];
		return m;
	}
	/* ############################################################################# */

	/*

	[ function name] : addColumn
	[ return type] : void
	[ inherited function/operation ] : setSubMatrix [CMatrix.cpp, line: ]
	[ functionality ] : adds a column of elements from the passed matrix to the caller matrix.

	*/
	void CMatrix ::addColumn(const CMatrix & m) {
		CMatrix n(max(nR, m.nR), nC + m.nC);
		n.setSubMatrix(0, 0, *this);
		n.setSubMatrix(0, nC, m);
		*this = n;
	}
	/* ############################################################################# */

	/*

	[ function name] : addRow
	[ return type] : void
	[ inherited function/operation ] : setSubMatrix [CMatrix.cpp, line: ]
	[ functionality ] : adds a row of elements from the passed matrix to the caller matrix.

	*/
	void CMatrix ::addRow(const CMatrix & m) {
		CMatrix n(name,nR + m.nR, max(nC, m.nC));
		n.setSubMatrix(0, 0, *this);
		n.setSubMatrix(nR, 0, m);
		*this = n;
	}
	/* ############################################################################# */

	/*

	[ function name] : getCofactor
	[ return type] : CMatrix
	[ inherited function/operation ] : none
	[ functionality ] : returns the cofactor matrix of values[r][c].

	*/
	CMatrix CMatrix ::getCofactor(int r, int c) {
		if(nR <= 1 && nC <= 1) throw ("Invalid matrix dimension");
		CMatrix m(nR - 1, nC - 1);
		for (int iR = 0; iR < m.nR; iR++)
			for (int iC = 0; iC < m.nC; iC++) {
				int sR = (iR < r) ? iR : iR + 1;
				int sC = (iC < c) ? iC : iC + 1;
				m.values[iR][iC] = values[sR][sC];
			}
		return m;
	}
	/* ############################################################################# */

	/*

	[ function name] : getDeterminant
	[ return type] : double
	[ inherited function/operation ] : none
	[ functionality ] : returns the determinant of the caller matrix.

	*/
	double CMatrix ::getDeterminant() {
			// Try to Solve it with Another Technique
			if(nR!= nC) throw ("Invalid matrix dimension");
			if(nR == 1 && nC == 1) return values[0][0];
			double value = 0, m = 1;
			for (int iR = 0; iR < nR; iR++) {
				value += m * values[0][iR] * getCofactor(0, iR).getDeterminant();
				m *= -1;
			}
			return value;
		}


		/* ############################################################################# */

	/*

	[ function name] : getTranspose
	[ return type] : CMatrix
	[ inherited function/operation ] : none
	[ functionality ] : returns the transpose of the caller matrix.

	*/
	CMatrix CMatrix::getTranspose()
	{
		CMatrix a(nC, nR);
		for (int iR = 0; iR < a.nR; iR++)
			for (int iC = 0; iC < a.nC; iC++)
				a.values[iR][iC] = values[iC][iR];

		return a;
	}
	/* ############################################################################# */

	/*

	[ function name] : getInverse
	[ return type] : CMatrix
	[ inherited function/operation ] : -getDeterminant [CMatrix.cpp, line: ]
									   -getCofactor [CMatrix.cpp, line: ]
	[ functionality ] : returns the inverse of the caller matrix if valid, otherwise returns a matrix with name "Invert"

	*/
	CMatrix CMatrix::getInverse()
	{	if(nR != nC)
			throw("Invertible matrix");
		if(getDeterminant() != 0) {
			CMatrix m(nR, nC);
			for (int iR = 0; iR < m.nR; iR++)
			for (int iC = 0; iC < m.nC; iC++)
			{
				if (iR % 2 == 0) {
					m.values[iR][iC] = (iC % 2 == 0) ? getCofactor(iR, iC).getDeterminant() : -getCofactor(iR, iC).getDeterminant();
				}
				else
				m.values[iR][iC] = (iC % 2 == 0) ? -getCofactor(iR, iC).getDeterminant() : getCofactor(iR, iC).getDeterminant();
			}
			m = m.getTranspose();
			m = m * (1 / getDeterminant());
			return m;
		} else {
			CMatrix m("Invert",nR,nC);
			return m;
		}
}
/* ############################################################################# */

/*

[ function name] : >>
[ return type] : istream&
[ inherited function/operation ] : += [CMatrix.cpp, line: ]
																		= [CMatrix.cpp, line: ]
[ functionality ] : overrides the >> operator to operate on CMatrix object,
										and returns by reference the caller passed matrix.

*/
	istream & operator >> (istream &is, CMatrix & m) {
		string s;
		getline(is, s, ']');
		s += "]";
		m = CMatrix(s);
		return is;
	}
	/* ############################################################################# */

	/*

	[ function name] : <<
	[ return type] : ostream&
	[ inherited function/operation ] : += [CMatrix.cpp, line: ]
																			= [CMatrix.cpp, line: ]
																			getString [CMatrix.cpp, line: ]
	[ functionality ] : overrides the << operator to operate on CMatrix object,
											and returns by reference the string form of the passed matrix.

	*/
	ostream & operator << (ostream & os, CMatrix & m) {
		os << m.getString();
		return os;
	}
