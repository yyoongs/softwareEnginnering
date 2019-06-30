#include "SearchRegisteredTicketUI.h"
#include "SearchRegisteredTicket.h"


SearchRegisteredTicketUI::SearchRegisteredTicketUI()
{

}


SearchRegisteredTicketUI::~SearchRegisteredTicketUI()
{
}




SearchRegisteredTicketUI* SearchRegisteredTicketUI::SearchRegisteredTicketUIInstance = NULL;

SearchRegisteredTicketUI* SearchRegisteredTicketUI::getSearchRegisteredTicketUIInstance() {
	if (SearchRegisteredTicketUIInstance == NULL) {
		SearchRegisteredTicketUIInstance = new SearchRegisteredTicketUI();
	}
	return SearchRegisteredTicketUIInstance;
}

void SearchRegisteredTicketUI::startInterface(ofstream & out_fp) {
	SearchRegisteredTicket* control = SearchRegisteredTicket::getSearchRegisteredTicketInstance();
	control->searchTicket(out_fp);
}


void SearchRegisteredTicketUI::menu3_2output(ofstream& out_fp, vector<Ticket*> temp_sellerTicket, int num_ticket) {

	cout << "3.2. 등록티켓 조회" << endl;
	out_fp << "3.2. 등록티켓 조회" << endl;

	for (int i = 0; i < num_ticket; i++) {
		Ticket* t = temp_sellerTicket.at(i);

		cout << "> " << t->getPrice() << " ";
		out_fp << "> " << t->getPrice() << " ";
		t->showDateAndTime(out_fp);

		cout << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << " " <<
			t->getAuctionChoice() << " " << t->getAvailableSale() << endl<<endl;

		out_fp << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << " " <<
			t->getAuctionChoice() << " " << t->getAvailableSale() << endl << endl << endl;
	}
}