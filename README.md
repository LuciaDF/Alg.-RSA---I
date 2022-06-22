# Alg.-RSA---I

## 1.- Objetivo:

 <br />

Generar tanto las llaves publicas y privadas como el cifrado y descifrado del Algoritmo RSA.
 <br />
  <br />
  
## 2.- Algoritmos:
 <br />
 
* Euclides

* Euclides Extendido
  
* Detector de Compuestos
* Miller Rabin
* Random Bits (RANDB)
* RandomGen_Primos (RANDBP)

  
<br />
  <br />
  
## Acerca de:

 <br />

### *Euclides*:
 <br />
 
Este algoritmo de Euclides, este en específico, calcula el máximo común divisor de dos números enteros positivos.

 <br />
 
### *Euclides Extendido*:

 <br />
 
Basándose en el teorema el cual el máximo común divisor de *a* y *b*, dos números enteros positivos, es el mínimo elemento de combinaciones lineales entre ambos números.


<img width="297" alt="Euclides Extendido" src="https://user-images.githubusercontent.com/62950378/174401085-29386bf0-cf9e-40a8-badb-df13006d7127.png">

 <br />

### *Detector de Compuestos*:


Para un numero compuesto *n*, *n -1* es primo y se puede escribir de la siguiente manera:

 <br />

<img width="200" alt="" src="https://user-images.githubusercontent.com/62950378/170874057-c5eb4b7c-b0a9-4968-9882-f7f9ab163862.png">

 <br />
 
Esto nos permite utilizarlo para factorizar en el Pequeño Teorema de Fermat (*Test de Primalidad de Fermat*):
 <br />
  <br />
  
<img width="1000" alt="" src="https://user-images.githubusercontent.com/62950378/170874109-621e6d3d-757f-479d-9219-9537a04c1e20.png">
 <br />
 
Si n es primo tendrá que dividir a todos los factores, si al menos divide a uno será pseudoprimo en la base *a*, si no cumple ninguna de estas significa que es compuesto. Con la condición, del Test de Primalidad de Fermat, que 2 < *a* ≤ n-1.


 <br />

###  *Miller Rabin*


Con la ayuda del Detector de Compuestos, el algoritmo Miller Rabin calcula los respectivos *t* y *u* de *n - 1*. Finalmente, determinamos una variable *s* el cual se encargará del grado de confianza, es decir, medir cuan fuerte es un pseudoprimo. Un pseudoprimo fuerte tiene altas probabilidades de ser primo por lo tanto, entre más valor le otorguemos a *s*, más probabilidad tendrá de que sea un pseudoprimo fuerte.
 <br />
 <br />
  <br />
 ###  *Random Bits (RANDB)*

Algoritmo que te permite generar un numero aleatorio de *b* bits. Origina un primo aleatorio el cual, con la ayuda de una "máscara", si su último digito es 1 significa que es impar, si es 0 es par.
 
   <br />
    <br />
     <br />
     
### *RandomGen_Primos (RANDBP)*
 
Verifica que un numero de *b* bits sea primo. Con la ayuda de Miller Rabin, si este resulta no ser primo entonces tiene que ir aumentando en 2 unidades hasta ser primo.

 <br />
   <br />
    <br />

### *Algoritmo RSA*

Las siglas RSA proviene de sus creadores: **Ron Rivest**, **Adi Shamir** y **Leonard Adleman**. Publicado en 1979 como respuesta a un problema abierto de **Diffie – Hellman** acerca de un nuevo sistema criptográfico de **clave pública**. El algoritmo consiste en que cada usuario tiene su propio clave publica y privada, cuando desean comunicarse el emisor cifrará con la clave publica y el receptor descifrará usando la clave privada según corresponda el caso.  Su seguridad radica en la **factorización de números enteros**, por cada usuario se generan dos números primos y al multiplicarlos se genera lo que es una de las llaves públicas. 

<br />
    <br />


#### *Clave Publica*: Consiste en el módulo n y el exponente público (o cifrado) e.
#### *Clave Privada*: Contiene el elemento privado d, p , q y  ϕ( n ) que tambien deben ser secretos.
#### *Cifrado*: Para enviar el mensaje (Bob a Alice) primero se debe converte este (mensaje) a un número m, luego se aplica el cifrado usando la clave pública de Alice e `{\displaystyle c\equiv m^{e}{\pmod {n}}.}`.
#### *Descifrado*:

## 4.- Pseudocodigo:

 <br />

 <img width="446" alt="Euclides" src="https://user-images.githubusercontent.com/62950378/174401275-f4a7f51a-07e5-4491-bf32-c774877b6b39.png">

  <br />
  
<img width="470" alt="Euclides Extendido" src="https://user-images.githubusercontent.com/62950378/174401382-f0b87286-6cd5-493e-a638-465bd22ab50f.png">

   <br />
  
<img width="488" alt="Detector de Compuestos" src="https://user-images.githubusercontent.com/62950378/170874378-9e74d7fa-6d5c-4134-928e-66eac8c8be90.png">

 <br />
 
<img width="587" alt="Miller Rabin" src="https://user-images.githubusercontent.com/62950378/170874429-4fd772b9-d6c6-4331-83d8-a0fe7f83fb0f.png">

 <br />

<img width="635" alt=" Random Bits" src="https://user-images.githubusercontent.com/62950378/170877686-670933e9-4f54-4ebd-a7f8-f2abe2f93c86.png">

 <br />
 
<img width="338" alt="RandomGen_Primos" src="https://user-images.githubusercontent.com/62950378/170877764-39cf408e-1da0-4322-b7b2-3eccec91bf2a.png">
 <br />
 <br />
 
## 5.- Lenguaje de Programación:

 <br />
 

|  Lenguaje de Programación  |
|  :---:| 
  |Python  |
  | C++|
  
 <br />
 <br />

 
## 6.- Como instalarlo:

El proyecto está concentrado en el main.cpp el cual se puede descargar o copiar y después añadir a un proyecto ya sea en **Visual Studio** o en **Xcode**.

 <br />
 <br />

 
## 7.- Instalación Extra:

 <br />

Para poder usar  int128_t deberá descargar la libreria Boost:

 ### En MacOs:
 

  **1.** package management system **Brew**:

  * Enlace con pasos:


        https://phoenixnap.com/kb/install-homebrew-on-mac

 **2.** Después descargar **Boost** library:

  * Enlace con pasos:

          http://neutrofoton.github.io/blog/2016/03/27/configure-boost-c-plus-plus-on-xcode/

        
 <br />

  ### En Windows:

  **1.** Descargar libreria Boost.

      https://www.boost.org/users/history/version_1_79_0.html


 <br />
  <br />
  
      
**2.** Seguir las instrucciones del siguiente video para instalar libreria en projecto:

      https://youtu.be/CH_YZ2bePPM
  
 <br />
  <br />
   <br />
   
## 8.- Como usarlo:

Al compilarlo se visualizará un **Menú** el cual al elegir su respectivo número se podrá desplegar el resultado.


```c++

int main()
{ 
    RSA u1;
    
    u1.Menu();
  
    return 0;
}

```





 <br />
 <br />
  <br />
 <br />
 

______


 <br />
 <br />
  <br />
 <br />

