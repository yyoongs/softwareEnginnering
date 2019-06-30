#include "RegisterTicket.h"
#include "RegisterTicketUI.h"

RegisterTicket::RegisterTicket()
{
}


RegisterTicket::~RegisterTicket()
{
}


RegisterTicket* RegisterTicket::RegisterTicketInstance = NULL;

RegisterTicket* RegisterTicket::getRegisterTicketInstance() {
	if (RegisterTicketInstance == NULL) {
		RegisterTicketInstance = new RegisterTicket();
	}
	return RegisterTicketInstance;
}


void RegisterTicket::RegisterTicketStart(ifstream& in_fp, ofstream& out_fp) {
	RegisterTicketUI *boundaryUI = RegisterTicketUI::getRegisterTicketUIInstance();
	boundaryUI->startInterface(in_fp, out_fp);
}

// ������ : �迵��
void RegisterTicket::addNewTicket(ofstream& out_fp, int price, string game_date_time, string game_home_team, string game_away_team, string game_seat_number, bool auction_check) {
	RegisterTicketUI* boundaryUI = RegisterTicketUI::getRegisterTicketUIInstance();
	Time *timeManager = Time::getTimetInstance();
	TicketLister *tickets = TicketLister::getTicketsInstance();
	string id;
	Ticket* ticket;
	int index = 0; // �Ǹ� Ƽ���� ����Ϸ��� member�� index
	int num_member; // ���� ���Ե� member ��
	int num_SellerTicket; //seller�� ����� Ƽ�� ��

	//string���� �Է¹��� game_date_time�� struct time�Լ��� �˸°� �������� 
	struct tm inputTime = timeManager->timeTypeSetting(game_date_time);

	if (timeManager->differTime(inputTime) < 48) {
		boundaryUI->menu3_1fail(out_fp);
		return;
	}
	//���� ���� ����ϴ� Ƽ���� ����ð��� 2�ϵ� ���̰� �ȳ��ٸ� Ƽ�ϵ�� �Ұ�

	Session* session_manage = Session::getSessionInstance();
	id = session_manage->getId();
	MemberLister* members__manage = MemberLister::getMembersInstance();
	num_member = members__manage->getNumberOfMember();
	vector<Member*> temp_members = members__manage->getMembers();

	for (int i = 0; i < num_member; i++) {
		if (id == temp_members.at(i)->getId()) {
			index = i;
			break;
		}
	}

	Seller* temp_member = (Seller*)temp_members.at(index);	//temp_members�� seller��

	// ���Ǽ��ÿ��ΰ� 1�̰� �����ð��� 24�ð� �̳��� �� auctionTicket���� ���
	if (auction_check == 1 && timeManager->differTime(inputTime) < 24)
	{
		ticket = new AuctionTicket(price, inputTime, game_home_team, game_away_team, game_seat_number, auction_check);
	}
	else
	{
		ticket = new Ticket(price, inputTime, game_home_team, game_away_team, game_seat_number, auction_check);
	}


	int numOfTicket = tickets->getNumOfTicket();
	numOfTicket++;
	tickets->setNumOfTicket(numOfTicket);

	// 2019.06.03 ���뼺
	// Ƽ�ϸ���Ʈ Ŭ������ Ƽ�ϸ���Ʈ�� Ƽ���߰��ϴ� �Լ� ���� ticket�߰�
	// Ƽ�ϰ��� ������Ű�� ������Ѿ���
	tickets->addTicketList(ticket);


	vector<Ticket*> temp_sellerTicket = temp_member->getSeller_Ticket();	//seller�� Ƽ�ϸ���Ʈ�� �ҷ���

	temp_sellerTicket.push_back(ticket);	//seller�� Ƽ�ϸ���Ʈ�� �ֱ�

	num_SellerTicket = temp_member->getNumberOfSellerTicket();	//seller�� Ƽ�� ���� ��������
	num_SellerTicket++;	// seller�� Ƽ�ϰ��� ������� +1
	temp_member->setNumberOfSellerTicket(num_SellerTicket);	//seller�� Ƽ�ϰ��� ������� ������Ʈ


	temp_member->setSeller_Ticket(temp_sellerTicket);	//seller�� Ƽ�ϸ���Ʈ ������Ʈ

	boundaryUI->menu3_1output(out_fp, price, game_date_time, game_home_team, game_away_team, game_seat_number, auction_check);
}