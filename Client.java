/**********************************************************/
/*                  Création d'un client                  */
/*     qui va recevoir des données du serveur             */
/**********************************************************/

//LES imports sont fait de java.net et java.io
//Gerer les exceptions

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client{
	public static void main(String[] args){
		
		Socket sock;
		BufferedReader in;
		PrintWriter out;
		try{
			
			sock = new Socket(InetAddress.getLocalHost(),2009);
				System.out.println("Demande de connexion");
				
			in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			String mesg_du_serveur = in.readLine();
			System.out.println("le message recu est : "+mesg_du_serveur);
			sock.close();
			}catch (IOException/*  | UnknownHostException*/ e2 ){
			System.out.println(e2.getMessage());
			}
			
	}
}
