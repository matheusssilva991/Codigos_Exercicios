package org.abstract_factory.Main;

import org.abstract_factory.COAP.FabricaCOAP;
import org.abstract_factory.HTTP.FabricaHTTP;
import org.abstract_factory.IFabrica;
import org.abstract_factory.IPacote;
import org.abstract_factory.IRemetente;
import org.abstract_factory.decoradorDePacote.DecoradorDePacoteCriptografiaDES;
import org.abstract_factory.decoradorDePacote.DecoradorDePacoteCriptografiaRSA;
import org.abstract_factory.decoradorDeRemetente.DecoradorDeAutenticacaoSenha;
import org.abstract_factory.decoradorDeRemetente.DecoradorDeAutenticacaoToken;
import org.abstract_factory.decoradorDeRemetente.DecoradorDeRemetente;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Main testaMenu = new Main();
        testaMenu.menu();
    }

    public void menu()
    {
        int op = 1;
        Scanner input = new Scanner(System.in);
        IFabrica fabrica;
        IPacote pacote;
        IRemetente remetente;
        String dadosEndereco;

        while(op != 0)
        {
            System.out.println("1 - Protocolo HTTP");
            System.out.println("2 - Protocolo COAP");
            System.out.println("0 - Sair");

            op = input.nextInt();

            switch(op)
            {
                case 1:
                    fabrica = new FabricaHTTP();
                    pacote = tipoCriptografia(fabrica);
                    remetente = tipoAutenticacao(fabrica);

                    System.out.println("Digite a dados a ser mandada:");
                    dadosEndereco = input.nextLine();
                    input.nextLine();
                    pacote.prepararDados(dadosEndereco);
                    pacote.criptografar();

                    System.out.println("Digite o endereço para mandar");
                    dadosEndereco = input.nextLine();
                    input.nextLine();
                    remetente.connect(dadosEndereco);
                    remetente.autenticar();
                    remetente.send(pacote);
                    remetente.close();

                    break;

                case 2:
                    fabrica = new FabricaCOAP();
                    pacote = tipoCriptografia(fabrica);
                    remetente = tipoAutenticacao(fabrica);

                    System.out.println("Digite a dados a ser mandada:");
                    dadosEndereco = input.nextLine();
                    input.nextLine();
                    pacote.prepararDados(dadosEndereco);
                    pacote.criptografar();

                    System.out.println("Digite o endereço para mandar");
                    dadosEndereco = input.nextLine();
                    input.nextLine();
                    remetente.connect(dadosEndereco);
                    remetente.autenticar();
                    remetente.send(pacote);
                    remetente.close();

                    break;

                case 0:
                    break;

                default:
                    System.out.println("Opcao invalida.");

            }
        }
    }

    public IPacote tipoCriptografia(IFabrica fabrica)
    {
        Scanner input = new Scanner(System.in);
        IPacote pacote;
        IPacote pacoteDecorado;

        System.out.println("1 - Sem criptografia");
        System.out.println("2 - Criptografia DES");
        System.out.println("3 - Criptografia RSA");
        int op = input.nextInt();

        switch (op)
        {
            case 1:
                pacote = fabrica.createPacote();
                return pacote;

            case 2:
                pacote = fabrica.createPacote();
                pacoteDecorado = new DecoradorDePacoteCriptografiaDES(pacote);
                return pacoteDecorado;

            case 3:
                pacote = fabrica.createPacote();
                pacoteDecorado = new DecoradorDePacoteCriptografiaRSA(pacote);
                return pacoteDecorado;

            default:
                System.exit(-1);
        }
        return null;
    }

    public IRemetente tipoAutenticacao(IFabrica fabrica)
    {
        Scanner input = new Scanner(System.in);
        IRemetente remetente;
        IRemetente remetenteDecorado;

        System.out.println("1 - Sem Autenticacao");
        System.out.println("2 - Autenticacao com Senha");
        System.out.println("3 - Autenticacao com token");
        int op = input.nextInt();

        switch (op)
        {
            case 1:
                remetente = fabrica.createRemetente();
                return remetente;

            case 2:
                remetente = fabrica.createRemetente();
                remetenteDecorado = new DecoradorDeAutenticacaoSenha(remetente);
                return remetenteDecorado;

            case 3:
                remetente = fabrica.createRemetente();
                remetenteDecorado = new DecoradorDeAutenticacaoToken(remetente);
                return remetenteDecorado;

            default:
                System.exit(-1);
        }
        return null;
    }
}
