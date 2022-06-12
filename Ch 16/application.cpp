#include <iostream>
#include <string>

#include "blobptr_template.cpp"

using namespace std;

extern template class Blob<string>;
//extern template int compare(const int&, const int&);
Blob<string> sa1, sa2;

/*
//Blob<int> a9;
*/

//Blob<int> a1;
//Blob<int> a2(a1);


