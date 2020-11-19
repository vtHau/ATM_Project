#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cmath>
#include <ctime>
#include "User.h"

using namespace std;

class Admin
{
private:
	string _strUser, _strPass;

public:

	string getUser();
	string getPass();

	void setUser(string user);
	void setPass(string pass);

	bool compare(vector<Admin> List);
};

class ListAdmin {

private:

	vector<Admin>_arrAdmin;

public:

	void readFile();
	vector<Admin> getListAdmin();
};

class FeatureAdmin {
public:
	ListAdmin _arrAdmin;
	Admin _admin;
	string _strUser, _strPin;

	FeatureAdmin();

	void input();
	bool checkLogin();

	void chooseOne();
	void chooseTwo();
	void chooseThree();
	void chooseFour();
	void chooseFive();
};