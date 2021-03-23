#include "estacao.hpp"
#include "administracao.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//construtor da classe que administra toda a lógica do problema
Administracao::Administracao(){
    this->contador_estacoes = 0;
    this->max_estacoes = 0;
    this->tempo_desconto_limite = 0;
}

//função para inicializar todo o problema e chamar outros métodos necessários
void Administracao::inicio(){
    //entrada do número de escalas(estações), máximo de estações e o tempo máximo para desconto
    cin >> this->contador_estacoes >> this->max_estacoes >> this->tempo_desconto_limite;

    for (int i = 0; i < this->max_estacoes; i++){
        //atribui os descontos em um vetor
        int desconto;
        cin >> desconto;

        this->descontos.push_back(desconto);
    }

    for (int i = 0; i < this->contador_estacoes; i++){
        int tempo;
        int custo;
        //atribui a cada estação o tempo e o custo dela
        cin >> tempo >> custo;

        this->estacoes.push_back(Estacao(tempo, custo));
    }

    inicializar_custos();
    matriz_custos();
    //calcula o custo mínimo
    double custo_minimo = get_minimo(this->contador_estacoes - 1);
    cout << fixed << setprecision(2) << custo_minimo << endl;

}

void Administracao::inicializar_custos(){
    //inicializa os caminhos de custos para serem analisados 
    this->custos = new double* [this->contador_estacoes];
    for (int i = 0; i < this->contador_estacoes; i++){
        this->custos[i] = new double[this->contador_estacoes];
    }

}

void Administracao::matriz_custos(){
    //ajusta os preços para cada estação visitada e otimiza a busca da função get_minimo
    for (int i = 0; i < this->contador_estacoes; i++){
        int tempo_cum = 0;
        int desconto_cum = 0;
        int estacoes_visitadas = 0;
        double minimo_atual = get_minimo(i -1);

        for (int j = i; j < this->contador_estacoes; j++){
            Estacao Estacao = this->estacoes.at(j);

            if(estacoes_visitadas < this->max_estacoes){
                desconto_cum += this->descontos.at(estacoes_visitadas);
            }
            else{
                desconto_cum = 0;
            }

            this->custos[i][j] = minimo_atual + Estacao.ajuste_preco(desconto_cum / 100.0);
            minimo_atual = this->custos[i][j];
            estacoes_visitadas++;
            tempo_cum += Estacao.get_tempo();

            if(tempo_cum >= this->tempo_desconto_limite){
                desconto_cum = 0;
                tempo_cum = 0;
                estacoes_visitadas = 0;
            }
        }
    }
}
//procura o menor custo dentre as possibilidades
double Administracao::get_minimo(int coluna){

    if(coluna < 0){
        return 0;
    }

    double minimo = this->custos[0][coluna];

    for(int row = 1; row < this->contador_estacoes; row++){
        double custo = custos[row][coluna];

        if(custo < minimo && custo > 0){
            minimo = custo;
        }
    }

    return minimo;
}
