#include "polynom2_header.h"

List *Creation(int de, int co)
{
    List *T;
    T=(List*)malloc(sizeof(List));
    T->deg=de;
    T->coef=co;
    return(T);
}

void PrintP(List *P)
{
    int k=0;
    List *C=P;
    cout<<"P(x)= ";
    while(C)
    {
        if(C->coef)
            {
                if((C->coef)!=1)
                   {
                        cout<<C->coef;
                        ++k;
                        if(C->deg)
                            cout<<"*";
                   }
                if(C->deg)
                    {
                        cout<<"x";
                        ++k;
                        if((C->deg)!=1)
                            cout<<"^"<<C->deg;
                    }

                if(C->next)
                    cout<<" + ";
            }
        C=C->next;
    }
    if(!k)
        cout<<k;
    cout<<endl;
}

void Push(List *P, List *T)
{
    List *C=P;
    while(C->next)
        C=C->next;
    C->next=T;
    T->next=NULL;
}

void CCreation(List **A, int n)
{
    int i,d,c;
    cout<<endl<<"Deg Coef"<<endl;
    for(i=0;i<n;++i)
    {
        cin>>d>>c;
        Push(*A, Creation(d,c));
    }
    //PrintP(*A);
}

void DeleteThis(List **A, int de)
{
    if(((*A)->next)->deg==de)
    {
        List *z=(*A)->next;
        (*A)->next=z->next;
        //cout<<z->id<<endl;
        //free(z);
    }
    else
    {
        //List *y;
        List *C=*A;
        while ((C->next)->deg!=de)
            C=C->next;
        //y=(C->next);
        C->next=(C->next)->next;
        //free(y);
    }
}

List *FindLink(List *A, int de)
{
    List *C=A;

    while((C->deg)!=de)
    {
        C=C->next;
    }
    return(C);
}

void Podobnie(List **P)
{
    List *C=*P;
    while(C)
    {
        List *A=C->next,*B=C;
        while(A)
        {
            if((A->deg)==(C->deg))
            {
                C->coef+=A->coef;
                B->next=A->next;
                A=B;
            }
            B=A;
            A=A->next;
        }
        C=C->next;
    }

}

void Menu(List **A)
{
    int command;
    int n;
    cout<<"1 - Dobavit' nescol'ko"<<endl<<"2 - Dobavit' odin"<<endl<<"3 - Udalit' po stepeni"<<endl<<"4 - Privesti podobnie"<<endl<<"5 - Print"<<endl<<"0 - Zavershenie raboti"<<endl<<"Enter the command:"<<endl;
    cin>> command;
    if(command==1)
    {

        cout<<"Skol'ko?:"<<endl;
        cin>>n;
        CCreation(A, n);
    }
    if(command==2)
    {
        cout<<"Deg Coef"<<endl;
        int d,c;
        cin>>d>>c;
        Push(*A, Creation(d,c));
    }
    if(command==3)
    {
        cout<<"Kogo udalit'?"<<endl;
        int de;
        cin>>de;
        DeleteThis(A, de);
    }
    if(command==4)
    {
        Podobnie(A);
    }
    if(command==5)
    {
        PrintP(*A);
    }
    if(command)
        Menu(A);
}
