#include <iostream>
#include "Login.h"
#include <Windows.h>

using namespace std;

void runProgram();

int main()
{
	runProgram();
	system("pause");
	return 0;
}

void runProgram() {
	//SetConsoleOutputCP(65001); // cho phep co tieng viet
	while (true) {
		Login login;
		login.optionChoose();
		char choose = login.getChoose();

		switch (choose)
		{
		case '1':
			login.loginAdmin();
			break;
		case '2':
			login.userLogin();
			break;
		default:
			system("cls");
			cout << endl << "\t\t\tNHAP SAI ROI CON HANG!!!\n\t\t\tNHAP LAI DEE (>_<)";
			break;
		}
	}
}