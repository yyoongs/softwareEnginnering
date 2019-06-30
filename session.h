#ifndef __SESSION_H__
#define __SESSION_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class : Sesseion
// ���� : ���� �α������� session�� ����Ǵ� class
// ������ : �迵��
class Session {
private:
	static Session* sessionInstance;
	string id; //���� �̿����� id
	vector<string> login_Id_list; // �α��ε� id list
	Session();

public:
	static Session* getSessionInstance();
	string getId();  //���� �̿����� id get
	void setId(string user_id); //���� �̿��� id set
	void addSessionId(string user_id); // login_Id_list���� �α��� �� id �� �߰�
	void deleteSessionId(string user_id); // login_Id_list���� �α� id �� ����
	vector<string> getIdList();

};

#endif