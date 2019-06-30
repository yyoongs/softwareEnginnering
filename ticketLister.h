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
// ���� : ��� Ƽ���� ������ �ִ� Ƽ�ϸ����͸� ���� ticket collection class
// ������ : �迵��
// ������ : ���뼺
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
	// Ƽ�ϸ���Ʈ�� �ش� Ƽ���� �ִ� �Լ�
	void addTicketList(Ticket* ticket);
	void setTicketList(int i);
	~TicketLister();

};

#endif 