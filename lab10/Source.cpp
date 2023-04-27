#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int tempcount = 0;

void Selectsort(string* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]){
				string temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int StringToWords(char* temp, string* lines, bool IsWrite) {
	char* count[50] = {};
	char* tempc = strtok_s(temp, " ", count);
	while (tempc != NULL) {
		if (IsWrite) {
			lines[tempcount] = tempc;
		}
		tempc = strtok_s(NULL, " ", count);
		tempcount++;
	}
	return tempcount;
}

int main() {
	ifstream input("./input.txt");
	ofstream output("./output.txt");
	string null = "";
	char tempd[256];
	int asize = 0;
	for (int i = 0; input.getline(tempd, 256); i++) {
		asize += StringToWords(tempd, NULL, NULL);
	}
	string* lines = new string[asize];
	input.close();
	input.open("./input.txt");
	tempcount = 0;
	for (int i = 0; input.getline(tempd, 256); i++)
	{
		StringToWords(tempd, lines, 1);
	}
	Selectsort(lines, asize);
	for (int i = 0; i < asize; i++) {
		if (lines[i] != null) {
			output << lines[i] << " ";
		}
	}
	return 0;
}