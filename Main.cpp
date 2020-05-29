#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>

using namespace std;

bool quitProgram;

string txtTemplate[5];

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
	quitProgram = false;
	cout << "Changed 'quitProgram' to 0" << endl;;
	InitializeTxtTemplate();
	InitializeRandomComponent();
	SetConsoleTitle((LPCSTR)"Hi");
}

int GenerateRandomInt()
{
	int result = 0;
	int random;

	
	random = rand() % 10 + 1;


	result = random;

	return result;
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

void WriteToConsoleMatrixModeBlock()
{
	int matrixLine = 1000;
	
	for (int i = 0; i < matrixLine-1; i++)
	{
		cout << GenerateRandomInt();
	}
}

int main() 
{
	InitializeMainScript();

	while (!quitProgram) {
		cout << quitProgram << endl;
		cout << "Write 0 or something else To Exit" << endl;
		cout << "Write 1 To Save Templates To txt File" << endl;
		cout << "Write 2 To Show Matrix Mode" << endl;
		int anwser;

		cin >> anwser;
		if (anwser == 2) {
			cout << "How many matrix blocks do you want to have? " << endl;

			int count;

			cin >> count;

			for (int i = 0; i < count; i++) {
				WriteToConsoleMatrixModeBlock();

				SetConsoleTitle((LPCSTR)"I'm sorry friend :C. No live window title. I hope you like games!");
			}

			cout << GenerateRandomInt() << endl;
			SetConsoleTitle("Hi");
		}
		else if (anwser == 1) 
		{
			cout << "How many templates you want to save to the .txt file? " << endl;

			int count;

			cin >> count;
			
			WriteTemplatesToTxtFile(count);
		}
		else if (anwser == 0) {
			quitProgram = true;
		}
		else 
		{
			cout << "Invalid format" << endl;
		}

	}

	return 0;
}
