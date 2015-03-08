/***************************
4101056017 邱冠喻 第一次作業 10/8
4101056017 Chiu Guan-Yu TheFirstHomework 10/8
***************************/

// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#define INPUT_MAX 50
#define DATE_STR_MAX 50
#define AUC_MAX 10

using namespace std;

struct Auction
{
	char* name;
	unsigned int* number;
	unsigned int* init_bid;
	unsigned int* winning_bid;
	unsigned int* shipping_cost;
	time_t* deadline;
};

void print_aut(Auction* a);
void fscanf_until(FILE* f,char* str);
FILE* prompt_file(char* mode);
unsigned int* prompt_uint(char* message);
time_t* promt_date(char* message);
void read_auction();
void create_auction();
unsigned int* mk_seq(unsigned int* sort_data,unsigned int* number);
void show_auction();
void show_auction(unsigned int* seq);
void auction_info_table();
void test();

Auction** a;
unsigned int* na;

int _tmain(int argc, _TCHAR* argv[])
{
	//test();

	printf("<<< Welcome to my auction system! >>>\n");
	char* action_n = (char*) (new int(0));

	while(*action_n != '0')
	{
		printf("\nPlease choose an action:\n\t1.read actions from file\n\t2.create auctions to file\n\n\t0.exit\nYour choise:");
		fflush(stdin);
		*action_n = getchar();

		switch (*action_n)
		{
		case '1':
			printf("\nPreparing to read auction...");
			read_auction();
			auction_info_table();
			break;
		case '2':
			printf("\nPreparing to create auction...");
			create_auction();
			auction_info_table();
			break;
		case '0':
			printf("\nExiting...\n");
			break;
		default:
			printf("\nUnknown option\n");
			break;
		}
	}
	

	printf("Program ended. Press enter to continue...");
	fflush(stdin);
	getchar();
	return 0;
}

void print_aut_head()
{
	printf("name       number init_bid winning_bid shipping_cost deadline\n");
}

void print_aut(Auction* a)
{
	time_t* deadline = a->deadline;
	struct tm * timeinfo = new struct tm;
	char* time_str = new char[DATE_STR_MAX]; 

	//time(deadline);
	localtime_s(timeinfo,deadline);
	if(timeinfo->tm_hour == -1)
		time_str = "Unknown";
	else
		strftime (time_str,DATE_STR_MAX,"%Y-%m-%d %a %I:%M %p",timeinfo);
	printf("%-10s %-6u %-8u %-11u %-13u %-10s\n",a->name,*(a->number),*(a->init_bid),*(a->winning_bid),*(a->shipping_cost),time_str);
}

void fscanf_until(FILE* f,char* str)
{
	char* cursor = new char(0);
	int* i = new int(0);
	for (*i = 0; (*i) < INPUT_MAX; (*i)++)
	{
		*cursor = fgetc(f);
		if('"' == *cursor)
			break;
		else
			*(str+*i) = *cursor;
	}
	*(str+*i) = 0;
	delete cursor,i;
}

FILE* prompt_file(char* mode)
{
	char* fname = new char[INPUT_MAX]; 
	FILE* f;
	while(true)
	{
		printf("\nPlease input a filename:");
		fflush(stdin);
		if(!scanf_s("%s",fname,INPUT_MAX))
			continue;
		printf("Opening [%s] in mode [%s]...\n",fname,mode);
		fopen_s(&f,fname,mode);
		if(!f){
			printf("Can not open file [%s] in mode [%s]!\n",fname,mode);
			continue;
		}
		if(!ferror(f))
			break;
		printf("Can not open file [%s] in mode [%s]!\n",fname,mode);
	}
	return f;
}

unsigned int* prompt_uint(char* message)
{
	unsigned int* n = new unsigned int(0);
	printf("%s",message);
	fflush(stdin);
	while(scanf_s("%u",n) != 1){
		printf("Not a valid input!\n%s",message);
		fflush(stdin);
	}
	return n;
}

time_t* promt_date(char* message)
{
	unsigned int* year = new unsigned int(0);
	unsigned int* month = new unsigned int(0);
	unsigned int* day = new unsigned int(0);
	unsigned int* hour = new unsigned int(0);
	unsigned int* minute = new unsigned int(0);
	while(!((*year >= 1970) && (*month > 0) && (*month < 13) && (*day > 0) && (*day < 32) && (*hour >= 0) && (*hour < 24) && (*minute >= 0) && (*minute < 61)))
	{
		printf("%s (YYYY-MM-DD HH:mm):",message);
		fflush(stdin);
		if(!scanf_s("%u-%u-%u %u:%u",year,month,day,hour,minute)){
			*year = 0;
			printf("Not a valid input!\n");
			continue;
		}
	}
	time_t* rawtime = new time_t;
	struct tm * timeinfo = new struct tm;

	time(rawtime);
	localtime_s(timeinfo, rawtime);
	timeinfo->tm_year = *year - 1900;
	timeinfo->tm_mon = *month - 1;
	timeinfo->tm_mday = *day;
	timeinfo->tm_hour = *hour;
	timeinfo->tm_min = *minute;

	*rawtime = mktime(timeinfo);

	delete year,month,day,hour,minute,timeinfo;
	
	return rawtime;
}

void read_auction()
{
	FILE* f = prompt_file("r");
	char* cursor = new char(0);

	a = new Auction*[AUC_MAX];
	na = new unsigned int(0);
	Auction* a_tmp;

	if(fscanf_s(f,"{\n  \"auctions\":\n  [\n") != 0){
		printf("Not a valid auction file!\n");
		return;
	}
	while(true)
	{
		*cursor = fgetc(f);
		if (*cursor == EOF || *cursor == ']')
			break;
		if (*cursor == '{')
		{
			if(fscanf_s(f," \"name\":\"") != 0){
				printf("Not a valid auction file!\n");
				return;
			}

			a_tmp = new Auction;
			a_tmp->name = new char[INPUT_MAX]; 
			a_tmp->number = new unsigned int(0);
			a_tmp->init_bid = new unsigned int(0);
			a_tmp->winning_bid = new unsigned int(0);
			a_tmp->shipping_cost = new unsigned int(0);
			a_tmp->deadline = new time_t;

			fscanf_until(f,a_tmp->name);

			if(fscanf_s(f,",\"number\":%u,\"init_bid\":%u,\"winning_bid\":%u,\"shipping_cost\":%u,\"deadline\":%lld},",a_tmp->number,a_tmp->init_bid,a_tmp->winning_bid,a_tmp->shipping_cost,a_tmp->deadline) != 5){
				printf("Not a valid auction file!\n");
				return;
			}

			*(a + *na) = a_tmp;
			(*na)++;
		}
	}

	fclose(f);
}

void create_auction()
{
	FILE* f = prompt_file("w");
	bool* ended = new bool(false);
	struct tm * timeinfo = new struct tm;

	a = new Auction*[AUC_MAX];
	na = new unsigned int(0);

	Auction* a_tmp;
	
	if(fprintf(f,"{\n  \"auctions\":\n  [\n") <= 0){
		printf("There is an error writing the file!\n");
		return;
	}
	while(!*ended)
	{
		a_tmp = new Auction;
		a_tmp->name = new char[INPUT_MAX];
		printf("\nPlease input the name of the product:");
		fflush(stdin);
		scanf_s("%s",a_tmp->name,INPUT_MAX);
		a_tmp->number = prompt_uint("Please input the number of the product:");
		a_tmp->init_bid = prompt_uint("Please input the init_bid of the product:");
		a_tmp->winning_bid = prompt_uint("Please input the winning_bid of the product:");
		a_tmp->shipping_cost = prompt_uint("Please input the shipping_cost of the product:");
		a_tmp->deadline = promt_date("Please input the deadline of the product");		

		if(strcspn(a_tmp->name,"\"") != strlen(a_tmp->name))
		{
			printf("'\"' can not be inputed!\n");
			continue;
		}
		if(*(a_tmp->winning_bid) < *(a_tmp->init_bid))
		{
			printf("winning_bid is less than init_bid!\n");
			continue;
		}

		printf("\n");
		print_aut_head();
		print_aut(a_tmp);
		printf("============================\nIs this correct? [Yn]:");
		fflush(stdin);
		if(getchar() == 'n')
			continue;

		if(fprintf(f,"    {\"name\":\"%s\",\"number\":%u,\"init_bid\":%u,\"winning_bid\":%u,\"shipping_cost\":%u,\"deadline\":%lld},\n",a_tmp->name,*(a_tmp->number),*(a_tmp->init_bid),*(a_tmp->winning_bid),*(a_tmp->shipping_cost),*(a_tmp->deadline)) <= 0){
			printf("There is an error writing the file!");
			return;
		}

		*(a + *na) = a_tmp;
		(*na)++;

		printf("Auction saved.\nDo you want to input more auction? [Yn]:");
		fflush(stdin);
		if(getchar() == 'Y')
			continue;
		else
			break;
	}
	if(fprintf(f,"  ],\n}") <= 0){
		printf("There is an error writing the file!\n");
		return;
	}

	delete ended,timeinfo,a_tmp;

	fclose(f);
}

void swap(unsigned int* a, unsigned int* b)
{
	unsigned int* i = new unsigned int(0);
	*i = *a;
	*a = *b;
	*b = *i;
	delete i;
}

unsigned int* mk_seq(unsigned int* sort_data,unsigned int* number)
{
	unsigned int* i = new unsigned int(0);
	unsigned int* j = new unsigned int(0);
	unsigned int* seq = new unsigned int[*number];
	for (; *i < *number; (*i)++)
		*(seq + *i) = *i;

	for ((*i)-- ; *i > 0; (*i)--)
		for (*j = 0; *j < *i; (*j)++)
			if (*(sort_data + *(seq + *j)) < *(sort_data + *(seq + *j + 1)))
				swap(seq + *j,seq + *j + 1);
	delete i,j;
	return seq;
}

void show_auction()
{
	print_aut_head();
	unsigned int* i = new unsigned int(0);
	for (; *i < *na; (*i)++)
		print_aut(*(a + *i));
	
	delete i;
}

void show_auction(unsigned int* seq)
{
	print_aut_head();
	unsigned int* i = new unsigned int(0);
	for (; *i < *na; (*i)++)
		print_aut(*(a + *(seq + *i)));
	
	delete i;
}

void auction_info_table()
{
	if(!*na)
		return;
	printf("\nAll Auctions:\n===========================\n");

	show_auction();

	char* action_n = (char*) (new int(0));
	unsigned int* sort_data = new unsigned int[*na];
	unsigned int* i = new unsigned int(0);

	while(*action_n != '0')
	{
		printf("===========================\nPlease choose a field to sort:\n\t1.Initial bid price\n\t2.Winning bid price\n\t3.Deadline\n\t4.Number\n\t5.Shipping cost\n\n\t0.leave\nYour choise:");
		fflush(stdin);
		*action_n = getchar();

		switch (*action_n)
		{
		case '1':
			for (*i = 0; *i < *na; (*i)++)
				*(sort_data + *i) = *((*(a + *i))->init_bid);
			break;
		case '2':
			for (*i = 0; *i < *na; (*i)++)
				*(sort_data + *i) = *((*(a + *i))->winning_bid);
			break;
		case '3':
			for (*i = 0; *i < *na; (*i)++)
				*(sort_data + *i) = *((*(a + *i))->deadline);
			break;
		case '4':
			for (*i = 0; *i < *na; (*i)++)
				*(sort_data + *i) = *((*(a + *i))->number);
			break;
		case '5':
			for (*i = 0; *i < *na; (*i)++)
				*(sort_data + *i) = *((*(a + *i))->shipping_cost);
			break;
		case '0':
			printf("\nLeaving...\n");
			return;
		default:
			printf("\nUnknown option\n");
			continue;
		}
		show_auction(mk_seq(sort_data,na));
	}
	delete action_n,sort_data[*na],i;
}

void test()
{
	printf("Self testing...\n");
}

/***************************
4101056017 邱冠喻 第一次作業 10/8
4101056017 Chiu Guan-Yu TheFirstHomework 10/8
***************************/
