#include <iostream>
#include <fstream>
#include "ticket.h"


using namespace std;

// class : SearchAuctionTicketUI
// 설명 : 경매 티켓 예약 기능의 boundary class
// 만든이 : 최유진
class SearchAuctionTicketUI
{

private:
	SearchAuctionTicketUI();
	static SearchAuctionTicketUI* SearchAuctionTicketUIInstance;

public:
	~SearchAuctionTicketUI();
	static SearchAuctionTicketUI* getSearchAuctionTicketUIInstance();
	void startInterface(ifstream & in_fp, ofstream& out_fp);
	void menu4_3output(ofstream& out_fp, Ticket* t);
};
