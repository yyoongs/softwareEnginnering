#include "RegisterTicketUI.h"
#include "RegisterTicket.h"


RegisterTicketUI::RegisterTicketUI()
{

}


RegisterTicketUI::~RegisterTicketUI()
{
}

RegisterTicketUI* RegisterTicketUI::RegisterTicketUIInstance = NULL;

RegisterTicketUI* RegisterTicketUI::getRegisterTicketUIInstance() {
	if (RegisterTicketUIInstance == NULL) {
		RegisterTicketUIInstance = new RegisterTicketUI();
	}
	return RegisterTicketUIInstance;
}

void RegisterTicketUI::startInterface(ifstream & in_fp, ofstream& out_fp) {
	RegisterTicket* control = RegisterTicket::getRegisterTicketInstance();

	int price; //�������
	string game_date_time; //��� ��¥ �� �ð�
	string game_home_team; //Ȩ��
	string game_away_team; //�������
	string game_seat_number; //�¼���ġ
	bool auction_check; //��ż��ÿ���

	in_fp >> price;
	in_fp >> game_date_time;
	in_fp >> game_home_team;
	in_fp >> game_away_team;
	in_fp >> game_seat_number;
	in_fp >> auction_check;

	control->addNewTicket(out_fp, price, game_date_time, game_home_team, game_away_team, game_seat_number, auction_check);

}

void RegisterTicketUI::menu3_1output(ofstream& out_fp, int price, string game_date_time, string game_home_team, string game_away_team,
	string game_seat_number, bool auction_check) {
	cout << "3.1. �Ǹ�Ƽ�� ���" << endl;
	out_fp << "3.1. �Ǹ�Ƽ�� ���" << endl;

	cout << "> " << price << " " << game_date_time << " " << game_home_team << " "
		<< game_away_team << " " << game_seat_number << " " << auction_check << endl;
	out_fp << "> " << price << " " << game_date_time << " " << game_home_team << " "
		<< game_away_team << " " << game_seat_number << " " << auction_check << endl << endl;
}

void RegisterTicketUI::menu3_1fail(ofstream& out_fp) {
	cout << "3.1. �Ǹ�Ƽ�� ���" << endl;
	out_fp << "3.1. �Ǹ�Ƽ�� ���" << endl;

	cout << "> ���� " << endl;
	out_fp << "> ���� " << endl << endl;
}

