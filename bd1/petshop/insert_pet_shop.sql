-- Insert Estado
INSERT INTO ESTADO VALUES(1, 'Acre', 'AC');
INSERT INTO ESTADO VALUES(2, 'Alagoas', 'AL');
INSERT INTO ESTADO VALUES(3, 'Amapá', 'AP');
INSERT INTO ESTADO VALUES(4, 'Amazonas', 'AM');
INSERT INTO ESTADO VALUES(5, 'Bahia', 'BA');
INSERT INTO ESTADO VALUES(6, 'Ceará', 'CE');
INSERT INTO ESTADO VALUES(7, 'Espírito Santo', 'ES');
INSERT INTO ESTADO VALUES(8, 'Goiás', 'GO');
INSERT INTO ESTADO VALUES(9, 'Maranhão', 'MA');
INSERT INTO ESTADO VALUES(10, 'Mato Grosso', 'MT');
INSERT INTO ESTADO VALUES(11, 'Mato Grosso do Sul', 'MS');
INSERT INTO ESTADO VALUES(12, 'Minas Gerais', 'MG');
INSERT INTO ESTADO VALUES(13, 'Pará', 'PA');
INSERT INTO ESTADO VALUES(14, 'Paraíba', 'PB');
INSERT INTO ESTADO VALUES(15, 'Paraná', 'PR');
INSERT INTO ESTADO VALUES(16, 'Pernambuco', 'PE');
INSERT INTO ESTADO VALUES(17, 'Piauí', 'PI');
INSERT INTO ESTADO VALUES(18, 'Rio de Janeiro', 'RJ');
INSERT INTO ESTADO VALUES(19, 'Rio Grande do Norte', 'RN');
INSERT INTO ESTADO VALUES(20, 'Rio Grande do Sul', 'RS');
INSERT INTO ESTADO VALUES(21, 'Rondônia', 'RO');
INSERT INTO ESTADO VALUES(22, 'Roraima', 'RR');
INSERT INTO ESTADO VALUES(23, 'Santa Caratina', 'SC');
INSERT INTO ESTADO VALUES(24, 'São Paulo', 'SP');
INSERT INTO ESTADO VALUES(25, 'Sergipe', 'SE');
INSERT INTO ESTADO VALUES(26, 'Tocantins', 'to');
INSERT INTO ESTADO VALUES(27, 'Distrito Federal', 'DF');
-- Fim Insert Estado

-- Insert Cidade
INSERT INTO CIDADE VALUES(1, 'Itabuna', 5);
INSERT INTO CIDADE VALUES(2, 'Ilhéus', 5);
INSERT INTO CIDADE VALUES(3, 'Jequié', 5);
INSERT INTO CIDADE VALUES(4, 'Salvador', 5);
INSERT INTO CIDADE VALUES(5, 'Porto Seguro', 5);
INSERT INTO CIDADE VALUES(6, 'Feira de Santana', 5);
INSERT INTO CIDADE VALUES(7, 'Vitória da Conquista', 5);
INSERT INTO CIDADE VALUES(8, 'Camaçari', 5);
-- Fim Insert Cidade

-- Insert Bairro
INSERT INTO BAIRRO VALUES(1, 'Odilon', 1);
INSERT INTO BAIRRO VALUES(2, 'Lomanto', 1);
INSERT INTO BAIRRO VALUES(3, 'Nova Itabuna', 1);
INSERT INTO BAIRRO VALUES(4, 'Nova Ferradas', 1);
INSERT INTO BAIRRO VALUES(5, 'Manoel Leão', 1);
INSERT INTO BAIRRO VALUES(6, 'Bananeira', 1);
INSERT INTO BAIRRO VALUES(7, 'Jorge Amado', 1);
INSERT INTO BAIRRO VALUES(8, 'Urbis 4', 1);
-- Fim Insert Bairro

-- Insert Endereco
INSERT INTO ENDERECO VALUES(1, 'Rua Quarta Travessa', 182, 1);
INSERT INTO ENDERECO VALUES(2, 'Rua Quarta Travessa', 190, 1);
INSERT INTO ENDERECO VALUES(3, 'Rua 28 de Julho', 234, 2);
INSERT INTO ENDERECO VALUES(4, 'Rua Bananeira', 534, 2);
INSERT INTO ENDERECO VALUES(5, '1ª Travessa A', 170, 3);
INSERT INTO ENDERECO VALUES(6, 'Rua A', 125 , 3);
INSERT INTO ENDERECO VALUES(7, 'Rua B', 393, 1);
INSERT INTO ENDERECO VALUES(8, 'Caminho Cinco', 963, 8);
-- Fim Insert Endereco

-- Insert Distribuidor
INSERT INTO DISTRIBUIDOR VALUES(1, 'Partidos Politicos', 'Partidos Politicos LTDA', '03778130000127', to_date('12/03/1989', 'DD/MM/YYYY'), to_date('16/09/2022', 'DD/MM/YYYY'), 'partidoPolitico@gmail.com');
-- Fim Insert Distribuidor

-- Insert Distribuidor_has_Endereco
INSERT INTO DISTRIBUIDOR_HAS_ENDERECO VALUES(1, 8);
-- Fim Insert Distribuidor_Has_Endereco

-- Insert Telefone
INSERT INTO TELEFONE VALUES(1, '73', '989898989');
INSERT INTO TELEFONE VALUES(2, '73', '988881515');
INSERT INTO TELEFONE VALUES(3, '73', '999344793');
INSERT INTO TELEFONE VALUES(4, '73', '988284818');
INSERT INTO TELEFONE VALUES(5, '73', '999514793');
INSERT INTO TELEFONE VALUES(6, '73', '988251828');
INSERT INTO TELEFONE VALUES(7, '73', '999344743');
INSERT INTO TELEFONE VALUES(8, '73', '988271518');
-- Fim Insert Telefone

-- Insert Distribuidor_Has_Telefone
INSERT INTO DISTRIBUIDOR_HAS_TELEFONE VALUES(1, 1);
-- Fim Insert Distribuidor_Has_Telefone

-- Insert Into Regiao
INSERT INTO REGIAO VALUES(1, 'NORTE', 'Localizada no Norte', to_date('14/07/1990', 'DD/MM/YYYY'));
INSERT INTO REGIAO VALUES(2, 'SUL', 'Localizada no Sul', to_date('20/02/1992', 'DD/MM/YYYY'));
INSERT INTO REGIAO VALUES(3, 'OESTE', 'Localizada no Oeste', to_date('14/07/1990', 'DD/MM/YYYY'));
INSERT INTO REGIAO VALUES(4, 'LESTE', 'Localizada no Leste', to_date('20/02/1992', 'DD/MM/YYYY'));
-- Fim Insert Regiao

-- Insert Varejista
INSERT INTO VAREJISTA VALUES(1, 'Varejista 1', 'VendePet LTDA', '01778130000127', to_date('12/03/1995', 'DD/MM/YYYY'), to_date('17/09/2022', 'DD/MM/YYYY'), 'vendePet@gmail.com', 1);

INSERT INTO VAREJISTA VALUES(2, 'Varejista 2', 'VendePet2 LTDA', '02778130000128', to_date('07/09/1995', 'DD/MM/YYYY'), to_date('15/09/2022', 'DD/MM/YYYY'), 'vendePet2@gmail.com', 2);

INSERT INTO VAREJISTA VALUES(3, 'Varejista 3', 'VendePet3 LTDA', '03778130000129', to_date('22/12/1998', 'DD/MM/YYYY'), to_date('06/09/2022', 'DD/MM/YYYY'), 'vendePet3@gmail.com', 3);

INSERT INTO VAREJISTA VALUES(4, 'Varejista 4', 'VendePet4 LTDA', '04778130000130', to_date('07/06/2000', 'DD/MM/YYYY'), to_date('17/09/2022', 'DD/MM/YYYY'), 'vendePet@gmail.com', 4);
-- Fim Insert Varejista

-- Insert Representante
INSERT INTO REPRESENTANTE VALUES(1, 'Lula', '01158131516', to_date('15/07/1967', 'DD/MM/YYYY'), 'lula@gmail.com', 1);
INSERT INTO REPRESENTANTE VALUES(2, 'Bozo', '02258131517', to_date('12/04/1975', 'DD/MM/YYYY'), 'bozo@gmail.com', 2);
INSERT INTO REPRESENTANTE VALUES(3, 'Ciro Gomes', '03358131518', to_date('01/09/1977', 'DD/MM/YYYY'), 'ciro@gmail.com', 3);
INSERT INTO REPRESENTANTE VALUES(4, 'Simone Tebet', '04458131519', to_date('03/12/1985', 'DD/MM/YYYY'), 'simone@gmail.com', 4);
-- Fim Insert Representante

-- Insert Varejista_has_Endereco
INSERT INTO VAREJISTA_HAS_ENDERECO VALUES(1, 7);
INSERT INTO VAREJISTA_HAS_ENDERECO VALUES(3, 6);
-- Fim Insert Varejista_has_Endereco

-- Insert Representante_has_Endereco
INSERT INTO REPRESENTANTE_HAS_ENDERECO VALUES(1, 1);
INSERT INTO REPRESENTANTE_HAS_ENDERECO VALUES(1, 2);
-- Fim Insert Representante_has_Endereco

-- Insert Varejista_has_Telefone
INSERT INTO VAREJISTA_HAS_TELEFONE VALUES(1, 4);
INSERT INTO VAREJISTA_HAS_TELEFONE VALUES(3, 5);
-- Fim Insert Varejista_Has_Telefone

-- Insert Representante_has_Telefone
INSERT INTO REPRESENTANTE_HAS_TELEFONE VALUES(1, 2);
INSERT INTO REPRESENTANTE_HAS_TELEFONE VALUES(1, 3);
-- Fim Insert Representante_has_Telefone

-- Insert Classe_Animal
INSERT INTO CLASSE_ANIMAL VALUES(1, 'Peixes', 'vivem na água', 1);
INSERT INTO CLASSE_ANIMAL VALUES(2, 'Anfibios', 'sapos, rãs, pererecas e salamandras e etc..', 1);
INSERT INTO CLASSE_ANIMAL VALUES(3, 'Répteis', 'tartarugas, jacarés, lagartos e etc...', 1);
INSERT INTO CLASSE_ANIMAL VALUES(4, 'Aves', 'galinha, avestruz, ema, pinguim, papagaio e etc...', 1);
INSERT INTO CLASSE_ANIMAL VALUES(5, 'Mamiferos', 'humanos, gatos, cachorros e etc...', 1);
-- Fim Insert Classe_Animal

-- Insert Raca
INSERT INTO RACA VALUES(1, 'Vira-Lata', 'Marrom', 1.0, 0.80, 20, 5);
INSERT INTO RACA VALUES(2, 'Husky siberiano', 'Branco', 1.25, 1.20, 40, 5);
INSERT INTO RACA VALUES(3, 'Bulldog Inglês', 'Marrom', 1.40, 1.40, 60, 5);
-- Fim Insert Raca

-- Insert Vacina
INSERT INTO VACINA VALUES(1, 'polivalente V10', 'protege de doenças contagiosas', 1);
INSERT INTO VACINA VALUES(2, 'Antirrábica', 'contra raiva', 1);
INSERT INTO VACINA VALUES(3, 'gripe', 'Protege contra gripe', 2);

-- Fim Insert Vacina

-- Insert Doenca
INSERT INTO DOENCA VALUES(1, 'Ehrlichiose', 'Doença de carrapato', 2);
INSERT INTO DOENCA VALUES(2, 'Raiva', 'Cachorro fica Agressivo', 1);
-- Fim Insert Doenca

-- Insert Alimento
INSERT INTO ALIMENTO VALUES(1, 'Ração qualquer filhote', 8, 'meses', 'Ração de Filhote', 3);
INSERT INTO ALIMENTO VALUES(2, 'Ração qualquer adulto', 18, 'anos', 'Ração de Adulto', 3);
INSERT INTO ALIMENTO VALUES(3, 'Ração Pedigree filhote', 8, 'meses', 'Ração de filhote', 3);
INSERT INTO ALIMENTO VALUES(4, 'Ração Pedigree adulto', 9, 'anos', 'Ração de Adulto', 3);
-- Fim Insert Alimento

-- Insert Raca_Alimento
INSERT INTO RACA_ALIMENTO VALUES(1, 3);
INSERT INTO RACA_ALIMENTO VALUES(1, 4);
INSERT INTO RACA_ALIMENTO VALUES(3, 1);
INSERT INTO RACA_ALIMENTO VALUES(3, 2);
INSERT INTO RACA_ALIMENTO VALUES(2, 1);
INSERT INTO RACA_ALIMENTO VALUES(2, 2);
-- Fim Insert Raca_Alimento

-- Insert Pedido
INSERT INTO PEDIDO VALUES(1, to_date('16/09/2022', 'DD/MM/YYYY'));
INSERT INTO PEDIDO VALUES(2, to_date('22/09/2022', 'DD/MM/YYYY'));
-- Fim Insert Pedido

-- Insert Representate_Pedido
INSERT INTO REPRESENTANTE_PEDIDO VALUES(1, 1);
INSERT INTO REPRESENTANTE_PEDIDO VALUES(1, 2);
-- Fim Insert Representante_Pedido

-- Insert Varejista_Pedido
INSERT INTO VAREJISTA_PEDIDO VALUES(1, 1);
INSERT INTO VAREJISTA_PEDIDO VALUES(1, 2);
-- Fim Insert Varejista_Pedido

-- Insert Item
INSERT INTO ITEM VALUES (1, 60, 12, 1);
INSERT INTO ITEM VALUES (2, 5000, 3, 2);
INSERT INTO ITEM VALUES (3, 147, 17, 3);
INSERT INTO ITEM VALUES (4, 3025, 4, 3);
-- Fim Insert Item

-- Insert Pedido_has_item
INSERT INTO PEDIDO_HAS_ITEM VALUES (1, 1);
INSERT INTO PEDIDO_HAS_ITEM VALUES (2, 2);
-- Fim Insert Pedido_has_item

-- Insert Cliente
INSERT INTO CLIENTE VALUES (1, 'matheus', '12151515511');
INSERT INTO CLIENTE VALUES (2, 'jesus', '21551515511');
-- Fim Insert Cliente

-- Insert Cliente_has_endereco
INSERT INTO CLIENTE_HAS_ENDERECO VALUES (1, 3);
INSERT INTO CLIENTE_HAS_ENDERECO VALUES (2, 4);
-- Fim Insert Cliente_has_endereco

-- Insert Cliente_has_telefone
INSERT INTO CLIENTE_HAS_TELEFONE VALUES (1, 7);
INSERT INTO CLIENTE_HAS_TELEFONE VALUES (2, 6);
-- Fim Insert Cliente_has_telefone

-- Insert Tipo_Pagamento
INSERT INTO TIPO_PAGAMENTO VALUES (1, 'a vista');
INSERT INTO TIPO_PAGAMENTO VALUES (2, 'a prazo');
-- Fim Insert Tipo_Pagamento

-- Insert Nota_fiscal
INSERT INTO NOTA_FISCAL VALUES (1, to_date('19/09/2022', 'DD/MM/YYYY'), 1);
INSERT INTO NOTA_FISCAL VALUES (2, to_date('03/10/2022', 'DD/MM/YYYY'), 2);
-- Fim Insert Nota_fiscal

-- Insert Cliente_NF
INSERT INTO CLIENTE_NF VALUES(1, 1);
INSERT INTO CLIENTE_NF VALUES(1, 2);
-- Fim Insert Cliente_NF

-- Insert Varejista_NF
INSERT INTO VAREJISTA_NF VALUES(1, 1);
INSERT INTO VAREJISTA_NF VALUES(1, 2);
-- Fim Insert Varejista_NF

-- Insert Nf_has_item
INSERT INTO NF_HAS_ITEM VALUES (1, 3);
INSERT INTO NF_HAS_ITEM VALUES (2, 4);
-- Fim Insert Nf_has_item




