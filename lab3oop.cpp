
#include <iostream>
#include "BOOKwrapper.h";
#include "lab3oop.h"
#include "PossibleFunctions.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    BOOK b;
    BOOKwrapper bw(&b);
    cout << b << endl;
    int choise = 0;
    while (choise != 14) {
        cout << "choose the action" << endl;
        cout << "1 - open book" << endl;
        cout << "2 - close book" << endl;
        cout << "3 - rename book" << endl;
        cout << "4 - open n sheet" << endl;
        cout << "5 - close n sheet" << endl;
        cout << "6 - rename n  sheet" << endl;
        cout << "7 - open n k cell from j sheet" << endl;
        cout << "8 - close n k cell from j sheet" << endl;
        cout << "9 - rename n k cell from j sheet" << endl;
        cout << "10 - put value in the n k cell from j sheet" << endl;
        cout << "11 - get value from the n k cell from j sheet" << endl;
        cout << "12 - save book to the disk" << endl;
        cout << "13 - get book from the disk" << endl;
        cout << "14 - exit this part of menu" << endl;
        cout << "15 - add new sheet to the book" << endl;
        cout << "16 - change the cell using left sided function f(row, coll) = cell" << endl;
        cout << "17 - print book" << endl;
        cin >> choise;
        switch (choise) {
        case 1:
            openBook(bw);
            break;
        case 2:
            closseBook(bw);
            break;
        case 3:
            renameBook(bw);
            break;
        case 4:
            openNSheet(bw);
            break;
        case 5:
            closeNSheet(bw);
            break;
        case 6:
            renameNSheet(bw);
            break;
        case 7:
            opennkCellFromjSheet(bw);
            break;
        case 8:
            closenkCellFromjSheet(bw);
            break;
        case 9:
            renamenkCellFromjSheet(bw);
            break;
        case 10:
            putValuenkCelljSheet(bw);
            break;
        case 11:
            getValuenkCelljSheet(bw);
            break;

        case 12:
            saveBookToDisk(b);
            break;

        case 13:
            getBookFromDisk(b);
            break;
        case 15:
            addingSheet(bw);
            break;
        case 16:
            useLeftSidedFunc(bw);
            break;
        case 17:
            printBookWithInfo(bw, b);
            break;
        }
    }
}