#include "ticket.h"
#include <iostream>
#include <fstream>

Ticket::Ticket(int price_t, tm game_date_time_t, string game_home_team_t, string game_away_team_t,
	string game_seat_number_t, bool auction_check_t) {
	price=price_t;
	game_date_time= game_date_time_t;
	game_home_team= game_home_team_t;
	game_away_team= game_away_team_t;
	game_seat_number= game_seat_number_t;
	auction_check= auction_check_t;
	availableSale = true;
}

Ticket::~Ticket()
{

}

int Ticket::getPrice() {
	return price;
}
tm Ticket::getDateAndTime() {
	return game_date_time;
}
string Ticket::getHometeam() {
	return game_home_team;
}
string Ticket::getAwayteam() {
	return game_away_team;
}
string Ticket::getSeatPosition() {
	return game_seat_number;
}
bool Ticket::getAuctionChoice() {
	return auction_check;
}
bool Ticket::getAvailableSale() {
	return availableSale;
}
void Ticket::setAvailableSale(bool a) {
	availableSale = a;
}

void Ticket::showDateAndTime(ofstream& out_fp)
{
	cout << game_date_time.tm_year << ":";
	if (game_date_time.tm_mon < 10)
	{
		cout << "0" << game_date_time.tm_mon << ":";
		out_fp << "0" << game_date_time.tm_mon << ":";
		
	}
	else
	{
		cout << game_date_time.tm_mon << ":";
		out_fp << game_date_time.tm_mon << ":";
	}

	if (game_date_time.tm_mday < 10)
	{
		cout << "0" << game_date_time.tm_mday << ":";
		out_fp << "0" << game_date_time.tm_mday << ":";
	}
	else
	{
		cout << game_date_time.tm_mday << ":";
		out_fp << game_date_time.tm_mday << ":";
	}

	if (game_date_time.tm_hour < 10)
	{
		cout << "0" << game_date_time.tm_hour << ":";
		out_fp << "0" << game_date_time.tm_hour << ":";
	}
	else
	{
		cout << game_date_time.tm_hour << ":";
		out_fp << game_date_time.tm_hour << ":";
	}

	if (game_date_time.tm_min < 10)
	{
		cout << "0" << game_date_time.tm_min << " ";
		out_fp << "0" << game_date_time.tm_min << " ";
	}
	else
	{
		cout << game_date_time.tm_min << " ";
		out_fp << game_date_time.tm_min << " ";
	}
}

bool Ticket::checkDateAndTime(string dateAndTime)
{
	char* context = NULL;	//���� ���ڿ��� �� context
	int inputDate[5];	// tokenȭ �� date ������ �� int�� �迭
	int i = 0;
	char *strBuffer = new char[50];	//�Է¹��� ���� ������ ���ڿ� ( �Է¹��� ���̴� 50���� ���� ) // ��¥�Է¹޴°Ŷ� �������� ��
	strcpy_s(strBuffer, 50, dateAndTime.c_str());	//txt���Ͽ��� �޾ƿ� ������ 50���̸�ŭ buffer�� ����
	char *token = strtok_s(strBuffer, ":", &context);	//strtok_s�� ����Ͽ� ":"�� ����
	while (token != nullptr)
	{
		inputDate[i] = atoi(string(token).c_str());	//�߷��� token�� date�� �ִµ� atoi�� ����� string���� int������ ����
		i++;
		token = strtok_s(nullptr, ":", &context);	// ���� buffer�� ã������ nullptr�� �־ ��ȯ������
	}

	if (inputDate[0] == game_date_time.tm_year && inputDate[1] == game_date_time.tm_mon && inputDate[2] == game_date_time.tm_mday && inputDate[3] == game_date_time.tm_hour && inputDate[4] == game_date_time.tm_min)
	{
		return true;
	}
	else
	{
		return false;
	}
}

