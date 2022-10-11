package org.lp3.visitor.novasFuncionalidades;
import org.lp3.visitor.No;

public class ExibirPreOrderVisitor implements ArvoreVisitor
{
    @Override
    public void visitar(No no)
    {
        if (no == null)
            return;

        System.out.println(no);
        visitar(no.getEsquerdo());
        visitar(no.getDireito());
    }
}
