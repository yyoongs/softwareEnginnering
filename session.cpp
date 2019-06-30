#include "session.h"
#include "memberLister.h"
#include <fstream>


Session* Session::sessionInstance = NULL; //static���� �ʱⰪ NULL ����

Session* Session::getSessionInstance() {
	if (sessionInstance == NULL) {
		sessionInstance = new Session();
	}
	return sessionInstance;
}

//static�Լ� 
//sessionInstance���� NULL�̸� Session object�ϳ� �����ϰ� ��ȯ
//NULL�� �ƴҽ� ��������ִ� Session object��ȯ
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
// Session object�� ó�� ������ �� id���� NULL(��α��� ����)

void Session::addSessionId(string user_id) {
	login_Id_list.push_back(user_id);
}//�α��ε� id list�� �Է¹��� id�߰�

void Session::deleteSessionId(string user_id) {
	for (int i = 0; i < login_Id_list.size(); i++) {
		if (login_Id_list.at(i) == user_id) {
			login_Id_list.erase(login_Id_list.begin() + i);
			return;
		}
	}
}//�α��ε� id list�� �Է¹��� id���� 

vector<string> Session::getIdList() {
	return login_Id_list;
}