
#include "Admin.h"

COORD _coord = { 0,0 };

void gotoxy(int x, int y) {	//defining/initializing to predefined objects
	_coord.X = x;
	_coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _coord);
}

string Admin::getUser() {
	return _strUser;
}
string Admin::getPass() {
	return _strPass;
}

void Admin::setUser(string user) {
	_strUser = user;
}
void Admin::setPass(string pass) {
	_strPass = pass;
}
bool Admin::compare(vector<Admin> List) {
	for (int i = 0; i < List.size(); i++)
		if (List[i].getUser() == _strUser && List[i].getPass() == _strPass) return true;
	return false;
}


//Class ListAdmin
void ListAdmin::readFile() {
	Admin admin;
	bool isUser = true;
	ifstream  file;
	file.open("ATM_data\\Admin.txt");
	while (!file.eof()) {
		string temp;
		if (isUser) {
			getline(file, temp);
			admin.setUser(temp);
		}
		else {
			getline(file, temp);
			admin.setPass(temp);
			_arrAdmin.push_back(admin);
		}
		isUser = !isUser;
	}
	file.close();
}
vector<Admin> ListAdmin::getListAdmin() {
	return _arrAdmin;
}

//Class FeatureAdmin
FeatureAdmin::FeatureAdmin() {
	system("cls");
	_arrAdmin.readFile();

}

void FeatureAdmin::input() {
	char c;
	string pass;
	cout << "\t\t\t\t@USER:      ";
	cin >> _strUser;
	_admin.setUser(_strUser);

	cout << "\t\t\t\t@PIN:       ";
	int i = 44;
	c = _getch();
	while (c == 8) {
		c = _getch();
	}
	while (c != 13) {
		if (c != 8) {
			pass.push_back(c);
			gotoxy(i, 9);
			cout << "*";
			i++;
			c = _getch();
		}
		else {
			while (i > 44) {
				do {
					pass.erase(pass.end() - 1);
					gotoxy(i - 1, 9);
					cout << " ";
					i--;
					c = _getch();
				} while (pass.empty() == false);
				if (pass.empty() == true) {
					c = _getch();
					while (c == 8) {
						c = _getch();
					}
				}
			}
		}
	}
	_strPin = pass;
	_admin.setPass(_strPin);
}
bool FeatureAdmin::checkLogin() {
	return _admin.compare(_arrAdmin.getListAdmin());
}

void FeatureAdmin::chooseOne() {
	int choose;

	cout << "\n\n\t\t\t\t* * * * o(0)DANH SACH TAI KHOAN(0)o * * * *\n\n" << endl;
	ListUser arrUser;
	arrUser.readFile();
	arrUser.viewListUser();
}
void FeatureAdmin::chooseTwo() {
	ListUser arrUSer;
	ListInfoUser arrInfoUser;
	arrUSer.readFile();
	string newID, newName, newSurplus, newType;
	cout << "\n\t\t\t\tNhap ID Muon Them: ";
	cin >> newID;
	cout << "\t\t\t\tNhap Ho va Ten: ";
	cin.ignore();
	getline(cin, newName);
	cout << "\t\t\t\tNhap so du: ";
	cin >> newSurplus;
	cout << "\t\t\t\tNhap loai tien te( Mac dinh VND): ";
	cin >> newType;
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
	if (arrUSer.search(newID) == false) {

		User newUser;
		InfoUser newInfo;
		newUser.setID(newID);
		newUser.setPIN("123456");
		arrUSer.addUser(newUser);
		arrUSer.writeFile();

		newInfo.setID(newID);
		newInfo.setName(newName);
		newInfo.setSurplus(newSurplus);
		newInfo.setTypeCurrency(newType);

		ofstream newFile;
		newFile.open("ATM_data\\LichSuGD\\LichSu" + newID + ".txt");
		newFile.close();

		//arrInfoUser.wrtieFile2(newID);

		ofstream writeInfo;
		writeInfo.open("ATM_data\\ID\\" + newID + ".txt");
		writeInfo << newID << endl << newName << endl << newSurplus << endl << newType;
		writeInfo.close();
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\tThem Tai Khoan Thanh Cong";
	}
	else cout << "\t\t\t\tTai Khoan Da Ton Tai";
	Sleep(400);
}
void FeatureAdmin::chooseThree() {
	ListUser arrUser;
	arrUser.readFile();

	cout << "\n\t\t\t\tNhap ID Muon Xoa: ";
	string ID;
	cin >> ID;
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
	if (arrUser.search(ID)) {
		arrUser.deleteUser(ID);
		arrUser.writeFile();
		cout << "\t\t\t\tXoa Tai Khoan Thanh Cong" << endl;
	}
	else cout << "\t\t\t\tTai Khoan Khong Ton Tai" << endl;
	Sleep(400);
}
void FeatureAdmin::chooseFour() {
	ListUser arrUser;
	arrUser.readFile();

	cout << "\n\t\t\t\tNhap ID Muon Mo Khoa: ";
	string ID;
	cin >> ID;
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
	if (arrUser.search(ID))
	{
		cout << "\t\t\t\tMo Khoa Thanh Cong";
		arrUser.unlockUser(ID);
		arrUser.writeFile();
	}
	else cout << "\t\t\t\tTai Khoan Khong Ton Tai";
	Sleep(400);
}
void FeatureAdmin::chooseFive() {
	cout << "\t\t\t\tThoat Thanh Cong";
	exit(0);
}
