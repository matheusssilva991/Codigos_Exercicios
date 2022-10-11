package org.lp3.mediator;

public class WindowsPhoneColleague extends Colleague
{
    public WindowsPhoneColleague(Mediator m)
    {
        super(m);
    }
    @Override
    public void receberMensagem(String mensagem)
    {
        System.out.println("Windows Phone recebeu: " + mensagem);
    }
}
