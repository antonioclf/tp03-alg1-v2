#ifndef ESTACAO_HPP
#define ESTACAO_HPP

class Estacao{
    private:
        int tempo;
        int custo;

    public:
        Estacao(){};
        Estacao(int tempo, int custo);
        int get_tempo();
        double ajuste_preco(double desconto);
};

#endif