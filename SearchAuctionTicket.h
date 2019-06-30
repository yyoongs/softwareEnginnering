#include "ticket.h"
#include "AuctionTicket.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// class : SearchAuctionTicket
// 설명 : 경매 티켓 예약 기능의 control class
// 만든이 : 최유진
class SearchAuctionTicket {

private:
	SearchAuctionTicket();
	static SearchAuctionTicket* SearchAuctionTicketInstance;
	vector<Ticket*> auctionTicket; // 모든 티켓을 받아옴
	vector<Ticket*> auctionTicketList; // 받아온 티켓들 중 AuctionTicket에 해당하는 티켓만 리스트에 저장

public:
	~SearchAuctionTicket();
	static SearchAuctionTicket* getSearchAuctionTicketInstance();
	void SearchAuctionTicketStart(ifstream& in_fp, ofstream& out_fp);
	void showAuctionTicket(ofstream& out_fp, string home_team);
	vector<Ticket*> getAuctionTicketList();
};

