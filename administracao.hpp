#ifndef ADMINISTRACAO_HPP
#define ADMINISTRACAO_HPP
#include <vector>
#include "estacao.hpp"

using namespace std;

class Administracao{
    private:
        int contador_estacoes;
        int max_estacoes;
        int tempo_desconto_limite;
        vector<double> descontos;
        vector<Estacao> estacoes;
        double** custos;

    public:
        Administracao();

        void inicializar_custos();
        void inicio();
        double get_minimo(int);
        void matriz_custos();
};

#endif