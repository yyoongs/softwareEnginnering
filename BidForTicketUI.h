#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// class : BidForTicketUI
// ���� : ��� ���� ����� boundary class
// ������ : ������
class BidForTicketUI
{
private:
	BidForTicketUI();
	static BidForTicketUI* BidForTicketUIInstance;

public:
	~BidForTicketUI();
	static BidForTicketUI* getBidForTicketUIInstance();
	void startInterface(ifstream & in_fp, ofstream& out_fp);
	void menu4_4output(ofstream& out_fp, int bid_price);
};