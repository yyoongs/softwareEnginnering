#ifndef _MANAGEBUYERSTICKET_H__
#define _MANAGEBUYERSTICKET_H__

#include <iostream>
#include <fstream>

using namespace std;

// class : ManageBuyersTicket
// ���� : �Ǹ����� ���Ƽ���� ������ִ� ����� �ϴ� control class
// ������ : ���뼺
class ManageBuyersTicket {

private:
	ManageBuyersTicket();
	static ManageBuyersTicket* ManageBuyersTicketInstance;

public:
	~ManageBuyersTicket();
	static ManageBuyersTicket* getManageBuyersTicketInstance();
	void ManageBuyersTicketStart(ofstream& out_fp);
	void searchTicket(ofstream& out_fp);
	//ManageBuyersTicketUI Ŭ������ ��������� ������ ����


};

#endif