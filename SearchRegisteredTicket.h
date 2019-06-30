#ifndef _SEARCHREGISTETREDTICKET_H__
#define _SEARCHREGISTETREDTICKET_H__

#include <iostream>
#include <fstream>

using namespace std;

// class : SearchRegisteredTicket
// 설명 : 판매자의 판매티켓 조회 기능의 control class
// 만든이 : 장유진
// 수정자 : 조용성
class SearchRegisteredTicket {

private:
	SearchRegisteredTicket();
	static SearchRegisteredTicket* SearchRegisteredTicketInstance;

public:
	~SearchRegisteredTicket();
	static SearchRegisteredTicket* getSearchRegisteredTicketInstance();
	void SearchRegisteredTicketStart(ofstream& out_fp);
	void searchTicket(ofstream& out_fp);
	//SearchRegisteredTicketUI 클래스를 멤버변수로 가지고 있음


};

#endif