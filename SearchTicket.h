#include "ticket.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// class : SearchTicket
// ���� : Ƽ�� �˻� ����� control class
// ������ : �迵��
// ������ : ���뼺
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

