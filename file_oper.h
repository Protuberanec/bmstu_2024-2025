#pragma once


#include <fstream>
#include <iostream>
#include <cstring>


bool openFile_w(const char* file_name);
bool openFile_r(const char* file_name);
void closeFile();
int writeFile(const char* data);
int readFile(char** data);
void writePoints(double x, double y);

