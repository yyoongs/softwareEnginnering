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


ChangeGuestSession* ChangeGuestSession::ChangeGuestSessionInstance = NULL; //static���� �ʱⰪ NULL ����

//�̱��� ����
ChangeGuestSession* ChangeGuestSession::getChangeGuestSessionInstance() {
	if (ChangeGuestSessionInstance == NULL) {
		ChangeGuestSessionInstance = new ChangeGuestSession();
	}
	return ChangeGuestSessionInstance;
}


// �����Լ�

void ChangeGuestSession::changeGuestSessionStart(ofstream& out_fp) {
	ChangeGuestSessionUI* boundaryUI = ChangeGuestSessionUI::getChangeGuestSessionUIInstance();
	boundaryUI->startInterface(out_fp);
}

//������ : �迵��
void ChangeGuestSession::ChangeGuest(ofstream& out_fp)
{
	ChangeGuestSessionUI* boundaryUI = ChangeGuestSessionUI::getChangeGuestSessionUIInstance();

	Session* session = Session::getSessionInstance();
	session->setId("");
	boundaryUI->menu6_2output(out_fp);
}
