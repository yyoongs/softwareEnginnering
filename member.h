#ifndef __MEMBER_H__
#define __MEMBER_H__

#include "AuctionTicket.h"
#include "ticket.h"
#include <vector>
#include <string>

using namespace std;

// class : Member
// 설명 : 판매자 혹은 구매자의 부모클래스
// 만든이 : 조용성
// 수정자 : 김영실
class Member{
protected:
	string id; //id
	string passwd;  //password
	string name;
	string ssn; //주민번호
	string user_type; //판매자유형
public:
	Member();
	string getId();
	string getPasswd();
	string getUser_type();
	~Member();
};

#endif