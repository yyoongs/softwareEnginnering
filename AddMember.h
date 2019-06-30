#ifndef _ADDMEMBER_H__
#define _ADDMEMBER_H__

#include "memberLister.h"
#include <iostream>
#include <fstream>

using namespace std;

// class : AddMember
// 설명 : 로그인시 사용될 control 함수 
// 만든이 : 김영실
class AddMember
{

private:
	AddMember();
	static AddMember* addMemberInstance;

public:
	static AddMember* getAddMemberInstance();
	void addMemberStart(ifstream& in_fp, ofstream& out_fp);
	void showSignUp(ofstream& out_fp,string id, string passwd, string name, string ssn, string user_type);
	~AddMember();
};

#endif