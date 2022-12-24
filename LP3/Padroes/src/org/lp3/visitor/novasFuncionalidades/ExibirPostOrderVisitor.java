package org.lp3.visitor.novasFuncionalidades;

import org.lp3.visitor.No;

public class ExibirPostOrderVisitor implements ArvoreVisitor
{
    @Override
    public void visitar(No no) {
        if (no == null)
            return;

        visitar(no.getEsquerdo());
        visitar(no.getDireito());
        System.out.println(no);
    }
}
