#pragma once
#include "ClassCrypto.h"
#include "ClassSetting.h"
#include <ctime>

class ClassUser : public ClassCrypto, public ClassSetting {
	MATRIX textMatrix;
	MATRIX revTextMatrix;
	MATRIX fileMatrix;
	MATRIX revFileMatrix;
	std::vector<int> textAlphavit;
	MATRIX textKey;
	MATRIX textRevKey;
	MATRIX fileKey;
	MATRIX fileRevKey;
	int modTextAlpha;
	int textPoryadok;
	int maxTextPorydok;
	int filePoryadok;
public:
	ClassUser() {
		setHelpColMenu(0);
		setLanguage(1);
		setColText(15);
		setColBack(0);
		setColSelText(14);
		setColSelBack(2);
		setChangeDate("17:04:37  13.04.2021");
		textPoryadok = 0;
		modTextAlpha = 0;
		maxTextPorydok = 0;
		filePoryadok = 0;
	}
	bool isEptyTextPoryadok() {
		if (textPoryadok > 1) { return 1; }
		else { return 0; }
	}
	bool isEptyFilePoryadok() {
		if (filePoryadok > 1) { return 1; }
		else { return 0; }
	}
	bool setTextAlphavit() {
		textAlphavit.clear();
		maxTextPorydok = 0;
		textPoryadok = 0;
		std::string tmpString;
		std::getline(std::cin, tmpString);
		const int max_i = tmpString.length();
		std::vector<int>::iterator it;
		for (int i = 0; i < max_i; i++) {
			char ch = tmpString[i];
			it = std::find(textAlphavit.begin(), textAlphavit.end(), ch);
			if (it == textAlphavit.end()) {
				textAlphavit.push_back(ch);
			}
		}
		modTextAlpha = textAlphavit.size();
		if (modTextAlpha > 1) {
			int tmpMax = setMaxPoryadok(modTextAlpha);
			if (tmpMax > 8) { maxTextPorydok = 8; }
			else { maxTextPorydok = tmpMax; }
			std::cout << getStr111() << modTextAlpha;
			return 0;
		}
		else { std::cout << getStr112(); return 1; }
	}
	bool checkAlpha(char ch) {
		std::vector<int>::iterator it;
		it = std::find(textAlphavit.begin(), textAlphavit.end(), ch);
		if (it == textAlphavit.end()) { return 1; }
		return 0;
	}
	bool setKeyText() {
		textKey.clear();
		while (1) {
			std::string tmpString;
			std::getline(std::cin, tmpString);
			const int max_i = tmpString.length();
			textPoryadok = getSqrt(max_i);
			if (textPoryadok < 2) { std::cout << getStr1211(); return 1; }
			else if (textPoryadok > maxTextPorydok) {
				std::cout << getStr1212() << maxTextPorydok;
				return 1;
			}
			textKey.resize(textPoryadok);
			for (int i = 0; i < textPoryadok; i++) {
				textKey[i].resize(textPoryadok);
			}
			int count = -1;
			for (int i = 0; i < textPoryadok; i++) {
				for (int j = 0; j < textPoryadok; j++) {
					count++;
					char ch = tmpString[count];
					if (checkAlpha(ch)) {
						std::cout << getStr12130() << ch << getStr12131();
						textPoryadok = 0; return 1;
					}
					std::vector<int>::iterator it = std::find(textAlphavit.begin(), textAlphavit.end(), ch);
					int alphaNum = std::distance(textAlphavit.begin(), it);
					textKey[i][j] = alphaNum;
				}
			}
			return setRevKey(1);
		}
	}
	bool setKeyMatrix(bool whatMode) {
		int tmpPoryadok = 0;
		int tmpMod;
		int tmpMaxPoryadok;
		if (whatMode) {
			textKey.clear();
			tmpMod = modTextAlpha;
			tmpMaxPoryadok = maxTextPorydok;
		}
		else {
			fileKey.clear();
			tmpMod = 256;
			tmpMaxPoryadok = 7;
		}
		MATRIX tmpKey;
		int poryadok2 = -1;
		int secondPoryadok = 0;
		bool helpInput = 0;
		while ((poryadok2 != tmpPoryadok) || helpInput) {
			if (poryadok2 == -1) { poryadok2 = 0; }
			secondPoryadok = 0;
			helpInput = 0;
			poryadok2++;
			std::string tmpString;
			std::getline(std::cin, tmpString);
			const int max_i = tmpString.length();
			int point = -2;
			std::string tmp2String = "";
			for (int i = 0; i < max_i; i++) {
				if ((tmpString[i] >= 48) & (tmpString[i] <= 57) || (tmpString[i] == 32)) {
					if (tmpString[i] != 32) {
						point = 1;
						if (i == max_i - 1) {
							point = -1;
							if (poryadok2 == 1) { tmpPoryadok++; }
							else { secondPoryadok++; }
							tmp2String += tmpString[i];
						}
					}
					else if (point == 1) {
						point = -1;
						if (poryadok2 == 1) { tmpPoryadok++; }
						else { secondPoryadok++; }
					}
					if (point == 1) { tmp2String += tmpString[i]; }
					if (point == -1) {
						point = 0;
						if (poryadok2 == 1) {
							tmpKey.resize(tmpPoryadok);
							for (int i = 0; i < tmpPoryadok; i++) {
								tmpKey[i].resize(tmpPoryadok);
							}
						}
						int tmpNum = atoi(tmp2String.c_str());
						if (tmpNum < tmpMod) {
							if (poryadok2 == 1) {
								tmpKey[poryadok2 - 1][tmpPoryadok - 1] = tmpNum;
							}
							else if ((poryadok2 > 1) & (secondPoryadok > tmpPoryadok)) {
								std::cout << getStr1221();
								return 1;
							}
							else {
								tmpKey[poryadok2 - 1][secondPoryadok - 1] = tmpNum;
							}
							tmp2String = "";
						}
						else {
							std::cout << getStr1222();
							return 1;
						}
					}
				}
				else {
					std::cout << getStr1223();
					return 1;
				}
			}
			if (tmpPoryadok == 1) {
				std::cout << getStr1224();
				return 1;
			}
			else if (tmpPoryadok > tmpMaxPoryadok) {
				std::cout << getStr1212() << tmpMaxPoryadok;
				return 1;
			}
			if ((poryadok2 > 1) & (secondPoryadok != tmpPoryadok) & (point != -2)) {
				std::cout << getStr1221();
				return 1;
			}
			if (point == -2) {
				poryadok2--;
				helpInput = 1;
			}
		}
		if (whatMode) {
			textPoryadok = tmpPoryadok;
			textKey = tmpKey;
			return setRevKey(1);
		}
		else {
			filePoryadok = tmpPoryadok;
			fileKey = tmpKey;
			return setRevKey(0);
		}
	}
	bool setRevKey(bool whatMode) {
		MATRIX tmpMatrix;
		MATRIX tmpRevMatrix;
		int tmpMod;
		int tmpPoryadok;
		if (whatMode) {
			textRevKey.clear();
			tmpMatrix = textKey;
			tmpMod = modTextAlpha;
			tmpPoryadok = textPoryadok;
		}
		else {
			fileRevKey.clear();
			tmpMatrix = fileKey;
			tmpMod = 256;
			tmpPoryadok = filePoryadok;
		}
		bool checkDet = checkDetMatrix(tmpMatrix, tmpMod);
		if (checkDet) {
			if (whatMode) { textPoryadok = 0; }
			else { filePoryadok = 0; }
			std::cout << getStr1214();
		}
		else {
			std::cout << getStr1215() << std::endl;
			printKeyMatrix(tmpMatrix, tmpMod);
			std::cout << getStr1216() << std::endl;
			int revDet = getRevDet(tmpMatrix, tmpMod);
			tmpRevMatrix = getRevMatrix(tmpMatrix, tmpMod, revDet);
			std::cout << getStr1217();
			if (whatMode) { textRevKey = tmpRevMatrix; }
			else { fileRevKey = tmpRevMatrix; }
		}
		return checkDet;
	}
	int setRev(bool whatMode, bool whatKey) {
		MATRIX tmpMatrix;
		MATRIX tmpRevMatrix;
		MATRIX tmpKey;
		MATRIX tmpRevKey;
		int tmpPoryadok;
		int mod;
		if (whatMode) {
			revTextMatrix.clear();
			int tmpCheck = setTextMatrix();
			if (tmpCheck == 1) { return 1; }
			else if (tmpCheck == -1) { return -1; }
			tmpMatrix = textMatrix;
			tmpKey = textKey;
			tmpRevKey = textRevKey;
			tmpPoryadok = textPoryadok;
			mod = modTextAlpha;
		}
		else {
			revFileMatrix.clear();
			int tmpCheck = setFileMatrix();
			if (tmpCheck == 1) { return 1; }
			else if (tmpCheck == -1) { return -1; }
			tmpMatrix = fileMatrix;
			tmpKey = fileKey;
			tmpRevKey = fileRevKey;
			tmpPoryadok = filePoryadok;
			mod = 256;
		}
		const int col = tmpMatrix.size();
		tmpRevMatrix.resize(col);
		for (int i = 0; i < col; i++) {
			tmpRevMatrix[i].resize(tmpPoryadok);
		}
		if (whatKey) {
			tmpRevMatrix = multiplyMatrixMod(tmpMatrix, tmpKey, mod);
		}
		else {
			tmpRevMatrix = multiplyMatrixMod(tmpMatrix, tmpRevKey, mod);
		}
		if (whatMode) {
			revTextMatrix.resize(col);
			for (int i = 0; i < col; i++) {
				revTextMatrix[i].resize(tmpPoryadok);
			}
			revTextMatrix = tmpRevMatrix;
		}
		else {
			revFileMatrix.resize(col);
			for (int i = 0; i < col; i++) {
				revFileMatrix[i].resize(tmpPoryadok);
			}
			revFileMatrix = tmpRevMatrix;
		}
		return 0;
	}
	std::string getRevText() {
		std::string tmpString = "";
		int col = revTextMatrix.size();
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < textPoryadok; j++) {
				tmpString += textAlphavit[revTextMatrix[i][j]];
			}
		}
		return tmpString;
	}
	int setTextMatrix() {
		textMatrix.clear();
		std::string tmpString;
		std::getline(std::cin, tmpString);
		if (tmpString == "") { return 1; }
		int max_i = tmpString.length();
		int dopText = getOstat(max_i, textPoryadok);
		if (dopText != 0) {
			dopText = textPoryadok - dopText;
			for (int i = 0; i < dopText; i++) {
				tmpString += textAlphavit[modTextAlpha - 1];
			}
			max_i += dopText;
		}
		const int col = max_i / textPoryadok;
		if (col > textMatrix.max_size()) {
			std::cout << getStr131();
			if (_getch() == 27) { return -1; }
			else { return 1; }
		}
		int count = 0;
		textMatrix.resize(col);
		for (int i = 0; i < col; i++) {
			textMatrix[i].resize(textPoryadok);
		}
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < textPoryadok; j++) {
				char ch = tmpString[count];
				count++;
				if (checkAlpha(ch)) {
					std::cout << getStr12130() << ch << getStr12131();
					if (_getch() == 27) { return -1; }
					else { return 1; }
				}
				std::vector<int>::iterator it = std::find(textAlphavit.begin(), textAlphavit.end(), ch);
				int alphaNum = std::distance(textAlphavit.begin(), it);
				textMatrix[i][j] = alphaNum;
			}
		}
		return 0;
	}
	int getModTextAlpha() { return modTextAlpha; }
	int setRandFilePoryadok() {
		std::string tmpString;
		std::cin >> tmpString;
		std::string tmp2String = "";
		const int length = tmpString.length();
		for (int i = 0; i < length; i++) {
			if ((tmpString[i] >= 48) & (tmpString[i] <= 57)) { tmp2String += tmpString[i]; }
			else {
				std::cout << getStr1223();
				if (_getch() == 27) { return -1; }
				else { return 1; }
			}
		}
		int tmpNum = atoi(tmp2String.c_str());
		if ((tmpNum < 8) & (tmpNum > 1)) { filePoryadok = tmpNum; return 0; }
		else {
			std::cout << getStr21201();
			if (_getch() == 27) { return -1; }
			else { return 1; }
		}
	}
	bool setRandFileKey() {
		fileKey.clear();
		fileKey.resize(filePoryadok);
		for (int i = 0; i < filePoryadok; i++) { fileKey[i].resize(filePoryadok); }
		for (int i = 0; i < filePoryadok; i++) {
			for (int j = 0; j < filePoryadok; j++) { fileKey[i][j] = rand() % 256; }
		}
		return checkDetMatrix(fileKey, 256);
	}
	void setRandRevKey() {
		printKeyMatrix(fileKey, 256);
		std::cout << getStr1216() << std::endl;
		int revDet = getRevDet(fileKey, 256);
		fileRevKey = getRevMatrix(fileKey, 256, revDet);
		std::cout << getStr1217();
		_getch();
	}
	int setFileMatrix() {
		fileMatrix.clear();
		std::string tmpString;
		std::getline(std::cin, tmpString);
		if (tmpString == "") { return 1; }
		FILE* takeBin = 0;
		fopen_s(&takeBin, tmpString.c_str(), "rb");
		if (takeBin == 0) {
			std::cout << getStr1321();
			if (_getch() == 27) { return -1; }
			else { return 1; }
		}
		else {
			system("cls");
			std::cout << getStr1322();
		}
		int col;
		LL startTime = clock();
		int helpExit = 0;
		int i;
		for (i = 0; !feof(takeBin); i++) {
			col = i / filePoryadok + 1;
			if (col > fileMatrix.max_size()) {
				std::cout << getStr131();
				if (_getch() == 27) { return -1; }
				else { return 1; }
			}
			fileMatrix.resize(col);
			for (int j = 0; j < col; j++) {
				fileMatrix[j].resize(filePoryadok);
			}
			fread(&fileMatrix[i / filePoryadok][i % filePoryadok], 1, 1, takeBin);
			LL endTime = clock();
			if (((endTime - startTime) / CLOCKS_PER_SEC > 60) & (helpExit >= 0)) {
				if (helpExit == 0) {
					std::cout << getStr13231() << getStr13232();
					std::cout << getStr13233() << getStr13234();
				}
				else if (helpExit == 1) {
					std::cout << getStr13235();
				}
				char ch = _getch();
				if (ch == 27) { return -1; }
				else if (ch == 13) {
					helpExit = -1;
					std::cout << std::endl;
				}
				else {
					helpExit = 1;
					startTime = clock();
					std::cout << std::endl;
				}
			}
		}
		i--;
		int dopBin = getOstat(i, filePoryadok);
		if (dopBin != 0) { dopBin = filePoryadok - dopBin; }
		for (int j = 0; j < dopBin; j++) {
			fileMatrix[i / filePoryadok][filePoryadok - j - 1] = 0;
		}
		fclose(takeBin);
		return 0;
	}
	bool setRevFile() {
		std::string tmpString;
		std::getline(std::cin, tmpString);
		if (tmpString == "") { return 1; }
		FILE* putBin = 0;
		fopen_s(&putBin, tmpString.c_str(), "wb");
		if (putBin == 0) {
			std::cout << getStr222();
			_getch();
			return 1;
		}
		int col = revFileMatrix.size();
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < filePoryadok; j++) {
				fwrite(&revFileMatrix[i][j], 1, 1, putBin);
			}
		}
		fclose(putBin);
		return 0;
	}
};