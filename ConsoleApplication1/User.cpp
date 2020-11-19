#include "User.h"

COORD coord = { 0, 0 };

void goToXY(int x, int y) {	//defining/initializing to predefined objects
	coord.X = x;
	coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Class User
string User::getID() { return _strID; }
string User::getPIN() { return _strPIN; }
bool User::getStatus() { return _bStatus; }

void User::setID(string ID) { _strID = ID; }
void User::setPIN(string PIN) { _strPIN = PIN; }
void User::setStatus(string status) {
	if (status == "1") { _bStatus = true; }
	if (status == "0") { _bStatus = false; }
}

void User::lock() {
	_bStatus = false;
}
void User::unlock() {
	_bStatus = true;
}

bool User::compare(vector<User>arrUser) {
	for (int i = 0; i < arrUser.size(); i++) {
		if (arrUser[i].getID() == _strID && arrUser[i].getPIN() == _strPIN && arrUser[i].getStatus() == true) return true;
	}
	return false;
}


//Class ListUser
void ListUser::readFile() {
	User user;
	//bool isID = true;
	int count = 1;
	ifstream  file;
	file.open("ATM_data\\TheTu.txt");
	while (!file.eof()) {
		string temp;
		switch (count)
		{
		case 1:
			getline(file, temp);
			user.setID(temp);
			break;
		case 2:
			getline(file, temp);
			user.setPIN(temp);
			break;
		case 3:
			getline(file, temp);
			user.setStatus(temp);
			_arrUser.push_back(user);
			count = 0;
			break;
		}
		count++;
	}
	file.close();
}
void ListUser::writeFile() {
	ofstream file;
	file.open("ATM_data\\TheTu.txt");
	for (int i = 0; i < _arrUser.size(); i++) {
		file << _arrUser[i].getID() << endl << _arrUser[i].getPIN() << endl << _arrUser[i].getStatus();
		if (i < _arrUser.size() - 1) file << endl;
	}
	file.close();
}

void ListUser::lockUser(string ID) {
	for (int i = 0; i < _arrUser.size(); i++) {
		if (_arrUser[i].getID() == ID) {
			_arrUser[i].lock();
			writeFile();
		}
	}
}
void ListUser::unlockUser(string ID) {
	for (int i = 0; i < _arrUser.size(); i++) {
		if (_arrUser[i].getID() == ID) _arrUser[i].unlock();
	}
}
void ListUser::deleteUser(string ID) {
	int count;
	for (int i = 0; i < _arrUser.size(); i++)
		if (ID == _arrUser[i].getID()) count = i;
	_arrUser.erase(_arrUser.begin() + count);
}
void ListUser::addUser(User user) {
	_arrUser.push_back(user);
}

bool ListUser::search(string ID) {
	for (int i = 0; i < _arrUser.size(); i++)
		if (_arrUser[i].getID() == ID) return true;
	return false;
}
void ListUser::changePIN(string ID, string PIN) {
	for (int i = 0; i < _arrUser.size(); i++) {
		if (_arrUser[i].getID() == ID) _arrUser[i].setPIN(PIN);
	}
}
bool ListUser::checkPIN(string ID, string PIN) {
	for (int i = 0; i < _arrUser.size(); i++)
		if (_arrUser[i].getID() == ID && _arrUser[i].getPIN() == PIN) return true;
	return false;
}

void ListUser::viewListUser() {
	string trangThai;
	cout << "\t\t\tStt\t Id\t\t\t PIN\t\tTrang thai\n\n";
	for (int i = 0; i < _arrUser.size(); i++) {
		if (_arrUser[i].getStatus()) trangThai = "Dang SD";
		else trangThai = "Bi khoa";
		cout << "\t\t\t " << i << "\t";
		cout << _arrUser[i].getID() << "\t\t";
		cout << _arrUser[i].getPIN() << "\t\t ";
		cout << trangThai << "\n";
	}
}
vector<User> ListUser::getListUser() {
	return _arrUser;
}


//Class InfoUser
void InfoUser::setID(string ID) {
	_strID = ID;
}
void InfoUser::setName(string name) {
	_strName = name;
}
void InfoUser::setTypeCurrency(string typeCurrency) {
	_strTypeCurrency = typeCurrency;
}
void InfoUser::setSurplus(string surplus) {
	_strSurplus = surplus;
}

string InfoUser::getID() {
	return _strID;
}
string InfoUser::getName() {
	return _strName;
}
string InfoUser::getSurplus() {
	return _strSurplus;
}
string InfoUser::getTypeCurrency() {
	return _strTypeCurrency;
}


//Class ListInfoUser
void ListInfoUser::readFile(ListUser arrUser) {
	vector<User> array = arrUser.getListUser();
	for (int i = 0; i < array.size(); i++) {
		InfoUser infoUser;
		int count = 1;
		string temp, path;
		path = "ATM_data\\ID\\" + (array)[i].getID() + ".txt";
		ifstream  file;
		file.open(path);

		while (!file.eof()) {
			if (count == 1) {
				getline(file, temp);
				infoUser.setID(temp);
			}

			if (count == 2) {
				getline(file, temp);
				infoUser.setName(temp);
			}

			if (count == 3) {
				getline(file, temp);
				infoUser.setSurplus(temp);
			}

			if (count == 4) {
				getline(file, temp);
				infoUser.setTypeCurrency(temp);
				_arrInfoUser.push_back(infoUser);
				count = 0;
			}
			count++;
		}
		file.close();

	}
}
//void ListInfoUser::wrtieFile() {
//	ofstream file;
//	for (int i = 0; i < _arrInfoUser.size(); i++) {
//		file.open("ATM_data\\ID\\" + _arrInfoUser[i].getID() + ".txt");
//		file << _arrInfoUser[i].getID() << endl << _arrInfoUser[i].getName() << endl << _arrInfoUser[i].getSurplus() << endl << _arrInfoUser[i].getTypeCurrency();
//		if (i < _arrInfoUser.size() - 1) file << endl;
//	}
//	file.close();
//}
void ListInfoUser::wrtieFile2(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (ID == _arrInfoUser[i].getID()) {
			ofstream file;
			file.open("ATM_data\\ID\\" + ID + ".txt");
			file << _arrInfoUser[i].getID() << endl << _arrInfoUser[i].getName() << endl << _arrInfoUser[i].getSurplus() << endl << _arrInfoUser[i].getTypeCurrency();
			if (i < _arrInfoUser.size() - 1) file << endl;
			file.close();
			break;
		}
	}
}
//void ListInfoUser::wrtieFile2(string ID) {
//			ofstream file;
//			file.open("ATM_data\\ID\\" + ID + ".txt");
//			//file << _arrInfoUser[i].getID() << endl << _arrInfoUser[i].getName() << endl << _arrInfoUser[i].getSurplus() << endl << _arrInfoUser[i].getTypeCurrency();
//			//if (i < _arrInfoUser.size() - 1) file << endl;
//			file.close();
//}

void ListInfoUser::takeMoney(string ID, string& s) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) {
			while (true) {
				cout << "\t\t\t\tMoi Ban Nhap So Tien Can Rut: ";
				cin >> s;
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
				if (stoi(_arrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_arrInfoUser[i].getSurplus()) >= 50000) {
					cout << "\t\t\t\tRut Tien Thanh Cong" << endl << endl;
					_arrInfoUser[i].setSurplus(to_string(stoi(_arrInfoUser[i].getSurplus()) - stoi(s)));
					Sleep(400);
					break;
				}
				else cout << "\t\t\t\tRut Tien That Bai" << endl;
				Sleep(400);
			}
		}
	}
}
void ListInfoUser::transferMoney(string ID, string s, string ID2) {
	int t = 0;
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) {
			if (stoi(_arrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_arrInfoUser[i].getSurplus()) >= 50000) {
				_arrInfoUser[i].setSurplus(to_string(stoi(_arrInfoUser[i].getSurplus()) - stoi(s)));
			}
			else t = 1;
		}
	}
	if (t == 0) {
		for (int i = 0; i < _arrInfoUser.size(); i++) {
			if (_arrInfoUser[i].getID() == ID2) {
				_arrInfoUser[i].setSurplus(to_string(stoi(_arrInfoUser[i].getSurplus()) + stoi(s)));
			}
		}
	}
}
bool ListInfoUser::checkMoney(string ID, string s) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) {
			if (stoi(_arrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_arrInfoUser[i].getSurplus()) >= 50000) return true;
		}
	}
	return false;
}
void ListInfoUser::viewInfoUser(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (ID == _arrInfoUser[i].getID()) {
			cout << "\t\t\t\tId: " << _arrInfoUser[i].getID() << endl;
			cout << "\t\t\t\tTen Tai Khoan: " << _arrInfoUser[i].getName() << endl;
			cout << "\t\t\t\tSo Du: " << _arrInfoUser[i].getSurplus() << endl;
			cout << "\t\t\t\tLoai Tien Te: " << _arrInfoUser[i].getTypeCurrency() << endl << endl << endl;
			break;
		}
	}
}
bool ListInfoUser::check(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++)
		if (_arrInfoUser[i].getID() == ID) return true;
	return false;
}

InfoUser ListInfoUser::getInfoUser(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) return _arrInfoUser[i];
	}
}


//Class History
string History::getID() {
	return _strID;
}
string History::getTime() {
	return _strTime;
}
string History::getTypeTransfer() {
	return  _strTypeTransfer;
}
string History::getMoneyTransfer() {
	return _strMoneyTransfer;
}

void History::setID(string ID) {
	_strID = ID;
}
void History::setTypeTransfer(string typeTransfer) {
	_strTypeTransfer = typeTransfer;
}
void History::setMoneyTransfer(string moneyTransfer) {
	_strMoneyTransfer = moneyTransfer;
}
void History::setTime(string time) {
	_strTime = time;
}

void History::viewHistory() {
	cout << "\t\t\t\tID: " << _strID << endl;
	cout << "\t\t\t\tLoai Giao Dich: " << _strTypeTransfer << endl;
	cout << "\t\t\t\tSo Tien Giao Dich: " << _strMoneyTransfer << endl;
	cout << "\t\t\t\tThoi Gian: " << _strTime << endl << endl;
}


//Class ListHistory
void ListHistory::readFile(ListUser arrUser) {
	for (int i = 0; i < arrUser.getListUser().size(); i++) {
		History history;
		int count = 1;
		string temp, path;
		path = "ATM_data\\LichSuGD\\LichSu" + (arrUser.getListUser())[i].getID() + ".txt";
		ifstream  file;
		file.open(path);
		while (!file.eof()) {
			if (count == 1) {
				getline(file, temp);
				history.setID(temp);
			}

			if (count == 2) {
				getline(file, temp);
				history.setTypeTransfer(temp);
			}
			if (count == 3) {
				getline(file, temp);
				history.setMoneyTransfer(temp);
			}
			if (count == 4) {
				getline(file, temp);
				history.setTime(temp);
				_arrHistory.push_back(history);
				count = 0;
			}
			count++;
		}
		file.close();
	}
}
void ListHistory::writeFile(string ID) {
	string path = "ATM_data\\LichSuGD\\LichSu" + ID + ".txt";
	ofstream file;
	file.open(path);
	for (int i = 0; i < _arrHistory.size(); i++) {
		if (_arrHistory[i].getID() == ID) {
			file << _arrHistory[i].getID() << endl << _arrHistory[i].getTypeTransfer() << endl << _arrHistory[i].getMoneyTransfer() << endl << _arrHistory[i].getTime();
			if (i < _arrHistory.size() - 1) file << endl;
		}
	}
	file.close();
}
void ListHistory::writeFile2(string ID, string h) {
	string path = "ATM_data\\LichSuGD\\LichSu" + ID + ".txt";
	ofstream file;
	file.open(path);
	for (int i = 0; i < _arrHistory.size(); i++) {
		if (_arrHistory[i].getID() == h || _arrHistory[i].getID() == ID) {
			file << _arrHistory[i].getID() << endl << _arrHistory[i].getTypeTransfer() << endl << _arrHistory[i].getMoneyTransfer() << endl << _arrHistory[i].getTime();
			if (i < _arrHistory.size() - 1) file << endl;

		}
	}
	file.close();
}

void ListHistory::add(History history) {
	_arrHistory.push_back(history);
}
void ListHistory::showHistory(string ID) {
	for (int i = 0; i < _arrHistory.size(); i++) {
		if (_arrHistory[i].getID() == ID) _arrHistory[i].viewHistory();
	}
}


//Class FeatureUser
FeatureUser::FeatureUser() {
	system("cls");
	_arrUser.readFile();
}

void FeatureUser::input() {
	char c;
	string pin;
	cout << "\t\t\t\t@ID:     ";
	cin >> _strID;
	_user.setID(_strID);

	cout << "\t\t\t\t@PIN:    ";
	int i = 41;
	c = _getch();
	while (c == 8) {
		c = _getch();
	}
	while (c != 13) {
		if (c != 8) {
			pin.push_back(c);
			goToXY(i, 9);
			cout << "*";
			i++;
			c = _getch();
		}
		else {
			while (i > 41) {
				do {
					pin.erase(pin.end() - 1);
					goToXY(i - 1, 9);
					cout << " ";
					i--;
					c = _getch();
				} while (pin.empty() == false);
				if (pin.empty() == true) {
					c = _getch();
					while (c == 8) {
						c = _getch();
					}
				}
			}
		}
	}
	_strPIN = pin;
	_user.setPIN(_strPIN);
}
bool FeatureUser::checkLogin() {
	return _user.compare(_arrUser.getListUser());
}
void FeatureUser::lockUser() {
	if (_strIDTemp == _strID) _iDem++;
	if (_iDem == 3) {
		if (_arrUser.search(_strID)) {
			cout << "\t\t\tTAI KHOAN CUA BAN DA BI KHOA DO NHAP SAI MAT KHAU QUA 3 LAN !!!";
			_arrUser.lockUser(_strID);
			exit(0);
		}
		else _iDem = 1;
	}
	_strIDTemp = _strID;
}

void FeatureUser::chooseOne() {
	cout << endl << "\t\t\t\tThong Tin Tai Khoan: " << endl;
	ListInfoUser arrInfoUser;
	arrInfoUser.readFile(_arrUser);
	arrInfoUser.viewInfoUser(_strID);
}
void FeatureUser::chooseTwo() {
	string h;
	time_t now = time(0);
	char* ch = ctime(&now);
	h = ch;

	string s;
	ListHistory _arrHistory;
	ListInfoUser arrInfoUser;

	_arrHistory.readFile(_arrUser);
	arrInfoUser.readFile(_arrUser);
	InfoUser a = arrInfoUser.getInfoUser(_strID);

	History history;
	history.setID(a.getID());
	history.setTime(h);
	history.setTypeTransfer("Rut Tien");
	arrInfoUser.takeMoney(_strID, s);
	history.setMoneyTransfer(s);

	_arrHistory.add(history);
	_arrHistory.writeFile(_strID);
	arrInfoUser.wrtieFile2(_strID);
}
void FeatureUser::chooseThree() {
	while (true) {
		cout << "\t\t\t\tNhap ID Tai Khoan Can Chuyen: ";
		string IDNeedTransfer;
		cin >> IDNeedTransfer;
		ListInfoUser arrInfoUser;
		arrInfoUser.readFile(_arrUser);
		if (arrInfoUser.check(IDNeedTransfer))
		{
			cout << "\t\t\t\tNhap So Tien Can Chuyen: ";
			string money;
			cin >> money;
			cout << "He thong dang chay, doi xiu nhe";
			Sleep(400);
			cout << ".";
			Sleep(400);
			cout << ".";
			Sleep(400);
			cout << ".";
			Sleep(400);
			cout << endl;
			if (arrInfoUser.checkMoney(_strID, money) && IDNeedTransfer != _strID) {
				arrInfoUser.transferMoney(_strID, money, IDNeedTransfer);
				arrInfoUser.wrtieFile2(_strID);
				arrInfoUser.wrtieFile2(IDNeedTransfer);

				string timeTransfer;
				History history;
				ListHistory _arrHistory;
				time_t now = time(0);
				char* ch = ctime(&now);
				timeTransfer = ch;

				_arrHistory.readFile(_arrUser);
				history.setTime(timeTransfer);
				history.setID(_strID);
				history.setTypeTransfer("chuyen tien cho: " + arrInfoUser.getInfoUser(IDNeedTransfer).getName() + " voi ID chuyen den la: " + IDNeedTransfer);
				history.setMoneyTransfer(money);
				_arrHistory.add(history);
				_arrHistory.writeFile2(_strID, IDNeedTransfer);
				cout << "\t\t\t\tChuyen Tien Thanh Cong!!!" << endl;
				Sleep(400);
				break;
			}
			else {
				cout << "\t\t\t\tSo tien chuyen khong phu hop, Vui long nhap lai " << endl;
				Sleep(400);
			}
		}
	}
}
void FeatureUser::chooseFour() {
	ListHistory _arrHistory;
	_arrHistory.readFile(_arrUser);
	_arrHistory.showHistory(_strID);
}
void FeatureUser::chooseFive() {
	ListUser _arrUser;
	_arrUser.readFile();
	cout << "\t\t\t\tDoi Ma Pin: " << endl << endl;
	while (true) {
		cout << "\t\t\t\tNhap Ma PIN Hien Tai: ";
		string currentPIN;
		cin >> currentPIN;
		if (_arrUser.checkPIN(_strID, currentPIN)) {
			while (true) {
				string newPIN, newPIN2;
				cout << "\t\t\t\tNhap Ma PIN Moi: ";
				cin >> newPIN;
				cout << "\t\t\t\tXac Nhan Ma PIN Moi: ";
				cin >> newPIN2;
				cout << "He thong dang chay, doi xiu nhe";
				Sleep(400);
				cout << ".";
				Sleep(400);
				cout << ".";
				Sleep(400);
				cout << ".";
				Sleep(400);
				cout << endl;
				if (newPIN == newPIN2)
				{
					_arrUser.changePIN(_strID, newPIN);
					_arrUser.writeFile();
					cout << "\t\t\t\tDoi Ma Pin Thanh Cong" << endl;
					Sleep(400);
					break;
				}
				else {
					cout << "\t\t\t\tXac Nhan Lai Ma Pin Chua Dung" << endl;
					Sleep(400);
				}
			}
			break;
		}
		else cout << "\t\t\t\tMa PIN Hien Tai Khong Dung" << endl;
		Sleep(400);
	}
}
void FeatureUser::chooseSix() {
	cout << "\t\t\t\tThoat Thanh Cong";
	exit(0);
}
