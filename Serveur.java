/**********************************************************/
/*                  Création d'un serveur                 */
/*     qui va envoyer des données au client               */
/**********************************************************/




//Les imports :
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
//import java.net.UnknownHostException;
public class Serveur {
	public static void main(String[] args){
		ServerSocket sockserveur;
		Socket sockduserveur;
		BufferedReader in ;
		PrintWriter out;
		try{
			sockserveur = new ServerSocket(2009);
			System.out.println("le serveur est branché au port :"+sockserveur.getLocalPort());
			sockduserveur = sockserveur.accept();
				System.out.println("nouvelle connexion");
			out = new PrintWriter(sockduserveur.getOutputStream());
			out.println("connexion");
			out.flush();
			sockduserveur.close();
			sockserveur.close();
		}catch (IOException e ){
			System.out.println(e.getMessage());
			}
	}
}
