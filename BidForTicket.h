#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ticket.h"

using namespace std;

// class : BidForTicket
// 설명 : 경매 참여 기능의 control class
// 만든이 : 최유진
class BidForTicket
{
private:
	BidForTicket();
	static BidForTicket* BidForTicketInstance;
	vector<Ticket*> bidAuctionTicketList;
	
public:
	~BidForTicket();
	static BidForTicket* getBidForTicketInstance();
	void BidForTicketStart(ifstream& in_fp, ofstream& out_fp);
	void bidForTicket(ofstream& out_fp, tm inputTime, string game_away_team, string game_seat_number, int bid_price);
};