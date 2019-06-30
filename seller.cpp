#include "seller.h"

Seller::Seller(string id, string passwd, string name, string ssn, string user_type)
{
	Seller::id = id;
	Seller::passwd = passwd;
	Seller::name = name;
	Seller::ssn = ssn;
	Seller::user_type = user_type;
	NumberOfSellerTicket = 0;
	NumberOfSellerAuctionTicket = 0;
}

vector<Ticket*> Seller::getSeller_Ticket() {
	return seller_Tickets;
}

void Seller::setSellerTicketList(vector<Ticket*> t) {
	seller_Tickets = t;
}

// seller의 ticketList에 저장할 때 시간 순서대로 저장하게 설정 (bubble sort)
// 2019.06.06 조용성
void Seller::setSeller_Ticket(vector<Ticket*> t) {
	Time* timer = Time::getTimetInstance();

	int i;
	int j;

	for (i = 0; i < NumberOfSellerTicket; i++)
	{
		for (j = 0; j < (NumberOfSellerTicket-1); j++)
		{
			tm ticketTime = t.at(j)->getDateAndTime();
			int first = timer->differTime(ticketTime); //시간차이 계산

			tm ticketTime2 = t.at(j+1)->getDateAndTime();
			int second = timer->differTime(ticketTime2); //시간차이 계산

			if (first > second)
			{
				t.insert(t.begin()+j, t.at(j + 1));
				t.erase(t.begin() + j + 2);
			}
		}
	}

	seller_Tickets = t;
}

vector<AuctionTicket*> Seller::getSeller_AuctionTicket() {
	return seller_AuctionTickets;
}
void Seller::setSeller_AuctionTicket(vector<AuctionTicket*> t) {
	seller_AuctionTickets = t;
}

int Seller::getNumberOfSellerTicket() {
	return NumberOfSellerTicket;
}

int Seller::getNumberOfSellerAuctionTicket() {
	return NumberOfSellerAuctionTicket;
}

void Seller::setNumberOfSellerTicket(int num) {
	NumberOfSellerTicket = num;
}

void Seller::setNumberOfSellerAuctionTicket(int num) {
	NumberOfSellerAuctionTicket = num;
}

Seller::~Seller()
{
}

