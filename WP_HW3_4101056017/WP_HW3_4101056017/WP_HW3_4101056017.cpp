/***************************
4101056017 邱冠喻 第三次作業 11/5
4101056017 Chiu Guan-Yu TheThirdHomework 11/5
***************************/

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include "Gamma.h"

#define STMT_MAX 200


double* use_file(char* fname);
void interactive_prompt();
char* arrange(int* argc,char** argv,int* startIndex);
double* parse(char* stmt);

double* expression(int* last_pri);
double* term();
void calculate(double* value,char* op,double* operand);

double* digit();
double* use_file();
int* get_pri(char* op);

bool* str_eq(char* str);

char* cursor;


int _tmain(int argc, _TCHAR* argv[]){
	char* stmt = nullptr;

	try{
		try{
			if(argc > 1){
				stmt = arrange(new int(argc),(char**) argv,new int(1));
				printf("< %s\n",stmt);
			}
			else{
				printf("Usage:\n\tWP_HW3_4101056017.exe \{expression\}\n\n\tExpression include: +,-,*,/,%,^,!,exp,sin,cos,tan,cot,set,csc\n\tdigits,(,[,{,},],) and filename with double quote (Ex: \"expression.txt\")\n");
				printf("");
				stmt = (char*) "expression.txt";
				throw new int(0);
			}
			printf(" = %f \n",*parse(stmt));
		}catch(int* s){
			printf("Open [%s] as file input...\n", stmt);
			printf(" = %f \n",*use_file(stmt));
		}
	}catch(char* msg){
		printf("ERROR:\n\t%s\n",msg);
		goto exited;
	}catch(int* s){
		printf("File [%s] open failed!\n", stmt);
	}
	printf("Entering interactive mode...\n", stmt);
	interactive_prompt();
	exited:
	printf("Press any key to continue...");
	getchar();
	return 0;
}

double* use_file(char* fname){
	FILE* f;
	fopen_s(&f,fname,"r");
	char* stmt = new char[STMT_MAX];
	int* i = new int(0);
	if(!f)
		throw new int(0);
	while(!feof(f) && (*i < STMT_MAX))
		*(stmt + (*i)++) = getc(f);
	fclose(f);
	*(stmt + *i) = 0;
	printf("[%s] > %s",fname,stmt);
	stmt = arrange(new int(1),&stmt,new int(0));
	double* result = parse(stmt);
	delete[] stmt;
	delete i;
	return result;
}

void interactive_prompt(){
	char* stmt = new char[STMT_MAX];
	double* result = nullptr;

	try{
		while(true){
			try{
				printf("> ");
				gets_s(stmt,STMT_MAX);
				if( *stmt == 0)
					continue;
				if( ( *stmt == '\\' && *(stmt + 1) == 'q' ))
					throw new int(0);
				stmt = arrange(new int(1),&stmt,new int(0));
				result = parse(stmt);
				printf("< %s\n", stmt);
				printf(" = %f\n", *result);
			}catch(char* msg){
				printf("ERROR:\n\t%s\n",msg);
			}
		}
	}catch(int* s){
		printf("Exited.\n");
	}
	delete[] stmt;
	delete result;
	return;
}

char* arrange(int* argc,char** argv,int* startIndex){
	char* stmt = new char[STMT_MAX];
	int* j = new int();
	int* i = new int();
	int* k = new int(0);
	for (*i = *startIndex; *i < *argc; ++(*i))
	{
		*j = -1;
		while(*( *( argv + *i ) + ( ++( *j ) ) ) != 0)
			if(( *( *( argv + *i ) + *j ) > ' ') && ( *( *( argv + *i ) + *j ) < '~' ))
				*( stmt + ( (*k)++ ) ) = *( *( argv + *i ) +  *j );
	}
	*(stmt + ((*k)++)) = 0;

	delete i;
	delete j;
	delete k;
	delete startIndex;
	return stmt;
}

double* parse(char* stmt){
	cursor = stmt;
	return expression(new int(-1));
}

double* expression(int* last_pri){

	double* value;
	double* operand = nullptr;
	int* pri = nullptr;
	int* new_pri = nullptr;
	char* op = nullptr;

	value = term();

scan_op_oprand: // === scan_op_oprand ===
	if(*cursor == 0 || *cursor == ')' || *cursor == '}' || *cursor == ']')
		goto end_scan_op_oprand;

	op = cursor;
	if(pri != nullptr) delete pri;
	pri = get_pri(cursor);

	cursor++;
	operand = term();

	if(*cursor != 0 && *cursor != ')' && *cursor != '}' && *cursor != ']'){
		if(new_pri != nullptr) delete new_pri;
		new_pri = get_pri(cursor);

		if(*new_pri > *pri){
			cursor = op + 1;
			operand = expression(pri);
		}
		calculate(value,op,operand);

		if(*last_pri >= *new_pri)
			goto end_scan_op_oprand;

		goto scan_op_oprand;
	}
	else
		calculate(value,op,operand);

end_scan_op_oprand: // === end_scan_op_oprand ===

	if(operand != nullptr) delete operand;
	if(pri != nullptr) delete pri;
	if(new_pri != nullptr) delete new_pri;

	return value;
}

double* term(){
	bool* minus = new bool(false);
	double* result_tmp = new double(0);

	if(*cursor == '-' || *cursor == '+'){
		*minus = *cursor == '-';
		cursor++;
	}
	if(*cursor == '(' || *cursor == '{' || *cursor == '['){
		cursor++;
		result_tmp = expression(new int(-1));
		cursor++;
		goto found;
	}

	if((*cursor >= '0' && *cursor <= '9') || *cursor == '.'){
		result_tmp = digit();
		goto found;
	}

	if(*cursor == '"'){
		result_tmp = use_file();
		goto found;
	}

	if(*str_eq((char*)"exp"))
		*result_tmp = exp(*term());
	else if(*str_eq((char*)"sin"))
		*result_tmp = sin(*term());
	else if(*str_eq((char*)"cos"))
		*result_tmp = cos(*term());
	else if(*str_eq((char*)"tan"))
		*result_tmp = tan(*term());
	else if(*str_eq((char*)"cot"))
		*result_tmp = 1.0/tan(*term());
	else if(*str_eq((char*)"sec"))
		*result_tmp = 1.0/cos(*term());
	else if(*str_eq((char*)"csc"))
		*result_tmp = 1.0/sin(*term());
	else
		throw "Unknown Symbol!";
	
	found:
	if(*cursor == '!'){
		*result_tmp = Gamma(*result_tmp + 1);
		cursor++;
	}
	if(*minus)
		*result_tmp = -*result_tmp;
	delete minus;
	return result_tmp;
}

void calculate(double* value,char* op,double* operand){
	switch(*op){
	case '+':
		*value += *operand;
		break;
	case '-':
		*value -= *operand;
		break;
	case '*':
		*value *= *operand;
		break;
	case '/':
		*value /= *operand;
		break;
	case '%':
		*value = fmod(*value,*operand);
		break;
	case '^':
		*value = pow(*value,*operand);
		break;
	default:
		throw "Unknown op!";
	}
}

inline void read_dig(int *int_r){
	*int_r *= 10;
	*int_r += *cursor - '0';
	cursor++;
}

double* digit(){
	int* int_r = new int(0);
	int* level = new int(0);

	while(*cursor >= '0' && *cursor <= '9')
		read_dig(int_r);
	if(*cursor == '.'){
		cursor++;
		
		while(*cursor >= '0' && *cursor <= '9'){
			read_dig(int_r);
			(*level)++;
		}
	}
	double* result_tmp = new double(*int_r);
	*result_tmp *= pow(0.1,*level);
	delete int_r;
	delete level;
	return result_tmp;
}

double* use_file(){
	char* fname = new char[STMT_MAX];
	int* i = new int(0);
	double* result_tmp;
	char* cursor_;
	cursor++;
	while((*(cursor)) != '"' && *(cursor) != 0)
		*(fname + (*i)++) = *(cursor++);
	*(fname + *i) = 0;
	cursor_ = ++cursor;
	try{
		result_tmp = use_file(fname);
		cursor = cursor_;
	}catch(int* s){
		throw "File open failed!";
	}
	delete[] fname;
	delete i;
	return result_tmp;
}

int* get_pri(char* op){
	switch(*cursor){
	case '+':
	case '-':
		return new int(0);
	case '*':
	case '/':
		return new int(1);
	case '%':
		return new int(2);
	case '^':
		return new int(3);
	default:
		throw "Unknown op!";
	}
}

bool* str_eq(char* str){
	char* cursor_ = cursor;
	while(*str != 0){
		if(*cursor != *str){
			cursor = cursor_;
			return new bool(false);
		}
		cursor++;
		str++;
	}
	cursor++;
	return new bool(true);
}

/***************************
4101056017 邱冠喻 第三次作業 11/5
4101056017 Chiu Guan-Yu TheThirdHomework 11/5
***************************/
