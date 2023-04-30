#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "ClassUser.h"

class ClassMenu {
    void drawLineUp(int size) {
        std::string tmpString = " ";
        for (int i = 0; i < size; i++) { tmpString += "_"; }
        std::cout << tmpString << std::endl;
    }
    void drawLineDown(int size) {
        std::string tmpString = "|";
        for (int i = 0; i < size - 1; i++) { tmpString += "_"; }
        tmpString += "|";
        std::cout << tmpString << std::endl;
    }
    int itemsCount;
    int titleItemCount;
    int selectedItem;
    int maxLength;
    static const int maxItem = 20;
    static const int maxTitle = 5;
    std::string items[maxItem];
    std::string titelStrings[maxTitle];
    void setMaxLength() {
        int tmpMax = 0;
        for (int i = 0; i < maxItem; i++) {
            if (items[i].length() > tmpMax) {
                tmpMax = items[i].length();
            }
        }
        for (int i = 0; i < maxTitle; i++) {
            if (titelStrings[i].length() > tmpMax) {
                tmpMax = titelStrings[i].length();
            }
        }
        maxLength = tmpMax;
    }
    std::string getColName(int col, ClassUser* user) {
        if (col == 0) { return user->getStr43(); }
        else if (col == 1) { return user->getStr44(); }
        else if (col == 2) { return user->getStr45(); }
        else if (col == 3) { return user->getStr46(); }
        else if (col == 4) { return user->getStr47(); }
        else if (col == 5) { return user->getStr48(); }
        else if (col == 6) { return user->getStr49(); }
        else if (col == 7) { return user->getStr410(); }
        else if (col == 8) { return user->getStr411(); }
        else if (col == 9) { return user->getStr412(); }
        else if (col == 10) { return user->getStr413(); }
        else if (col == 11) { return user->getStr414(); }
        else if (col == 12) { return user->getStr415(); }
        else if (col == 13) { return user->getStr416(); }
        else if (col == 14) { return user->getStr417(); }
        else if (col == 15) { return user->getStr418(); }
    }
    void draw(bool copiright, ClassUser* user) {
        system("cls");
        void* dOut = GetStdHandle(STD_OUTPUT_HANDLE);
        drawLineUp(maxLength + 2);
        std::string tmpString = "| ";
        while (tmpString.length() < maxLength + 3) { tmpString += " "; }
        tmpString += "|";
        std::cout << tmpString << std::endl;
        for (int i = 0; i < titleItemCount; i++) {
            tmpString = "| ";
            tmpString = tmpString + titelStrings[i].c_str();
            while (tmpString.length() < maxLength + 3) { tmpString += " "; }
            tmpString += "|";
            std::cout << tmpString << std::endl;
        }
        drawLineDown(maxLength + 3);
        for (int i = 0; i < itemsCount; i++) {
            if (i == selectedItem) {
                std::cout << "|";
                int col;
                if (user->getHelpColMenu() == 1) {
                    col = 17 * colNum[user->tmpColBack][selectedItem + 1];
                }
                else if (user->getHelpColMenu() == 2) {
                    col = 17 * colNum[user->tmpColText][selectedItem + 1];
                }
                else if (user->getHelpColMenu() == 3) {
                    col = 17 * colNum[user->tmpColSelBack][selectedItem + 1];
                }
                else if (user->getHelpColMenu() == 4) {
                    col = 17 * colNum[user->tmpColSelText][selectedItem + 1];
                }
                else { col = user->getColSelText() + 16 * user->getColSelBack(); }
                SetConsoleTextAttribute(dOut, col);
                std::cout << " " << items[i].c_str();
                tmpString = "";
                while (tmpString.length() < maxLength - items[i].length() + 1) {
                    tmpString += " ";
                }
                std::cout << tmpString;
                col = user->getColText() + 16 * user->getColBack();
                SetConsoleTextAttribute(dOut, col);
                std::cout << "|" << std::endl;
            }
            else {
                tmpString = "| ";
                tmpString += items[i].c_str();
                while (tmpString.length() < maxLength + 3) { tmpString += " "; }
                tmpString += "|";
                std::cout << tmpString << std::endl;
            }
        }
        if (itemsCount != 0) { drawLineDown(maxLength + 3); }
        if (copiright) {
            int max_i = 14 - itemsCount - titleItemCount;
            for (int i = 0; i < max_i; i++) { std::cout << std::endl; }
            std::cout << user->getStr41() << std::endl;
            std::string tmpString = user->getChangeDate();
            for (int i = 0; i < 45; i++) { tmpString += " "; }
            tmpString += (char)-87;
            tmpString += user->getStr42();
            std::cout << tmpString;
        }
    }
public:
    const int colNum[16][16] = {
        {15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {11, 0, 3, 4, 6, 7, 8, 9, 10, 11, 12, 14, 15},
        {9, 0, 4, 5, 6, 7, 11, 13, 14, 15},
        {9, 0, 1, 4, 5, 7, 12, 13, 14, 15},
        {13, 0, 1, 2, 3, 6, 7, 8, 9, 10, 11, 12, 14, 15},
        {12, 0, 2, 3, 6, 7, 8, 9, 10, 11, 12, 14, 15},
        {10, 0, 1, 2, 4, 5, 7, 11, 13, 14, 15},
        {12, 0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 13},
        {9, 0, 1, 4, 5, 7, 11, 13, 14, 15},
        {10, 0, 1, 4, 5, 7, 11, 12, 13, 14, 15},
        {10, 0, 1, 4, 5, 7, 11, 12, 13, 14, 15},
        {12, 0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14},
        {11, 0, 1, 3, 4, 5, 7, 9, 10, 11, 14, 15},
        {11, 0, 2, 3, 6, 7, 8, 9, 10, 11, 14, 15},
        {13, 0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13},
        {11, 0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 13}
    };
    ClassMenu() {
        selectedItem = 0;
        itemsCount = 0;
        titleItemCount = 0;
        maxLength = 0;
    }
    void eraseTitle() {
        titleItemCount = 0;
        for (int i = 0; i < maxTitle; i++) {
            titelStrings[i].clear();
        }
    }
    void eraseItem() {
        itemsCount = 0;
        for (int i = 0; i < maxItem; i++) { items[i].clear(); }
    }
    void eraseAll() { eraseTitle();  eraseItem(); }
    int getSelectedItem() { return selectedItem; }
    void addItem(std::string inString) {
        items[itemsCount].assign(inString.c_str());
        itemsCount++;
    }
    void addTitleItem(std::string inString) {
        titelStrings[titleItemCount].assign(inString.c_str());
        titleItemCount++;
    }
    void setDown() {
        selectedItem++;
        if (selectedItem > itemsCount - 1) { selectedItem = 0; }
    }
    void setUp() {
        selectedItem--;
        if (selectedItem < 0) { selectedItem = itemsCount - 1; }
    }
    void run(bool mainMenu, ClassUser* user) {
        setMaxLength();
        char ch = ' ';
        draw(mainMenu, user);
        if (itemsCount != 0) {
            while (ch != 13) {
                ch = _getch();
                if ((ch == 80) || (ch == 77)) { setDown(); }
                if ((ch == 72) || (ch == 75)) { setUp(); }
                draw(mainMenu, user);
            }
        }
    }
    void addColor(int revCol, ClassUser* user, ClassMenu* menu) {
        int max_i = colNum[revCol][0];
        for (int i = 1; i <= max_i; i++) {
            menu->addItem(getColName(colNum[revCol][i], user));
        }
    }
};