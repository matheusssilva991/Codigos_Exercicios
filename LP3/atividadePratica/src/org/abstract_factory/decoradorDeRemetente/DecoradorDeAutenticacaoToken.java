package org.abstract_factory.decoradorDeRemetente;
import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;
import org.abstract_factory.decoradorDeRemetente.DecoradorDeRemetente;

public class DecoradorDeAutenticacaoToken extends DecoradorDeRemetente {

    private IRemetente remetente;

    public DecoradorDeAutenticacaoToken(IRemetente remetente)
    {
        this.remetente = remetente;
    }

    @Override
    public void connect(String enderecoDeDestino)
    {
        this.remetente.connect(enderecoDeDestino);
        
    }

    @Override
    public void send(IPacote dados) {
        this.remetente.send(dados);
        
    }

    @Override
    public void close()
    {
        this.remetente.close();
    }

    @Override
    public void autenticar()
    {
        this.remetente.autenticar();
        System.out.println(" com Token");
    }
    
}
