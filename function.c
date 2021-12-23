#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void Ex1(char* str)
{
	int start_first_word = 0;
	int end_first_word = 0;
	long long start_last_word = strlen(str) - 1;
	long long end_last_word = strlen(str) - 1;
	int i = 0;

	while (str[start_first_word] == ' ')
	{
		++start_first_word;
		++end_first_word;
	}

	while (str[end_last_word] == ' ')
	{
		--end_last_word;
		--start_last_word;
	}

	while (str[end_first_word] != ' ')
		++end_first_word;
	--end_first_word;

	while (str[start_last_word] != ' ')
		--start_last_word;
	++start_last_word;


	char* str2 = (char*)malloc(strlen(str) * 2);
	if (str2)
	{
		while (i != start_first_word)
		{
			str2[i] = ' ';
			++i;
		}

		long long b = start_last_word;
		while (b <= end_last_word)
		{
			str2[i] = str[b];
			++b;
			++i;
		}
		
		int a = end_first_word + 1;
		while (a < start_last_word)
		{
			str2[i] = str[a];
			++a;
			++i;
		}

		while (start_first_word <= end_first_word)
		{
			str2[i] = str[start_first_word];
			++start_first_word;
			++i;
		}

		while (str[i] != '\0')
		{
			str2[i] = ' ';
			++i;
		}


		str2[strlen(str)] = '\0';

		for (i = 0; i < strlen(str); ++i)
			str[i] = str2[i];
		printf("%s", str);
	}
	else
		printf("ERROR");

}



void Ex2()
{
	struct Marat
	{
		char name[256];
		char surname[256];
		char patronymic[256];
		char gender[256];
		char job[256];
		int year_of_birth;
	};

	int N;
	printf("Enter the number of Marats, pls\n");
	scanf_s("%d", &N);

	struct Marat* Arr = (struct Marat*)malloc(N * sizeof(struct Marat));
	if (Arr == NULL)
	{
		printf("Error");
		exit(0);
	}

	for (int i = 0; i < N; i++)
	{
		printf("Enter the name of %d person, pls\n", i+1);
		scanf_s("%s", Arr[i].name, 256);
		printf("Enter the surname of %d person, pls\n", i + 1);
		scanf_s("%s", Arr[i].surname, 256);
		printf("Enter the patronymic of %d person, pls\n", i + 1);
		scanf_s("%s", Arr[i].patronymic, 256);
		printf("Enter the gender of %d person, pls\n", i + 1);
		scanf_s("%s", Arr[i].gender, 256);
		printf("Enter the job of %d person, pls\n", i + 1);
		scanf_s("%s", Arr[i].job, 256);
		printf("Enter the year of birth of %d person, pls\n", i + 1);
		scanf_s("%d", &Arr[i].year_of_birth);
	}

	for (int i = 0; i < N; i++)
	{
		if (strcmp(Arr[i].job, "engineer") == 0)
		{
			if (strcmp(Arr[i].gender, "M") == 0)
			{
				if (2021 - Arr[i].year_of_birth >= 65)
				{
					printf("%s %s %s, %s, %s, %d", Arr[i].name, Arr[i].surname, Arr[i].patronymic, Arr[i].gender, Arr[i].job, Arr[i].year_of_birth);
				}
			}
			else
			{
				if (2021 - Arr[i].year_of_birth >= 60)
				{
					printf("%s %s %s, %s, %s, %d", Arr[i].name, Arr[i].surname, Arr[i].patronymic, Arr[i].gender, Arr[i].job, Arr[i].year_of_birth);
				}
			}
		}
	}
}
