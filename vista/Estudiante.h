#pragma once
#include "persona.h"
#include "conexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;
// los dos : quiere decir hereda de la clase persona 
class Estudiante : persona
{

	// atributos 
private: string codigo;
	   int id_estudiante = 0;
	   //constructor 

public:
	   Estudiante (){}
	   Estudiante (string  nom, string ape, string dir, int tel, string fn, int id_ts, string cod, int id_e): persona (nom,ape,dir,tel,fn,id_ts){
		   codigo = cod;
		   id_estudiante = id_e;
		   }

	   //metodos get y set 
	   // set modificar un atributo

	   void setId_estudiante(int e) {  id_estudiante = e; }
	   void setCodigo(string c) { codigo = c; }
	   void setNombres(string n) { nombres = n;  }
	   void setApellidos(string a) { apellidos = a; }
	   void setDireccion(string d) { direccion = d; }
	   void setTelefono(int t) { telefono = t; }
	   void setFecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	   void setId_tipo_sangre(int ts) { id_tipo_sangre = ts; }

	   // get mostrar el contenido del atributo
	   int getId_estudiante() { return  id_estudiante; }
	   string getCodigo() { return codigo; }
	   string  getNombres() { return nombres; }
	   string getApellidos() { return  apellidos; }
	   string  getDireccion() { return direccion; }
	   int getTelefono() {  return telefono; }
	   string getFecha_nacimiento() { return fecha_nacimiento; }
	   int getId_tipo_sangre() { return id_tipo_sangre ; }


//metodos 
		   void crear () {
			   int q_estado = 0;
			   ConexionBD cn = ConexionBD();
			   cn.abrir_conexion();
			   if (cn.getConector()) {
				   string t = to_string(telefono);
				   string id_ts = to_string(id_tipo_sangre);
				   string  consulta = "INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre)VALUES ('"+codigo+"','"+nombres+"','" + apellidos + "','" + direccion + "'," +t+ ",'" +fecha_nacimiento+ "'," +id_ts+ ");";
				   const char* c = consulta.c_str();
				   q_estado = mysql_query(cn.getConector(), c);
				   if (!q_estado) {
					   cout << "Ingreso de datos exitoso..." << endl;

				   }
				   else {
					   cout << "Consulta fallida..." << endl;
				   }

			   }
			   else {
				   cout << "conexion fallida " << endl;
			   }
			   cn.cerrar_conexion();

		   }

		   void leer(){
			   int q_estado = 0;
			   ConexionBD cn = ConexionBD();
			   MYSQL_ROW fila;
			   MYSQL_RES* resultado; 
			   cn.abrir_conexion();
			   if(cn.getConector()){
				   cout << "___________Datos del Estudiante_________" << endl;
				   string consulta = "select e.id_estudiante as id,e.codigo,e.nombres,e.apellidos,e.direccion,e.telefono,e.fecha_nacimiento,ts.sangre from estudiantes  as e inner join tipo_sangre as ts on e.id_tipo_sangre = ts.id_tipo_sangre;";
				   const char* c = consulta.c_str();
				   q_estado = mysql_query(cn.getConector(), c);
				   if (!q_estado) {
					   resultado = mysql_store_result(cn.getConector());
					   while (fila = mysql_fetch_row(resultado)) {
						   cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << endl;
					   }
				   }
				 
			   }
			   else {
				   cout << "fallo la conexion ..." << endl;
			   }
			   cn.cerrar_conexion();
		   
		   }
		   void actualizar () {
			   int q_estado = 0;
			   ConexionBD cn = ConexionBD();
			   cn.abrir_conexion();
			   if (cn.getConector()) {
				   string t = to_string(telefono);
				   string id_ts = to_string(id_tipo_sangre);
				   string id_e = to_string(id_estudiante);
				   string  consulta = "update estudiantes set codigo = '" + codigo + "',nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "',telefono = " + t + ",fecha_nacimiento = '" + fecha_nacimiento + "',id_tipo_sangre = " + id_ts + "where id_estudiante = " + id_e + "";
				   const char* c = consulta.c_str();
				   q_estado = mysql_query(cn.getConector(), c);
				   if (q_estado) {
					   cout << "Modificacion de datos exitoso..." << endl;

				   }
				   else {
					   cout << "Consulta fallida..." << endl;
				   }

			   }
			   else {
				   cout << "conexion fallida " << endl;
			   }
			   cn.cerrar_conexion();

		   }
		   void borrar () {
			   int q_estado = 0;
			   ConexionBD cn = ConexionBD();
			   cn.abrir_conexion();
			   if (cn.getConector()) {
				   string t = to_string(telefono);
				   string id_ts = to_string(id_tipo_sangre);
				   string id_e = to_string(id_estudiante);
				   string  consulta = "delete from estudiantes where id_estudiante = " + id_e + "";
				   const char* c = consulta.c_str();
				   q_estado = mysql_query(cn.getConector(), c);
				   if (!q_estado) {
					   cout << "eliminacion  de datos exitoso..." << endl;

				   }
				   else {
					   cout << "Consulta fallida..." << endl;
				   }

			   }
			   else {
				   cout << "conexion fallida: " << endl;
			   }
			   cn.cerrar_conexion();

		   }


};

