package org.abstract_factory.HTTP;

import org.abstract_factory.IFabrica;
import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;

public class FabricaHTTP implements IFabrica{

    @Override
    public IPacote createPacote()
    {
        return new PacoteHTTP ();
    }

    @Override
    public IRemetente createRemetente ()
    {
        return new RemetenteHTTP();
    }
    
}