/* hello.cpp */
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class PontoDeInteresse
{
private:
    int codigo;
    int valorTuristico;

public:
    PontoDeInteresse(int codigo, int valorTuristico)
    {
        this->codigo = codigo;
        this->valorTuristico = valorTuristico;
    }
};

class Trecho
{
private:
    int trechoUm;
    int trechoDois;
    double custo;

public:
    Trecho(int trechoUm, int trechoDois, double custo)
    {
        this->trechoUm = trechoUm;
        this->trechoDois = trechoDois;
        this->custo = custo;
    }
};

void leEntradaPrincipal(int &quantidadePontosDeInteresse, int &quantidadeTrechosPossiveis)
{
    string temp;
    getline(cin, temp);
    vector<string> result;
    istringstream iss(temp);
    for (string s; iss >> s;)
        result.push_back(s);

    quantidadePontosDeInteresse = stoi(result.at(0));
    quantidadeTrechosPossiveis = stoi(result.at(1));
}

vector<PontoDeInteresse> leEntradaPontosDeInteresse(int quantidadePontosDeInteresse)
{
    string line;
    vector<PontoDeInteresse> vetorPontosDeInteresse;
    getline(cin, line);
    istringstream iss(line);
    int codigoAtual = 0;
    for (string s; iss >> s;)
    {
        PontoDeInteresse pontoDeInteresseAtual = PontoDeInteresse(codigoAtual, stoi(s));
        codigoAtual++;
        vetorPontosDeInteresse.push_back(pontoDeInteresseAtual);
    }

    return vetorPontosDeInteresse;
}

vector<Trecho> leEntradaTrechos(int quantidadeDeTrechosPossiveis)
{

    vector<Trecho> vetorTrechos;

    for (int i = 0; i < quantidadeDeTrechosPossiveis; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<string> temp;
        for (string s; iss >> s;)
        {
            temp.push_back(s);
        }

        int trechoUm = stoi(temp.at(0));
        int trechoDois = stoi(temp.at(1));
        double custo = stoi(temp.at(2));

        Trecho trechoAtual = Trecho(trechoUm, trechoDois, custo);
        vetorTrechos.push_back(trechoAtual);
    }

    return vetorTrechos;
}

int main()
{
    int quantidadePontosDeInteresse, quantidadeTrechosPossiveis;
    vector<PontoDeInteresse> vetorPontosDeInteresse;
    vector<Trecho> vetorTrechos;
    leEntradaPrincipal(quantidadePontosDeInteresse, quantidadeTrechosPossiveis);
    vetorPontosDeInteresse = leEntradaPontosDeInteresse(quantidadePontosDeInteresse);
    vetorTrechos = leEntradaTrechos(quantidadeTrechosPossiveis);

    return 0;
}