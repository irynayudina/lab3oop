// lab3oop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BOOK.h";
#include "lab3oop.h"
using namespace std;



void cell_selector(int& j, int& n, int& k, BOOK& b)
{
    cout << "enter the j" << endl;
    cin >> j;
    cout << "enter the n" << endl;
    cin >> n;
    cout << "enter the k" << endl;
    cin >> k;
    if (j <0 || j > b.get_content_length()) {
        j = 0;
    }
    if (n <0 || n > b.get_content()[j].get_content_length()) {
        n = 0;
    }
    if (k <0 || k > b.get_content()[j][n].get_content_length()) {
        k = 0;
    }
}

void name_to_zero(char  new_name_temp[100], char*& new_name, int& count, char& ch)
{
    //free(new_name_temp);
    new_name = NULL;
    count = 0;
    ch = 1;
}

void name_enterer(char& ch, char  new_name_temp[100], int& count, char*& new_name)
{
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




void openBook(BOOK& b)
{
    b.open();
    cout << b << endl;
}

void renameBook(char& ch, char  new_name_temp[100], int& count, char*& new_name, BOOK& b)
{
    char new_name_temp[100];
    char* new_name = NULL;
    cout << "enter the name of the book without spaces:" << endl;
    name_enterer(ch, new_name_temp, count, new_name);
    b.change_name(count, new_name);
    cout << b << endl;
}

void openNSheet(int& nums, BOOK& b)
{
    cout << "enter the number of the sheet" << endl;
    cin >> nums;
    if (nums <0 || nums > b.get_content_length()) {
        nums = 0;
    }
    b.get_content()[nums].open();
    cout << b << endl;
}

void closeNSheet(int& nums, BOOK& b)
{
    cout << "enter the number of the sheet" << endl;
    cin >> nums;
    if (nums <0 || nums > b.get_content_length()) {
        nums = 0;
    }
    b.get_content()[nums].close();
    cout << b << endl;
}

void renameNSheet(int& num, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch)
{
    cout << "enter the number of the sheet" << endl;
    cin >> num;
    if (num <0 || num > b.get_content_length()) {
        num = 0;
    }
    cout << "enter the name of the sheet without spaces:" << endl;
    name_to_zero(new_name_temp, new_name, count, ch);
    name_enterer(ch, new_name_temp, count, new_name);
    b.get_content()[num].change_name(count, new_name);
    cout << b << endl;
}

void opennkCellFromjSheet(int& j, int& n, int& k, BOOK& b)
{
    cell_selector(j, n, k, b);
    b.get_content()[j][n][k].open();
    cout << b << endl;
}

void closenkCellFromjSheet(int& j, int& n, int& k, BOOK& b)
{
    cell_selector(j, n, k, b);
    b.get_content()[j][n][k].close();
    cout << b << endl;
}

void renamenkCellFromjSheet(int& j, int& n, int& k, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch)
{
    cell_selector(j, n, k, b);
    name_to_zero(new_name_temp, new_name, count, ch);
    name_enterer(ch, new_name_temp, count, new_name);
    b.get_content()[j][n][k].change_name(count, new_name);
    cout << b << endl;
}

void putValuenkCelljSheet(int& j, int& n, int& k, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch)
{
    cell_selector(j, n, k, b);
    name_to_zero(new_name_temp, new_name, count, ch);
    name_enterer(ch, new_name_temp, count, new_name);
    b.get_content()[j][n][k].put_value(count, new_name);
    cout << b << endl;
}

void getValuenkCelljSheet(int& j, int& n, int& k, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch)
{
    cell_selector(j, n, k, b);
    name_to_zero(new_name_temp, new_name, count, ch);
    name_enterer(ch, new_name_temp, count, new_name);
    b.get_content()[j][n][k].get_value();
    cout << b << endl;
}

void saveBookToDisk(BOOK& b)
{
    b.save_to_the_disk();
}

void getBookFromDisk(BOOK& b)
{
    b.get_from_the_disk();
}
void closseBook(BOOK& b)
{
    b.close();
    cout << b << endl;
}

int main()
{
    std::cout << "Hello World!\n";
    BOOK b;
    BOOK b2;
    cout << b << endl;
    int choise = 0;
    char new_name_temp[100];
    char* new_name = NULL;
    int count = 0;
    char ch = 1;
    int num;
    int nums;
    int n;
    int k;
    int j;
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
        cin >> choise;
        switch (choise) {
        case 1:
            openBook(b);
            break;
        case 2:
            closseBook(b);
            break;
        case 3:
            renameBook(ch, new_name_temp, count, new_name, b);
            break;
        case 4:
            openNSheet(nums, b);
            break;
        case 5:
            closeNSheet(nums, b);
            break;
        case 6:
            renameNSheet(num, b, new_name_temp, new_name, count, ch);
            break;
        case 7:
            opennkCellFromjSheet(j, n, k, b);
            break;
        case 8:
            closenkCellFromjSheet(j, n, k, b);
            break;
        case 9:
            renamenkCellFromjSheet(j, n, k, b, new_name_temp, new_name, count, ch);
            break;
        case 10:
            putValuenkCelljSheet(j, n, k, b, new_name_temp, new_name, count, ch);
            break;
        case 11:
            getValuenkCelljSheet(j, n, k, b, new_name_temp, new_name, count, ch);
            break;

        case 12:
            saveBookToDisk(b);
            break;

        case 13:
            getBookFromDisk(b);
            break;
        }
    }
}





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
