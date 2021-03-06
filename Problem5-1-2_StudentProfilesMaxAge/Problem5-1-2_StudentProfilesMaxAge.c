// Problem5-1-2_StudentProfilesMaxAge.c : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma warning( disable : 4996 )

struct Student
{
	size_t sno;
	char sname[20];
	size_t sage;
};

typedef struct Student Student;


int main()
{
	Student students[10];
	for (size_t i = 0; i < 10; i++)
	{
		printf("Enter student number: ");
		scanf("%zu", &students[i].sno);
		getchar();
		size_t temp;
		for (temp = 0; temp < i; temp++)
		{
			if (students[temp].sno == students[i].sno)
			{
				break;
			}
		}
		if (temp < i)
		{
			printf("Invalid input\n");
			i--;
			continue;
		}
		printf("Enter student name: ");
		gets_s(students[i].sname, 20);
		printf("Enter student age: ");
		scanf("%zu", &students[i].sage);
		getchar();
	}
	size_t locations[10];
	size_t length = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (length > 0 && students[i].sage > students[locations[length - 1]].sage)
		{
			length = 0;
		}
		if (length == 0 || students[i].sage == students[locations[length - 1]].sage)
		{
			locations[length] = i;
			length++;
		}
	}
	for (size_t i = 0; i < length; i++)
	{
		printf("%zu\n", students[locations[i]].sno);
		puts(students[locations[i]].sname);
		printf("%zu\n", students[locations[i]].sage);
	}
	return 0;
}

