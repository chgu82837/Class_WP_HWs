#pragma once

ref class Auction
{
private:
	DateTime^ deadline_;
	
public:
	Auction(void);
	Auction(Newtonsoft::Json::JsonTextReader^);

	static Auction^ promt_new();

	String^ name;
	UInt32^ number;
	UInt32^ init_bid;
	UInt32^ bid;
	UInt32^ winning_bid;
	UInt32^ shipping_cost;
	UInt64^ deadline;

	Boolean^ raise_bid(UInt32^);

	static String^ headerStr();
	static void printHeader();
	String^ toString();
	void print();

	DateTime^ getDeadline();
	UInt32^ getBid();
};

