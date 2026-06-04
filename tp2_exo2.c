#include<stdio.h>
double saisir_montant(double min, double max) {
double m;
    do{
        printf("\n Entrez un montant:");
        scanf("%lf",&m);
        if (m<min || m>max)
        {
            printf("le montant est invalide: ");
        }
        
    }
  while (m<min || m>max);
 
    return m;
}
void saisir_transactions(double t[], int n) {
    for (int i = 0; i < n; i++) {
        t[i] = saisir_montant(0,100000);
    }
}
void afficher_transactions(const double t[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Transaction %d: %lf cs \n", i + 1, t[i]);
    }
}
double total(const double t[],int n) {
    double s=0;
    for (int i = 0; i <n; i++)
    {
        s=s+t[i];/* code */
    }
    return s;
}
double moyenne_d(const double t[], int n) {
    double s=0;
    for (int i = 0; i <n; i++)
    {
        s=s+t[i];/* code */
    }
    return s/n;
}
double maximum_d(const double t[],int n) {
    double max=t[0];
    for (int i = 0; i < n; i++)
    {
        if (t[i]>t[0])
        {
           max=t[i]; /* code */
        }
    }
    return max;
}
double minimum_d(const double t[],int n) {
    double min=t[0];
    for (int i = 0; i < n; i++)
    {
        if (t[i]<t[0])
        {
           min=t[i]; /* code */
        }
    }
    return min;
}
int montant_sup(const double t[],int n, double seuil) {
    int c=0;
    for (int i = 0; i < n; i++)
    {
        if (t[i]>seuil)
        {
           c++; /* code */
        }
    }
    return c;
}
int recherche_montant(const double t[],int n, double cible) {
    for (int i = 0; i < n; i++)
    {
       if (t[i]==cible)
       {
        return i+1;/* code */
       }
     } 
      return -1;
    }

void trier(double t[], int n) {
    double mps;
 for (int i = 0; i < n; i++)
 {
    for (int j = 0; j < n; j++)
    {
        if (t[i]>t[j])
        {
           mps=t[i];
           t[i]=t[j];
           t[j]=mps;/* code */
        }
        /* code */
    }
    
 }
 
}
 void afficher_trier (double t[], int n) {
    for (int i = 0; i < n; i++)
    {
      printf("\nTransaction %d : %lf cs",i,t[i]) ;/* code */
    }
    
 }
double calculer_montant(double m) {
if (m<=1000)
{
    return 25;
}
else if (m>=1001 && m<=100000)
{
    return (m*1.5)/100;
}
else if (m>=100001 && m<250000)
{
    return (m*2)/100;
}
else if (m>=250000)
{
    return 5000;
}
return 0;
}

double frais_journaliers (const double t[], int n) {
   double toto=0;
    for (int i = 0; i < n; i++)
    {
     toto=toto+calculer_montant(t[i]);
    }
   return toto; 
}
int est_numero_valide(const char *numero) {
    int i;
    for (i = 0; i<7; i++) {
        if (numero[i] > '7') {
            return 0; // Numéro invalide
        }
        i++;
    }
    return 1; // Numéro valide
    

}
int main() {
    int n;
    printf("Entrez le nombre de transactions: ");
    scanf("%d", &n);
    
    double transactions[n];
    double cible;
    char numero[7];
    
    saisir_transactions(transactions, n);
    afficher_transactions(transactions, n);
    total(transactions,n);
    printf("le total des transactions est: %lf cs \n",total(transactions,n));
    moyenne_d(transactions,n);
    printf("la moyenne des transactions est: %lf cs \n",moyenne_d(transactions,n));
    printf("le maximum des transactions est: %lf cs \n",maximum_d(transactions,n));
    printf("le minimum des transactions est: %lf cs \n",minimum_d(transactions,n));
    double seuil=6000;                                                   
    printf("le nombre de transactions supérieures a %lf cs est: %d \n", seuil, montant_sup(transactions,n,seuil));
    printf("Entrez la valeur que voulez rechercher:");
    scanf("%lf",&cible);
    printf("\nTransaction %d correspondant a %lf",recherche_montant(transactions,n,cible),cible);

    printf("Le total des frais journalier est:%lf",frais_journaliers(transactions,n));
    printf("Entrez un numero de telephone:");
    scanf("%s",numero);
    printf("Le numero de telephone est %s et il est %s", numero, est_numero_valide(numero) ? "valide" : "invalide");
    return 0;
}
