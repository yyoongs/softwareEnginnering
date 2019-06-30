#include "ChangeGuestSessionUI.h"
#include "ChangeGuestSession.h"
#include <fstream>


ChangeGuestSessionUI::ChangeGuestSessionUI()
{

}


ChangeGuestSessionUI::~ChangeGuestSessionUI()
{
}

ChangeGuestSessionUI* ChangeGuestSessionUI::ChangeGuestSessionUIInstance = NULL; //static변수 초기값 NULL 설정

ChangeGuestSessionUI* ChangeGuestSessionUI::getChangeGuestSessionUIInstance() {
	if (ChangeGuestSessionUIInstance == NULL) {
		ChangeGuestSessionUIInstance = new ChangeGuestSessionUI();
	}
	return ChangeGuestSessionUIInstance;
}

void ChangeGuestSessionUI::startInterface(ofstream& out_fp) {
	ChangeGuestSession* control = ChangeGuestSession::getChangeGuestSessionInstance();
	control->ChangeGuest(out_fp);
};

// 출력함수
void ChangeGuestSessionUI::menu6_2output(ofstream& out_fp) {
	cout << "6.2. guest session으로 변경" << endl;
	out_fp << "6.2. guest session으로 변경" << endl << endl;;
}