#pragma once

ref class AucOrder
{
public:
	AucOrder(AucBuyer^ buyer,AucProduct^ product);

	void prompt();
	Boolean^ raise_bid(UInt32^ bid);
	void save(AucSys^ a);

private:
	AucBuyer^ buyer;
	AucProduct^ product;
	UInt32^ price;
	Boolean^ got;
};
