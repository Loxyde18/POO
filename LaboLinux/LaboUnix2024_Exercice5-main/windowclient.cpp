#include "windowclient.h"
#include "ui_windowclient.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

extern WindowClient *w;

#include "protocole.h" // contient la cle et la structure d'un message

extern char nomClient[40];
int idQ; // identifiant de la file de message
void handlerSIGUSR1(int);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
WindowClient::WindowClient(QWidget *parent):QMainWindow(parent),ui(new Ui::WindowClient)
{
  ui->setupUi(this);
  setWindowTitle(nomClient);


  // Recuperation de l'identifiant de la file de messages
  fprintf(stderr,"(CLIENT %s %d) Recuperation de l'id de la file de messages\n",nomClient,getpid());
  // TO DO (etape 2)
  idQ = msgget(CLE, IPC_CREAT | 0666);
  if (idQ == -1) {
    perror("Erreur msgget");
    exit(EXIT_FAILURE);
  }


  // Envoi d'une requete d'identification
  // TO DO (etape 5)
  MESSAGE message;
  message.type = 1;
  message.expediteur = getpid();
  strcpy(message.texte, "Identification");

  if (msgsnd(idQ, &message, sizeof(MESSAGE) - sizeof(long), 0) == -1) {
      perror("Erreur lors de l'envoi de la requête d'identification");
      exit(EXIT_FAILURE);
  }

  // Armement du signal SIGUSR1
  // TO DO (etape 4)
  struct sigaction A;
  A.sa_handler = handlerSIGUSR1;
  sigemptyset(&A.sa_mask);
  A.sa_flags = 0;

  if (sigaction(SIGUSR1,&A,NULL) == -1)
  {
    perror("Erreur de sigaction");
    exit(1);
  }

}

WindowClient::~WindowClient()
{
  delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowClient::setRecu(const char* Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditRecu->clear();
    return;
  }
  ui->lineEditRecu->setText(Text);
}

void WindowClient::setAEnvoyer(const char* Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditEnvoyer->clear();
    return;
  }
  ui->lineEditEnvoyer->setText(Text);
}

const char* WindowClient::getAEnvoyer()
{
  if (ui->lineEditEnvoyer->text().size())
  { 
    strcpy(aEnvoyer,ui->lineEditEnvoyer->text().toStdString().c_str());
    return aEnvoyer;
  }
  return NULL;
}

const char* WindowClient::getRecu()
{
  if (ui->lineEditRecu->text().size())
  { 
    strcpy(recu,ui->lineEditRecu->text().toStdString().c_str());
    return recu;
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowClient::on_pushButtonEnvoyer_clicked()
{
  fprintf(stderr,"Clic sur le bouton Envoyer\n");
  // TO DO (etapes 2, 3, 4)
  MESSAGE message;

  message.type = 1;  // Type pour le client
  message.expediteur = getpid();
  const char* text = getAEnvoyer();
  strcpy(message.texte, text);
  
  if (msgsnd(idQ, &message, sizeof(MESSAGE) - sizeof(long), 0) == -1) {
    perror("Erreur msgsnd");
    exit(EXIT_FAILURE);
  }
}

void WindowClient::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  if (msgctl(idQ, IPC_RMID, NULL) == -1) perror("(SERVEUR) Erreur lors de la suppression de la file de messages");
  else fprintf(stderr, "(SERVEUR)File de messages supprimée avec succès.\n");
  exit(1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TO DO (etape 4)

void handlerSIGUSR1(int sig){
  (void) sig;
  MESSAGE recois;
  if (msgrcv(idQ, &recois, sizeof(MESSAGE) - sizeof(long), 0, 0) == -1){
    perror("Erreur msgrcv");
    exit(EXIT_FAILURE);
  }
  fprintf(stderr, "CLIENT(%d) Message : %s\n", recois.expediteur, recois.texte);
  w->setRecu(recois.texte);
}