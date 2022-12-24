package org.abstract_factory.COAP;

import org.abstract_factory.HTTP.PacoteHTTP;
import org.abstract_factory.IFabrica;
import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;

public class FabricaCOAP implements IFabrica {

    @Override
    public IPacote createPacote()
    {
        return new PacoteCOAP();
    }

    @Override
    public IRemetente createRemetente()
    {
        return new RemetenteCOAP();
    }
}
