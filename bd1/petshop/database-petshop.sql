-- Database generated with pgModeler (PostgreSQL Database Modeler).
-- pgModeler version: 0.9.4
-- PostgreSQL version: 13.0
-- Project Site: pgmodeler.io
-- Model Author: ---

-- Database creation must be performed outside a multi lined SQL file. 
-- These commands were put in this file only as a convenience.
-- 
-- object: petshop | type: DATABASE --
-- DROP DATABASE IF EXISTS petshop;
-- CREATE DATABASE petshop;
-- ddl-end --


-- object: public.distribuidor | type: TABLE --
-- DROP TABLE IF EXISTS public.distribuidor CASCADE;
CREATE TABLE public.distribuidor (
	id serial NOT NULL,
	nome_fantasia varchar(50) NOT NULL,
	razao_social varchar(50) NOT NULL,
	cnpj varchar(14) NOT NULL,
	data_ativacao date NOT NULL,
	data_fechamento date,
	correio_eletronico varchar(80),
	CONSTRAINT "Distribuidor_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.distribuidor OWNER TO postgres;
-- ddl-end --

-- object: public.telefone | type: TABLE --
-- DROP TABLE IF EXISTS public.telefone CASCADE;
CREATE TABLE public.telefone (
	id serial NOT NULL,
	ddd varchar(10) NOT NULL,
	numero varchar(20) NOT NULL,
	CONSTRAINT "Telefone_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.telefone OWNER TO postgres;
-- ddl-end --

-- object: public.distribuidor_has_telefone | type: TABLE --
-- DROP TABLE IF EXISTS public.distribuidor_has_telefone CASCADE;
CREATE TABLE public.distribuidor_has_telefone (
	id_distribuidor integer,
	id_telefone integer

);
-- ddl-end --
ALTER TABLE public.distribuidor_has_telefone OWNER TO postgres;
-- ddl-end --

-- object: distribuidor_fk | type: CONSTRAINT --
-- ALTER TABLE public.distribuidor_has_telefone DROP CONSTRAINT IF EXISTS distribuidor_fk CASCADE;
ALTER TABLE public.distribuidor_has_telefone ADD CONSTRAINT distribuidor_fk FOREIGN KEY (id_distribuidor)
REFERENCES public.distribuidor (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: telefone_fk | type: CONSTRAINT --
-- ALTER TABLE public.distribuidor_has_telefone DROP CONSTRAINT IF EXISTS telefone_fk CASCADE;
ALTER TABLE public.distribuidor_has_telefone ADD CONSTRAINT telefone_fk FOREIGN KEY (id_telefone)
REFERENCES public.telefone (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.estado | type: TABLE --
-- DROP TABLE IF EXISTS public.estado CASCADE;
CREATE TABLE public.estado (
	id serial NOT NULL,
	nome_estado varchar(50) NOT NULL,
	uf varchar(2) NOT NULL,
	CONSTRAINT "Estado_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.estado OWNER TO postgres;
-- ddl-end --

-- object: public.cidade | type: TABLE --
-- DROP TABLE IF EXISTS public.cidade CASCADE;
CREATE TABLE public.cidade (
	id serial NOT NULL,
	nome_cidade varchar(50) NOT NULL,
	id_estado integer,
	CONSTRAINT "Cidade_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.cidade OWNER TO postgres;
-- ddl-end --

-- object: public.bairro | type: TABLE --
-- DROP TABLE IF EXISTS public.bairro CASCADE;
CREATE TABLE public.bairro (
	id serial NOT NULL,
	nome_bairro varchar(50) NOT NULL,
	id_cidade integer,
	CONSTRAINT "Bairro_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.bairro OWNER TO postgres;
-- ddl-end --

-- object: public.endereco | type: TABLE --
-- DROP TABLE IF EXISTS public.endereco CASCADE;
CREATE TABLE public.endereco (
	id serial NOT NULL,
	endereco varchar(80) NOT NULL,
	numero numeric(5) NOT NULL,
	id_bairro integer,
	CONSTRAINT "Endereco_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.endereco OWNER TO postgres;
-- ddl-end --

-- object: estado_fk | type: CONSTRAINT --
-- ALTER TABLE public.cidade DROP CONSTRAINT IF EXISTS estado_fk CASCADE;
ALTER TABLE public.cidade ADD CONSTRAINT estado_fk FOREIGN KEY (id_estado)
REFERENCES public.estado (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: cidade_fk | type: CONSTRAINT --
-- ALTER TABLE public.bairro DROP CONSTRAINT IF EXISTS cidade_fk CASCADE;
ALTER TABLE public.bairro ADD CONSTRAINT cidade_fk FOREIGN KEY (id_cidade)
REFERENCES public.cidade (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: bairro_fk | type: CONSTRAINT --
-- ALTER TABLE public.endereco DROP CONSTRAINT IF EXISTS bairro_fk CASCADE;
ALTER TABLE public.endereco ADD CONSTRAINT bairro_fk FOREIGN KEY (id_bairro)
REFERENCES public.bairro (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.distribuidor_has_endereco | type: TABLE --
-- DROP TABLE IF EXISTS public.distribuidor_has_endereco CASCADE;
CREATE TABLE public.distribuidor_has_endereco (
	id_distribuidor integer,
	id_endereco integer

);
-- ddl-end --
ALTER TABLE public.distribuidor_has_endereco OWNER TO postgres;
-- ddl-end --

-- object: public.regiao | type: TABLE --
-- DROP TABLE IF EXISTS public.regiao CASCADE;
CREATE TABLE public.regiao (
	id serial NOT NULL,
	nome_regiao varchar(50) NOT NULL,
	descricao varchar(60),
	data_cadastro date NOT NULL,
	id_distribuidor integer,
	CONSTRAINT "Regiao_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.regiao OWNER TO postgres;
-- ddl-end --

-- object: public.representante | type: TABLE --
-- DROP TABLE IF EXISTS public.representante CASCADE;
CREATE TABLE public.representante (
	id serial NOT NULL,
	nome varchar(50) NOT NULL,
	cpf varchar(11) NOT NULL,
	data_nascimento date NOT NULL,
	correio_eletronico varchar(80) NOT NULL,
	id_regiao integer,
	CONSTRAINT "Representante_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.representante OWNER TO postgres;
-- ddl-end --

-- object: public.varejista | type: TABLE --
-- DROP TABLE IF EXISTS public.varejista CASCADE;
CREATE TABLE public.varejista (
	id serial NOT NULL,
	nome_fantasia varchar(50) NOT NULL,
	razao_social varchar(50) NOT NULL,
	cnpj varchar(14) NOT NULL,
	data_ativacao date NOT NULL,
	data_fechamento date NOT NULL,
	correio_eletronico varchar(80),
	id_regiao integer,
	CONSTRAINT "Distribuidor_pk_cp" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.varejista OWNER TO postgres;
-- ddl-end --

-- object: regiao_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista DROP CONSTRAINT IF EXISTS regiao_fk CASCADE;
ALTER TABLE public.varejista ADD CONSTRAINT regiao_fk FOREIGN KEY (id_regiao)
REFERENCES public.regiao (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: varejista_uq | type: CONSTRAINT --
-- ALTER TABLE public.varejista DROP CONSTRAINT IF EXISTS varejista_uq CASCADE;
ALTER TABLE public.varejista ADD CONSTRAINT varejista_uq UNIQUE (id_regiao);
-- ddl-end --

-- object: public.representante_has_endereco | type: TABLE --
-- DROP TABLE IF EXISTS public.representante_has_endereco CASCADE;
CREATE TABLE public.representante_has_endereco (
	id_representante integer,
	id_endereco integer

);
-- ddl-end --
ALTER TABLE public.representante_has_endereco OWNER TO postgres;
-- ddl-end --

-- object: public.varejista_has_endereco | type: TABLE --
-- DROP TABLE IF EXISTS public.varejista_has_endereco CASCADE;
CREATE TABLE public.varejista_has_endereco (
	id_varejista integer,
	id_endereco integer

);
-- ddl-end --
ALTER TABLE public.varejista_has_endereco OWNER TO postgres;
-- ddl-end --

-- object: representante_fk | type: CONSTRAINT --
-- ALTER TABLE public.representante_has_endereco DROP CONSTRAINT IF EXISTS representante_fk CASCADE;
ALTER TABLE public.representante_has_endereco ADD CONSTRAINT representante_fk FOREIGN KEY (id_representante)
REFERENCES public.representante (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: varejista_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_has_endereco DROP CONSTRAINT IF EXISTS varejista_fk CASCADE;
ALTER TABLE public.varejista_has_endereco ADD CONSTRAINT varejista_fk FOREIGN KEY (id_varejista)
REFERENCES public.varejista (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.varejista_has_telefone | type: TABLE --
-- DROP TABLE IF EXISTS public.varejista_has_telefone CASCADE;
CREATE TABLE public.varejista_has_telefone (
	id_varejista integer,
	id_telefone integer

);
-- ddl-end --
ALTER TABLE public.varejista_has_telefone OWNER TO postgres;
-- ddl-end --

-- object: varejista_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_has_telefone DROP CONSTRAINT IF EXISTS varejista_fk CASCADE;
ALTER TABLE public.varejista_has_telefone ADD CONSTRAINT varejista_fk FOREIGN KEY (id_varejista)
REFERENCES public.varejista (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: telefone_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_has_telefone DROP CONSTRAINT IF EXISTS telefone_fk CASCADE;
ALTER TABLE public.varejista_has_telefone ADD CONSTRAINT telefone_fk FOREIGN KEY (id_telefone)
REFERENCES public.telefone (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.representante_has_telefone | type: TABLE --
-- DROP TABLE IF EXISTS public.representante_has_telefone CASCADE;
CREATE TABLE public.representante_has_telefone (
	id_representante integer,
	id_telefone integer

);
-- ddl-end --
ALTER TABLE public.representante_has_telefone OWNER TO postgres;
-- ddl-end --

-- object: representante_fk | type: CONSTRAINT --
-- ALTER TABLE public.representante_has_telefone DROP CONSTRAINT IF EXISTS representante_fk CASCADE;
ALTER TABLE public.representante_has_telefone ADD CONSTRAINT representante_fk FOREIGN KEY (id_representante)
REFERENCES public.representante (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: telefone_fk | type: CONSTRAINT --
-- ALTER TABLE public.representante_has_telefone DROP CONSTRAINT IF EXISTS telefone_fk CASCADE;
ALTER TABLE public.representante_has_telefone ADD CONSTRAINT telefone_fk FOREIGN KEY (id_telefone)
REFERENCES public.telefone (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: distribuidor_fk | type: CONSTRAINT --
-- ALTER TABLE public.regiao DROP CONSTRAINT IF EXISTS distribuidor_fk CASCADE;
ALTER TABLE public.regiao ADD CONSTRAINT distribuidor_fk FOREIGN KEY (id_distribuidor)
REFERENCES public.distribuidor (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: regiao_fk | type: CONSTRAINT --
-- ALTER TABLE public.representante DROP CONSTRAINT IF EXISTS regiao_fk CASCADE;
ALTER TABLE public.representante ADD CONSTRAINT regiao_fk FOREIGN KEY (id_regiao)
REFERENCES public.regiao (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: representante_uq | type: CONSTRAINT --
-- ALTER TABLE public.representante DROP CONSTRAINT IF EXISTS representante_uq CASCADE;
ALTER TABLE public.representante ADD CONSTRAINT representante_uq UNIQUE (id_regiao);
-- ddl-end --

-- object: public.pedido | type: TABLE --
-- DROP TABLE IF EXISTS public.pedido CASCADE;
CREATE TABLE public.pedido (
	id serial NOT NULL,
	data_pedido date NOT NULL,
	CONSTRAINT "Pedido_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.pedido OWNER TO postgres;
-- ddl-end --

-- object: public.item | type: TABLE --
-- DROP TABLE IF EXISTS public.item CASCADE;
CREATE TABLE public.item (
	id serial NOT NULL,
	valor money NOT NULL,
	quantidade numeric(4) NOT NULL,
	id_raca integer,
	CONSTRAINT "Item_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.item OWNER TO postgres;
-- ddl-end --

-- object: public.alimento | type: TABLE --
-- DROP TABLE IF EXISTS public.alimento CASCADE;
CREATE TABLE public.alimento (
	id serial NOT NULL,
	nome_alimento varchar(50) NOT NULL,
	idade_maxima numeric(2) NOT NULL,
	unidade_idade varchar(20) NOT NULL,
	descricao varchar(100) NOT NULL,
	quantidade_diaria numeric(2) NOT NULL,
	CONSTRAINT "Alimento_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.alimento OWNER TO postgres;
-- ddl-end --

-- object: public.classe_animal | type: TABLE --
-- DROP TABLE IF EXISTS public.classe_animal CASCADE;
CREATE TABLE public.classe_animal (
	id serial NOT NULL,
	nome varchar(50) NOT NULL,
	descricao varchar(50) NOT NULL,
	id_distribuidor integer,
	CONSTRAINT "Classe_Animal_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.classe_animal OWNER TO postgres;
-- ddl-end --

-- object: public.raca | type: TABLE --
-- DROP TABLE IF EXISTS public.raca CASCADE;
CREATE TABLE public.raca (
	id serial NOT NULL,
	nome_raca varchar(50) NOT NULL,
	cor_caracteristica varchar(20) NOT NULL,
	comprimento_medio numeric(3) NOT NULL,
	altura_media numeric(3) NOT NULL,
	peso_medio numeric(4) NOT NULL,
	id_classe_animal integer,
	CONSTRAINT "Raca_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.raca OWNER TO postgres;
-- ddl-end --

-- object: distribuidor_fk | type: CONSTRAINT --
-- ALTER TABLE public.classe_animal DROP CONSTRAINT IF EXISTS distribuidor_fk CASCADE;
ALTER TABLE public.classe_animal ADD CONSTRAINT distribuidor_fk FOREIGN KEY (id_distribuidor)
REFERENCES public.distribuidor (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: classe_animal_fk | type: CONSTRAINT --
-- ALTER TABLE public.raca DROP CONSTRAINT IF EXISTS classe_animal_fk CASCADE;
ALTER TABLE public.raca ADD CONSTRAINT classe_animal_fk FOREIGN KEY (id_classe_animal)
REFERENCES public.classe_animal (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.doenca | type: TABLE --
-- DROP TABLE IF EXISTS public.doenca CASCADE;
CREATE TABLE public.doenca (
	id serial NOT NULL,
	nome varchar(50) NOT NULL,
	descricao varchar(100) NOT NULL,
	id_raca integer,
	CONSTRAINT "Doenca_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.doenca OWNER TO postgres;
-- ddl-end --

-- object: public.vacina | type: TABLE --
-- DROP TABLE IF EXISTS public.vacina CASCADE;
CREATE TABLE public.vacina (
	id serial NOT NULL,
	nome varchar(50) NOT NULL,
	descricao varchar(100) NOT NULL,
	id_raca integer,
	CONSTRAINT "Vacina_pk" PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.vacina OWNER TO postgres;
-- ddl-end --

-- object: raca_fk | type: CONSTRAINT --
-- ALTER TABLE public.vacina DROP CONSTRAINT IF EXISTS raca_fk CASCADE;
ALTER TABLE public.vacina ADD CONSTRAINT raca_fk FOREIGN KEY (id_raca)
REFERENCES public.raca (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: raca_fk | type: CONSTRAINT --
-- ALTER TABLE public.doenca DROP CONSTRAINT IF EXISTS raca_fk CASCADE;
ALTER TABLE public.doenca ADD CONSTRAINT raca_fk FOREIGN KEY (id_raca)
REFERENCES public.raca (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: endereco_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_has_endereco DROP CONSTRAINT IF EXISTS endereco_fk CASCADE;
ALTER TABLE public.varejista_has_endereco ADD CONSTRAINT endereco_fk FOREIGN KEY (id_endereco)
REFERENCES public.endereco (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: varejista_has_endereco_uq | type: CONSTRAINT --
-- ALTER TABLE public.varejista_has_endereco DROP CONSTRAINT IF EXISTS varejista_has_endereco_uq CASCADE;
ALTER TABLE public.varejista_has_endereco ADD CONSTRAINT varejista_has_endereco_uq UNIQUE (id_endereco);
-- ddl-end --

-- object: endereco_fk | type: CONSTRAINT --
-- ALTER TABLE public.representante_has_endereco DROP CONSTRAINT IF EXISTS endereco_fk CASCADE;
ALTER TABLE public.representante_has_endereco ADD CONSTRAINT endereco_fk FOREIGN KEY (id_endereco)
REFERENCES public.endereco (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: representante_has_endereco_uq | type: CONSTRAINT --
-- ALTER TABLE public.representante_has_endereco DROP CONSTRAINT IF EXISTS representante_has_endereco_uq CASCADE;
ALTER TABLE public.representante_has_endereco ADD CONSTRAINT representante_has_endereco_uq UNIQUE (id_endereco);
-- ddl-end --

-- object: public.pedido_has_item | type: TABLE --
-- DROP TABLE IF EXISTS public.pedido_has_item CASCADE;
CREATE TABLE public.pedido_has_item (
	id_item integer,
	id_pedido integer

);
-- ddl-end --
ALTER TABLE public.pedido_has_item OWNER TO postgres;
-- ddl-end --

-- object: item_fk | type: CONSTRAINT --
-- ALTER TABLE public.pedido_has_item DROP CONSTRAINT IF EXISTS item_fk CASCADE;
ALTER TABLE public.pedido_has_item ADD CONSTRAINT item_fk FOREIGN KEY (id_item)
REFERENCES public.item (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: pedido_has_item_uq | type: CONSTRAINT --
-- ALTER TABLE public.pedido_has_item DROP CONSTRAINT IF EXISTS pedido_has_item_uq CASCADE;
ALTER TABLE public.pedido_has_item ADD CONSTRAINT pedido_has_item_uq UNIQUE (id_item);
-- ddl-end --

-- object: pedido_fk | type: CONSTRAINT --
-- ALTER TABLE public.pedido_has_item DROP CONSTRAINT IF EXISTS pedido_fk CASCADE;
ALTER TABLE public.pedido_has_item ADD CONSTRAINT pedido_fk FOREIGN KEY (id_pedido)
REFERENCES public.pedido (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.nota_fiscal | type: TABLE --
-- DROP TABLE IF EXISTS public.nota_fiscal CASCADE;
CREATE TABLE public.nota_fiscal (
	id serial NOT NULL,
	data_venda date NOT NULL,
	id_tipo_pagamento integer,
	CONSTRAINT nota_fiscal_pk PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.nota_fiscal OWNER TO postgres;
-- ddl-end --

-- object: public.nf_has_item | type: TABLE --
-- DROP TABLE IF EXISTS public.nf_has_item CASCADE;
CREATE TABLE public.nf_has_item (
	id_nota_fiscal integer,
	id_item integer

);
-- ddl-end --
ALTER TABLE public.nf_has_item OWNER TO postgres;
-- ddl-end --

-- object: nota_fiscal_fk | type: CONSTRAINT --
-- ALTER TABLE public.nf_has_item DROP CONSTRAINT IF EXISTS nota_fiscal_fk CASCADE;
ALTER TABLE public.nf_has_item ADD CONSTRAINT nota_fiscal_fk FOREIGN KEY (id_nota_fiscal)
REFERENCES public.nota_fiscal (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: item_fk | type: CONSTRAINT --
-- ALTER TABLE public.nf_has_item DROP CONSTRAINT IF EXISTS item_fk CASCADE;
ALTER TABLE public.nf_has_item ADD CONSTRAINT item_fk FOREIGN KEY (id_item)
REFERENCES public.item (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: nf_has_item_uq | type: CONSTRAINT --
-- ALTER TABLE public.nf_has_item DROP CONSTRAINT IF EXISTS nf_has_item_uq CASCADE;
ALTER TABLE public.nf_has_item ADD CONSTRAINT nf_has_item_uq UNIQUE (id_item);
-- ddl-end --

-- object: public.cliente | type: TABLE --
-- DROP TABLE IF EXISTS public.cliente CASCADE;
CREATE TABLE public.cliente (
	id serial NOT NULL,
	nome varchar(50) NOT NULL,
	cpf varchar(11) NOT NULL,
	CONSTRAINT cliente_pk PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.cliente OWNER TO postgres;
-- ddl-end --

-- object: public.cliente_has_endereco | type: TABLE --
-- DROP TABLE IF EXISTS public.cliente_has_endereco CASCADE;
CREATE TABLE public.cliente_has_endereco (
	id_cliente integer,
	id_endereco integer

);
-- ddl-end --
ALTER TABLE public.cliente_has_endereco OWNER TO postgres;
-- ddl-end --

-- object: cliente_fk | type: CONSTRAINT --
-- ALTER TABLE public.cliente_has_endereco DROP CONSTRAINT IF EXISTS cliente_fk CASCADE;
ALTER TABLE public.cliente_has_endereco ADD CONSTRAINT cliente_fk FOREIGN KEY (id_cliente)
REFERENCES public.cliente (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: endereco_fk | type: CONSTRAINT --
-- ALTER TABLE public.cliente_has_endereco DROP CONSTRAINT IF EXISTS endereco_fk CASCADE;
ALTER TABLE public.cliente_has_endereco ADD CONSTRAINT endereco_fk FOREIGN KEY (id_endereco)
REFERENCES public.endereco (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: cliente_has_endereco_uq | type: CONSTRAINT --
-- ALTER TABLE public.cliente_has_endereco DROP CONSTRAINT IF EXISTS cliente_has_endereco_uq CASCADE;
ALTER TABLE public.cliente_has_endereco ADD CONSTRAINT cliente_has_endereco_uq UNIQUE (id_endereco);
-- ddl-end --

-- object: public.cliente_has_telefone | type: TABLE --
-- DROP TABLE IF EXISTS public.cliente_has_telefone CASCADE;
CREATE TABLE public.cliente_has_telefone (
	id_cliente integer,
	id_telefone integer

);
-- ddl-end --
ALTER TABLE public.cliente_has_telefone OWNER TO postgres;
-- ddl-end --

-- object: cliente_fk | type: CONSTRAINT --
-- ALTER TABLE public.cliente_has_telefone DROP CONSTRAINT IF EXISTS cliente_fk CASCADE;
ALTER TABLE public.cliente_has_telefone ADD CONSTRAINT cliente_fk FOREIGN KEY (id_cliente)
REFERENCES public.cliente (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: telefone_fk | type: CONSTRAINT --
-- ALTER TABLE public.cliente_has_telefone DROP CONSTRAINT IF EXISTS telefone_fk CASCADE;
ALTER TABLE public.cliente_has_telefone ADD CONSTRAINT telefone_fk FOREIGN KEY (id_telefone)
REFERENCES public.telefone (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: raca_fk | type: CONSTRAINT --
-- ALTER TABLE public.item DROP CONSTRAINT IF EXISTS raca_fk CASCADE;
ALTER TABLE public.item ADD CONSTRAINT raca_fk FOREIGN KEY (id_raca)
REFERENCES public.raca (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: distribuidor_fk | type: CONSTRAINT --
-- ALTER TABLE public.distribuidor_has_endereco DROP CONSTRAINT IF EXISTS distribuidor_fk CASCADE;
ALTER TABLE public.distribuidor_has_endereco ADD CONSTRAINT distribuidor_fk FOREIGN KEY (id_distribuidor)
REFERENCES public.distribuidor (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: endereco_fk | type: CONSTRAINT --
-- ALTER TABLE public.distribuidor_has_endereco DROP CONSTRAINT IF EXISTS endereco_fk CASCADE;
ALTER TABLE public.distribuidor_has_endereco ADD CONSTRAINT endereco_fk FOREIGN KEY (id_endereco)
REFERENCES public.endereco (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: distribuidor_has_endereco_uq | type: CONSTRAINT --
-- ALTER TABLE public.distribuidor_has_endereco DROP CONSTRAINT IF EXISTS distribuidor_has_endereco_uq CASCADE;
ALTER TABLE public.distribuidor_has_endereco ADD CONSTRAINT distribuidor_has_endereco_uq UNIQUE (id_endereco);
-- ddl-end --

-- object: public.tipo_pagamento | type: TABLE --
-- DROP TABLE IF EXISTS public.tipo_pagamento CASCADE;
CREATE TABLE public.tipo_pagamento (
	id serial NOT NULL,
	tipo_pagamento varchar(20),
	CONSTRAINT tipo_pagamento_pk PRIMARY KEY (id)
);
-- ddl-end --
ALTER TABLE public.tipo_pagamento OWNER TO postgres;
-- ddl-end --

-- object: tipo_pagamento_fk | type: CONSTRAINT --
-- ALTER TABLE public.nota_fiscal DROP CONSTRAINT IF EXISTS tipo_pagamento_fk CASCADE;
ALTER TABLE public.nota_fiscal ADD CONSTRAINT tipo_pagamento_fk FOREIGN KEY (id_tipo_pagamento)
REFERENCES public.tipo_pagamento (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.raca_alimento | type: TABLE --
-- DROP TABLE IF EXISTS public.raca_alimento CASCADE;
CREATE TABLE public.raca_alimento (
	id_raca integer,
	id_alimento integer

);
-- ddl-end --
ALTER TABLE public.raca_alimento OWNER TO postgres;
-- ddl-end --

-- object: raca_fk | type: CONSTRAINT --
-- ALTER TABLE public.raca_alimento DROP CONSTRAINT IF EXISTS raca_fk CASCADE;
ALTER TABLE public.raca_alimento ADD CONSTRAINT raca_fk FOREIGN KEY (id_raca)
REFERENCES public.raca (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: alimento_fk | type: CONSTRAINT --
-- ALTER TABLE public.raca_alimento DROP CONSTRAINT IF EXISTS alimento_fk CASCADE;
ALTER TABLE public.raca_alimento ADD CONSTRAINT alimento_fk FOREIGN KEY (id_alimento)
REFERENCES public.alimento (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public.representante_pedido | type: TABLE --
-- DROP TABLE IF EXISTS public.representante_pedido CASCADE;
CREATE TABLE public.representante_pedido (
	id_representante integer,
	id_pedido integer

);
-- ddl-end --
ALTER TABLE public.representante_pedido OWNER TO postgres;
-- ddl-end --

-- object: representante_fk | type: CONSTRAINT --
-- ALTER TABLE public.representante_pedido DROP CONSTRAINT IF EXISTS representante_fk CASCADE;
ALTER TABLE public.representante_pedido ADD CONSTRAINT representante_fk FOREIGN KEY (id_representante)
REFERENCES public.representante (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: pedido_fk | type: CONSTRAINT --
-- ALTER TABLE public.representante_pedido DROP CONSTRAINT IF EXISTS pedido_fk CASCADE;
ALTER TABLE public.representante_pedido ADD CONSTRAINT pedido_fk FOREIGN KEY (id_pedido)
REFERENCES public.pedido (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: representante_pedido_uq | type: CONSTRAINT --
-- ALTER TABLE public.representante_pedido DROP CONSTRAINT IF EXISTS representante_pedido_uq CASCADE;
ALTER TABLE public.representante_pedido ADD CONSTRAINT representante_pedido_uq UNIQUE (id_pedido);
-- ddl-end --

-- object: public.varejista_pedido | type: TABLE --
-- DROP TABLE IF EXISTS public.varejista_pedido CASCADE;
CREATE TABLE public.varejista_pedido (
	id_varejista integer,
	id_pedido integer

);
-- ddl-end --
ALTER TABLE public.varejista_pedido OWNER TO postgres;
-- ddl-end --

-- object: varejista_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_pedido DROP CONSTRAINT IF EXISTS varejista_fk CASCADE;
ALTER TABLE public.varejista_pedido ADD CONSTRAINT varejista_fk FOREIGN KEY (id_varejista)
REFERENCES public.varejista (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: pedido_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_pedido DROP CONSTRAINT IF EXISTS pedido_fk CASCADE;
ALTER TABLE public.varejista_pedido ADD CONSTRAINT pedido_fk FOREIGN KEY (id_pedido)
REFERENCES public.pedido (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: varejista_pedido_uq | type: CONSTRAINT --
-- ALTER TABLE public.varejista_pedido DROP CONSTRAINT IF EXISTS varejista_pedido_uq CASCADE;
ALTER TABLE public.varejista_pedido ADD CONSTRAINT varejista_pedido_uq UNIQUE (id_pedido);
-- ddl-end --

-- object: public.varejista_nf | type: TABLE --
-- DROP TABLE IF EXISTS public.varejista_nf CASCADE;
CREATE TABLE public.varejista_nf (
	id_varejista integer,
	id_nota_fiscal integer

);
-- ddl-end --
ALTER TABLE public.varejista_nf OWNER TO postgres;
-- ddl-end --

-- object: varejista_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_nf DROP CONSTRAINT IF EXISTS varejista_fk CASCADE;
ALTER TABLE public.varejista_nf ADD CONSTRAINT varejista_fk FOREIGN KEY (id_varejista)
REFERENCES public.varejista (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: nota_fiscal_fk | type: CONSTRAINT --
-- ALTER TABLE public.varejista_nf DROP CONSTRAINT IF EXISTS nota_fiscal_fk CASCADE;
ALTER TABLE public.varejista_nf ADD CONSTRAINT nota_fiscal_fk FOREIGN KEY (id_nota_fiscal)
REFERENCES public.nota_fiscal (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: varejista_nf_uq | type: CONSTRAINT --
-- ALTER TABLE public.varejista_nf DROP CONSTRAINT IF EXISTS varejista_nf_uq CASCADE;
ALTER TABLE public.varejista_nf ADD CONSTRAINT varejista_nf_uq UNIQUE (id_nota_fiscal);
-- ddl-end --

-- object: public.cliente_nf | type: TABLE --
-- DROP TABLE IF EXISTS public.cliente_nf CASCADE;
CREATE TABLE public.cliente_nf (
	id_cliente integer,
	id_nota_fiscal integer

);
-- ddl-end --
ALTER TABLE public.cliente_nf OWNER TO postgres;
-- ddl-end --

-- object: cliente_fk | type: CONSTRAINT --
-- ALTER TABLE public.cliente_nf DROP CONSTRAINT IF EXISTS cliente_fk CASCADE;
ALTER TABLE public.cliente_nf ADD CONSTRAINT cliente_fk FOREIGN KEY (id_cliente)
REFERENCES public.cliente (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: nota_fiscal_fk | type: CONSTRAINT --
-- ALTER TABLE public.cliente_nf DROP CONSTRAINT IF EXISTS nota_fiscal_fk CASCADE;
ALTER TABLE public.cliente_nf ADD CONSTRAINT nota_fiscal_fk FOREIGN KEY (id_nota_fiscal)
REFERENCES public.nota_fiscal (id) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: cliente_nf_uq | type: CONSTRAINT --
-- ALTER TABLE public.cliente_nf DROP CONSTRAINT IF EXISTS cliente_nf_uq CASCADE;
ALTER TABLE public.cliente_nf ADD CONSTRAINT cliente_nf_uq UNIQUE (id_nota_fiscal);
-- ddl-end --


