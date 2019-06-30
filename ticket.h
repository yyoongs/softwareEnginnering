#ifndef __TICKET_H__
#define __TICKET_H__

#include <string>

using namespace std;

// class : Ticket
// 설명 : ticket의 정보가 저장되는 ticket class
// 만든이 : 조용성
class Ticket
{
protected:
	int price; //희망가격
	//조용성
	struct tm game_date_time; //경기 날짜 및 시간
	string game_home_team; //홈팀
	string game_away_team; //어웨이팀
	string game_seat_number; //좌석위치
	bool auction_check; //경매선택여부
	bool availableSale;

public:
	Ticket(int price_t, tm game_date_time_t, string game_home_team_t,string game_away_team_t,
		string game_seat_number_t,bool auction_check_t);
	~Ticket();

	int getPrice();
	//조용성
	tm getDateAndTime();
	string getHometeam();
	string getAwayteam();
	string getSeatPosition();
	bool getAuctionChoice();
	bool getAvailableSale();
	void setAvailableSale(bool a);
	void showDateAndTime(ofstream& out_fp);
	bool checkDateAndTime(string dateAndTime);
};	

#endif
