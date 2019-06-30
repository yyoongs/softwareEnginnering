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
	id = session_manage->getId();	//현재 세션의 아이디를 가져옴
	session_manage->setId("");	// 세션의 아이디를 ""로 변경 (guest id)
	session_manage->deleteSessionId(id); // Session class에서의 현재 로그인된 id list에서 로그아웃한 id를 지운다.

	boundaryUI->menu2_2output(out_fp, id); //로그아웃 했을때의 출력물
}