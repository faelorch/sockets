#include <stdio.h> 
#include <stdlib.h> 
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h> 

int main(int argc, char *argv[])   
{ 
   int s_ecoute,scom, lg_app,i,j,cle=0,somme=0; 
   struct sockaddr_in adr; 
   struct sockaddr_storage recep; 
   char buf[1500], renvoi[1500], host[1024],service[20]; 
   s_ecoute=socket(AF_INET,SOCK_STREAM,0); 
   printf("creation socket\n"); 
   adr.sin_family=AF_INET; 
   adr.sin_port=htons(atoi(argv[1])); 
   adr.sin_addr.s_addr=INADDR_ANY;
   
   if (bind(s_ecoute,(struct sockaddr *)&adr,sizeof(struct sockaddr_in)) !=0) 
   { 
     printf("probleme de bind sur v4\n"); 
     exit(1); 
   } 
     
   if (listen(s_ecoute,5) != 0)      
   { 
       printf("pb ecoute\n"); exit(1);
   }
   printf("en attente de connexion\n"); 
   
   while (1)  { 
      scom=accept(s_ecoute,(struct sockaddr *)&recep, (int *)&lg_app); 
      getnameinfo((struct sockaddr *)&recep,sizeof (recep), host, sizeof(host),service, sizeof(service),0); 
      printf("recu de %s venant du port %s\n",host, service); 
      while (1)    
      { 
				 /* Reception */
				 recv(scom,buf,sizeof(buf),0);
				 
				 /* Décryptage César */
				 for(i=0; i<strlen(buf); i++)
						buf[i]=buf[i]-cle;
				 buf[i]='\0';
				 
				 printf("buf recu %s\n",buf); 
				 
				 /* Renvoi */
				 bzero(renvoi,sizeof(renvoi)); 
				 for(i=0 ; i < strlen(buf) ; i++)
				 {
				 		somme = buf[i];
			 			printf("lettre : %d\n",buf[i]);
			 	 }
			 	 /* test***************
			 	 GET/~laurenco/ZZ2/pourcentage_v_get.php?phrase=fati&valider=valider HTTP/1.1;
					HOST: www.isima.fr*/
			 	 
				 somme = ((somme/2)%281);
				 printf("SOMME : %d\n",somme);
					 
				 sprintf(renvoi,"%d",somme);
				 /*for(i=strlen(buf)-1,j=0;i>=0;i--,j++)  
						renvoi[j]=buf[i]; 
				 renvoi[j+1]='\0';*/ 
				 send(scom,renvoi,strlen(renvoi),0); 
				  
				 
				 if (strcmp(buf,"FIN") == 0)    
						break; 
				 bzero(buf,sizeof(buf));  
			} 
   close(scom); 
   
   } 
close(s_ecoute); 
} 

/*gcc serveur_tcp.c -o serveur_tcp && clear && serveur_tcp  */
