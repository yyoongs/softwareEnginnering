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


// 만든이 : 김영실
void Login::showLogin(ofstream& out_fp, string id, string passwd) {

	MemberLister* memberList = MemberLister::getMembersInstance();
	LoginUI* boundaryUI = LoginUI::getLoginUIInstance();

	for (int i = 0; i < memberList->getNumberOfMember(); i++) {
		// for문을 돌면서 member의 아이디와 패스워드가 일치하는 멤버가 있을 때
		if (id == memberList->getMembers().at(i)->getId() && passwd == memberList->getMembers().at(i)->getPasswd()) {
			Session* session_manage = Session::getSessionInstance();
			session_manage->setId(id);	//세션의 아이디를 해당 아이디로 설정
			session_manage->addSessionId(id); // Session class에서의 현재 로그인된 id list에 로그인한 id를 추가한다.

			boundaryUI->menu2_1output(out_fp, id, passwd); //출력물
			return;
		}

	}

	//틀릴경우 바뀌지 않음
	boundaryUI->menu2_1fail(out_fp);
}