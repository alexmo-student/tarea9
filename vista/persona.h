#pragma once
#include <iostream>
using namespace std; 
class persona
{
	//atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono = 0, id_tipo_sangre = 0;

		 //constructor 
		 persona() {}
		 persona(string  nom, string ape, string dir, int tel, string fn, int id_ts) {
			 nombres = nom;
			 apellidos = ape;
			 direccion = dir;
			 telefono = tel;
			 fecha_nacimiento = fn;
			 id_tipo_sangre = id_ts;
		 }

};

