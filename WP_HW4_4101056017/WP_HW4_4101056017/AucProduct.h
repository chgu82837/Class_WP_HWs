#pragma once

ref class AucProduct :
public AucItem
{
private:
	DateTime^ deadline_;
	
public:
	AucProduct(void);

	String^ name;
	UInt32^ quantity;
	UInt32^ remaining;
	UInt32^ bids_times;
	UInt32^ init_bid;
	UInt32^ bid;
	UInt32^ winning_bid;
	UInt32^ shipping_cost;

	UInt64^ deadline;

	AucRela^ owner;
	List<AucRela^>^ bids;

	void setDeadline(DateTime^ deadline);
	DateTime^ getDeadline();
	Boolean^ ended();

	static String^ headerStr();
	static void printHeader();
	String^ toString();
	void print();

	UInt32^ getBid();
};
