#include "LoginUI.h"
#include "Login.h"


LoginUI::LoginUI()
{
}


LoginUI::~LoginUI()
{
}

LoginUI* LoginUI::LoginUIInstance = NULL;

LoginUI* LoginUI::getLoginUIInstance() {
	if (LoginUIInstance == NULL)
	{
		LoginUIInstance = new LoginUI();
	}
	return LoginUIInstance;
}


void LoginUI::startInterface(ifstream& in_fp, ofstream& out_fp) {
	Login* control = Login::getLoginInstance();
	string id, passwd;
	in_fp >> id;
	in_fp >> passwd;
	control->showLogin(out_fp, id, passwd);
}

//출력함수
void LoginUI::menu2_1output(ofstream& out_fp, string id, string passwd) {
	cout << "2.1. 로그인 " << endl;
	cout << "> " << id << " " << passwd << endl;
	out_fp << "2.1. 로그인" << endl;
	out_fp << "> " << id << " " << passwd << endl << endl;
}

void LoginUI::menu2_1fail(ofstream& out_fp) {
	cout << "2.1. 로그인 " << endl;
	cout << "아이디와 비밀번호가 맞지 않습니다." << endl;
	out_fp << "2.1. 로그인" << endl;
	out_fp << "아이디와 비밀번호가 맞지 않습니다." << endl;
}

