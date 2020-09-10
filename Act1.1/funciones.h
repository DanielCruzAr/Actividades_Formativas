#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <iostream>

class Funciones {
public:
    Funciones(){};
    int sumaIterativa(int n);
    int sumaRecursiva(int n);
    int sumaDirecta(int n);
};

int Funciones::sumaIterativa(int n){ //O(n)
    int acum=0;
    for(int i=1;i<=n;i++){
        acum+=i;
    }
    return acum;
}

int Funciones::sumaRecursiva(int n) { //O(n)
    if(n<1){
        return 0;
    }
    else{
      return n+sumaRecursiva(n-1);
    }
}

int Funciones::sumaDirecta(int n){ //O(1)
    return (n+1)*n/2;
}

#endif // FUNCIONES_H_
