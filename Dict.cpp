#include<iostream>
#include<string>
#include "dbc.h"

#define dict_size 100
using namespace std;


class Dictionary
{
	string keys[dict_size];
	string values[dict_size];
	int Head=0;
public:
	/*
	General Form of a method(using assertions)  :
	Invariant 
	Precondition
	implementation
	postcondition
	invariant
	*/
	
	void Add(string name , string email)
	{

		INVARIANT0(get_size()>=0 && get_size()<dict_size);
		REQUIRE0(get_size()<dict_size && is_key_valid(name) );

		keys[Head] = name;
		values[Head] = email;
		Head++;

		ENSURE0(get_size()<dict_size);
		ENSURE0(Head=get_size());
		INVARIANT0(get_size()>=0 && get_size()<dict_size);
	}
	void Remove(string name)
	{
		INVARIANT0(get_size()>0 && get_size()<dict_size);
		REQUIRE0(is_key_exist(name));


		int index = 0;
		for (int i = 0; i < Head; i++)
		{
			if (keys[i] == name)
			{
				index = i;
				break;
			}
		}

		Head--;

		for (int j = index; j < Head ;j++)
		{
			keys[index] = keys[index + 1];
			values[index] = values[index + 1];

		}
		ENSURE0(!is_key_exist(name));
		ENSURE0(get_size()>0);
		ENSURE0(Head = get_size());
		INVARIANT0(get_size()>0 && get_size()<dict_size);
	}


	// Queries
	void PrintEntries() 
	{
		for (int i = 0; i < Head;i++)
		{
			cout <<"#"<<i<<"-> "<<keys[i]<<"  :  "<<values[i]<<endl;
		}
	}
	string get_email(string name) 
	{

		for (int i = 0; i < Head; i++)
		{
			if (keys[i] == name) return values[i];
		}
		
	}
	int get_size() { return Head; }
	bool is_key_valid(string input_key)
	{
		for (int i = 0; i < Head; i++)
		{
			if (keys[i] == input_key) return false;
		}
		return true;
	}
	bool is_key_exist(string input_key)
	{
		for (int i = 0; i < Head; i++)
		{
			if (keys[i] == input_key) return true;
		}
		return false;
	}
};






int main()
{
	try {
		Dictionary x;
		x.Add("Muhamamd", "muh.nashaat@gmail.com");
		x.Add("Muhamamd Nashaat", "m.nashaat3@gmail.com");
    x.PrintEntries();
    
    cout <<"==============="<<endl;

		x.Remove("Muhammad Nashaat");
		x.PrintEntries();
	}
	catch (DesignByContractException e)
	{
		cout << (string)e << endl;
	}
	return 0;
}
