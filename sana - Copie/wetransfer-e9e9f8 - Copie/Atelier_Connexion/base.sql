create table attestation(
id integer PRIMARY KEY,
cin VARCHAR2(9) unique, 
nom VARCHAR2(20),
prenom VARCHAR2(20),
mail varchar2(25),
objet varchar2(20),
caracteristique VARCHAR2(300),
date_attestation date,
lieu VARCHAR2(30)
);
create table passeport(
id int primary key,
cin varchar(9) unique,
traitement varchar2(30),
raison varchar (30),
date_naissance date,
sexe varchar2(10),
etat_civil varchar2(25),
adress varchar2(30),
type varchar2(30),
mail varchar2(30)
);