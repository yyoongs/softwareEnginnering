#include "buyer.h"
#include "time.h"

Buyer::Buyer(string id, string passwd, string name, string ssn, string user_type)
{
	Buyer::id = id;
	Buyer::passwd = passwd;
	Buyer::name = name;
	Buyer::ssn = ssn;
	Buyer::user_type = user_type;
	NumberOfBuyerTicket = 0;
}


vector<Ticket*> Buyer::getBuyer_Ticket() {
	return buyer_Tickets;
}

int Buyer::getNumberOfBuyerTicket() {
	return NumberOfBuyerTicket;
}
void Buyer::setNumberOfBuyerTicket(int num) {
	NumberOfBuyerTicket = num;
}

Buyer::~Buyer()
{
}


// buyer의 ticketList에 저장할 때 시간 순서대로 저장하게 설정
void Buyer::setBuyer_Ticket(vector<Ticket*> t) {
	Time* timer = Time::getTimetInstance();

	int i;
	int j;

	for (i = 0; i < NumberOfBuyerTicket; i++)
	{
		for (j = 0; j < (NumberOfBuyerTicket - 1); j++)
		{
			tm ticketTime = t.at(j)->getDateAndTime();
			int first = timer->differTime(ticketTime); //시간차이 계산

			tm ticketTime2 = t.at(j + 1)->getDateAndTime();
			int second = timer->differTime(ticketTime2); //시간차이 계산

			if (first > second)
			{
				t.insert(t.begin() + j, t.at(j + 1));
				t.erase(t.begin() + j + 2);
			}
		}
	}

	buyer_Tickets = t;
}