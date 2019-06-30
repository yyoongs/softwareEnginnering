#include "ReserveTicketUI.h"
#include "ReserveTicket.h"


ReserveTicketUI::ReserveTicketUI()
{
}


ReserveTicketUI::~ReserveTicketUI()
{
}

ReserveTicketUI* ReserveTicketUI::ReserveTicketUIInstance = NULL;

ReserveTicketUI* ReserveTicketUI::getReserveTicketUIInstance() {
	if (ReserveTicketUIInstance == NULL) {
		ReserveTicketUIInstance = new ReserveTicketUI();
	}
	return ReserveTicketUIInstance;
}

void ReserveTicketUI::startInterface(ifstream & in_fp, ofstream& out_fp) {
	ReserveTicket* ReserveTicket = ReserveTicket::getReserveTicketInstance();

	string dateAndTime, away, seat;
	in_fp >> dateAndTime;
	in_fp >> away;
	in_fp >> seat;

	ReserveTicket->reserveTicket(out_fp, dateAndTime,away,seat);
}

// 출력함수
void ReserveTicketUI::menu4_2output(ofstream& out_fp, Ticket* t) {
	cout << "4.2. 티켓 예약" << endl;
	out_fp << "4.2. 티켓 예약" << endl;

	cout << "> " << t->getPrice() << " ";
	out_fp << "> " << t->getPrice() << " ";
	t->showDateAndTime(out_fp);
	cout << " " << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << endl;
	out_fp << " " << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << endl << endl;
}