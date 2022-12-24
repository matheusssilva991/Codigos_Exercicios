package org.abstract_factory;

public interface IRemetente {

    public void connect(String enderecoDeDestino);
    public void autenticar();
    public void send(IPacote dados);
    public void close();
}
