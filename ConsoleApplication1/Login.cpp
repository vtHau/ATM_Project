#include "Login.h"


void Login::inputMyChoose() {
	cin >> _cChoose;
}
char Login::getChoose() {
	return _cChoose;
}
void Login::optionChoose()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);

	cout << endl << endl;
	cout << "\n\n\t\t\t\tChon Loai Tai Khoan Dang Nhap:\n";
	cout << "\t\t==============================(@_@)===============================\n\n";
	cout << "\t\t\t=================================================\n";
	cout << "\t\t\t|*\t                                       *|\n";
	cout << "\t\t\t|*\t1.Dang Nhap Tai Khoan Admin            *|\n";
	cout << "\t\t\t|*\t2.Dang Nhap Tai Khoan User             *|\n";
	cout << "\t\t\t|*\t                                       *|\n";
	cout << "\t\t\t=================================================\n\n\n\n";
	cout << "\t\t\t\tNhap Lua Chon Cua Ban:  ";
	inputMyChoose();
}

void Login::menuAdmin()
{
	cout << "\n\n\n\n";
	cout << "\t\t\t* * * * * * * * ADMIN_MENU * * * * * * * * *" << endl << endl;
	cout << "\t\t\t\t1. Xem danh sach tai khoan" << endl;
	cout << "\t\t\t\t2. Them tai khoan" << endl;
	cout << "\t\t\t\t3. Xoa tai khoan" << endl;
	cout << "\t\t\t\t4. Mo khoa tai khoan" << endl;
	cout << "\t\t\t\t5. Thoat" << endl << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}
void Login::menuUser()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t* * * * * * * * USER_MENU * * * * * * * * *" << endl << endl;
	cout << "\t\t\t\t1. Xem thong tin tai khoan" << endl;
	cout << "\t\t\t\t2. Rut tien" << endl;
	cout << "\t\t\t\t3. Chuyen tien" << endl;
	cout << "\t\t\t\t4. Xem noi dung giao dich" << endl;
	cout << "\t\t\t\t5. Doi ma PIN" << endl;
	cout << "\t\t\t\t6. Thoat" << endl << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}

void Login::loginAdmin()
{
	FeatureAdmin feature;
	while (true) {

		cout << "\n\n\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*             DANG NHAP ADMIN                *" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		feature.input();
		cout << endl << endl;
		cout << "\t\tHe thong dang chay, doi xiu nhe";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << endl;
		switch (feature.checkLogin())
		{
		case true:
			cout << "\t\t\t\tDang Nhap Thanh Cong" << endl << endl;
			Sleep(400);
			system("cls");
			while (true) {
				menuAdmin();
				cout << endl << "\t\t\t\tMoi Ban Nhap Lua Chon: ";
				char choose;
				cin >> choose;

				switch (choose)
				{
				case '1':
					system("cls");
					feature.chooseOne();
					cout << "\n\t\t\tNhan phim bat ky de quay lai ADMIN_MENU: ";
					if (cin >> choose) {
						system("cls");
						break;
					}

				case '2':
					system("cls");
					feature.chooseOne();
					feature.chooseTwo();
					feature.chooseOne();
					break;

				case '3':
					system("cls");
					feature.chooseOne();
					feature.chooseThree();
					feature.chooseOne();
					break;

				case '4':
					system("cls");
					feature.chooseOne();
					feature.chooseFour();
					feature.chooseOne();
					break;

				case '5':
					system("cls");
					feature.chooseFive();
					break;

				default:
					system("cls");
					cout << endl << "\t\t\tNHAP SAI ROI CON HANG!!!\tNHAP LAI DEE (>_<)";
					break;
				}
			}
		default:
			system("cls");
			cout << "\t\t\tDANG NHAP THAT BAI!!!\tTU KIEM TRA LAI DEEE \\(T_T)/";
			break;
		}
	}
}
void Login::userLogin() {
	FeatureUser feature;
	while (true) {
		cout << "\n\n\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*             DANG NHAP USER                *" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		feature.input();
		cout << endl << endl;
		cout << "\t\tHe thong dang chay, doi xiu nhe";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << ".";
		Sleep(400);
		cout << endl;
		if (feature.checkLogin()) {
			cout << "\t\t\t\tDang Nhap Thanh Cong" << endl << endl;
			Sleep(400);
			while (true) {
				menuUser();
				cout << "\t\t\t\tMoi Ban Nhap Lua Chon: ";
				int choose;
				cin >> choose;

				switch (choose)
				{
				case 1:
					system("cls");
					feature.chooseOne();
					cout << "\n\t\t\tNhap phim bat ky de quay lai USER_MENU: ";
					if (cin >> choose) {
						system("cls");
						break;
					}

				case 2:
					system("cls");
					feature.chooseTwo();
					break;

				case 3:
					system("cls");
					feature.chooseThree();
					break;

				case 4:
					system("cls");
					feature.chooseFour();
					cout << "\n\t\t\tNhap phim bat ky de quay lai USER_MENU: ";
					if (cin >> choose) {
						system("cls");
						break;
					}

				case 5:
					system("cls");
					feature.chooseFive();
					break;

				case 6:
					system("cls");
					feature.chooseSix();
					break;

				default:
					system("cls");
					cout << endl << "\t\t\tNHAP SAI ROI CON HANG!!!\tNHAP LAI DEE (>_<)";
					break;
				}
			}
			break;
		}
		else {
			system("cls");
			cout << "\t\t\tDANG NHAP THAT BAI!!!\tVUI LONG NHAP LAI ID & PIN \\(T_T)/";
		}
		feature.lockUser();
	}
}