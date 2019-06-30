#include "ChangeUserSessionUI.h"
#include "ChangeUserSession.h"
#include <fstream>


ChangeUserSessionUI::ChangeUserSessionUI()
{

}


ChangeUserSessionUI::~ChangeUserSessionUI()
{
}

ChangeUserSessionUI* ChangeUserSessionUI::ChangeUserSessionUIInstance = NULL; //static���� �ʱⰪ NULL ����

ChangeUserSessionUI* ChangeUserSessionUI::getChangeUserSessionUIInstance() {
	if (ChangeUserSessionUIInstance == NULL) {
		ChangeUserSessionUIInstance = new ChangeUserSessionUI();
	}
	return ChangeUserSessionUIInstance;
}

void ChangeUserSessionUI::startInterface(ifstream& in_fp, ofstream& out_fp) {
	ChangeUserSession* control = ChangeUserSession::getChangeUserSessionInstance();
	string input_id;
	in_fp >> input_id;


	control->ChangeUser(out_fp,input_id);
};

//����Լ�
void ChangeUserSessionUI::menu6_1output(ofstream& out_fp, string input_id) {
	cout << "6.1. session����" << endl;
	cout << "> " << input_id << endl;
	out_fp << "6.1. session����" << endl;
	out_fp << "> " << input_id << endl << endl;
}

void ChangeUserSessionUI::menu6_1fail(ofstream& out_fp) {
	cout << "6.1. session����" << endl;
	cout << "> ����" << endl;
	out_fp << "6.1. session����" << endl;
	out_fp << "> ����" << endl << endl;
}