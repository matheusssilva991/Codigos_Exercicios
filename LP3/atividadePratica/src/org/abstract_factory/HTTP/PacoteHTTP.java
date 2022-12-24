package org.abstract_factory.HTTP;

import org.abstract_factory.IPacote;

public class PacoteHTTP implements IPacote {

    public void prepararDados(String dados)
    {
        System.out.println("Preparando dados HTTP");
    }
    public  void criptografar()
    {
        System.out.println("Sem Criptografia");
    }

}


