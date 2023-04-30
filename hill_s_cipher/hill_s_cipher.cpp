// hill's_cipher.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "ClassCrypto.h"
#include "ClassMenu.h"
#include "ClassUser.h"
#include "ClassSetting.h"
#include <windows.h>

int main() {
    ClassUser* user = new ClassUser();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    user->setSetting();
    while (1) {
        void* dOut = GetStdHandle(STD_OUTPUT_HANDLE);
        int col = user->getColText() + 16 * user->getColBack();
        SetConsoleTextAttribute(dOut, col);
        ClassMenu* mainMenu = new ClassMenu();
        mainMenu->addTitleItem(user->getStr0());
        mainMenu->addItem(user->getStr1());
        mainMenu->addItem(user->getStr2());
        mainMenu->addItem(user->getStr3());
        mainMenu->addItem(user->getStr4());
        mainMenu->run(1, user);
        int selectedItem = mainMenu->getSelectedItem();
        if (selectedItem == 0) {
            ClassMenu* tmpMenu = new ClassMenu();
            tmpMenu->addTitleItem(user->getStr100());
            tmpMenu->addTitleItem(user->getStr101());
            tmpMenu->addItem(user->getStr11());
            tmpMenu->addItem(user->getStr12());
            tmpMenu->addItem(user->getStr13());
            tmpMenu->addItem(user->getStr14());
            tmpMenu->addItem(user->getStr15());
            int tmpSelectedItem = 0;
            while (tmpSelectedItem != 4) {
                tmpMenu->run(1, user);
                tmpSelectedItem = tmpMenu->getSelectedItem();
                if (tmpSelectedItem == 0) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr1100());
                    tmp2Menu->addTitleItem(user->getStr1101());
                    bool tmpCheckError = 1;
                    while (tmpCheckError) {
                        tmp2Menu->run(0, user);
                        tmpCheckError = user->setTextAlphavit();
                        _getch();
                    }
                    delete tmp2Menu;
                }
                else if ((tmpSelectedItem == 1) & (user->getModTextAlpha() > 1)) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr120());
                    tmp2Menu->addItem(user->getStr121());
                    tmp2Menu->addItem(user->getStr122());
                    tmp2Menu->run(0, user);
                    int tmp2SelectedItem = tmp2Menu->getSelectedItem();
                    if (tmp2SelectedItem == 0) {
                        tmp2Menu->eraseAll();
                        tmp2Menu->addTitleItem(user->getStr1210());
                        bool tmpCheckError = 1;
                        while (tmpCheckError) {
                            tmp2Menu->run(0, user);
                            tmpCheckError = user->setKeyText();
                            if (_getch() == 27) { tmpCheckError = 0; };
                        }
                    }
                    else if (tmp2SelectedItem == 1) {
                        tmp2Menu->eraseAll();
                        tmp2Menu->addTitleItem(user->getStr12200());
                        tmp2Menu->addTitleItem(user->getStr12201());
                        tmp2Menu->addTitleItem(user->getStr12202());
                        int maxAlpha = user->getModTextAlpha() - 1;
                        tmp2Menu->addTitleItem(user->getStr12203() + std::to_string(maxAlpha));
                        bool tmpCheckError = 1;
                        while (tmpCheckError) {
                            tmp2Menu->run(0, user);
                            tmpCheckError = user->setKeyMatrix(1);
                            if (_getch() == 27) { tmpCheckError = 0; };
                        }
                    }
                    delete tmp2Menu;
                }
                else if ((tmpSelectedItem == 2) & user->isEptyTextPoryadok()) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr1300());
                    tmp2Menu->addTitleItem(user->getStr1101());
                    int tmpCheckError = 1;
                    while (tmpCheckError == 1) {
                        tmp2Menu->run(0, user);
                        tmpCheckError = user->setRev(1, 1);
                    }
                    if (tmpCheckError == -1) {
                        delete tmp2Menu;
                        continue;
                    }
                    tmp2Menu->eraseAll();
                    tmp2Menu->addTitleItem(user->getStr1302());
                    tmp2Menu->run(0, user);
                    std::cout << user->getRevText();
                    _getch();
                    delete tmp2Menu;
                }
                else if ((tmpSelectedItem == 3) & user->isEptyTextPoryadok()) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr1400());
                    tmp2Menu->addTitleItem(user->getStr1101());
                    int tmpCheckError = 1;
                    while (tmpCheckError == 1) {
                        tmp2Menu->run(0, user);
                        tmpCheckError = user->setRev(1, 0);
                    }
                    if (tmpCheckError == -1) {
                        delete tmp2Menu;
                        continue;
                    }
                    tmp2Menu->eraseAll();
                    tmp2Menu->addTitleItem(user->getStr1401());
                    tmp2Menu->run(0, user);
                    std::cout << user->getRevText();
                    _getch();
                    delete tmp2Menu;
                }
            }
            delete tmpMenu;
        }
        else if (selectedItem == 1) {
            ClassMenu* tmpMenu = new ClassMenu();
            tmpMenu->addTitleItem(user->getStr20());
            tmpMenu->addItem(user->getStr12());
            tmpMenu->addItem(user->getStr13());
            tmpMenu->addItem(user->getStr14());
            tmpMenu->addItem(user->getStr15());
            int tmpSelectedItem = 0;
            while (tmpSelectedItem != 3) {
                tmpMenu->run(1, user);
                tmpSelectedItem = tmpMenu->getSelectedItem();
                if (tmpSelectedItem == 0) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr120());
                    tmp2Menu->addItem(user->getStr211());
                    tmp2Menu->addItem(user->getStr212());
                    tmp2Menu->run(0, user);
                    int tmp2SelectedItem = tmp2Menu->getSelectedItem();
                    if (tmp2SelectedItem == 0) {
                        tmp2Menu->eraseAll();
                        tmp2Menu->addTitleItem(user->getStr12200());
                        tmp2Menu->addTitleItem(user->getStr12201());
                        tmp2Menu->addTitleItem(user->getStr12202());
                        tmp2Menu->addTitleItem(user->getStr12203() + "256");
                        bool tmpCheckError = 1;
                        while (tmpCheckError) {
                            tmp2Menu->run(0, user);
                            tmpCheckError = user->setKeyMatrix(0);
                            if (_getch() == 27) { tmpCheckError = 0; }
                        }
                    }
                    else if (tmp2SelectedItem == 1) {
                        tmp2Menu->eraseAll();
                        tmp2Menu->addTitleItem(user->getStr2120());
                        int tmpCheckError = 1;
                        while (tmpCheckError == 1) {
                            tmp2Menu->run(0, user);
                            tmpCheckError = user->setRandFilePoryadok();
                        }
                        if (tmpCheckError == -1) {
                            delete tmp2Menu;
                            continue;
                        }
                        tmpCheckError = 1;
                        while (tmpCheckError) {
                            tmp2Menu->run(0, user);
                            std::cout << user->getStr2121();
                            tmpCheckError = user->setRandFileKey();
                        }
                        tmp2Menu->eraseAll();
                        tmp2Menu->addTitleItem(user->getStr1215());
                        tmp2Menu->run(0, user);
                        user->setRandRevKey();
                    }
                    delete tmp2Menu;
                }
                else if ((tmpSelectedItem == 1) & user->isEptyFilePoryadok()) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr221());
                    int tmpCheckError = 1;
                    while (tmpCheckError == 1) {
                        tmp2Menu->run(0, user);
                        tmpCheckError = user->setRev(0, 1);
                    }
                    if (tmpCheckError == -1) {
                        delete tmp2Menu;
                        continue;
                    }
                    tmp2Menu->eraseAll();
                    tmp2Menu->addTitleItem(user->getStr223());
                    tmp2Menu->run(0, user);
                    tmpCheckError = 1;
                    while (tmpCheckError) {
                        tmp2Menu->run(0, user);
                        tmpCheckError = user->setRevFile();
                    }
                    delete tmp2Menu;
                }
                else if ((tmpSelectedItem == 2) & user->isEptyFilePoryadok()) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr221());
                    int tmpCheckError = 1;
                    while (tmpCheckError == 1) {
                        tmp2Menu->run(0, user);
                        tmpCheckError = user->setRev(0, 0);
                    }
                    if (tmpCheckError == -1) {
                        delete tmp2Menu;
                        continue;
                    }
                    tmp2Menu->eraseAll();
                    tmp2Menu->addTitleItem(user->getStr223());
                    tmpCheckError = 1;
                    while (tmpCheckError) {
                        tmp2Menu->run(0, user);
                        tmpCheckError = user->setRevFile();
                    }
                    delete tmp2Menu;
                }
            }
            delete tmpMenu;
        }
        else if (selectedItem == 2) {
            ClassMenu* tmpMenu = new ClassMenu();
            tmpMenu->addTitleItem(user->getStr300());
            int tmpCheckError = 1;
            while (tmpCheckError == 1) {
                std::string check = "";
                std::string fake = "";
                char ch = 0;
                while (ch != 13) {
                    tmpMenu->run(0, user);
                    std::cout << fake;
                    ch = _getch();
                    if (ch == 8) {
                        std::string tmpString = fake;
                        fake = "";
                        int max_i = tmpString.length() - 1;
                        for (int i = 0; i < max_i; i++) { fake += tmpString[i]; }
                        tmpString = check;
                        check = "";
                        max_i = tmpString.length() - 1;
                        for (int i = 0; i < max_i; i++) { check += tmpString[i]; }
                    }
                    else if ((ch < 0) || (ch > 31)) {
                        check += ch;
                        if (rand() % 2) { fake += "*"; }
                    }
                }
                if (user->getPassword() == check) { tmpCheckError = 0; }
                else {
                    std::cout << user->getStr301();
                    if (_getch() == 27) { tmpCheckError = -1; }
                }
            }
            if (tmpCheckError == -1) {
                delete tmpMenu;
                delete mainMenu;
                continue;
            }
            user->tmpColText = user->getColText();
            user->tmpColBack = user->getColBack();
            user->tmpColSelText = user->getColSelText();
            user->tmpColSelBack = user->getColSelBack();
            user->tmpLanguage = user->getLanguage();
            tmpMenu->eraseAll();
            tmpMenu->addTitleItem(user->getStr3());
            tmpMenu->addItem(user->getStr31());
            tmpMenu->addItem(user->getStr312());
            tmpMenu->addItem(user->getStr313());
            tmpMenu->addItem(user->getStr314());
            int tmpSelectedItem = 0;
            while (tmpSelectedItem != 3) {
                tmpMenu->run(0, user);
                tmpSelectedItem = tmpMenu->getSelectedItem();
                if (tmpSelectedItem == 0) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr320());
                    tmp2Menu->addItem(user->getStr321());
                    tmp2Menu->addItem(user->getStr322());
                    tmp2Menu->addItem(user->getStr15());
                    int tmp2SelectedItem = 0;
                    while (tmp2SelectedItem != 2) {
                        user->setHelpColMenu(0);
                        tmp2Menu->run(0, user);
                        tmp2SelectedItem = tmp2Menu->getSelectedItem();
                        if (tmp2SelectedItem == 0) {
                            ClassMenu* tmp3Menu = new ClassMenu();
                            user->setHelpColMenu(1);
                            tmp3Menu->addTitleItem(user->getStr323());
                            tmp3Menu->addColor(user->tmpColBack, user, tmp3Menu);
                            bool check = 1;
                            while (check) {
                                tmp3Menu->run(0, user);
                                int checkColText = tmp3Menu->colNum[user->tmpColBack][tmp3Menu->getSelectedItem() + 1];
                                if ((checkColText == user->tmpColSelText) & (user->tmpColBack == user->tmpColSelBack)) {
                                    system("cls");
                                    std::cout << user->getStr324();
                                    _getch();
                                }
                                else {
                                    user->tmpColText = checkColText;
                                    check = 0;
                                }
                            }
                            delete tmp3Menu;
                        }
                        else if (tmp2SelectedItem == 1) {
                            ClassMenu* tmp3Menu = new ClassMenu();
                            user->setHelpColMenu(2);
                            tmp3Menu->addTitleItem(user->getStr33());
                            tmp3Menu->addColor(user->tmpColText, user, tmp3Menu);
                            bool check = 1;
                            while (check) {
                                tmp3Menu->run(0, user);
                                int checkColBack = tmp3Menu->colNum[user->tmpColText][tmp3Menu->getSelectedItem() + 1];
                                if ((checkColBack == user->tmpColSelBack) & (user->tmpColText == user->tmpColSelText)) {
                                    system("cls");
                                    std::cout << user->getStr324();
                                    _getch();
                                }
                                else {
                                    user->tmpColBack = checkColBack;
                                    check = 0;
                                }
                            }
                            delete tmp3Menu;
                        }
                    }
                    delete tmp2Menu;
                }
                else if (tmpSelectedItem == 1) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr34());
                    tmp2Menu->addItem(user->getStr321());
                    tmp2Menu->addItem(user->getStr322());
                    tmp2Menu->addItem(user->getStr15());
                    int tmp2SelectedItem = 0;
                    while (tmp2SelectedItem != 2) {
                        user->setHelpColMenu(0);
                        tmp2Menu->run(0, user);
                        tmp2SelectedItem = tmp2Menu->getSelectedItem();
                        if (tmp2SelectedItem == 0) {
                            ClassMenu* tmp3Menu = new ClassMenu();
                            user->setHelpColMenu(3);
                            tmp3Menu->addTitleItem(user->getStr323());
                            tmp3Menu->addColor(user->tmpColSelBack, user, tmp3Menu);
                            bool check = 1;
                            while (check) {
                                tmp3Menu->run(0, user);
                                int checkColSelText = tmp3Menu->colNum[user->tmpColSelBack][tmp3Menu->getSelectedItem() + 1];
                                if ((checkColSelText == user->tmpColText) & (user->tmpColBack == user->tmpColSelBack)) {
                                    system("cls");
                                    std::cout << user->getStr324();
                                    _getch();
                                }
                                else {
                                    user->tmpColSelText = checkColSelText;
                                    check = 0;
                                }
                            }
                            delete tmp3Menu;
                        }
                        else if (tmp2SelectedItem == 1) {
                            ClassMenu* tmp3Menu = new ClassMenu();
                            user->setHelpColMenu(4);
                            tmp3Menu->addTitleItem(user->getStr33());
                            tmp3Menu->addColor(user->tmpColSelText, user, tmp3Menu);
                            bool check = 1;
                            while (check) {
                                tmp3Menu->run(0, user);
                                int checkColSelBack = tmp3Menu->colNum[user->tmpColSelText][tmp3Menu->getSelectedItem() + 1];
                                if ((checkColSelBack == user->tmpColBack) & (user->tmpColText == user->tmpColSelText)) {
                                    system("cls");
                                    std::cout << user->getStr324();
                                    _getch();
                                }
                                else {
                                    user->tmpColSelBack = checkColSelBack;
                                    check = 0;
                                }
                            }
                            delete tmp3Menu;
                        }
                    }
                    delete tmp2Menu;
                }
                else if (tmpSelectedItem == 2) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr350());
                    tmp2Menu->addItem(user->getStr351());
                    tmp2Menu->addItem(user->getStr352());
                    int tmp2SelectedItem = 0;
                    tmp2Menu->run(0, user);
                    user->tmpLanguage = tmp2Menu->getSelectedItem();
                    delete tmp2Menu;
                }
                else if (tmpSelectedItem == 3) {
                    ClassMenu* tmp2Menu = new ClassMenu();
                    tmp2Menu->addTitleItem(user->getStr353());
                    tmp2Menu->addTitleItem(user->getStr354());
                    tmp2Menu->addItem(user->getStr355());
                    tmp2Menu->addItem(user->getStr356());
                    int tmp2SelectedItem = 0;
                    tmp2Menu->run(0, user);
                    tmp2SelectedItem = tmp2Menu->getSelectedItem();
                    if (tmp2SelectedItem == 0) {
                        struct tm curTime;
                        long sec;
                        _time32(&sec);
                        _localtime32_s(&curTime, &sec);
                        FILE* putSetting = 0;
                        fopen_s(&putSetting, "programSettings", "wb");
                        user->setChangeDate(user->getDate(curTime));
                        char date[21];
                        strcpy_s(date, 21, user->getChangeDate().c_str());
                        fwrite(&date, 21, 1, putSetting);
                        bool tmpB = user->tmpLanguage;
                        fwrite(&tmpB, 1, 1, putSetting);
                        user->setLanguage(tmpB);
                        int tmpI = user->tmpColText;
                        fwrite(&tmpI, 4, 1, putSetting);
                        user->setColText(tmpI);
                        tmpI = user->tmpColBack;
                        fwrite(&tmpI, 4, 1, putSetting);
                        user->setColBack(tmpI);
                        tmpI = user->tmpColSelText;
                        fwrite(&tmpI, 4, 1, putSetting);
                        user->setColSelText(tmpI);
                        tmpI = user->tmpColSelBack;
                        fwrite(&tmpI, 4, 1, putSetting);
                        user->setColSelBack(tmpI);
                        fclose(putSetting);
                    }
                    delete tmp2Menu;
                }
            }
            delete tmpMenu;
        }
        else if (selectedItem == 3) {
            delete user;
            system("cls");
            return 0;
        }
        delete mainMenu;
    }
    delete user;
}