#ifndef __AUCTIONTICKET_H__
#define __AUCTIONTICKET_H__

#include <string>
#include <iostream>
#include "ticket.h"

using namespace std;

class AuctionTicket :
	public ticket
{
public:
	AuctionTicket();
	~AuctionTicket();
};

#endif