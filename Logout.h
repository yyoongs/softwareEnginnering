#ifndef _LOGOUT_H__
#define _LOGOUT_H__
	
#include "memberLister.h"
#include <iostream>
#include <fstream>

using namespace std;

// class : Logout
// ���� : ������ �α׾ƿ��ϴ� ����� control class
// ������ : �迵��
// ������ : ������
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