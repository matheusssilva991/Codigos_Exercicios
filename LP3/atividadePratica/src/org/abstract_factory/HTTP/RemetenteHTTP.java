package org.abstract_factory.HTTP;
import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;

public class RemetenteHTTP implements IRemetente {


    @Override
    public void connect(String enderecoDeDestino)
    {
        System.out.println("Conectando ao endereço:\t" + enderecoDeDestino+".HTTP");
    }

    @Override
    public void autenticar()
    {
        System.out.print("Autenticacao HTTP");
    }

    @Override
    public void send(IPacote dados)
    {
        System.out.println("Enviando dados...");
    }

    @Override
    public void close()
    {
        System.out.println("Encerrando HTTP");
    }
}
