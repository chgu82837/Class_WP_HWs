#pragma once

class AucProduct :
	public AucItem
{
public:
	AucProduct(void);
	AucProduct(Json::Value* Json);

	~AucProduct(void);

	String name;
	int quantity;
	int remaining;
	int bids_times;
	int init_bid;
	int bid;
	int winning_bid;
	int shipping_cost;

	long long deadline;

	ARela owner;
	AucRelas bids;

	bool ended_chk();
	bool ended();
	void close();

	void chkBids();

	void check();
	void save(ASys sys,ARole user);
	ABid raise(int bid);

	static void set_list_head(CListCtrl* listView);
	void to_list(CListCtrl* listView);

	Json::Value* toJson();

private:
	bool done_end_chk;
};

