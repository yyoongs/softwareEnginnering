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

	string game_date_time; //경기 날짜 및 시간
	string game_away_team; //어웨이팀
	string game_seat_number; //좌석위치
	int bid_price;

	in_fp >> game_date_time;
	in_fp >> game_away_team;
	in_fp >> game_seat_number;
	in_fp >> bid_price;

	//string으로 입력받은 game_date_time을 struct time함수로 알맞게 변경해줌 
	struct tm inputTime = timeManager->timeTypeSetting(game_date_time);

	BidForTicketControl->bidForTicket(out_fp, inputTime, game_away_team, game_seat_number, bid_price);
}

// 출력함수
void BidForTicketUI::menu4_4output(ofstream& out_fp, int bid_price) {
	out_fp << "4.4 경매 참여" << endl << endl;
	out_fp << "> " << bid_price << endl << endl;
	cout << "4.4 경매 참여" << endl;
	cout << "> " << bid_price << endl;
}