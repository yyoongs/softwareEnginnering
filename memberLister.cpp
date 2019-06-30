#include "memberLister.h"
#include "session.h"
#include <fstream>

MemberLister* MemberLister::membersInstance = NULL;

MemberLister* MemberLister::getMembersInstance() {
	if (membersInstance == NULL)
		membersInstance = new MemberLister();
	
	return membersInstance;
}


// ������� �������� �Լ�
int MemberLister::getNumberOfMember() {
	return NumberOfMember;
}

// ������� ���� �Լ�
void MemberLister::setNumberOfMember(int num) {
	NumberOfMember = num;
}

//������� ��ȯ�ϴ� �Լ�
vector<Member*> MemberLister::getMembers() {
	return members;
}

// �������Ʈ�� ��� �߰�
void MemberLister::addMembers(Member* member) {
	members.push_back(member);
}

// numofmembers�� 1�߰� ���ִ� �Լ�
void MemberLister::addNumberOfMember() {
	NumberOfMember += 1;
}


//������
MemberLister::MemberLister() {
	NumberOfMember = 0;
}

//�Ҹ���
MemberLister::~MemberLister(){

}