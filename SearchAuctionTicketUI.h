#include <iostream>
#include <fstream>
#include "ticket.h"


using namespace std;

// class : SearchAuctionTicketUI
// ���� : ��� Ƽ�� ���� ����� boundary class
// ������ : ������
class SearchAuctionTicketUI
{

private:
	SearchAuctionTicketUI();
	static SearchAuctionTicketUI* SearchAuctionTicketUIInstance;

public:
	~SearchAuctionTicketUI();
	static SearchAuctionTicketUI* getSearchAuctionTicketUIInstance();
	void startInterface(ifstream & in_fp, ofstream& out_fp);
	void menu4_3output(ofstream& out_fp, Ticket* t);
};
