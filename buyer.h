#ifndef __BUYER_H__
#define __BUYER_H__

#include "member.h"

// class : Buyer
// 설명 : member class를 상속받아 만든 buyer클래스
// 만든이 : 조용성 김영실
class Buyer : public Member {
private:
	vector<Ticket*> buyer_Tickets;
	int NumberOfBuyerTicket;
public:
	Buyer(string id, string passwd, string name, string ssn, string user_type);
	vector<Ticket*> getBuyer_Ticket();
	void setBuyer_Ticket(vector<Ticket*> t);
	int getNumberOfBuyerTicket();
	void setNumberOfBuyerTicket(int num);
	~Buyer();
	
};

#endif