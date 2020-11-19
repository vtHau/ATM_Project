
#include "User.h"
#include "Admin.h"

class Login
{
private:
	char _cChoose;
public:

	void inputMyChoose();
	char getChoose();
	void optionChoose();

	void menuAdmin();
	void menuUser();

	void loginAdmin();
	void userLogin();
};