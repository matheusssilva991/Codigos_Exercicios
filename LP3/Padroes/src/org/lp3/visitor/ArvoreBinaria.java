package org.lp3.visitor;

import org.lp3.visitor.novasFuncionalidades.ArvoreVisitor;

public class ArvoreBinaria {
    No raiz;
    int qtdElementos;

    public ArvoreBinaria(int chaveRaiz) {
        raiz = new No(chaveRaiz);
        qtdElementos = 0;
    }

    public void addNo(int chave) {
        addNo(chave, raiz);
    }

    public void remover(int chave){
        System.out.println("Removido o elemento:" + chave + "da arvore");
        System.out.println("Muito Trabalho implementar...");
    }

    public void buscar(int chave){
        System.out.println("Elemento buscado, confia...");
    }

    private void addNo(int chave, No no)
    {
        if (no.getChave() == chave)
            return;

        if (chave > no.getChave()) {
            if (no.getDireito() == null) {
                no.setDireito(new No(chave));
                qtdElementos++;
                return;
            }
            addNo(chave, no.getDireito());

        } else {if (no.getEsquerdo() == null) {
            no.setEsquerdo(new No(chave));
            qtdElementos++;
            return;
        }
            addNo(chave, no.getEsquerdo());
        }
    }

    public void aceitarVisitante(ArvoreVisitor visitor)
    {
        visitor.visitar(raiz);
    }
}
