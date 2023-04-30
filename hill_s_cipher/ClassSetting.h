#pragma once
#include "iostream"
#include <ctime>
#include <string>

class ClassSetting {
	bool bLanguage;
	const char password[20] = "ПушкинPotapovaEcrjd";
	int colText;
	int colBack;
	int colSelText;
	int colSelBack;
	int helpColMenu;
	std::string changeDate;
public:
	bool tmpLanguage;
	int tmpColText;
	int tmpColBack;
	int tmpColSelText;
	int tmpColSelBack;
	void setSetting() {
		FILE* takeSetting = 0;
		fopen_s(&takeSetting, "programSettings", "rb");
		if (takeSetting != 0) {
			char date[21];
			fread(&date, 21, 1, takeSetting);
			setChangeDate(date);
			bool tmpLanguage;
			fread(&tmpLanguage, 1, 1, takeSetting);
			setLanguage(tmpLanguage);
			int tmpInt;
			fread(&tmpInt, 4, 1, takeSetting);
			setColText(tmpInt);
			fread(&tmpInt, 4, 1, takeSetting);
			setColBack(tmpInt);
			fread(&tmpInt, 4, 1, takeSetting);
			setColSelText(tmpInt);
			fread(&tmpInt, 4, 1, takeSetting);
			setColSelBack(tmpInt);
			fclose(takeSetting);
		}
	}
	std::string getDate(tm inDate) {
		std::string tmpDate = "";
		if (inDate.tm_hour < 10) { tmpDate += "0"; }
		tmpDate += std::to_string(inDate.tm_hour);
		tmpDate += ":";
		if (inDate.tm_min < 10) { tmpDate += "0"; }
		tmpDate += std::to_string(inDate.tm_min);
		tmpDate += ":";
		if (inDate.tm_sec < 10) { tmpDate += "0"; }
		tmpDate += std::to_string(inDate.tm_sec);
		tmpDate += "  ";
		if (inDate.tm_mday < 10) { tmpDate += "0"; }
		tmpDate += std::to_string(inDate.tm_mday);
		tmpDate += ".";
		if (inDate.tm_mon < 9) { tmpDate += "0"; }
		tmpDate += std::to_string(inDate.tm_mon + 1);
		tmpDate += ".";
		tmpDate += std::to_string(inDate.tm_year + 1900);
		return tmpDate;
	}
	std::string getChangeDate() { return changeDate; }
	void setChangeDate(std::string date) { changeDate = date; }
	const char* getPassword() { return password; }
	void setLanguage(bool rusEng) { bLanguage = rusEng; }
	bool getLanguage() { return bLanguage; }
	void setColText(int col) { colText = col; }
	void setColBack(int col) { colBack = col; }
	void setColSelText(int col) { colSelText = col; }
	void setColSelBack(int col) { colSelBack = col; }
	int getColText() { return colText; }
	int getColBack() { return colBack; }
	int getColSelText() { return colSelText; }
	int getColSelBack() { return colSelBack; }
	void setHelpColMenu(int mode) { helpColMenu = mode; }
	int getHelpColMenu() { return helpColMenu; }
	std::string getStr0() {
		if (bLanguage) { return "Шифр Хилла"; }
		else { return "Hill's Cipher"; }
	}
	std::string getStr1() {
		if (bLanguage) { return "Для текстов"; }
		else { return "For texts"; }
	}
	std::string getStr2() {
		if (bLanguage) { return "Для файлов"; }
		else { return "For files"; }
	}
	std::string getStr3() {
		if (bLanguage) { return "Настройки"; }
		else { return "Settings"; }
	}
	std::string getStr4() {
		if (bLanguage) { return "Выход"; }
		else { return "Exit"; }
	}
	std::string getStr100() {
		if (bLanguage) { return "Шифрование текстов с символами"; }
		else { return "Encrypting texts with characters"; }
	}
	std::string getStr101() {
		if (bLanguage) { return "из стандартной клавиатуры"; }
		else { return  "from a standard keyboard"; }
	}
	std::string getStr11() {
		if (bLanguage) { return "Установить алфавит"; }
		else { return "Set the alphabet"; }
	}
	std::string getStr12() {
		if (bLanguage) { return "Установить ключ"; }
		else { return "Install Key"; }
	}
	std::string getStr13() {
		if (bLanguage) { return "Зашифровать"; }
		else { return "Encrypt"; }
	}
	std::string getStr14() {
		if (bLanguage) { return "Расшифровать"; }
		else { return "Decrypt"; }
	}
	std::string getStr15() {
		if (bLanguage) { return "Назад"; }
		else { return "Back"; }
	}
	std::string getStr1100() {
		if (bLanguage) { return "Введите алфавит"; }
		else { return "Enter the alphabet"; }
	}
	std::string getStr1101() {
		if (bLanguage) { return "Нажмите Enter для завершения"; }
		else { return "Press Enter to finish"; }
	}
	std::string getStr111() {
		if (bLanguage) { return "Алфавит установлен, число различных элементов равно "; }
		else { return "The alphabet is set, the number of different elements is "; }
	}
	std::string getStr112() {
		if (bLanguage) { return "\aОшибка, введите хотя бы два различных символа"; }
		else { return "\aError, enter at least two different characters"; }
	}
	std::string getStr120() {
		if (bLanguage) { return "Выберите вариант записи ключа"; }
		else { return "Select the key entry option"; }
	}
	std::string getStr121() {
		if (bLanguage) { return "Задать ключ кодовой фразой"; }
		else { return "Set the key with a passphrase"; }
	}
	std::string getStr122() {
		if (bLanguage) { return "Задать ключ матрицей алфавитных чисел"; }
		else { return "Set the key as a matrix of alphabetic numbers"; }
	}
	std::string getStr1210() {
		if (bLanguage) { return "Введите кодовую фразу"; }
		else { return "Enter a passphrase"; }
	}
	std::string getStr1211() {
		if (bLanguage) { return "Длина ключа должна быть квадратом натурального числа, начиная с 2"; }
		else { return "The key length must be the square of a natural number, starting from 2"; }
	}
	std::string getStr1212() {
		if (bLanguage) { return "\aОшибка, максимальный порядок для текущего алфавита равен "; }
		else { return "\aError, the maximum order for the current alphabet is "; }
	}
	std::string getStr12130() {
		if (bLanguage) { return "Символа \""; }
		else { return "The \""; }
	}
	std::string getStr12131() {
		if (bLanguage) { return "\" нету в алфавите"; }
		else { return "\" character is not present in the alphabet"; }
	}
	std::string getStr1214() {
		if (bLanguage) { return "\aОшибка, не существует обратной матрицы по модулю длины алфавита"; }
		else { return "\aError, there is no inverse matrix modulo the length of the alphabet"; }
	}
	std::string getStr1215() {
		if (bLanguage) { return "Ключ успешно записан"; }
		else { return "Key recorded successfully"; }
	}
	std::string getStr1216() {
		if (bLanguage) { return "\nВычисляется ключ для расшифровывания..."; }
		else { return "\nThe decryption key is calculated..."; }
	}
	std::string getStr1217() {
		if (bLanguage) { return "Спасибо за ожидание"; }
		else { return "Thank you for waiting"; }
	}
	std::string getStr12200() {
		if (bLanguage) { return "Введите матрицу ключа."; }
		else { return "Enter the key matrix."; }
	}
	std::string getStr12201() {
		if (bLanguage) { return "Каждая строка отделяется Enter'ом"; }
		else { return "Each line is separated by an Enter"; }
	}
	std::string getStr12202() {
		if (bLanguage) { return "Элементы строки отделяются пробелами"; }
		else { return "Line elements are separated by spaces"; }
	}
	std::string getStr12203() {
		if (bLanguage) { return "Алфавитные числа c 0 по "; }
		else { return "Alphabetic numbers from 0 to "; }
	}
	std::string getStr1221() {
		if (bLanguage) { return "\aОшибка, число элементов в строках матрицы не постоянно"; }
		else { return "\aError, the number of elements in the matrix rows is not constant"; }
	}
	std::string getStr1222() {
		if (bLanguage) { return "\aОшибка, ожидалось алфавитное число"; }
		else { return "\aError, expected alphabetic number"; }
	}
	std::string getStr1223() {
		if (bLanguage) { return "\aОшибка, ожидалось неотрицательное число"; }
		else { return "\aError, expected non-negative number"; }
	}
	std::string getStr1224() {
		if (bLanguage) { return "\aОшибка, минимальный порядок матрицы равен 2"; }
		else { return "\aError, the minimum order of the matrix is 2"; }
	}
	std::string getStr1300() {
		if (bLanguage) { return "Введите текст для зашифровывания"; }
		else { return "Enter the text to encrypt"; }
	}
	std::string getStr1302() {
		if (bLanguage) { return "Зашифрованный текст"; }
		else { return "Encrypted text"; }
	}
	std::string getStr131() {
		if (bLanguage) { return "Объём информации велик, обратитесь к разработчику"; }
		else { return "The amount of information is large, please contact the developer"; }
	}
	std::string getStr1321() {
		if (bLanguage) { return "Данный файл невозможно открыть"; }
		else { return "This file cannot be opened"; }
	}
	std::string getStr1322() {
		if (bLanguage) { return "Идёт разгрузка файла..."; }
		else { return "The file is being unloaded..."; }
	}
	std::string getStr13231() {
		if (bLanguage) { return "\nЗагрузка файла длится более минуты, выберите команду"; }
		else { return "\nThe file upload takes more than a minute, select the command"; }
	}
	std::string getStr13232() {
		if (bLanguage) { return "\nНажмите Esc для отмены загрузки"; }
		else { return "\n Press Esc to cancel the download"; }
	}
	std::string getStr13233() {
		if (bLanguage) { return "\nНажмите Enter для загрузки файла до конца"; }
		else { return "\n Press Enter to load the file to the end"; }
	}
	std::string getStr13234() {
		if (bLanguage) { return "\nНажмите любую другую клавишу, если хотите подождать ещё минуту"; }
		else { return "\n Press any other key if you want to wait another minute"; }
	}
	std::string getStr13235() {
		if (bLanguage) { return "Прошла минута, команды те же"; }
		else { return "A minute has passed, the commands are the same"; }
	}
	std::string getStr1400() {
		if (bLanguage) { return "Введите текст для расшифровывания"; }
		else { return "Enter the decryption text"; }
	}
	std::string getStr1401() {
		if (bLanguage) { return "Расшифрованный текст"; }
		else { return "Decrypted text"; }
	}
	std::string getStr20() {
		if (bLanguage) { return "Шифрование файлов"; }
		else { return "File encryption"; }
	}
	std::string getStr211() {
		if (bLanguage) { return "Задать ключ вручную"; }
		else { return "Set the key manually"; }
	}
	std::string getStr212() {
		if (bLanguage) { return "Задать ключ рандомно"; }
		else { return "Set the key randomly"; }
	}
	std::string getStr2120() {
		if (bLanguage) { return "Введите порядок ключа c 2 по 7"; }
		else { return "Enter the key order from 2 to 7"; }
	}
	std::string getStr21201() {
		if (bLanguage) { return "\aОшибка, порядок ключа c 2 по 7"; }
		else { return "\aError, the key order from 2 to 7"; }
	}
	std::string getStr2121() {
		if (bLanguage) { return "Подождите, составляется матрица ключа..."; }
		else { return "Wait, the key matrix is being compiled..."; }
	}
	std::string getStr221() {
		if (bLanguage) { return "Введите полный путь к файлу с его именем"; }
		else { return "Enter the full path to the file with its name"; }
	}
	std::string getStr222() {
		if (bLanguage) { return "Такой файл невозможно создать"; }
		else { return "This file cannot be created"; }
	}
	std::string getStr223() {
		if (bLanguage) { return "Введите полный путь и имя файла для сохранения"; }
		else { return "Enter the full path and file name to save"; }
	}
	std::string getStr300() {
		if (bLanguage) { return "Введите ключ доступа"; }
		else { return "Enter the access key"; }
	}
	std::string getStr301() {
		if (bLanguage) { return "\n\aОшибка, неверный ключ"; }
		else { return "\n\aError, invalid key"; }
	}
	std::string getStr31() {
		if (bLanguage) { return "Изменить основной цвет"; }
		else { return "Change the primary color"; }
	}
	std::string getStr312() {
		if (bLanguage) { return "Изменить цвет выделения"; }
		else { return "Change the selection color"; }
	}
	std::string getStr313() {
		if (bLanguage) { return "Изменить язык"; }
		else { return "Change the language"; }
	}
	std::string getStr314() {
		if (bLanguage) { return "Закончить настройку"; }
		else { return "Finish setting up"; }
	}
	std::string getStr320() {
		if (bLanguage) { return "Выберите основной параметр"; }
		else { return "Select the main parameter"; }
	}
	std::string getStr321() {
		if (bLanguage) { return "Цвет текста"; }
		else { return "Text Color"; }
	}
	std::string getStr322() {
		if (bLanguage) { return "Цвет фона"; }
		else { return "Background Color"; }
	}
	std::string getStr323() {
		if (bLanguage) { return "Выберите цвет текста"; }
		else { return "Choose a text color"; }
	}
	std::string getStr324() {
		if (bLanguage) { return "\aОшибка, параметры выделенного пункта должны отличаться от основных"; }
		else { return "\aError, the parameters of the selected item should differ from the main ones"; }
	}
	std::string getStr33() {
		if (bLanguage) { return "Выберите цвет фона"; }
		else { return "Choose a background color"; }
	}
	std::string getStr34() {
		if (bLanguage) { return "Выберите параметр выделенного пункта"; }
		else { return "Select the option of the highlighted item"; }
	}
	std::string getStr350() {
		if (bLanguage) { return "Выберите язык"; }
		else { return "Select a language"; }
	}
	std::string getStr351() {
		if (bLanguage) { return "Английский язык"; }
		else { return "English language"; }
	}
	std::string getStr352() {
		if (bLanguage) { return "Русский язык"; }
		else { return "Russian language"; }
	}
	std::string getStr353() {
		if (bLanguage) { return "Вы действительно хотите"; }
		else { return "Do you really want to"; }
	}
	std::string getStr354() {
		if (bLanguage) { return "сохранить настройки?"; }
		else { return "save your settings?"; }
	}
	std::string getStr355() { if (bLanguage) { return "Да"; } else { return "Yes"; } }
	std::string getStr356() { if (bLanguage) { return "Нет"; } else { return "No"; } }
	std::string getStr41() {
		if (bLanguage) { return "Последнее изменение настроек"; }
		else { return "Last change to settings"; }
	}
	std::string getStr42() {
		if (bLanguage) { return " Усков К.А., 2021"; }
		else { return " Uskov K. A., 2021"; }
	}
	std::string getStr43() {
		if (bLanguage) { return "Чёрный цвет"; }
		else { return "Black color"; }
	}
	std::string getStr44() {
		if (bLanguage) { return "Синий цвет"; }
		else { return "Blue color"; }
	}
	std::string getStr45() {
		if (bLanguage) { return "Зелёный цвет"; }
		else { return "Green color"; }
	}
	std::string getStr46() {
		if (bLanguage) { return "Голубой цвет"; }
		else { return "Light blue color"; }
	}
	std::string getStr47() {
		if (bLanguage) { return "Красный цвет"; }
		else { return "Red color"; }
	}
	std::string getStr48() {
		if (bLanguage) { return "Фиолетовый цвет"; }
		else { return "Purple color"; }
	}
	std::string getStr49() {
		if (bLanguage) { return "Жёлтый цвет"; }
		else { return "Yellow color"; }
	}
	std::string getStr410() {
		if (bLanguage) { return "Белый цвет"; }
		else { return "White color"; }
	}
	std::string getStr411() {
		if (bLanguage) { return "Серый цвет"; }
		else { return "Gray color"; }
	}
	std::string getStr412() {
		if (bLanguage) { return "Тёмно-голубой цвет"; }
		else { return "Dark blue color"; }
	}
	std::string getStr413() {
		if (bLanguage) { return "Светло-зелёный цвет"; }
		else { return "Light green color"; }
	}
	std::string getStr414() {
		if (bLanguage) { return "Светло-голубой цвет"; }
		else { return "Super light blue color"; }
	}
	std::string getStr415() {
		if (bLanguage) { return "Светло-красный цвет"; }
		else { return "Light red color"; }
	}
	std::string getStr416() {
		if (bLanguage) { return "Ярко-фиолетовый цвет"; }
		else { return "Bright purple color"; }
	}
	std::string getStr417() {
		if (bLanguage) { return "Светло-жёлтый цвет"; }
		else { return "Light yellow color"; }
	}
	std::string getStr418() {
		if (bLanguage) { return "Ярко-белый цвет"; }
		else { return "Bright white color"; }
	}
};