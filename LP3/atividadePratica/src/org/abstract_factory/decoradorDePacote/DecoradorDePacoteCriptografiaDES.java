package org.abstract_factory.decoradorDePacote;

import org.abstract_factory.IPacote;

public class DecoradorDePacoteCriptografiaDES extends DecoradorDePacote{

    private IPacote pacote;

    public DecoradorDePacoteCriptografiaDES(IPacote pacote)
    {
        this.pacote = pacote;
    }

    @Override
    public  void criptografar()
    {
        System.out.println("Criptografado com DES");
    }

    @Override
    public void prepararDados(String dados)
    {
        pacote.prepararDados(dados);
    }
}
