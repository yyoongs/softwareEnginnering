#include "WithdrawMemberUI.h"
#include "WithdrawMember.h"


WithdrawMemberUI::WithdrawMemberUI()
{
}


WithdrawMemberUI::~WithdrawMemberUI()
{
}

WithdrawMemberUI*WithdrawMemberUI::withdrawMemberUIInstance = NULL;

WithdrawMemberUI* WithdrawMemberUI::getWithdrawMemberUIInstance() {
	if (withdrawMemberUIInstance == NULL)
	{
		withdrawMemberUIInstance = new WithdrawMemberUI();
	}
	return withdrawMemberUIInstance;
}

void WithdrawMemberUI::menu1_2output(ofstream& out_fp, string id) {
	cout << "1.2. ȸ��Ż��" << endl;
	cout << "> " << id << endl;
	out_fp << "1.2. ȸ��Ż��" << endl;
	out_fp << "> " << id << endl << endl;
}

void WithdrawMemberUI::menu1_2fail(ofstream& out_fp) {
	cout << "1.2. ȸ��Ż��" << endl;
	cout << "> ȸ��Ż�� �Ұ���" << endl;
	out_fp << "1.2. ȸ��Ż��" << endl;
	out_fp << "> ȸ��Ż�� �Ұ���" << endl << endl;
}

void WithdrawMemberUI::startInterface(ifstream & in_fp, ofstream& out_fp) {
	WithdrawMember *control = WithdrawMember::getWithdrawMemberInstance();
	string id, passwd, name, ssn, user_type;
	in_fp >> id;
	in_fp >> passwd;
	in_fp >> name;
	in_fp >> ssn;
	in_fp >> user_type;

	control->showWithdraw(out_fp);

}