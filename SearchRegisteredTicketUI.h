#ifndef _SEARCHREGISTETREDTICKETUI_H__
#define _SEARCHREGISTETREDTICKETUI_H__

#include <iostream>
#include <fstream>
#include "memberLister.h"
#include "session.h"

using namespace std;

// class : SearchRegisteredTicket
// 설명 : 판매자의 판매티켓 조회 기능의 control class
// 만든이 : 장유진
// 수정자 : 조용성
class SearchRegisteredTicketUI
{

private:
	static SearchRegisteredTicketUI* SearchRegisteredTicketUIInstance;
	SearchRegisteredTicketUI();

public:
	~SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* getSearchRegisteredTicketUIInstance();
	void startInterface(ofstream & out_fp);
	void menu3_2output(ofstream& out_fp, vector<Ticket*> temp_sellerTicket, int num_ticket);

};

#endif