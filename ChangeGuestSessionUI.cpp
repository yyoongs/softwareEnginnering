#include "ChangeGuestSessionUI.h"
#include "ChangeGuestSession.h"
#include <fstream>


ChangeGuestSessionUI::ChangeGuestSessionUI()
{

}


ChangeGuestSessionUI::~ChangeGuestSessionUI()
{
}

ChangeGuestSessionUI* ChangeGuestSessionUI::ChangeGuestSessionUIInstance = NULL; //static���� �ʱⰪ NULL ����

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

// ����Լ�
void ChangeGuestSessionUI::menu6_2output(ofstream& out_fp) {
	cout << "6.2. guest session���� ����" << endl;
	out_fp << "6.2. guest session���� ����" << endl << endl;;
}