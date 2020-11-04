#pragma once

void openBook(BOOK& b);

void renameBook(char& ch, char  new_name_temp[100], int& count, char*& new_name, BOOK& b);

void openNSheet(int& nums, BOOK& b);

void closeNSheet(int& nums, BOOK& b);

void renameNSheet(int& num, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch);

void opennkCellFromjSheet(int& j, int& n, int& k, BOOK& b);

void closenkCellFromjSheet(int& j, int& n, int& k, BOOK& b);

void renamenkCellFromjSheet(int& j, int& n, int& k, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch);

void putValuenkCelljSheet(int& j, int& n, int& k, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch);

void getValuenkCelljSheet(int& j, int& n, int& k, BOOK& b, char  new_name_temp[100], char*& new_name, int& count, char& ch);

void saveBookToDisk(BOOK& b);

void getBookFromDisk(BOOK& b);

void addingSheet(BOOK& b);

void useLeftSidedFunc(BOOK& b);

void closseBook(BOOK& b);
