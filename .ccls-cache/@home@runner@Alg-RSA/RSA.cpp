#include "RSA.hpp"

void RSA::Enemenos1(int128_t &t,int128_t &u, int128_t v) // privado, que funcione en p y q.
{
    t=0;
    u=v-1;
    while(u%2==0)
    {
        t++;
        u=u/2;
    }
}

bool RSA::DetectorCompuestos(int128_t v,int128_t u,int128_t t,int128_t a)
{
    int128_t a1=EXPMOD(a,u,v);
    if(a1==1 or a1==v-1)
    {
        return 0;
    }
    
    for(int128_t i=1;i<=t;i++)
    {
        a1=(a1*a1)%v;
        if(a1==v-1)
        {
            return 0;
        }
    }
    return 1;
}

int128_t RSA::EXP(int128_t a,int128_t x)
{
    int128_t v1,v2;
    if(x==0)
    {
        return 1;
    }
    else if(x%2!=0)
    {
        v1=EXP(a, x-1);
        return (v1*a);
    }
    else
    {
        v2=EXP(a,x/2);
        return (v2*v2);
    }
}

int128_t RSA::EXPMOD(int128_t a,int128_t x,int128_t n)
{
    int128_t r1,r2;
    if(x==0)
    {
        return 1;
    }
    else if(x%2!=0)
    {
        r1=EXPMOD(a, x-1, n)%n;
        return (r1*a)%n;
    }
    else
    {
        r2=EXPMOD(a, x/2, n)%n;
        return (r2*r2)%n;
    }
}

int128_t RSA::Euclides(int128_t a,int128_t b)
{
    if(b==0)
    {
        return a;
    }
    return Euclides(b, a%b);
}

bool RSA::MillerRabin(int128_t v,int128_t s)
{
    int128_t u,t,a;
    Enemenos1(t, u, v);
    for(int i=1;i<s;i++)
    {
        a=2 + rand()%(v-3);
        if(DetectorCompuestos(v, u, t, a))
        {
            return 0;
        }
    }
    return 1;
}

int128_t RSA::RANDB(int b)
{
    int128_t n1,m;
    n1=3 + rand()%EXP(2, b)-1;
    m=EXP(2, b-1)+1;
    n1 =n1 | m;
    return n1;
}

int128_t RSA::RANDBP(int b)
{
    int128_t n1=RANDB(b);
    while(!MillerRabin(n1, 4))
    {
        n1+=2;
    }
    return n1;
}

int128_t RSA::EUEXT(int128_t a,int128_t b,int128_t *x,int128_t *y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    int128_t x1,y1,m;
    m=EUEXT(b, a%b, &x1, &y1);
    *x=y1;
    *y=x1-(a/b)*y1;
    return m;
}

int128_t RSA::PhiN()
{
    int128_t ph;
    ph=(p-1)*(q-1);
    return ph;
}
int128_t RSA::GenerarE()
{
    int128_t e1;
    e1=2 + rand()%phin;
    while(Euclides(e1, phin)!=1)
    {
        e1=2 + rand()%phin;
    }
    return e1;
    
}
int128_t RSA::InversoE()
{
    int128_t y,d1;
    
    EUEXT(e, phin, &d1, &y);
    ModPhi(d1, phin);
    
    return d1;
}

void RSA::ModPhi(int128_t &v,int128_t p)
{
    if(v<0)
    {
        return ModPhi(v=p+v,p);
    }
    else if (v>p)
    {
        return ModPhi(v=v-p,p);
    }
    
}

/*
int128_t* RSA::CifrarF()
{
    string m;
    cout<<endl<<"------CIFRAR-------"<<endl;
    cout<<"Digite frase: ";getline(cin,m);
    
    tam=(int)size(m);
    int128_t *c=new int128_t[tam];
    for(int i=0;i<tam;i++)
    {
        c[i]=EXPMOD((int128_t)m[i], e, n);
    }
    for(int i=0;i<tam;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    return c;
}

char* RSA::DescifrarF()
{
    //int tam=sizeof(C)/sizeof(C[0]); => ERA el tamaño del PUNTERO!!!!!
    char* mn=new char[tam];
    
    cout<<endl<<"------DESCIFRAR-------"<<endl;
    for(int i=0;i<tam;i++)
    {
        mn[i]=(char)EXPMOD(C[i], d, n);
    }
    for(int i=0;i<tam;i++)
    {
        cout<<mn[i];
    }
    cout<<endl;
    return mn;
}
*/

void RSA::TablaRSA()
{
    cout<<"---------------------TABLA-RSA64---------------------"<<endl;
    cout<<"   m    "<<"      e      "<<"     d      "<<"           n          "<<"           C = m ^(e) mod n     "<<"   m ^(d)  mod  n      "<<"  m   "<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<10;i++)
    {
        RSA_KEY_GENERATOR();
        int128_t m=RANDB(16);
        cout<<endl<<m<<"  "<<e<<"  "<<d<<"   "<<n<<"    "<<CifrarL(m)<<"         "<<DescifrarL(CifrarL(m))<<"            "<<m<<"      "<<endl;
        cout<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
        
    }
    
    Menu();
}

int128_t RSA::CifrarL(int128_t m)
{
    m=EXPMOD(m,e,n);
    return m;
}

int128_t RSA::DescifrarL(int128_t c)
{
    c=EXPMOD(c, d, n);
    return c;
}

void RSA::setTodos()
{
    cout<<endl<<"Llave Privada: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"d: "<<d<<endl;
    cout<<"--------------"<<endl;
    cout<<"φ(n): "<<phin<<endl;
    cout<<"--------------"<<endl;
    cout<<"Llave Publica: "<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"--------------"<<endl;
    
}
void RSA::RSA_KEY_GENERATOR()
{
    p=RANDBP(32);
    q=RANDBP(32);
    n=p*q;
    phin=PhiN();
    e=GenerarE();
    d=InversoE();
}

void RSA::Menu()
{
    int op;
    cout<<endl<<"----------RSA---------"<<endl;
    cout<<"1.- Generador de llaves."<<endl;
    cout<<"2.- Tabla RSA-64."<<endl;
    cout<<"3.- Salir."<<endl;
    cout<<"Opcion? ";cin>>op;
    
    if(op==1)
    {
        RSA_KEY_GENERATOR();
        setTodos();
        Menu();
    }
    else if(op==2)
    {
        TablaRSA();
    }
    else
    {
        exit(1);
    }
    
    
}
