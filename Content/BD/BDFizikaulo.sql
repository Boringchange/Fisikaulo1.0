Drop database if exists fizikaulo;
create database fizikaulo;
use fizikaulo;

create table perfiles(
id_usr int primary key not null,
nom_usr varchar(25),
pass varchar(30)
);

