#include "ChangeGuestSession.h"
#include "ChangeGuestSessionUI.h"
#include "session.h"
#include <fstream>

ChangeGuestSession::ChangeGuestSession()
{

}


ChangeGuestSession::~ChangeGuestSession()
{
}


ChangeGuestSession* ChangeGuestSession::ChangeGuestSessionInstance = NULL; //static변수 초기값 NULL 설정

//싱글턴 생성
ChangeGuestSession* ChangeGuestSession::getChangeGuestSessionInstance() {
	if (ChangeGuestSessionInstance == NULL) {
		ChangeGuestSessionInstance = new ChangeGuestSession();
	}
	return ChangeGuestSessionInstance;
}


// 수행함수

void ChangeGuestSession::changeGuestSessionStart(ofstream& out_fp) {
	ChangeGuestSessionUI* boundaryUI = ChangeGuestSessionUI::getChangeGuestSessionUIInstance();
	boundaryUI->startInterface(out_fp);
}

//만든이 : 김영실
void ChangeGuestSession::ChangeGuest(ofstream& out_fp)
{
	ChangeGuestSessionUI* boundaryUI = ChangeGuestSessionUI::getChangeGuestSessionUIInstance();

	Session* session = Session::getSessionInstance();
	session->setId("");
	boundaryUI->menu6_2output(out_fp);
}
