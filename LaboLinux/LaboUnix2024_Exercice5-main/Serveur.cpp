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

int main()
{
  MESSAGE requete;
  pid_t destinataire;

  // Armement du signal SIGINT
  // TO DO (etape 6)

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
  fprintf(stderr,"(SERVEUR) Attente de connection d'un premier client...\n");
  // TO DO (etape 5)
  fprintf(stderr,"(SERVEUR) Attente de connection d'un second client...\n");
  // TO DO (etape 5)


  while(1) 
  {
    // TO DO (etapes 3, 4 et 5)
  	fprintf(stderr,"(SERVEUR) Attente d'une requete...\n");
    if (msgrcv(idQ, &requete, sizeof(MESSAGE) - sizeof(long), 1, 0) == -1) {
      perror("(SERVEUR) Erreur msgrcv");
      exit(EXIT_FAILURE);
    }
    fprintf(stderr,"(SERVEUR) Requete recue de %d : --%s--\n",requete.expediteur,requete.texte);
    fprintf(stderr, "%ld       pid : %d      msg : %s\n", requete.type, requete.expediteur, requete.texte);
    pid1 = requete.expediteur;
    destinataire = pid1;
    fprintf(stderr,"(SERVEUR) Envoi de la reponse a %d\n",destinataire);

    MESSAGE reponse;
    strcpy(reponse.texte, requete.texte);
    char prefix[] = "(SERVER)";
    strcat(reponse.texte, prefix);
    reponse.type = destinataire;
    reponse.expediteur = getpid();
    msgsnd(idQ, &reponse, sizeof(MESSAGE) - sizeof(long), 0);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TO DO (etape 6)
