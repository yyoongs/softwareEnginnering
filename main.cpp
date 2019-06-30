#include <iostream>
#include <fstream>
#include "memberLister.h"
#include "session.h"
#include "time.h"
#include "ticketLister.h"
#include "SearchRegisteredTicket.h"
#include "RegisterTicket.h"
#include "AddMember.h"
#include "SearchAuctionTicket.h"
#include "BidForTicket.h"
#include "SearchTicket.h"
#include "ReserveTicket.h"
#include "ChangeGuestSession.h"
#include "ChangeUserSession.h"
#include "Login.h"
#include "Logout.h"
#include "WithdrawMember.h"
#include "ManageBuyersTicket.h"

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask(ifstream & in_fp, ofstream & out_fp);

// ���� ����
FILE* in_fp, * out_fp;	// input output ���� ������ ����

int main()
{
	ifstream in_fp(INPUT_FILE_NAME);
	ofstream out_fp(OUTPUT_FILE_NAME);
	doTask(in_fp, out_fp);
	return 0;
}

void doTask(ifstream& in_fp, ofstream& out_fp)
{ // �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;

	while (!is_program_exit)
	{ // �Է����Ͽ��� �޴� ���� 2���� �б�
		in_fp >> menu_level_1;
		in_fp >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // 1.1. ȸ������ �޴�
			{
				AddMember* control = AddMember::getAddMemberInstance();
				control->addMemberStart(in_fp, out_fp);

				break;
			}
			case 2:	// 1.2. ȸ��Ż�� �޴�
			{
				WithdrawMember* control = WithdrawMember::getWithdrawMemberInstance();
				control->withdrawMemberStart(in_fp, out_fp);
			
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:	// 2.1 �α��� �޴�
			{
				Login* control = Login::getLoginInstance();
				control->LoginStart(in_fp, out_fp);

				break;
			}
			case 2: // 2.2 �α׾ƿ� �޴�
			{
				Logout* control = Logout::getLogoutInstance();
				control->logOutStart(out_fp);

				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // 3.1. �Ǹ�Ƽ�� ��� �޴�
			{
				RegisterTicket* control = RegisterTicket::getRegisterTicketInstance();
				control->RegisterTicketStart(in_fp, out_fp);

				break;
			}
			case 2:	// 3.2. ���Ƽ�� ��ȸ �޴�
			{
				SearchRegisteredTicket* control = SearchRegisteredTicket::getSearchRegisteredTicketInstance();
				control->SearchRegisteredTicketStart(out_fp);

				break;
			}
			}
			break;
		}
		// case 4.3, 4.4 �߰� (������)
		case 4:
		{
			switch (menu_level_2)
			{
				case 1:		// Ƽ�� �˻� ���
				{
					SearchTicket* control = SearchTicket::getSearchTicketInstance();
					control->SearchTicketStart(in_fp,out_fp);

					break;
				}
				
				case 2: //Ƽ�� ���� ���
				{
					ReserveTicket* control = ReserveTicket::getReserveTicketInstance();
					control->reserveTicketStart(in_fp, out_fp);

					break;
				}

				case 3: //auction Ƽ�� �˻�
				{
					SearchAuctionTicket* control = SearchAuctionTicket::getSearchAuctionTicketInstance();
					control->SearchAuctionTicketStart(in_fp, out_fp);

					break;
				}

				case 4: // auction ���� ���
				{
					BidForTicket* control = BidForTicket::getBidForTicketInstance();
					control->BidForTicketStart(in_fp, out_fp);
					break;
				}

				case 5: //���� ���� ��ȸ ���
				{
					ManageBuyersTicket* control = ManageBuyersTicket::getManageBuyersTicketInstance();
					control->ManageBuyersTicketStart(out_fp);
					break;
				}
			}
			break;
		}
		case 5:
		{
			switch (menu_level_2)
			{
				case 1: // �ð� ���� ���
				{
				
					Time* time_manage=Time::getTimetInstance();	//time Ŭ���� ���� ( �̸� : time_manage )
					time_manage->setTime(in_fp, out_fp);	//setTime����
					break;
				}
			
			}
			break;
		}
		case 6:
		{
			switch (menu_level_2)
			{
				case 1: // "6.1. ���Ǻ��桰 �޴� �κ�
				{
					ChangeUserSession* control = ChangeUserSession::getChangeUserSessionInstance();
					control->ChangeUserSessionStart(in_fp, out_fp);
					
					break;

				}
				case 2:
				{

					ChangeGuestSession* control = ChangeGuestSession::getChangeGuestSessionInstance();
					control->changeGuestSessionStart(out_fp);

					break;
				}
			}
			break;
		}


		case 7:
		{
			switch (menu_level_2)
			{
				case 1: // "7.1. ���ᡰ �޴� �κ�
				{
					cout << "prog exit" << endl;
					out_fp << "prog exit" << endl;
					is_program_exit = 1;
					break;
				}
			}
			break;
		}
		}
		cout << endl;
	}
}