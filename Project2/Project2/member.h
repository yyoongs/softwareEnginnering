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
	string ssn; //�ֹι�ȣ
	string user_type; //�Ǹ�������
public:
	Member();
	~Member();

};

#endif