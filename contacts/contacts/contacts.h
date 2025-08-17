#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


#define DEFALT_SZ 3

#define PEOOLE_MAX 100
#define NAME_MAX 20
#define SEX_MAX 12
#define TELE_MAX 16
#define ADDR_MAX 28


typedef struct PeoInfo
{
	int serial;
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];

}PeoInfo;

//¾²Ì¬°æ±¾
//typedef struct Contacts
//{
//	PeoInfo date[PEOOLE_MAX];
//	int count;
//}Contacts;


typedef struct Contacts
{
	PeoInfo *date;
	int count;
	int capacity;
}Contacts;

enum OpNum
{
	EXIT,
	ADD,
	DEL,
	SEACRH,
	MOD,
	SHOW,
	SORT,

};

enum ModOpNum
{
	MOD_EXIT,
	MOVE_TO,
	EXCHANG,
	MOD_ALL,
	NAME,
	AGE,
	SEX,
	TELE,
	ADDR
};


int charToInt(char* s);

int LoadContacts(Contacts* pc);


int SaveContacts(const Contacts* pc);


int Initdate(Contacts* pc);

void DestroyContacts(Contacts* pc);

void AddPeo(Contacts* pc);

void DelPeo(Contacts* pc);

void SearchPeo(Contacts* pc);

void ModDate(Contacts* pc);

void ShowDate(Contacts* pc);

void SortDate(Contacts* pc);
