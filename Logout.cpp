#include "Logout.h"
#include "LogoutUI.h"
#include "session.h"

Logout :: Logout()
{
}

Logout :: ~Logout()
{
}

Logout* Logout::logoutInstance = NULL;

Logout* Logout::getLogoutInstance() {
	if (logoutInstance == NULL)
	{
		logoutInstance = new Logout();
	}
	return logoutInstance;
}

void Logout::logOutStart(ofstream& out_fp) {
	LogoutUI* boundaryUI = LogoutUI::getLogoutUIInstance();
	boundaryUI->startInterface(out_fp);
}

void Logout ::showLogout(ofstream& out_fp) {
	LogoutUI* boundaryUI = LogoutUI::getLogoutUIInstance();
	string id;
	Session* session_manage = Session::getSessionInstance();
	id = session_manage->getId();	//���� ������ ���̵� ������
	session_manage->setId("");	// ������ ���̵� ""�� ���� (guest id)
	session_manage->deleteSessionId(id); // Session class������ ���� �α��ε� id list���� �α׾ƿ��� id�� �����.

	boundaryUI->menu2_2output(out_fp, id); //�α׾ƿ� �������� ��¹�
}