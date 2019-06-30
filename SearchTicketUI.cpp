#include "SearchTicketUI.h"
#include "SearchTicket.h"


SearchTicketUI::SearchTicketUI()
{
}


SearchTicketUI::~SearchTicketUI()
{
}

SearchTicketUI* SearchTicketUI::SearchTicketUIInstance = NULL;

SearchTicketUI* SearchTicketUI::getSearchTicketUIInstance() {
	if (SearchTicketUIInstance == NULL) {
		SearchTicketUIInstance = new SearchTicketUI();
	}
	return SearchTicketUIInstance;
}

void SearchTicketUI::startInterface(ifstream & in_fp, ofstream& out_fp) {
	SearchTicket* searchTicket = SearchTicket::getSearchTicketInstance();

	string home_team;
	in_fp >> home_team;

	searchTicket->showTicket(out_fp, home_team);
}

void SearchTicketUI::menu4_1output1(ofstream& out_fp) {
	cout << "4.1. 티켓 검색" << endl;
	out_fp << "4.1. 티켓 검색" << endl;
}

void SearchTicketUI::menu4_1output2(ofstream& out_fp, Ticket* t) {
	cout << "> " << t->getPrice() << " ";
	out_fp << "> " << t->getPrice() << " ";
	t->showDateAndTime(out_fp);
	cout << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << endl;
	out_fp << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << endl << endl;
}