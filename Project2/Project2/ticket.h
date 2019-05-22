#ifndef __TICKET_H__
#define __TICKET_H__

#include <string>
#include <iostream>

using namespace std;

class ticket
{
private:
	int price; //희망가격
	string game_date_time; //경기 날짜 및 시간
	string game_home_team; //홈팀
	string game_away_team; //어웨이팀
	int game_seat_number; //좌석위치
	bool auction_check; //경매선택여부

public:
	ticket();
	~ticket();

};

#endif