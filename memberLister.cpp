#include "memberLister.h"
#include "session.h"
#include <fstream>

MemberLister* MemberLister::membersInstance = NULL;

MemberLister* MemberLister::getMembersInstance() {
	if (membersInstance == NULL)
		membersInstance = new MemberLister();
	
	return membersInstance;
}


// 멤버갯수 가져오는 함수
int MemberLister::getNumberOfMember() {
	return NumberOfMember;
}

// 멤버갯수 설정 함수
void MemberLister::setNumberOfMember(int num) {
	NumberOfMember = num;
}

//멤버벡터 반환하는 함수
vector<Member*> MemberLister::getMembers() {
	return members;
}

// 멤버리스트에 멤버 추가
void MemberLister::addMembers(Member* member) {
	members.push_back(member);
}

// numofmembers에 1추가 해주는 함수
void MemberLister::addNumberOfMember() {
	NumberOfMember += 1;
}


//생성자
MemberLister::MemberLister() {
	NumberOfMember = 0;
}

//소멸자
MemberLister::~MemberLister(){

}