#ifndef _MANAGEBUYERSTICKET_H__
#define _MANAGEBUYERSTICKET_H__

#include <iostream>
#include <fstream>

using namespace std;

// class : ManageBuyersTicket
// 설명 : 판매자의 등록티켓을 출력해주는 기능을 하는 control class
// 만든이 : 조용성
class ManageBuyersTicket {

private:
	ManageBuyersTicket();
	static ManageBuyersTicket* ManageBuyersTicketInstance;

public:
	~ManageBuyersTicket();
	static ManageBuyersTicket* getManageBuyersTicketInstance();
	void ManageBuyersTicketStart(ofstream& out_fp);
	void searchTicket(ofstream& out_fp);
	//ManageBuyersTicketUI 클래스를 멤버변수로 가지고 있음


};

#endif