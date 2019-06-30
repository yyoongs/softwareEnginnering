#include "ticket.h"
#include "AuctionTicket.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// class : SearchAuctionTicket
// ���� : ��� Ƽ�� ���� ����� control class
// ������ : ������
class SearchAuctionTicket {

private:
	SearchAuctionTicket();
	static SearchAuctionTicket* SearchAuctionTicketInstance;
	vector<Ticket*> auctionTicket; // ��� Ƽ���� �޾ƿ�
	vector<Ticket*> auctionTicketList; // �޾ƿ� Ƽ�ϵ� �� AuctionTicket�� �ش��ϴ� Ƽ�ϸ� ����Ʈ�� ����

public:
	~SearchAuctionTicket();
	static SearchAuctionTicket* getSearchAuctionTicketInstance();
	void SearchAuctionTicketStart(ifstream& in_fp, ofstream& out_fp);
	void showAuctionTicket(ofstream& out_fp, string home_team);
	vector<Ticket*> getAuctionTicketList();
};

