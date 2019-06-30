#ifndef __SELLER_H__
#define __SELLER_H__

#include "member.h"
#include "time.h"

// class : Sellser
// ���� : member class�� ��ӹ޾� ���� seller class
// ������ : �迵��
// ������ : ���뼺
class Seller :public Member {
private:
	vector<Ticket*> seller_Tickets;
	vector<AuctionTicket*> seller_AuctionTickets;
	int NumberOfSellerTicket;
	int NumberOfSellerAuctionTicket;

public:
	Seller(string id, string passwd, string name, string ssn, string user_type);
	~Seller();
	vector<Ticket*> getSeller_Ticket();
	vector<AuctionTicket*> getSeller_AuctionTicket();

	void setSeller_Ticket(vector<Ticket*> t);
	void setSeller_AuctionTicket(vector<AuctionTicket*> t);
	
	int getNumberOfSellerTicket();
	int getNumberOfSellerAuctionTicket();

	void setNumberOfSellerTicket(int num);
	void setNumberOfSellerAuctionTicket(int num);

	void setSellerTicketList(vector<Ticket*> t);

};

#endif