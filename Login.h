#ifndef _LOGIN_H__
#define _LOGIN_H__

#include "memberLister.h"
#include <iostream>
#include <fstream>

using namespace std;

// class : Login
// ���� : ������ �Է��� user�� �α����ϴ� ����� control class
// ������ : �迵��
// ������ : ������
class Login
{

private:
	Login();
	static Login* LoginInstance;

public:
	static Login* getLoginInstance();
	void LoginStart(ifstream& in_fp, ofstream& out_fp);
	void showLogin(ofstream& out_fp, string id, string passwd);
	~Login();
};

#endif