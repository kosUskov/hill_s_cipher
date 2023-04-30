#pragma once
#include <string>
#include <iostream>
#include <vector>

typedef long long LL;
typedef std::vector<std::vector <int>> MATRIX;

class ClassCrypto {
	MATRIX delRowCol(MATRIX m, int _i, int _j) {
		int k = m.size();
		MATRIX newM(m);
		newM.erase(newM.begin() + _i);
		for (int i = 0; i < k - 1; i++) { newM[i].erase(newM[i].begin() + _j); }
		return newM;
	}
	LL getAlgDop(MATRIX m, int _i, int _j) {
		LL algDop = 0;
		int k = m.size() - 1;
		MATRIX _m = delRowCol(m, _i, _j);
		if (k == 1) { algDop = _m[0][0]; }
		else {
			for (LL j = 0; j < k; j++) {
				algDop += _m[0][j] * getAlgDop(_m, 0, j);
			}
		}
		bool tmpI = (_i + _j) % 2;
		if (tmpI) { return -algDop; }
		else { return algDop; }
	}
	LL getDetMatrix(MATRIX m) {
		int k = m.size();
		LL det = 0;
		for (int i = 0; i < k; i++) {
			det += m[0][i] * getAlgDop(m, 0, i);
		}
		return det;
	}
public:
	int getOstat(LL delim, int delit) {
		if (delit != 0) {
			while ((delim < 0) || (delim >= delit)) {
				delim %= delit;
				if (delim < 0) { delim += delit; }
			}
			return delim;
		}
		else { return -1; }
	}
	MATRIX multiplyMatrixMod(MATRIX leftMatrix, MATRIX rightMatrix, int mod) {
		int row = leftMatrix.size();
		int med = rightMatrix.size();
		int col = rightMatrix[0].size();
		MATRIX result(row, std::vector <int>(col));
		for (int i = 0; i < row; i++) { result[i].resize(col); }
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				LL sum = 0;
				for (int k = 0; k < med; k++) {
					sum += leftMatrix[i][k] * rightMatrix[k][j];
				}
				result[i][j] = getOstat(sum, mod);
			}
		}
		return result;
	}
	int getRevDet(MATRIX m, int mod) {
		LL det = getDetMatrix(m);
		if (det <= 0) { return -1; }
		else {
			for (int i = 1; i < mod; i++) {
				if (i * det % mod == 1) return i;
			}
			return -1;
		}
	}
	MATRIX getRevMatrix(MATRIX m, int mod, int revDet) {
		int k = m.size();
		MATRIX result(k, std::vector <int>(k));
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				LL tmpResult = revDet * getAlgDop(m, i, j);
				result[j][i] = getOstat(tmpResult, mod);
			}
		}
		return result;
	}
	int getSqrt(int x) {
		for (int i = 1; i <= x; i++) {
			if (i * i <= x) { if (i * i == x) { return i; } }
			else { return 0; }
		}
	}
	bool checkDetMatrix(MATRIX matrix, int mod) {
		int k = getRevDet(matrix, mod);
		if (k == -1) { return 1; }
		return 0;
	}
	int setMaxPoryadok(int mod) { //алгоритм не совершенен
		if (mod == 2) { return 100; }
		int maxAlphaNum = mod - 1;
		for (int max = 2; max < 60; max++) {
			LL maxValue = max - 1;
			for (int i = 0; i < max; i++) {
				LL a = maxValue * maxAlphaNum;
				if (a > maxValue) { maxValue = a; }
				else { return max - 1; }
			}
		}
	}
	void printKeyMatrix(MATRIX matrix, int mod) {
		std::string tmpString = std::to_string(mod);
		int length = tmpString.length();
		int poryadok = matrix.size();
		std::cout << std::endl;
		for (int i = 0; i < poryadok; i++) {
			std::cout << "   ";
			for (int j = 0; j < poryadok; j++) {
				int tmpValue = matrix[i][j];
				tmpString = std::to_string(tmpValue);
				tmpValue = tmpString.length();
				tmpValue = length - tmpValue;
				tmpString = " ";
				for (int k = 0; k < tmpValue; k++) { tmpString += " "; }
				std::cout << matrix[i][j] << tmpString;
			}
			std::cout << std::endl;
		}
	}
};