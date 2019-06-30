#ifndef __TICKET_H__
#define __TICKET_H__

#include <string>

using namespace std;

// class : Ticket
// ���� : ticket�� ������ ����Ǵ� ticket class
// ������ : ���뼺
class Ticket
{
protected:
	int price; //�������
	//���뼺
	struct tm game_date_time; //��� ��¥ �� �ð�
	string game_home_team; //Ȩ��
	string game_away_team; //�������
	string game_seat_number; //�¼���ġ
	bool auction_check; //��ż��ÿ���
	bool availableSale;

public:
	Ticket(int price_t, tm game_date_time_t, string game_home_team_t,string game_away_team_t,
		string game_seat_number_t,bool auction_check_t);
	~Ticket();

	int getPrice();
	//���뼺
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
