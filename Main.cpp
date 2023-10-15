#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>

using namespace std;

string txtTemplate[6];

void InitializeTxtTemplate() {
	txtTemplate[0] = "Nazwa: ";
	txtTemplate[1] = "Cecha 1: ";
	txtTemplate[2] = "Cecha 2: ";
	txtTemplate[3] = "Cecha 3: ";
	txtTemplate[4] = "Cecha 4: ";
	txtTemplate[5] = "";
}

void InitializeRandomComponent()
{
	srand((unsigned)time(NULL));
}

void InitializeMainScript() {
	InitializeTxtTemplate();
	InitializeRandomComponent();
}

void WriteTemplatesToTxtFile(int count) 
{
	int templatesWritedToFile = 0;

	fstream txtFile;
	txtFile.open("txtFile.txt", ios::out);

	cout << "Succesfully created file" << endl;

	while (templatesWritedToFile < count)
	{
		for (int i = 0; i <= 5; i++) {
			txtFile << txtTemplate[i] << endl;
			cout << "  Writed '" << txtTemplate[i] << "' to the file" << endl;
		}
		templatesWritedToFile++;
		cout << " Succesfully writed " << templatesWritedToFile << " template to txt (Requested templates: " << count << ")" << endl;
	}
	txtFile.close();
	cout << "Succesfully ended saving file" << endl;
}

void WriteToConsoleMatrixModeBlock(int t)
{
	int matrixLine = 1000;
	for(int j = 0; j < t;j++)
	{
		for (int i = 0; i < matrixLine; i++)
		{
			cout << rand() % 10 + 1;
		}
	}
}

int main() 
{
	InitializeMainScript();

	int tempCount;
	while (true) {
		cout << "Write 0 To Exit" << endl;
		cout << "Write 1 To Save Templates To txt File" << endl;
		cout << "Write 2 To Show Matrix Mode" << endl;

		int anwser;
		cin >> anwser;

		if(anwser == 0) { return 0; }
		if (anwser == 2) {
			cout << "How many matrix blocks do you want to have? " << endl;

			cin >> tempCount;

			WriteToConsoleMatrixModeBlock(tempCount);

			cout << endl;
		}
		else if (anwser == 1) 
		{
			cout << "How many templates you want to save to the .txt file? " << endl;

			cin >> tempCount;

			WriteTemplatesToTxtFile(tempCount);
		}
		else { cout << "Invalid format" << endl; }
	}

	return 0;
}
