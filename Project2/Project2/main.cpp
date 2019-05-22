// 헤더 선언
#include <iostream>
#include <string>
#include <fstream>
#include "member.h"
#include "ticket.h"
#include "Seller.h"
#include "Buyer.h"


// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join(string id, string passwd, string name, string ssn, string user_type);
void program_exit();
void withdraw(string id);

// 변수 선언
FILE* in_fp, *out_fp;

int main()
{ // 파일 입출력을 위한 초기화
	//파일 입출력을 여기서 하려고 했으나 파일포인터 매개변수로 넘기는게 잘 안되서 일단 dotask 안에!
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
{ // 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
	ifstream in_fp(INPUT_FILE_NAME);

	while (!is_program_exit)
	{ // 입력파일에서 메뉴 숫자 2개를 읽기
		in_fp >> menu_level_1;
		in_fp >> menu_level_2;
		cout << menu_level_1 << endl;
		cout << menu_level_2 << endl;
		//fscanf_s(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1) {
		case 1:
		{	
			switch (menu_level_2)
			{
				case 1: // "1.1. 회원가입“ 메뉴 부분
				{ // join() 함수에서 해당 기능 수행
					cout << "join" << endl;
					// 파일포인터 매개변수 문제 때문에 여기서 fp를 읽음
					string id, passwd, name, ssn, user_type, test;
					// 매개변수 선언을 여기서 해줘야하는 문제 발생
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
				case 1: // "7.1. 종료“ 메뉴 부분
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
	// 입력 형식 : ID, 비밀번호, 이름, 주민번호, 사용자유형을 파일로부터 읽음
	//in_fp >> id;
	//in_fp >> menu_level_2;
	//fscanf_s(in_fp, "%s %s %s %s %s", id, passwd, name, ssn, user_type);
	// 해당 기능 수행
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
	// boundary, control 구현해서 만들어야함
	// 15장 인스턴스 생성 관련 ppt참고해서...?


		// 출력 형식

	cout << "1.1" << endl;
	cout << id << " " << passwd << " " << name << " " << ssn << " " << user_type << endl;
		//fprintf(out_fp, "1.1. 회원가입\n"); 
		//fprintf(out_fp, "%s %s %s %s %s\n", id, passwd, name, ssn, user_type);
};


void program_exit()
{
	cout << "prog exit" << endl;
}

void withdraw(string id)
{
	//Member member; 추상클래스로 하면 선언안됨
	// 그렇다면 회원탈퇴는 어떻게?
	// boundary 클래스와 control클래스??
}