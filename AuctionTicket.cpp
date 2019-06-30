#include "AuctionTicket.h"
#include <iostream>
#include <string>
#include <vector>
#include "ticket.h"
#include "session.h"

// 생성자
AuctionTicket::AuctionTicket(int price_t, tm game_date_time_t, string game_home_team_t, string game_away_team_t, string game_seat_number_t, bool auction_check_t) : Ticket(price_t, game_date_time_t, game_home_team_t, game_away_team_t, game_seat_number_t, auction_check_t)
{
	this->bid_price = price_t / 2;
}

// 생성자 오버로딩
AuctionTicket::AuctionTicket(int price_t, tm game_date_time_t, string game_home_team_t, string game_away_team_t, string game_seat_number_t, bool auction_check_t, int bid_price) : Ticket(price_t, game_date_time_t, game_home_team_t, game_away_team_t, game_seat_number_t, auction_check_t)
{
	Session* session_manage = Session::getSessionInstance();
	string id = session_manage->getId();

	this->bid_price = bid_price;
	this->buyer_id = id;
}

//소멸자
AuctionTicket::~AuctionTicket()
{
}


int AuctionTicket::getBidPrice() {
	return bid_price;
};

string AuctionTicket::getBuyerId() {
	return buyer_id;
}

//옥션티켓리스트에 넣어줌
void AuctionTicket::updateBidInfo(ofstream& out_fp, AuctionTicket* t, int bid_price){
	AT.push_back(t);
}

int AuctionTicket::getPrice() {
	return bid_price;
}