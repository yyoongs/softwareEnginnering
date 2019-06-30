#include <iostream>
#include <fstream>
#include "ticket.h"


using namespace std;

// class : SearchTicketUI
// 설명 : 티켓 검색 기능의 boundary class
// 만든이 : 김영실
// 수정자 : 조용성
class SearchTicketUI
{

private:
	SearchTicketUI();
	static SearchTicketUI* SearchTicketUIInstance;

public:
	~SearchTicketUI();
	static SearchTicketUI* getSearchTicketUIInstance();
	void startInterface(ifstream & in_fp, ofstream& out_fp);
	void menu4_1output1(ofstream& out_fp);
	void menu4_1output2(ofstream& out_fp, Ticket* t);
};
