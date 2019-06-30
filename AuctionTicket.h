#ifndef __AUCTIONTICKET_H__
#define __AUCTIONTICKET_H__

#include <string>
#include <iostream>
#include <vector>
#include "ticket.h"

using namespace std;


// class : AuctionTicket
// 설명 : 경매 티켓 선언 함수
// 만든이 : 조용성
// 수정자 : 최유진
class AuctionTicket :
	public Ticket
{
private:
	int bid_price;	//경매금액
	string buyer_id; //입찰자 id
	vector<AuctionTicket*> AT; //경매에 참여한 티켓 리스트

public:
	AuctionTicket(int price_t, tm game_date_time_t, string game_home_team_t, string game_away_team_t, string game_seat_number_t, bool auction_check_t);
	AuctionTicket(int price_t, tm game_date_time_t, string game_home_team_t, string game_away_team_t, string game_seat_number_t, bool auction_check_t, int bid_price);
	~AuctionTicket();
	void updateBidInfo(ofstream& out_fp, AuctionTicket* t, int bid_price);
	int getBidPrice();
	string getBuyerId();
	int getPrice();
};

#endif