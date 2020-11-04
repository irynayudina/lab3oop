
#include <iostream>
#include "BOOKwrapper.h";
#include "lab3oop.h"
using namespace std;



void cell_selector(int& s, int& r, int& c, BOOK& b)
{
    cout << "the number of SHEET: " << endl;
    cin >> s;
    cout << "the number of row: " << endl;
    cin >> r;
    cout << "the number of column: " << endl;
    cin >> c;
    if (s <0 || s > b.get_content_length()-1) {
        s = 0;
    }
    if (r <0 || r > b.get_content()[s].get_content_length()-1) {
        r = 0;
    }
    if (c <0 || c > b.get_content()[s][r].get_content_length()-1) {
        c = 0;
    }
}

void name_enterer( int& count, char*& new_name)
{
    char ch = 1;
    char new_name_temp[100];
    while (ch != '/') {
        cout << "enter the symbol('/' to finish)" << endl;
        cin >> ch;
        if (ch != '/') {
            new_name_temp[count] = ch;
            ++count;
        }
    }
    new_name = new char[count];
    for (int i = 0; i < count; i++) {
        new_name[i] = new_name_temp[i];
    }
}




void openBook(BOOKwrapper& bw)
{
    bw->open();
}
void closseBook(BOOKwrapper& b)
{
    b->close();
}
void renameBook(BOOKwrapper& b)
{
    int count = 0;
    char* new_name = NULL;
    cout << "enter the name of the book without spaces:" << endl;
    name_enterer(count, new_name);
    b->change_name(count, new_name);
}

void openNSheet(BOOKwrapper& b)
{
    int nums;
    cout << "enter the number of the sheet" << endl;
    cin >> nums;
    if (nums <0 || nums > b->get_content_length()) {
        nums = 0;
    }
    b.decr_num_of_changes_in_the_book();
    b->get_content()[nums].open();
}

void closeNSheet(BOOKwrapper& b)
{
    int nums;
    cout << "enter the number of the sheet" << endl;
    cin >> nums;
    if (nums <0 || nums > b->get_content_length()) {
        nums = 0;
    }
    b.decr_num_of_changes_in_the_book();
    b->get_content()[nums].close();
}

void renameNSheet(BOOKwrapper& b)
{
    int count = 0;
    char* new_name = NULL;
    int num;
    cout << "enter the number of the sheet" << endl;
    cin >> num;
    if (num <0 || num > b->get_content_length()) {
        num = 0;
    }
    b.decr_num_of_changes_in_the_book();
    cout << "enter the name of the sheet without spaces:" << endl;
    name_enterer(count, new_name);
    b->get_content()[num].change_name(count, new_name);
}

void opennkCellFromjSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    b->get_content()[j][n][k].open();
}

void closenkCellFromjSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    b->get_content()[j][n][k].close();
}

void renamenkCellFromjSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    int count = 0;
    char* new_name = NULL;
    name_enterer(count, new_name);
    b->get_content()[j][n][k].change_name(count, new_name);
}

void putValuenkCelljSheet(BOOKwrapper& b)
{
    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    int count = 0;
    char* new_name = NULL;
    name_enterer(count, new_name);
    b->get_content()[j][n][k].put_value(count, new_name);
}

void getValuenkCelljSheet(BOOKwrapper& b)
{

    int j, n, k;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(j, n, k, bk);
    int count = 0;
    char* new_name = NULL;
    cell_selector(j, n, k, bk);
    name_enterer(count, new_name);
    b->get_content()[j][n][k].get_value();
}

void saveBookToDisk(BOOK& b)
{
    b.save_to_the_disk();
    cout << b << endl;
}

void getBookFromDisk(BOOK& b)
{
    b.get_from_the_disk();
    cout << b << endl;
}


void addingSheet(BOOKwrapper& b)
{
    SHEET s2;
    char* nameofcell;
    int sizeofname = 0;
    name_enterer(sizeofname, nameofcell);
    s2[0][0].change_name(sizeofname, nameofcell);
    /*cout << s2[0][0] << endl;
    cout << s2 << endl;*/
    /*SHEET s1;
    char* nameofcell1;
    int sizeofname1 = 0;
    name_enterer(sizeofname1, nameofcell1);
    s1[0][0].change_name(sizeofname1, nameofcell1);
    cout << s1[0][0] << endl;
    cout << s1 << endl;
    s2 = s1;
    cout << s2 << endl;*/
    b->add_value(s2);
}

void useLeftSidedFunc(BOOKwrapper& b)
{
    int s, r, c, sr;
    BOOK bk = *(b->get_book());
    b.decr_num_of_changes_in_the_book();
    cell_selector(s, r, c, bk);
    cout << "number of sheet to get the first cell from: " << endl;
    cin >> sr;
    if (sr <0 || sr > b->get_content_length() - 1) {
        sr = 0;
    }
    b.decr_num_of_changes_in_the_book();
    bk[s].changeCell(r, c) = bk[sr][0][0];
}

void printBookWithInfo(BOOKwrapper& bw, BOOK& b)
{
    cout << "number of changes ever made to the book: " << endl;
    cout << bw.get_num_of_changes_in_the_book() << endl;
    cout << "the book: " << endl;
    cout << b << endl;
}

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