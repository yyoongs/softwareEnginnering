#include "session.h"
#include "memberLister.h"
#include <fstream>


Session* Session::sessionInstance = NULL; //static변수 초기값 NULL 설정

Session* Session::getSessionInstance() {
	if (sessionInstance == NULL) {
		sessionInstance = new Session();
	}
	return sessionInstance;
}

//static함수 
//sessionInstance값이 NULL이면 Session object하나 생성하고 반환
//NULL이 아닐시 만들어져있는 Session object반환
string Session::getId() {
	return id;
}

void Session::setId(string user_id) {
	id = user_id;
}

Session::Session()
{
	id = "";
}
// Session object가 처음 생성될 때 id값은 NULL(비로그인 상태)

void Session::addSessionId(string user_id) {
	login_Id_list.push_back(user_id);
}//로그인된 id list에 입력받은 id추가

void Session::deleteSessionId(string user_id) {
	for (int i = 0; i < login_Id_list.size(); i++) {
		if (login_Id_list.at(i) == user_id) {
			login_Id_list.erase(login_Id_list.begin() + i);
			return;
		}
	}
}//로그인된 id list에 입력받은 id삭제 

vector<string> Session::getIdList() {
	return login_Id_list;
}