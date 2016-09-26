#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

char separarFuncao(string, char[], char[]); // função para separar a função da entrada, Ex: f(x) = x^2 * x^3  >>>  x^2 * x^3

void separarExpressoes(char[],char[],char[], char, int);  // função para separar as 2 expressões da função, Ex: x^2 * x^3 >>> (x^2)  (x^3) 

void derivar(char[], char[]);  // função para derivar as expressões, Ex: x^2 >>> 2x

void print(char, char[], char[], char[], char[], char[]);  // função para dar a saida para o usuário

int main(){
    string entrada;
    char tipo;
    
    cout << "Informe sua entrada no formato:  f(x) = x^2 * x^3  (com os espaços)" << endl;
    
    
    
    getline(cin, entrada);
    
    int tamEntrada = entrada.length() - 6;
    
    char comecoSaida[100] = {0};
    
    char funcao[100] = {0};
    
    // Lista de funcoes testadas
    // quaisquer funcao diferente 
    // nao esta no escopo do programa
    // e nao cai na garantia.
    // no refunds allowed
    // todos os direitos reservados
    // Nascimento e Gonçalves SA

    //f(x) = x^2 * x^3 
    //f(x) = x^4 * 2x^4
    //f(x) = 3x^2 * x^6
    //f(x) = 2x^3 * x^2
    //f(x) = 3x^3 * 3x^2
    
    //f(x) = x^3 / x^2
    //f(x) = 3x^3 / x^4
    //f(x) = 2x^2 / 3x^3
    //f(x) = 3x^2 / 2x^3
    //f(x) = x^2 / 2x^3
    
    tipo = separarFuncao(entrada, funcao, comecoSaida);
    
    char primeiraExp[100] = {0};
    char segundaExp[100] = {0};
    char primeiraExpDerivada[100] = {0};
    char segundaExpDerivada[100] = {0};
    
    
    separarExpressoes(funcao, primeiraExp, segundaExp, tipo, tamEntrada);
    
    derivar(primeiraExp, primeiraExpDerivada);
    derivar(segundaExp, segundaExpDerivada);
    
    
    print(tipo, primeiraExp, primeiraExpDerivada, segundaExp, segundaExpDerivada, comecoSaida);

    return 0;
    
}

char separarFuncao(string entrada, char funcao[], char comecoSaida[]){
    bool comeco = false;
    
    char tipo;
    
    int j = 0;
    int h = 0;
    
    for(int i = 0; i < 100; i++){
        if(entrada[i] == '='){
            comeco = true;
            i++;
            i++;
            
        }
        
        
        
        
        if(comeco){
            funcao[j] = entrada[i]; 
            j++;
        }
        else{
            comecoSaida[h] = entrada[i];
            h++;
        }
    }
    
    
    
    
    for(int i = 0; i < 100; i++){
        if(isspace(funcao[i])){
            i++;
            tipo = funcao[i];
            break;
        }
        
    }
    
    
    return tipo;

}

void separarExpressoes(char funcao[], char primeiraExp[], char segundaExp[], char tipo, int tamEntrada){
    bool meio = false;
    int j = 0;
    
    for(int i = 0; i < tamEntrada; i++){
        
        if(!meio && !isspace(funcao[i]) && funcao[i] != tipo){
            primeiraExp[j] = funcao[i];
            j++;
        }
        
        if(meio && !isspace(funcao[i]) && funcao[i] != tipo){
            segundaExp[j] = funcao[i];
            j++;
        }
        
        if(funcao[i] == tipo){
            meio = true;
            j = 0;
        }
        
        
        
    }
    
    
}


void derivar(char expressao[], char derivada[]){
    bool var = false;
    bool expo = false;
    char variavel;
    char exponencial = '1';
    char numeral;
    int numeralN;
    int exponencialN;
    
    for(int i = 0; i < 100; i++){
        if((expressao[i] >= 'a' && expressao[i] <= 'z') || (expressao[i] >= 'A' && expressao[i] <= 'Z')){
            variavel = expressao[i];
            var = true;
        }
    }
    
    if(!var){
       derivada[0] = '1';
    }
    else{
        for (int i = 0; i < 100; i++){
            if(expressao[i] == '^'){
                expo = true;
                
                if(expressao [i + 1] == variavel){
                    exponencial = expressao[i + 2];
                }
                else{
                    exponencial = expressao[i + 1];
                }
            
                if(expressao[i - 1] == variavel && isdigit(expressao[i - 2])){
                    numeral = expressao[i - 2];
                }
                else if(isdigit(expressao[i - 1])){
                    numeral = expressao[i - 1];
                }
                else{
                    numeral = '1';
                }
            }
        }
        
        numeralN = numeral - '0';
        exponencialN = exponencial - '0';
        
        stringstream ss;
        
        numeralN = numeralN * exponencialN;
        exponencialN = exponencialN - 1;
        
        char a, b;
        
        ss << numeralN << exponencialN;
        
        ss >> a >> b;
        
        if(!expo){
            derivada[0] = a;
        }
        
        
        else if(b == '1'){
            derivada[0] = a;
            derivada[1] = variavel;
        }
        
        else{
            derivada[0] = a;
            derivada[1] = variavel;
            derivada[2] = '^';
            derivada[3] = b;
        } 
        
        
    }
    
    return;
    
}

void print(char tipo, char primeiraExp[], char primeiraExpDerivada[], char segundaExp[], char segundaExpDerivada[], char comecoSaida[]){
    
    for(int i = 0; i < 100; i++){
        cout << comecoSaida[i];
        
        if(comecoSaida[i + 1] == '('){
            cout << "'";
        }
    }
    
    cout << "= ";
    
    if(tipo == '*'){
        for(int i = 0; i < 100; i++){
            cout << primeiraExpDerivada[i];
            
        }    
        
        cout << " * ";
        
        for(int i = 0; i < 100; i++){
            cout << segundaExp[i];
        } 
        
        cout << " + ";
         
        for(int i = 0; i < 100; i++){
            cout << primeiraExp[i];
        } 
        
        cout << " * ";
        
        for(int i = 0; i < 100; i++){
            cout << segundaExpDerivada[i];
        } 
        
        cout << endl;
    }
    
    else if(tipo == '/'){
        
        cout << "(";
        
        for(int i = 0; i < 100; i++){
            cout << primeiraExpDerivada[i];
            
        }    
        
        cout << " * ";
        
        for(int i = 0; i < 100; i++){
            cout << segundaExp[i];
        } 
        
        cout << " - ";
         
        for(int i = 0; i < 100; i++){
            cout << primeiraExp[i];
        } 
        
        cout << " * ";
        
        for(int i = 0; i < 100; i++){
            cout << segundaExpDerivada[i];
        } 
        
        cout << ")";
        
        cout << " / ";
        
        cout << "(";
        
        for(int i = 0; i < 100; i++){
            cout << segundaExp[i];
        }         
        
        cout << ")^2";
        
        
        cout << endl;        
        
    }
    
    return;

}