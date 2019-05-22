// ��� ����
#include <iostream>
#include <string>
#include <fstream>
#include "member.h"
#include "ticket.h"
#include "Seller.h"
#include "Buyer.h"


// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void join(string id, string passwd, string name, string ssn, string user_type);
void program_exit();
void withdraw(string id);

// ���� ����
FILE* in_fp, *out_fp;

int main()
{ // ���� ������� ���� �ʱ�ȭ
	//���� ������� ���⼭ �Ϸ��� ������ ���������� �Ű������� �ѱ�°� �� �ȵǼ� �ϴ� dotask �ȿ�!
	//ifstream in_fp;
	//in_fp.open(INPUT_FILE_NAME);
	//FILE* in_fp = fopen_s(&in_fp,INPUT_FILE_NAME, "r+");
	//ofstream out_fp;
	//out_fp.open(OUTPUT_FILE_NAME);
	//int menu_level_1 = 0;
	//FILE* out_fp = fopen_s(&out_fp,OUTPUT_FILE_NAME, "w+");
	doTask();
	return 0;
}

void doTask()
{ // �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
	ifstream in_fp(INPUT_FILE_NAME);

	while (!is_program_exit)
	{ // �Է����Ͽ��� �޴� ���� 2���� �б�
		in_fp >> menu_level_1;
		in_fp >> menu_level_2;
		cout << menu_level_1 << endl;
		cout << menu_level_2 << endl;
		//fscanf_s(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1) {
		case 1:
		{	
			switch (menu_level_2)
			{
				case 1: // "1.1. ȸ�����ԡ� �޴� �κ�
				{ // join() �Լ����� �ش� ��� ����
					cout << "join" << endl;
					// ���������� �Ű����� ���� ������ ���⼭ fp�� ����
					string id, passwd, name, ssn, user_type, test;
					// �Ű����� ������ ���⼭ ������ϴ� ���� �߻�
					// TODO
					in_fp >> id;
					in_fp >> passwd;
					in_fp >> name;
					in_fp >> ssn;
					in_fp >> user_type;
					in_fp >> test;
					cout << "test : " << test << endl;
					join(id, passwd, name, ssn, user_type);
					break;
				}
				case 2:
				{
					cout << "withdraw" << endl;
					string id;
					in_fp >> id;
					withdraw(id);
					break;
				}
			}
		}



		case 7:
		{	
			switch (menu_level_2)
			{
				case 1: // "7.1. ���ᡰ �޴� �κ�
				{
					program_exit();
					is_program_exit = 1;
					break;
				}
				case 2:
				{
					break;
				}
			}
		}
		return;
		}
	}
}

void join(string id, string passwd, string name, string ssn, string user_type)
{
	// �Է� ���� : ID, ��й�ȣ, �̸�, �ֹι�ȣ, ����������� ���Ϸκ��� ����
	//in_fp >> id;
	//in_fp >> menu_level_2;
	//fscanf_s(in_fp, "%s %s %s %s %s", id, passwd, name, ssn, user_type);
	// �ش� ��� ����
	if (user_type.compare("seller") == 0)
	{
		cout << "make seller" << endl;
		Seller seller;
		cout << "seller num : " << seller.num << endl;
	}
	else if (user_type.compare("buyer") == 0)
	{
		cout << "make buyer" << endl;
		Buyer buyer;
	}
	else
	{
		cout << "error" << endl;
	}
	// boundary, control �����ؼ� ��������
	// 15�� �ν��Ͻ� ���� ���� ppt�����ؼ�...?


		// ��� ����

	cout << "1.1" << endl;
	cout << id << " " << passwd << " " << name << " " << ssn << " " << user_type << endl;
		//fprintf(out_fp, "1.1. ȸ������\n"); 
		//fprintf(out_fp, "%s %s %s %s %s\n", id, passwd, name, ssn, user_type);
};


void program_exit()
{
	cout << "prog exit" << endl;
}

void withdraw(string id)
{
	//Member member; �߻�Ŭ������ �ϸ� ����ȵ�
	// �׷��ٸ� ȸ��Ż��� ���?
	// boundary Ŭ������ controlŬ����??
}