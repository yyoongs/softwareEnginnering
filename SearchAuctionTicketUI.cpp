#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicket.h"
#include "time.h"

SearchAuctionTicketUI::SearchAuctionTicketUI()
{
}


SearchAuctionTicketUI::~SearchAuctionTicketUI()
{
}

SearchAuctionTicketUI* SearchAuctionTicketUI::SearchAuctionTicketUIInstance = NULL;

SearchAuctionTicketUI* SearchAuctionTicketUI::getSearchAuctionTicketUIInstance() {
	if (SearchAuctionTicketUIInstance == NULL) {
		SearchAuctionTicketUIInstance = new SearchAuctionTicketUI();
	}
	return SearchAuctionTicketUIInstance;
}

void SearchAuctionTicketUI::startInterface(ifstream & in_fp, ofstream& out_fp) {
	SearchAuctionTicket* searchAuctionTicket = SearchAuctionTicket::getSearchAuctionTicketInstance();

	string home_team;
	in_fp >> home_team;

	searchAuctionTicket->showAuctionTicket(out_fp, home_team);
}

void SearchAuctionTicketUI::menu4_3output(ofstream& out_fp, Ticket* t) {
	Time* timer = Time::getTimetInstance();
	tm ticketTime = t->getDateAndTime();
	int differentTime = timer->differTime(ticketTime);

	out_fp << "4.3. 경매 중인 티켓 검색" << endl;
	cout << "4.3. 경매 중인 티켓 검색" << endl;
	out_fp << "> ";
	t->showDateAndTime(out_fp);
	out_fp << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << " " << differentTime << ":00" << endl;
	cout << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << " " << differentTime << ":00" << endl;
}