#ifndef _LOGOUT_H__
#define _LOGOUT_H__
	
#include "memberLister.h"
#include <iostream>
#include <fstream>

using namespace std;

// class : Logout
// 설명 : 세션을 로그아웃하는 기능의 control class
// 만든이 : 김영실
// 수정자 : 장유진
class Logout{

private:
	Logout();
	static Logout* logoutInstance;

public:
	static Logout* getLogoutInstance();
	//void addMemberStart(ifstream& in_fp, ofstream& out_fp);
	void showLogout(ofstream& out_fp);
	void logOutStart(ofstream& out_fp);
	~Logout();
};

#endif