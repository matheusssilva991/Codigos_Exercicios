package org.abstract_factory.COAP;

import org.abstract_factory.IPacote;

public class PacoteCOAP implements IPacote {

    @Override
    public void prepararDados(String dados)
    {
        System.out.println("Preparando Dados com COAP");
    }

    @Override
    public  void criptografar()
    {
        System.out.println("Sem Criptografia");
    }

}
