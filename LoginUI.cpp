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

//����Լ�
void LoginUI::menu2_1output(ofstream& out_fp, string id, string passwd) {
	cout << "2.1. �α��� " << endl;
	cout << "> " << id << " " << passwd << endl;
	out_fp << "2.1. �α���" << endl;
	out_fp << "> " << id << " " << passwd << endl << endl;
}

void LoginUI::menu2_1fail(ofstream& out_fp) {
	cout << "2.1. �α��� " << endl;
	cout << "���̵�� ��й�ȣ�� ���� �ʽ��ϴ�." << endl;
	out_fp << "2.1. �α���" << endl;
	out_fp << "���̵�� ��й�ȣ�� ���� �ʽ��ϴ�." << endl;
}

