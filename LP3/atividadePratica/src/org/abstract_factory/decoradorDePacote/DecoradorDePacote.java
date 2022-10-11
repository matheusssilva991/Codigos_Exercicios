package org.abstract_factory.decoradorDePacote;

import org.abstract_factory.IPacote;

public abstract class DecoradorDePacote implements IPacote {

    public abstract void criptografar();
    public abstract void prepararDados(String dados);

}

