package org.lp3.visitor;

import org.lp3.visitor.novasFuncionalidades.*;

public class Main {
    public static void main(String[] args)
    {
        ArvoreBinaria arvoreB = new ArvoreBinaria(7);

        arvoreB.addNo(2);
        arvoreB.addNo(3);
        arvoreB.addNo(4);
        arvoreB.addNo(5);
        arvoreB.addNo(9);

        System.out.println("Imprimindo dados arvore binaria");
        ArvoreVisitor visitor = new ExibirPreOrderVisitor();
        arvoreB.aceitarVisitante(visitor);
    }
}
