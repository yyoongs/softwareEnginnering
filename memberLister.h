#ifndef __MEMBERLISTER_H__
#define __MEMBERLISTER_H__

#include "seller.h"
#include "buyer.h"
#include <vector>
#include <iostream>

// class : MemberLister
// 설명 : 모든 멤버들을 가지는 멤버리스트를 가지는 멤버콜렉션 class
// 만든이 : 김영실
class MemberLister {
	private:
		static MemberLister* membersInstance;
		int NumberOfMember;
		vector<Member*> members;
		MemberLister();
	public:
		static MemberLister* getMembersInstance();
		int getNumberOfMember();
		void setNumberOfMember(int num);
		void addNumberOfMember();
		vector<Member*> getMembers();
		void addMembers(Member* member);
		~MemberLister();

};

#endif