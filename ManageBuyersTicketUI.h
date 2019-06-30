#ifndef _MANAGEBUYERSTICKETUI_H__
#define _MANAGEBUYERSTICKETUI_H__

#include <iostream>
#include <fstream>
#include "memberLister.h"
#include "session.h"

using namespace std;

// class : ManageBuyersTicketUI
// ���� : �Ǹ����� ���Ƽ���� ������ִ� ����� �ϴ� boundary class
// ������ : ���뼺
class ManageBuyersTicketUI
{

private:
	static ManageBuyersTicketUI* ManageBuyersTicketUIInstance;
	ManageBuyersTicketUI();

public:
	~ManageBuyersTicketUI();
	static ManageBuyersTicketUI* getManageBuyersTicketUIInstance();
	void startInterface(ofstream & out_fp);
	void menu4_5output(ofstream& out_fp, vector<Ticket*> temp_buyerTicket, int num_ticket);

};

#endif