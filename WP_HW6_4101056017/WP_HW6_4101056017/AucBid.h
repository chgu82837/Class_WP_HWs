#pragma once

class AucBid :
	public AucItem
{
public:
	AucBid(void);
	AucBid(Json::Value* Json);
	~AucBid(void);

	ARela product;
	int price;
	bool got;
	bool shipped;
	bool recieved;
	ARela owner; // the buyer

	static void set_list_head(CListCtrl* listView);
	static void switch_name_col(CListCtrl* listView,bool display_cus);
	void to_list(CListCtrl* listView);
	void to_list(CListCtrl* listView,bool display_cus);

	void save(ASys sys,ARole user,AProduct product);

	void ship(bool trying);
	void receive(bool trying);

	Json::Value* toJson();
};

