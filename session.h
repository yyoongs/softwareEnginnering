#ifndef __SESSION_H__
#define __SESSION_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class : Sesseion
// 설명 : 현재 로그인중인 session이 저장되는 class
// 만든이 : 김영실
class Session {
private:
	static Session* sessionInstance;
	string id; //현재 이용중인 id
	vector<string> login_Id_list; // 로그인된 id list
	Session();

public:
	static Session* getSessionInstance();
	string getId();  //현재 이용중인 id get
	void setId(string user_id); //현재 이용할 id set
	void addSessionId(string user_id); // login_Id_list에서 로그인 된 id 를 추가
	void deleteSessionId(string user_id); // login_Id_list에서 로그 id 를 삭제
	vector<string> getIdList();

};

#endif