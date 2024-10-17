#include "FichierUtilisateur.h"

int estPresent(const char* nom)
{
  int fb = open("utilisateurs.dat", O_RDWR | O_CREAT, 0644);

  if (fb == -1)
  {
    std::cerr << "Erreur : Impossible d'ouvrir ou de créer le fichier." << std::endl;
    return -1;
  }
    
  UTILISATEUR utilisateur;
  int position = 1;
  while(read(fb, &utilisateur, sizeof(UTILISATEUR)) > 0)
  {

    if (strcmp(utilisateur.nom, nom) == 0)
    {
      close(fb);
      return position;
    }
    position++;
  }
  close(fb);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
int hash(const char* motDePasse)
{
  int position = 0;
  int cpt =1;
  int somme = 0;
  int taille;
  taille = strlen(motDePasse);

  while(position < taille)
  {
    int code_ascii = motDePasse[position];
    somme += cpt * code_ascii;
    position++;
    cpt++;
  };
  somme = somme % 97;
  return somme;
}

void afficher()
{
  int fb = open("utilisateurs.dat", O_RDWR | O_CREAT, 0644);
    
    if (fb == -1) {
        std::cerr << "Erreur : Impossible d'ouvrir ou de créer le fichier." << std::endl;
        return; // Arrêter si le fichier ne peut pas être ouvert
    }

    UTILISATEUR utilisateur;

    while(read(fb, &utilisateur, sizeof(utilisateur)) > 0)
    {
      printf("Nom : %s Hash : %d\n", utilisateur.nom, utilisateur.hash);
    }
  close(fb);
}

////////////////////////////////////////////////////////////////////////////////////
void ajouteUtilisateur(const char* nom, const char* motDePasse)
{
  int fb = open("utilisateurs.dat", O_RDWR | O_CREAT, 0644);
    
    if (fb == -1)
    {
      std::cerr << "Erreur : Impossible d'ouvrir ou de créer le fichier." << std::endl;
      return;
    }

    UTILISATEUR utilisateur;

    strncpy(utilisateur.nom, nom, sizeof(utilisateur.nom) - 1);
    utilisateur.hash = hash(motDePasse);


    lseek(fb, 0, SEEK_END);

    if (write(fb, &utilisateur, sizeof(utilisateur)) == -1) {
        std::cerr << "Erreur lors de l'écriture dans le fichier." << std::endl;
    }

    close(fb);
}

////////////////////////////////////////////////////////////////////////////////////
int verifieMotDePasse(int pos, const char* motDePasse)
{
  int fb = open("utilisateurs.dat", O_RDWR | O_CREAT, 0644), hassh;

  if (fb == -1)
  {
    std::cerr << "Erreur : Impossible d'ouvrir ou de créer le fichier." << std::endl;
  }

  UTILISATEUR utilisateur;
  lseek(fb, pos * sizeof(UTILISATEUR), SEEK_SET);
  read(fb, &utilisateur, sizeof(utilisateur));
  hassh = hash(motDePasse);
  if(utilisateur.hash == hassh) 
  {
    close(fb);
    return 1;
  }
  close(fb);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
int listeUtilisateurs(UTILISATEUR *vecteur) // le vecteur doit etre suffisamment grand
{
  // TO DO
  return 0;
}
