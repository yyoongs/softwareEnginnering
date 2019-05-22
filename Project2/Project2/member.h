#ifndef __MEMBER_H__
#define __MEMBER_H__

#include <string>
#include <iostream>

using namespace std;

class Member abstract
{
protected:
	string id; //id
	string passwd;  //password
	string name;
	string ssn; //주민번호
	string user_type; //판매자유형
public:
	Member();
	~Member();

};

#endif