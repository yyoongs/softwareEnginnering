#include "ChangeUserSession.h"
#include "ChangeUserSessionUI.h"
#include "session.h"
#include <fstream>

ChangeUserSession::ChangeUserSession()
{

}


ChangeUserSession::~ChangeUserSession()
{
}


ChangeUserSession* ChangeUserSession::ChangeUserSessionInstance = NULL; //static���� �ʱⰪ NULL ����

ChangeUserSession* ChangeUserSession::getChangeUserSessionInstance() {
	if (ChangeUserSessionInstance == NULL) {
		ChangeUserSessionInstance = new ChangeUserSession();
	}
	return ChangeUserSessionInstance;
}



void ChangeUserSession::ChangeUserSessionStart(ifstream& in_fp, ofstream& out_fp) {
	ChangeUserSessionUI* boundaryUI = ChangeUserSessionUI::getChangeUserSessionUIInstance();
	boundaryUI->startInterface(in_fp, out_fp);
}



void ChangeUserSession::ChangeUser(ofstream& out_fp, string input_id) {
	bool id_exist = false;
	int index;
	ChangeUserSessionUI* boundaryUI = ChangeUserSessionUI::getChangeUserSessionUIInstance();
	Session* session = Session::getSessionInstance();
	vector<string> login_Id_list = session->getIdList();
	for (int i = 0; i < login_Id_list.size(); i++) {
		if (input_id == login_Id_list.at(i)) {
			id_exist = true;
			index = i;
			break;
		}
	}		// for���� ���鼭 ��� ���͵��߿� ����� ���̵� ���� �Էµ� id�� �������
			// �� ��� ������ �ε����� ��ȯ
	if (id_exist) {
		session->setId(input_id);
		boundaryUI->menu6_1output(out_fp, input_id);
	}
	else {
		boundaryUI->menu6_1fail(out_fp);
	}
}// session class�� id�� �Է¹��� input_id�� ���� 
