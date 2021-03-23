#include "estacao.hpp"

Estacao::Estacao(int tempo, int custo){
    this->tempo = tempo;
    this->custo = custo;
}

int Estacao::get_tempo(){
    return tempo;
}
//atribuição do desconto ao preço
double Estacao::ajuste_preco(double desconto){
    double novo_preco = (double)custo;

    return (novo_preco- (novo_preco * desconto));
}