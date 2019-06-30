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
	
	// getTicketList 함수를 통해 모든 티켓을 불러옴
	TicketLister* TL = TicketLister::getTicketsInstance();
	auctionTicket = TL->getTicketList();

	// <<boundary>> SearchAuctionTicketUI 생성 및 실행
	boundaryUI->startInterface(in_fp,out_fp);
}

// 경매티켓 검색 기능 수행 함수
// 만든이 : 최유진
void SearchAuctionTicket::showAuctionTicket(ofstream& out_fp, string home_team){
	SearchAuctionTicketUI* boundaryUI = SearchAuctionTicketUI::getSearchAuctionTicketUIInstance();
	Time *timeManager = Time::getTimetInstance();

	for (int i = 0; i < auctionTicket.size(); i++)
	{
		// 경매선택여부와 티켓의 시간을 확인해 경매티켓인지 확인
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