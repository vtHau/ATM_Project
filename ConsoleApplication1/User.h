#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cmath>


using namespace std;

class User {
private:
	string _strID;
	string _strPIN;
	bool _bStatus = false; // mo la 0, khoa la 1
public:
	string getID();
	string getPIN();
	bool getStatus();

	void setID(string ID);
	void setPIN(string PIN);
	void setStatus(string status);

	void lock();
	void unlock();

	bool compare(vector<User>arrUser);
};

class ListUser :public User {
private:
	vector<User> _arrUser;
public:
	void readFile();
	void writeFile();

	void lockUser(string ID);
	void unlockUser(string ID);
	void deleteUser(string ID);
	void addUser(User user);

	bool search(string ID);
	void changePIN(string ID, string PIN);
	bool checkPIN(string ID, string PIN);

	void viewListUser();
	vector<User> getListUser();
};

class InfoUser {
private:
	string _strID, _strName, _strSurplus, _strTypeCurrency;
	//bool _bStatus;
public:
	void setID(string ID);
	void setName(string name);
	void setTypeCurrency(string typeCurrency);
	void setSurplus(string surplus);
	//void setStatus(string status);

	string getID();
	string getName();
	string getSurplus();
	string getTypeCurrency();
	//bool getStatus();
};

class ListInfoUser {
private:
	vector<InfoUser>_arrInfoUser;
public:
	void readFile(ListUser arrUser);
	void wrtieFile2(string ID);

	void takeMoney(string ID, string& s);
	void transferMoney(string ID, string s, string ID2);
	bool checkMoney(string ID, string s);
	void viewInfoUser(string ID);
	bool check(string ID);

	InfoUser getInfoUser(string ID);
};

class History {
private:
	string _strID;
	string _strTypeTransfer;
	string _strMoneyTransfer;
	string _strTime;
public:
	string getID();
	string getTime();
	string getTypeTransfer();
	string getMoneyTransfer();

	void setID(string ID);
	void setTypeTransfer(string typeTransfer);
	void setMoneyTransfer(string moneyTransfer);
	void setTime(string time);

	void viewHistory();
};

class ListHistory
{
private:
	vector<History>_arrHistory;
public:
	void readFile(ListUser arrUser);
	void writeFile(string ID);
	void writeFile2(string ID, string h);

	void add(History history);
	void showHistory(string ID);
};

class FeatureUser :public User {

public:
	ListUser _arrUser;
	User _user;
	string _strID, _strPIN, _strIDTemp;
	int _iDem = 1;

	FeatureUser();

	void input();
	bool checkLogin();

	void lockUser();
	void chooseOne();
	void chooseTwo();
	void chooseThree();
	void chooseFour();
	void chooseFive();
	void chooseSix();
};


