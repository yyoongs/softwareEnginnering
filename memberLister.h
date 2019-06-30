#ifndef __MEMBERLISTER_H__
#define __MEMBERLISTER_H__

#include "seller.h"
#include "buyer.h"
#include <vector>
#include <iostream>

// class : MemberLister
// ���� : ��� ������� ������ �������Ʈ�� ������ ����ݷ��� class
// ������ : �迵��
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