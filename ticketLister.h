#ifndef __TICKETLISTER_H__
#define __TICKETLISTER_H__


#include "ticket.h"
#include "AuctionTicket.h"
#include "time.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

// class : TicketLister
// 설명 : 모든 티켓을 가지고 있는 티켓리스터를 가진 ticket collection class
// 만든이 : 김영실
// 수정자 : 조용성
class TicketLister {
private:
	static TicketLister* ticketsInstance;
	vector<Ticket*> tickets;
	int NumOfTicket;
	TicketLister();

public:
	static TicketLister* getTicketsInstance();
	int getNumOfTicket();
	void setNumOfTicket(int num);
	void TicketUpdate();
	void TicketExpired();
	void TicketDelete();
	vector<Ticket*> getTicketList();
	// 티켓리스트에 해당 티켓을 넣는 함수
	void addTicketList(Ticket* ticket);
	void setTicketList(int i);
	~TicketLister();

};

#endif 