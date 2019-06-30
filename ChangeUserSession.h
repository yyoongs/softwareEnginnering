#ifndef __CHANGEUSERSESSION_H__
#define __CHANGEUSERSESSION_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class : ChangeUserSession
// ���� : ������ �Է��� user�� ����� ����� control class
// ������ : �迵��
class ChangeUserSession {
private:
	ChangeUserSession();
	static ChangeUserSession* ChangeUserSessionInstance;

public:
	~ChangeUserSession();
	static ChangeUserSession* getChangeUserSessionInstance();
	void ChangeUserSessionStart(ifstream& in_fp, ofstream& out_fp);
	void ChangeUser(ofstream& out_fp, string input_id);
};

#endif