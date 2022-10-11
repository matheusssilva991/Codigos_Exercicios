package org.abstract_factory.decoradorDeRemetente;
import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;
import org.abstract_factory.decoradorDeRemetente.DecoradorDeRemetente;

public class DecoradorDeAutenticacaoSenha extends DecoradorDeRemetente
{
    private IRemetente remetente;

    public DecoradorDeAutenticacaoSenha(IRemetente remetente)
    {
        this.remetente = remetente;
    }

    @Override
    public void connect(String enderecoDeDestino)
    {
       remetente.autenticar();
    }

    @Override
    public void send(IPacote dados)
    {
        remetente.send(dados);
    }

    @Override
    public void close()
    {
        remetente.close();
    }

    @Override
    public void autenticar()
    {
       remetente.autenticar();
        System.out.println(" com Senha");
    }

}
