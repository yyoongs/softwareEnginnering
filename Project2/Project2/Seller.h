#ifndef __SELLER_H__
#define __SELLER_H__

#include <string>
#include <iostream>
#include "member.h"

using namespace std;

class Seller :
	public Member
{
public:
	Seller();
	~Seller();
	string getsellerid();
	int num = 0;
};

#endif