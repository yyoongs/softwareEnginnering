#include "ticket.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// class : SearchTicket
// 설명 : 티켓 검색 기능의 control class
// 만든이 : 김영실
// 수정자 : 조용성
class SearchTicket {

private:
	SearchTicket();
	static SearchTicket* SearchTicketInstance;

public:
	~SearchTicket();
	static SearchTicket* getSearchTicketInstance();
	void SearchTicketStart(ifstream& in_fp, ofstream& out_fp);
	void showTicket(ofstream& out_fp, string home_team);
};

