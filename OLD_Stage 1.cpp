#include <iostream>
#include <string>
#include <fstream>
#include "CMatrix.h"
#include "stdarg.h"
#include <vector>

using namespace std;

bool getIndexAndCheckIfExist(vector<string> &matrixNames,
	vector<CMatrix> &matrix,
	string &firstParmeter, int &firstIndex, bool &found1,
	string &secondParmeter, int &secondIndex, bool &found2) {

	found1 = false;
	for (int i = 0; i < matrixNames.size(); i++) {
		if (firstParmeter == matrixNames[i]) {
			firstIndex = i;
			if (firstIndex >= matrix.size())
				found1 = false;
			else
				found1 = true;

			break;
		}
	}
	found2 = false;
	for (int i = 0; i < matrixNames.size(); i++) {
		if (secondParmeter == matrixNames[i]) {
			secondIndex = i;
			if (secondIndex >= matrix.size())
				found2 = false;
			else
				found2 = true;

			break;
		}
	}

	bool doBreak = false;

	if (!found1 && !found2) {
		cout << firstParmeter << " and "
			<< secondParmeter << " aren't Intiallized" << endl;
		doBreak = true;
	}
	if (!found1 && !doBreak) {
		cout << firstParmeter << " is not Intiallized" << endl;
		doBreak = true;
	}
	if (!found2 && !doBreak) {
		cout << secondParmeter << " is not Intiallized" << endl;
		doBreak = true;
	}

	return doBreak;
}

bool checkAlpha(const string &str) {
	for (int i = 0; i < str.size(); i++)
		if (!isalpha(str[i]) || !isspace(str[i]))
			return true;
	return false;
}

int main() {

	vector<string> matrixNames;
	vector<CMatrix> matrix;
	vector<long> existingIndex;
	vector<bool> existingFlag;

	string line = "";
	int numlines = 0;
	
	while (1) {
		getline(cin, line);

		if (line.find("[") != string::npos && line.find("]") == string::npos) {
			while (line.find("]") == string::npos) {
				string newLine;
				getline(cin, newLine);
				line = line + newLine;
			}
		}
		
		if (line == "end" || line == "end;") {
			cout << "thanks, good bye..." << endl;
			break;
		}
		if (line.empty()) {
			continue;
		}
		
		bool semiColonFlag = false;
		if (line[line.length()] == ';') {
			semiColonFlag = true;
			line = line.substr(0, line.length() - 1);
		}
		

		size_t n = std::count(line.begin(), line.end(), '=');  // count = 
		int x = 0;
	
		if (n == 0) {
			if (matrixNames.size() == 0) {
				cout << "unintiallized matrix" << endl; 
			}
			for (int i = 0; i < matrixNames.size(); i++) {
				if (matrixNames[i] == line && i < matrix.size()) {
					cout << matrix[i];
					break;
				}
				if (i == matrixNames.size() - 1) {
					cout << "unintiallized matrix" << endl;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			string l = (line.substr(0, line.find('=')));
			string::iterator end_pos = remove(l.begin(), l.end(), ' ');
			l.erase(end_pos, l.end());
			if (!matrixNames.size()) {
				existingFlag.push_back(false);
			}
			for (int i = 0; i < matrixNames.size(); i++) {
				if (l == matrixNames[i]) {
					existingFlag.push_back(true);
					existingIndex.push_back(i);
					break;
				}
				if (i == matrixNames.size() - 1) {
					existingFlag.push_back(false);
				}
			}

			if (!existingFlag[numlines + i]) {
				matrixNames.push_back(l);
				existingIndex.push_back(i);
			}
			else {
				matrixNames.push_back(l);
			}
			line = line.substr(line.find('=') + 1);
		}

		for (int i = 0; i < n; i++) {

			if (line[0] == ' ') {
				line = line.substr(1, line.length());
			}
			if (line[line.length()] == ' ') {
				line = line.substr(0, line.length()-1);
			}

			if (line.find('[') != string::npos) {
				if (!existingFlag[numlines + i]) {
	
					matrix.push_back(CMatrix(line));
					
				}
				else {
					matrix.push_back(NULL);
					matrix[existingIndex[numlines + i]] = CMatrix(line);

				}

			}
			else if (line.find('[') == string::npos) {

				//removing spaces
				string::iterator end_pos = remove(line.begin(), line.end(), ' ');
				line.erase(end_pos, line.end());

				if (line.find('+') != string::npos) {
					string firstparmeter = line.substr(0, line.find('+'));
					string secondparmeter = line.substr(line.find('+') + 1);
					int firstindex, secondindex;
					bool found1, found2;

					if (getIndexAndCheckIfExist(matrixNames, matrix,
						firstparmeter, firstindex, found1,
						secondparmeter, secondindex, found2))
						break;

					if (!existingFlag[numlines + i]) {
						matrix.push_back(matrix[firstindex] + matrix[secondindex]);
					}
					else {
						matrix.push_back(NULL);
						matrix[existingIndex[numlines + i]] = matrix[firstindex] + matrix[secondindex];
					}
				}
				else if (line.find('-') != string::npos) {
					string firstparmeter = line.substr(0, line.find('-'));
					string secondparmeter = line.substr(line.find('-') + 1);
					int firstindex, secondindex;
					bool found1, found2;

					if (getIndexAndCheckIfExist(matrixNames, matrix,
						firstparmeter, firstindex, found1,
						secondparmeter, secondindex, found2))
						break;

					if (!existingFlag[numlines + i]) {
						matrix.push_back(matrix[firstindex] - matrix[secondindex]);
					}
					else {
						matrix.push_back(NULL);
						matrix[existingIndex[numlines + i]] = matrix[firstindex] - matrix[secondindex];
					}

				}
				else if (line.find('*') != string::npos) {
					string firstparmeter = line.substr(0, line.find('*'));
					string secondparmeter = line.substr(line.find('*') + 1);
					int firstindex, secondindex;
					bool found1, found2;

					if (getIndexAndCheckIfExist(matrixNames, matrix,
						firstparmeter, firstindex, found1,
						secondparmeter, secondindex, found2))
						break;

					if (!existingFlag[numlines + i]) {
						matrix.push_back(matrix[firstindex] * matrix[secondindex]);
					}
					else {
						matrix.push_back(NULL);
						matrix[existingIndex[numlines + i]] = matrix[firstindex] * matrix[secondindex];
					}
				}
				else if (line.find('/') != string::npos) {
					string firstparmeter = line.substr(0, line.find('/'));
					string secondparmeter = line.substr(line.find('/') + 1);
					int firstindex, secondindex;
					bool found1, found2;

					if (getIndexAndCheckIfExist(matrixNames, matrix,
						firstparmeter, firstindex, found1,
						secondparmeter, secondindex, found2))
						break;

					if (!existingFlag[numlines + i]) {
						matrix.push_back(matrix[firstindex] * matrix[secondindex].getInverse());
					}
					else {
						matrix.push_back(NULL);
						matrix[existingIndex[numlines + i]] = matrix[firstindex] * matrix[secondindex].getInverse();
					}
				}
				else if (line.find("'") != string::npos) {
					string firstParmeter = line.substr(0, line.find("'"));
					int firstIndex;
					bool found1;

					found1 = false;
					for (int i = 0; i < matrixNames.size(); i++) {
						if (firstParmeter == matrixNames[i]) {
							firstIndex = i;
							if (firstIndex >= matrix.size())
								found1 = false;
							else
								found1 = true;
				
							break;
						}
					}

					if (!found1) {
						cout << firstParmeter << " is not Intiallized" << endl;
						break;
					}

					if (!existingFlag[numlines + i]) {
						matrix.push_back(matrix[firstIndex].getTranspose());
					}
					else {
						matrix.push_back(NULL);
						matrix[existingIndex[numlines + i]] = matrix[firstIndex].getTranspose();
					}
				}
				else if (checkAlpha(line)) {

					bool found = false; int index;
					for (int i = 0; i < matrixNames.size(); i++) {
						if (line == matrixNames[i]) {
							index = i;
							if (index >= matrix.size())
								found = false;
							else
								found = true;
							break;
						}
					}

					if (!found) {
						cout << line << " is not Intiallized" << endl;
						break;
					}

					if (!existingFlag[numlines + i]) {
						matrix.push_back(matrix[index] + 0);
					}
					else {
						matrix.push_back(NULL);
						matrix[existingIndex[numlines + i]] = matrix[index];
					}

				}
				else {
					cout << "operation not found" << endl;
				}
			}

		}

		numlines += n;
	}





	return 0;
}

//
//bool found1 = false;
//for (int i = 0; i < matrixNames.size(); i++) {
//	if (firstParmeter == matrixNames[i]) {
//		firstIndex = i;
//		if (firstIndex >= matrix.size())
//			found1 = false;
//		else
//			found1 = true;
//
//		break;
//	}
//}
//bool found2 = false;
//for (int i = 0; i < matrixNames.size(); i++) {
//	if (secondParmeter == matrixNames[i]) {
//		secondIndex = i;
//		if (secondIndex >= matrix.size())
//			found2 = false;
//		else
//			found2 = true;
//
//		break;
//	}
//}
//if (!found1 && !found2) {
//	cout << firstParmeter << " and "
//		<< secondParmeter << " aren't Intiallized" << endl;
//	break;
//}
//if (!found1) {
//	cout << firstParmeter << " is not Intiallized" << endl;
//	break;
//}
//if (!found2) {
//	cout << secondParmeter << " is not Intiallized" << endl;
//	break;
//}
//
//if (!existingFlag[NumLines + i]) {
//	matrix.push_back(matrix[firstIndex] + matrix[secondIndex]);
//}
//else {
//	matrix.push_back(NULL);
//	matrix[existingIndex[NumLines + i]] = matrix[firstIndex] + matrix[secondIndex];
//}

