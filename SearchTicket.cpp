#include "SearchTicket.h"
#include "SearchTicketUI.h"
#include "ticketLister.h"

SearchTicket::SearchTicket()
{
}


SearchTicket::~SearchTicket()
{
}

SearchTicket* SearchTicket::SearchTicketInstance = NULL;

SearchTicket* SearchTicket::getSearchTicketInstance() {
	if (SearchTicketInstance == NULL) {
		SearchTicketInstance = new SearchTicket();
	}
	return SearchTicketInstance;
}

void SearchTicket::SearchTicketStart(ifstream& in_fp, ofstream& out_fp)
{
	SearchTicketUI* boundaryUI = SearchTicketUI::getSearchTicketUIInstance();

	boundaryUI->startInterface(in_fp, out_fp);
}

void SearchTicket::showTicket(ofstream& out_fp, string home_team) {
	SearchTicketUI* boundaryUI = SearchTicketUI::getSearchTicketUIInstance();
	Time *timeManager = Time::getTimetInstance();
	TicketLister* ticketLister = TicketLister::getTicketsInstance();
	int NumOfTicket = ticketLister->getNumOfTicket();
	vector<Ticket*> tickets = ticketLister->getTicketList();
	Ticket* t;
	//2019.05.30 Á¶¿ë¼º
	boundaryUI->menu4_1output1(out_fp);
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		if (t->getAvailableSale() == true && t->getHometeam() == home_team) {
			boundaryUI->menu4_1output2(out_fp, t);
		}
	}
}
