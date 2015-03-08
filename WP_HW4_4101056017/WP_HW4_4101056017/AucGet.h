#pragma once

ref class AucGet
{
public:
	AucGet(AucBuyer^ buyer,AucBid^ bid);

	void receive();
private:
	AucBuyer^ buyer;
	AucBid^ bid;
};
