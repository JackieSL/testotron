#pragma once
#include <iostream>

#define WHITE "\x1B[37m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"



struct Test
{
	std::string name;
	bool Result;
	std::string* OutputData;
	int DataEntryCount;
	void (*FuncToTest)(bool&, int&, std::string*);

	Test() : DataEntryCount(0), OutputData(new std::string[125]), name("Undefined test"), Result(false), FuncToTest(NULL) 
	{

	}

	Test(std::string n, void(*f)(bool&, int&, std::string*))
		: name(n), Result(false), OutputData(new std::string[125]), DataEntryCount(0), FuncToTest(f)
	{

	}

	void Run()
	{
		FuncToTest(Result, DataEntryCount, OutputData);
		if (!Result)
		{
			std::cout << "Test " << name << ":" << RED << " Failed!" << WHITE << std::endl;
			for (int i = 0; i < DataEntryCount; i++)
			{
				std::cout << "Error " << i + 1 << ": " << OutputData[i] << std::endl;
			}
		}
		else
		{
			std::cout << "Test " << name  << ":" << GREEN << " Success!" << WHITE << std::endl;
			if(OutputData[0].compare("") != 0)
				std::cout << "Result: " << OutputData[0] << std::endl;
		}
	}
};




