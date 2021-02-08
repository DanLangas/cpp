#include <iostream>
using namespace std;

struct nod
{
    int inf;
    nod *next;
};
nod *prim=NULL;
int opt=1,x,y;

void add_inceput(nod *&prim,int x);
void parcurge(nod *prim);
void add_sfarsit(nod *&prim,int x);
nod *cauta(nod *prim,int x);
void inserare_dupa(nod *&prim,nod *p,int x);
void inserare_inainte(nod *&prim,nod *p,int x);
void sterge(nod *&prim,nod *p);
void ordonare(nod *prim);

int main()
{
    nod *p;
        do
    {
        cout<<"1. adaugare la inceput"<<endl;
        cout<<"2. adaugare la sfarsit"<<endl;
        cout<<"3. parcurge"<<endl;
        cout<<"4. cautare element"<<endl;
        cout<<"5. inserare dupa un element"<<endl;
        cout<<"6. inserare inaintea unui element"<<endl;
        cout<<"7. stergerea unui element din lista"<<endl;
        cout<<"8. ordonarea listei"<<endl;
        cout<<"0. iesire"<<endl;
        cout<<"alege optiunea:";cin>>opt;
        switch (opt)
        {
            case 1:cout<<"inf:";cin>>x;
                add_inceput(prim,x);
                break;
            case 2:cout<<"inf:";cin>>x;
                add_sfarsit(prim,x);
                break;
            case 3:parcurge(prim);break;
            case 4:cout<<"x=";cin>>x;
                   p=cauta(prim,x);
                    if (p)
                      cout<<p->inf<<endl;
                   break;
            case 5:cout<<"nodul dupa care inserez=";cin>>y;
                    p=cauta(prim,y);
                    if(p)
                    {
                        cout<<"x=";cin>>x;
                        inserare_dupa(prim,p,x);
                    }
                    else
                      cout<<"nodul nu exista";
                    break;
            case 6:cout<<"nodul inaintea caruia inserez=";cin>>y;
                    p=cauta(prim,y);
                    if(p)
                    {
                        cout<<"x=";cin>>x;
                        inserare_inainte(prim,p,x);
                    }
                    else
                      cout<<"nodul nu exista";
                    break;
             case 7:cout<<"nodul care trebuie sters:"; cin>>x;
                    p=p=cauta(prim,x);
                    if(p)
                      sterge(prim,p);
                    break;
             case 8:ordonare(prim);
        };
    }while (opt!=0);
    return 0;
}
void add_inceput(nod *&prim,int x)
{
    nod *p;
    p=new nod;
    p->inf=x;
    p->next=prim;
    prim=p;
}
void add_sfarsit(nod *&prim,int x)
{
    nod *p,*q;
    p=new nod;
    p->inf=x;
    p->next=NULL;
    if(!prim)
        prim=p;
    else
       {
           q=prim;
           while(q->next)
              q=q->next;
           q->next=p;
       }
}
void parcurge(nod *prim)
{
    nod *p=prim;
    while(p)
        {cout<<p->inf<<" ";
         p=p->next;
        }
    cout<<endl;
}
nod *cauta(nod *prim,int x)
{
    nod *p=prim;
    while(p && p->inf!=x)
       p=p->next;
    return p;
}
void inserare_dupa(nod *&prim,nod *p,int x)
{
    nod *q=new nod;
    q->inf=x;
    q->next=p->next;
    p->next=q;
}
void inserare_inainte(nod *&prim,nod *p,int x)
{
    nod *q=new nod;
    *q=*p;
    p->inf=x;
    p->next=q;

}
void sterge(nod *&prim,nod *p)
{
    nod *q;
    if(p==prim)
    {
        prim=prim->next;
        delete p;
    }
    else
        if(p->next==NULL)
            {
                q=prim;
                while(q->next->next)
                    q=q->next;
                q->next=NULL;
                delete p;
            }
        else
        {
            q=p->next;
            *p=*q;
            delete q;
        }
}

void ordonare(nod *prim)
{
    nod *p,*q; int aux;
    p=prim;
    while(p->next)
    {
        q=p->next;
        while(q)
        {
            if(p->inf>q->inf)
            {
               aux=p->inf;
               p->inf=q->inf;
               q->inf=aux;
            }
            q=q->next;
        }
        p=p->next;
    }
}
