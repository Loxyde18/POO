#include "mywindow.h"
#include "ui_mywindow.h"

#include "FichierUtilisateur.h"


MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    // Configuration de la table des clients (ne pas modifier)
    ui->tableWidgetClients->setColumnCount(2);
    ui->tableWidgetClients->setRowCount(0);
    QStringList labelsTableClients;
    labelsTableClients << "Nom" << "Hash du mot de passe";
    ui->tableWidgetClients->setHorizontalHeaderLabels(labelsTableClients);
    ui->tableWidgetClients->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidgetClients->horizontalHeader()->setVisible(true);
    ui->tableWidgetClients->horizontalHeader()->setDefaultSectionSize(300);
    ui->tableWidgetClients->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetClients->verticalHeader()->setVisible(false);
    ui->tableWidgetClients->horizontalHeader()->setStyleSheet("background-color: lightyellow");
    afficher();
}

MyWindow::~MyWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::setNom(const char* Text)
{
  if (strlen(Text) == 0 )
  {
    ui->lineEditNom->clear();
    return;
  }
  ui->lineEditNom->setText(Text);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* MyWindow::getNom()
{
  strcpy(_nom,ui->lineEditNom->text().toStdString().c_str());
  return _nom;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::setMotDePasse(const char* Text)
{
  if (strlen(Text) == 0 )
  {
    ui->lineEditMotDePasse->clear();
    return;
  }
  ui->lineEditMotDePasse->setText(Text);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* MyWindow::getMotDePasse()
{
  strcpy(_motDePasse,ui->lineEditMotDePasse->text().toStdString().c_str());
  return _motDePasse;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MyWindow::isNouveauChecked()
{
  if (ui->checkBoxNouveau->isChecked()) return 1;
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::setResultat(const char* Text)
{
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat->clear();
    return;
  }
  ui->lineEditResultat->setText(Text);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des utilisateurs (ne pas modifier) //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::ajouteTupleTableUtilisateurs(const char* nom,int hash)
{
    char Hash[20];
    sprintf(Hash,"%d",hash);

    // Ajout
    int nbLignes = ui->tableWidgetClients->rowCount();
    nbLignes++;
    ui->tableWidgetClients->setRowCount(nbLignes);
    ui->tableWidgetClients->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    auto flags = item->flags();
    flags.setFlag(Qt::ItemIsEditable, false).setFlag(Qt::ItemIsSelectable, false);
    item->setFlags(flags);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(nom);
    ui->tableWidgetClients->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    flags = item->flags();
    flags.setFlag(Qt::ItemIsEditable, false).setFlag(Qt::ItemIsSelectable, false);
    item->setFlags(flags);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Hash);
    ui->tableWidgetClients->setItem(nbLignes-1,1,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::videTableUtilisateurs()
{
    ui->tableWidgetClients->setRowCount(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::on_pushButtonLogin_clicked()
{
  // Récupération nom et mot de passe
  char nom[20],motDePasse[20];
  int nouvelUtilisateur, verif;
  strcpy(nom,getNom());
  strcpy(motDePasse,getMotDePasse());
  nouvelUtilisateur = isNouveauChecked();

  // TO DO
  int position = estPresent(nom);
  if(position == 0 && nouvelUtilisateur == 0)
  {
    setResultat("Utilisateur Pas Trouvé =(");
  }
  else
  {
    if(position == -1)
    {
      setResultat("Pas De Fichier !! (Bouton Login) =(");
    }
    else
    {
      setResultat("Bonjour Utilisateur !! =)");
    }
  }

  if(nouvelUtilisateur == 0)
  {
    verif = verifieMotDePasse(position, motDePasse);
  }

  if(verif == 0 && position > 0)
  {
    setResultat("Mot De Passe Incorrect =(");
  }

  if(nouvelUtilisateur == 1)
  {
    ajouteUtilisateur(nom, motDePasse);
    if(position > 0)
    {
      setResultat("Utilisateur Déjà Existant ! =(");
    }
    else
    {
      setResultat("Ajouté ! =)");
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::on_pushButtonAfficheFichier_clicked()
{
  // TO DO
  videTableUtilisateurs();
  int i = 0;
  UTILISATEUR vect[50];
  int cpt = listeUtilisateurs(vect);

  if(cpt == -1)
  {
    setResultat("Pas De Fichier (Bouton Afficher)");
  }
  else
  {
    while(i < cpt)
    {
      ajouteTupleTableUtilisateurs(vect[i].nom, vect[i].hash);
      i++;
    }
  }
}