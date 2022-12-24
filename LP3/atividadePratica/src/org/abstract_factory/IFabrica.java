package org.abstract_factory;

public interface IFabrica {

    public  IPacote createPacote();
    public IRemetente createRemetente();
}
