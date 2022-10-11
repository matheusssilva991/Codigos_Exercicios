package org.abstract_factory.COAP;

import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;

public class RemetenteCOAP implements IRemetente
{

    @Override
    public void connect(String enderecoDeDestino)
    {
        System.out.println("Conectando ao endereço:\t" + enderecoDeDestino+".COAP");
    }

    @Override
    public void autenticar()
    {
        System.out.print("Autenticacao COAP");
    }

    @Override
    public void send(IPacote dados)
    {
        System.out.println("Enviando dados...");
    }

    @Override
    public void close()
    {
        System.out.println("Encerrando COAP");
    }
}
