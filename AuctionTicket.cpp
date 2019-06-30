#include "AuctionTicket.h"
#include <iostream>
#include <string>
#include <vector>
#include "ticket.h"
#include "session.h"

// ������
AuctionTicket::AuctionTicket(int price_t, tm game_date_time_t, string game_home_team_t, string game_away_team_t, string game_seat_number_t, bool auction_check_t) : Ticket(price_t, game_date_time_t, game_home_team_t, game_away_team_t, game_seat_number_t, auction_check_t)
{
	this->bid_price = price_t / 2;
}

// ������ �����ε�
AuctionTicket::AuctionTicket(int price_t, tm game_date_time_t, string game_home_team_t, string game_away_team_t, string game_seat_number_t, bool auction_check_t, int bid_price) : Ticket(price_t, game_date_time_t, game_home_team_t, game_away_team_t, game_seat_number_t, auction_check_t)
{
	Session* session_manage = Session::getSessionInstance();
	string id = session_manage->getId();

	this->bid_price = bid_price;
	this->buyer_id = id;
}

//�Ҹ���
AuctionTicket::~AuctionTicket()
{
}


int AuctionTicket::getBidPrice() {
	return bid_price;
};

string AuctionTicket::getBuyerId() {
	return buyer_id;
}

//����Ƽ�ϸ���Ʈ�� �־���
void AuctionTicket::updateBidInfo(ofstream& out_fp, AuctionTicket* t, int bid_price){
	AT.push_back(t);
}

int AuctionTicket::getPrice() {
	return bid_price;
}