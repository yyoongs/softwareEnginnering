#ifndef __AUCTIONTICKET_H__
#define __AUCTIONTICKET_H__

#include <string>
#include <iostream>
#include <vector>
#include "ticket.h"

using namespace std;


// class : AuctionTicket
// ���� : ��� Ƽ�� ���� �Լ�
// ������ : ���뼺
// ������ : ������
class AuctionTicket :
	public Ticket
{
private:
	int bid_price;	//��űݾ�
	string buyer_id; //������ id
	vector<AuctionTicket*> AT; //��ſ� ������ Ƽ�� ����Ʈ

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