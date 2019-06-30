#include "SearchAuctionTicket.h"
#include "SearchAuctionTicketUI.h"
#include "ticketLister.h"

SearchAuctionTicket::SearchAuctionTicket()
{
}


SearchAuctionTicket::~SearchAuctionTicket()
{
}

SearchAuctionTicket* SearchAuctionTicket::SearchAuctionTicketInstance = NULL;

SearchAuctionTicket* SearchAuctionTicket::getSearchAuctionTicketInstance() {
	if (SearchAuctionTicketInstance == NULL) {
		SearchAuctionTicketInstance = new SearchAuctionTicket();
	}
	return SearchAuctionTicketInstance;
}

void SearchAuctionTicket::SearchAuctionTicketStart(ifstream& in_fp, ofstream& out_fp)
{
	SearchAuctionTicketUI* boundaryUI = SearchAuctionTicketUI::getSearchAuctionTicketUIInstance();
	
	// getTicketList �Լ��� ���� ��� Ƽ���� �ҷ���
	TicketLister* TL = TicketLister::getTicketsInstance();
	auctionTicket = TL->getTicketList();

	// <<boundary>> SearchAuctionTicketUI ���� �� ����
	boundaryUI->startInterface(in_fp,out_fp);
}

// ���Ƽ�� �˻� ��� ���� �Լ�
// ������ : ������
void SearchAuctionTicket::showAuctionTicket(ofstream& out_fp, string home_team){
	SearchAuctionTicketUI* boundaryUI = SearchAuctionTicketUI::getSearchAuctionTicketUIInstance();
	Time *timeManager = Time::getTimetInstance();

	for (int i = 0; i < auctionTicket.size(); i++)
	{
		// ��ż��ÿ��ο� Ƽ���� �ð��� Ȯ���� ���Ƽ������ Ȯ��
		if (auctionTicket.at(i)->getAuctionChoice() == 1 && timeManager->differTime(auctionTicket.at(i)->getDateAndTime()) < 24)
		{
			auctionTicketList.push_back(auctionTicket.at(i));
			if (home_team == auctionTicket.at(i)->getHometeam())
			{
				boundaryUI->menu4_3output(out_fp, auctionTicket.at(i));
			}
				
		}
	}
}

vector<Ticket*> SearchAuctionTicket::getAuctionTicketList(){
	return auctionTicketList;
}