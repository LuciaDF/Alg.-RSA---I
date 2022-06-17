#ifndef RSA_hpp
#define RSA_hpp

#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

using namespace std;

class RSA
{
    int128_t p; // primo 1
    int128_t q; // primo 2
    int128_t d; // clave privada, descifrar
    int128_t e;// clave publica, cifrar
    int128_t n; // n = p*q, clave publica
    int128_t phin; // phi(n)
    
    // Algoritmos Utiles
    
    void Enemenos1(int128_t &t,int128_t &u, int128_t v);
    int128_t EXP(int128_t a,int128_t x);
    int128_t EXPMOD(int128_t a,int128_t x,int128_t n);
    int128_t Euclides(int128_t a,int128_t b);
    int128_t EUEXT(int128_t a,int128_t b,int128_t *x,int128_t *y);
    void ModPhi(int128_t &v,int128_t p);
    

    //Test de Primalidad
    
    bool DetectorCompuestos(int128_t v,int128_t u,int128_t t,int128_t a);
    bool MillerRabin(int128_t v,int128_t s);
    
    // Generadores Primos Aleatorios
    
    int128_t RANDB(int b);
    int128_t RANDBP(int b);
    
    // Setters
    
    int128_t PhiN();
    int128_t GenerarE();// *
    int128_t InversoE();// *

    //
    
    void RSA_KEY_GENERATOR();
    int128_t CifrarL(int128_t m);
    int128_t DescifrarL(int128_t c);
    void TablaRSA();

public:
    
    RSA()
    {
        p=RANDBP(32);
        q=RANDBP(32);
        n=p*q;
        phin=PhiN();
        e=GenerarE();
        d=InversoE();
    }
    ~RSA()
    {
        cout<<"*"<<endl;
    }
    void setTodos();
    void Menu();

};


#endif /* RSA_hpp */

