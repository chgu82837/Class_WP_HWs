#pragma once

ref class AucBid :
public AucItem
{
public:
	AucBid(void);

	AucRela^ product;
	UInt32^ price;
	Boolean^ got;
	Boolean^ shipped;
	Boolean^ recieved;
	AucRela^ owner; // the buyer

	static String^ headerStr();
	static void printHeader();
	String^ toString();
	void print();
};
