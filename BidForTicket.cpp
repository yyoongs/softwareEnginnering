#include "BidForTicket.h"
#include "BidForTicketUI.h"
#include "SearchAuctionTicket.h"
#include "time.h"
#include "session.h"
#include "memberLister.h"

BidForTicket::BidForTicket()
{
}


BidForTicket::~BidForTicket()
{
}


BidForTicket* BidForTicket::BidForTicketInstance = NULL;

BidForTicket* BidForTicket::getBidForTicketInstance() {
	if (BidForTicketInstance == NULL) {
		BidForTicketInstance = new BidForTicket();
	}
	return BidForTicketInstance;
}

// control class를 처음 시작시키는 함수
void BidForTicket::BidForTicketStart(ifstream& in_fp, ofstream& out_fp){
	BidForTicketUI* boundaryUI = BidForTicketUI::getBidForTicketUIInstance();

	SearchAuctionTicket* SearchAuctionTicket = SearchAuctionTicket::getSearchAuctionTicketInstance();

	bidAuctionTicketList = SearchAuctionTicket->getAuctionTicketList();
	boundaryUI->startInterface(in_fp, out_fp);
}


// 티켓 입찰 기능을 수행하는 함수
// 입력정와 일치한 티켓일 경우 티켓의 정보를 업데이트 하고 buyer의 티켓리스트에 넣어줌
// 만든이 : 최유진
// 수정자 : 조용성
void BidForTicket::bidForTicket(ofstream& out_fp, tm inputTime, string game_away_team, string game_seat_number, int bid_price){
	BidForTicketUI* boundaryUI = BidForTicketUI::getBidForTicketUIInstance();
	Ticket* t = bidAuctionTicketList.at(0);
	Time *timeManager = Time::getTimetInstance();
	int check = 0;

	// 입력정보와 티켓이 일치할 때 
	for (int i = 0; i < bidAuctionTicketList.size(); i++)
	{
		if (game_away_team == bidAuctionTicketList.at(i)->getAwayteam() && game_seat_number== bidAuctionTicketList.at(i)->getSeatPosition())
		{
			if (timeManager->differTime(inputTime) == timeManager->differTime(bidAuctionTicketList.at(i)->getDateAndTime()))
			{
				t = bidAuctionTicketList.at(i);
				check = 1;
				break;
			}
		}
	}

	//옥션티켓을 업데이트
	AuctionTicket* bid_ticket = new AuctionTicket(t->getPrice(), t->getDateAndTime(), t->getHometeam(), t->getAwayteam(), t->getSeatPosition(), t->getAuctionChoice(), bid_price);

	if (check==1)
		bid_ticket->updateBidInfo(out_fp, bid_ticket, bid_price);

	string id;
	int num_member,index,num_ticket;
	//buyer의 구매리스트에 추가해줘야함
	Session* session_manage = Session::getSessionInstance();
	id = session_manage->getId();
	MemberLister* members__manage = MemberLister::getMembersInstance();
	num_member = members__manage->getNumberOfMember();
	vector<Member*> temp_members = members__manage->getMembers();

	for (int i = 0; i < num_member; i++) {
		if (id == temp_members.at(i)->getId()) {
			index = i;
			break;
		}
	}
	Buyer* temp_member = (Buyer*)temp_members.at(index);
	vector<Ticket*> temp_buyerTicket = temp_member->getBuyer_Ticket();
	num_ticket = temp_member->getNumberOfBuyerTicket();

	temp_buyerTicket.push_back(bid_ticket);
	temp_member->setBuyer_Ticket(temp_buyerTicket);
	num_ticket++;
	temp_member->setNumberOfBuyerTicket(num_ticket);

	//출력
	boundaryUI->menu4_4output(out_fp, bid_price);

}