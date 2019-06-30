#include "BidForTicketUI.h"
#include "BidForTicket.h"
#include "time.h"


BidForTicketUI::BidForTicketUI()
{
}


BidForTicketUI::~BidForTicketUI()
{
}

BidForTicketUI* BidForTicketUI::BidForTicketUIInstance = NULL;

BidForTicketUI* BidForTicketUI::getBidForTicketUIInstance() {
	if (BidForTicketUIInstance == NULL) {
		BidForTicketUIInstance = new BidForTicketUI();
	}
	return BidForTicketUIInstance;
}

void BidForTicketUI::startInterface(ifstream & in_fp, ofstream& out_fp){
	BidForTicket* BidForTicketControl = BidForTicket::getBidForTicketInstance();
	Time *timeManager = Time::getTimetInstance();

	string game_date_time; //��� ��¥ �� �ð�
	string game_away_team; //�������
	string game_seat_number; //�¼���ġ
	int bid_price;

	in_fp >> game_date_time;
	in_fp >> game_away_team;
	in_fp >> game_seat_number;
	in_fp >> bid_price;

	//string���� �Է¹��� game_date_time�� struct time�Լ��� �˸°� �������� 
	struct tm inputTime = timeManager->timeTypeSetting(game_date_time);

	BidForTicketControl->bidForTicket(out_fp, inputTime, game_away_team, game_seat_number, bid_price);
}

// ����Լ�
void BidForTicketUI::menu4_4output(ofstream& out_fp, int bid_price) {
	out_fp << "4.4 ��� ����" << endl << endl;
	out_fp << "> " << bid_price << endl << endl;
	cout << "4.4 ��� ����" << endl;
	cout << "> " << bid_price << endl;
}