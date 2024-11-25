#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "protocole.h" // contient la cle et la structure d'un message

int idQ;
int pid1,pid2;

//void handlerSIGINT(int sig);

int main()
{
  MESSAGE requete;
  pid_t destinataire;

  // Armement du signal SIGINT
  // TO DO (etape 6)
  /*struct sigaction as;
  as.sa_handler = handlerSIGINT;
  sigemptyset(&as.sa_mask);
  as.sa_flags = 0;

  if (sigaction(SIGINT,&as,NULL) == -1)
  {
    perror("Erreur de sigaction");
    exit(1);
  }*/

  // Creation de la file de message
  fprintf(stderr,"(SERVEUR) Creation de la file de messages\n");
  // TO DO (etape 2)
  idQ = msgget(CLE, IPC_CREAT | 0666);
  if (idQ == -1) {
      perror("(SERVEUR) Erreur msgget");
      exit(EXIT_FAILURE);
  }
  else{
    fprintf(stderr,"file créé\n");
  }

  // Attente de connection de 2 clients
  // TO DO (etape 5)
  //1er Client
  while(true){
    fprintf(stderr,"(SERVEUR) Attente de connection d'un premier client...\n");
    MESSAGE identifiant;
    if(msgrcv(idQ, &identifiant, sizeof(MESSAGE) - sizeof(long), 1, 0) == -1){
      fprintf(stderr,"ERREUR");
      exit(1);
    }
  pid1 = identifiant.expediteur;
  break;
  }
  fprintf(stderr,"pid client 1 : %d\n", pid1);

  //2ème Client
  while(true)
  {
    fprintf(stderr,"(SERVEUR) Attente de connection d'un second client...\n");
    MESSAGE identifiant2;
    if(msgrcv(idQ, &identifiant2, sizeof(MESSAGE) - sizeof(long), 1, 0) == -1){
      fprintf(stderr,"ERREUR");
      exit(1);
    }
    pid2 = identifiant2.expediteur;
    break;
  }
  fprintf(stderr,"pid client 2 : %d\n", pid2);


  while(1) 
  {
    // TO DO (etapes 3, 4 et 5)

    //En attente d'une requête
  	fprintf(stderr,"(SERVEUR) Attente d'une requete...\n");
    if (msgrcv(idQ, &requete, sizeof(MESSAGE) - sizeof(long), 1, 0) == -1) {
      perror("(SERVEUR) Erreur msgrcv");
      exit(EXIT_FAILURE);
    }

    fprintf(stderr,"(SERVEUR) Requete recue de %d : --%s--\n",requete.expediteur,requete.texte);
    fprintf(stderr, "%ld       pid : %d      msg : %s\n", requete.type, requete.expediteur, requete.texte);

    //Choix de mes destinataires
    if (requete.expediteur == pid1) destinataire = pid2;
    else destinataire = pid1;


    fprintf(stderr,"(SERVEUR) Envoi de la reponse a %d\n",destinataire);

    //Envoie de la réponse du client 1 a client 2 ou l'inverse
    MESSAGE reponse;
    strcpy(reponse.texte, requete.texte);
    reponse.type = destinataire;
    if (destinataire == pid1) reponse.expediteur = pid2;
    else reponse.expediteur = pid1;
    msgsnd(idQ, &reponse, sizeof(MESSAGE) - sizeof(long), 0);

    //Envoie du signal a mes destinaires;
    if (destinataire == pid2) kill(pid2, SIGUSR1);
    else kill(pid1, SIGUSR1);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TO DO (etape 6)
/*void handlerSIGINT(int sig){
}*/