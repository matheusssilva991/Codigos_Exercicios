package org.abstract_factory.decoradorDePacote;

import org.abstract_factory.IPacote;

public class DecoradorDePacoteCriptografiaRSA extends DecoradorDePacote{

    private IPacote pacote;

    public DecoradorDePacoteCriptografiaRSA(IPacote pacote)
    {
        this.pacote = pacote;
    }

    @Override
    public  void criptografar()
    {
        System.out.println("Criptografado com RSA");
    }

    @Override
    public void prepararDados(String dados)
    {
        pacote.prepararDados(dados);
    }
}
