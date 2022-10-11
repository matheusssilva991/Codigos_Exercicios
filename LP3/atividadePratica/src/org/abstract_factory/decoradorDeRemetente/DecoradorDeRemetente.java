package org.abstract_factory.decoradorDeRemetente;
import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;

public abstract class DecoradorDeRemetente implements IRemetente
{

    public abstract void autenticar();
    public abstract void connect(String enderecoDeDestino);
    public abstract void send(IPacote dados);
    public abstract void close();
}
