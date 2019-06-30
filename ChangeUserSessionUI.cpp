#include "ChangeUserSessionUI.h"
#include "ChangeUserSession.h"
#include <fstream>


ChangeUserSessionUI::ChangeUserSessionUI()
{

}


ChangeUserSessionUI::~ChangeUserSessionUI()
{
}

ChangeUserSessionUI* ChangeUserSessionUI::ChangeUserSessionUIInstance = NULL; //static변수 초기값 NULL 설정

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

//출력함수
void ChangeUserSessionUI::menu6_1output(ofstream& out_fp, string input_id) {
	cout << "6.1. session변경" << endl;
	cout << "> " << input_id << endl;
	out_fp << "6.1. session변경" << endl;
	out_fp << "> " << input_id << endl << endl;
}

void ChangeUserSessionUI::menu6_1fail(ofstream& out_fp) {
	cout << "6.1. session변경" << endl;
	cout << "> 실패" << endl;
	out_fp << "6.1. session변경" << endl;
	out_fp << "> 실패" << endl << endl;
}