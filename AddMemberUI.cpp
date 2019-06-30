#include "AddMemberUI.h"
#include "AddMember.h"


AddMemberUI::AddMemberUI()
{
}


AddMemberUI::~AddMemberUI()
{
}

AddMemberUI* AddMemberUI::addMemberUIInstance = NULL;

AddMemberUI* AddMemberUI::getAddMemberUIInstance() {
	if (addMemberUIInstance == NULL)
	{
		addMemberUIInstance = new AddMemberUI();
	}
	return addMemberUIInstance;
}

// 입력함수
void AddMemberUI::startInterface(ifstream & in_fp, ofstream& out_fp) {
	AddMember *control = AddMember::getAddMemberInstance();
	string id, passwd, name, ssn, user_type;
	in_fp >> id;
	in_fp >> passwd;
	in_fp >> name;
	in_fp >> ssn;
	in_fp >> user_type;

	control->showSignUp(out_fp, id, passwd, name, ssn, user_type);
}

// 출력함수
void AddMemberUI::menu1_1output(ofstream& out_fp, string id, string passwd, string name, string ssn, string user_type) {
	out_fp << "1.1. 회원가입" << endl;
	out_fp << "> " << id << " " << passwd << " " << name << " " << ssn << " " << user_type << endl << endl;

	cout << "1.1. 회원가입" << endl;
	cout << "> " << id << " " << passwd << " " << name << " " << ssn << " " << user_type << endl;
}

