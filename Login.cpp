#include "Login.h"
#include "LoginUI.h"
#include "session.h"

Login::Login()
{
}


Login::~Login()
{
}


Login* Login::LoginInstance = NULL;

Login* Login::getLoginInstance() {
	if (LoginInstance == NULL)
	{
		LoginInstance = new Login();
	}
	return LoginInstance;
}

void Login::LoginStart(ifstream& in_fp, ofstream& out_fp) {
	LoginUI* boundaryUI = LoginUI::getLoginUIInstance();
	boundaryUI->startInterface(in_fp, out_fp);
}


// ������ : �迵��
void Login::showLogin(ofstream& out_fp, string id, string passwd) {

	MemberLister* memberList = MemberLister::getMembersInstance();
	LoginUI* boundaryUI = LoginUI::getLoginUIInstance();

	for (int i = 0; i < memberList->getNumberOfMember(); i++) {
		// for���� ���鼭 member�� ���̵�� �н����尡 ��ġ�ϴ� ����� ���� ��
		if (id == memberList->getMembers().at(i)->getId() && passwd == memberList->getMembers().at(i)->getPasswd()) {
			Session* session_manage = Session::getSessionInstance();
			session_manage->setId(id);	//������ ���̵� �ش� ���̵�� ����
			session_manage->addSessionId(id); // Session class������ ���� �α��ε� id list�� �α����� id�� �߰��Ѵ�.

			boundaryUI->menu2_1output(out_fp, id, passwd); //��¹�
			return;
		}

	}

	//Ʋ����� �ٲ��� ����
	boundaryUI->menu2_1fail(out_fp);
}