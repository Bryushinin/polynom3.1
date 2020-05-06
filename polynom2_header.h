#ifndef POLYNOM2_HEADER_H_INCLUDED
#define POLYNOM2_HEADER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct link
{
    int deg;
    int coef;
    struct link *next;
} List;



List *Creation(int de, int co);
void PrintP(List *P);
void Push(List *P, List *T);
void CCreation(List **A, int n);
void DeleteThis(List **A, int de);
List *FindLink(List *A, int de);
void Podobnie(List **P);
void Menu(List **A);

#endif // POLYNOM2_HEADER_H_INCLUDED
