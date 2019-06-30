#ifndef __CHANGEUSERSESSION_H__
#define __CHANGEUSERSESSION_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class : ChangeUserSession
// 설명 : 세션을 입력한 user로 만드는 기능의 control class
// 만든이 : 김영실
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