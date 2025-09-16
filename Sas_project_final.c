
#include<stdio.h> 
#include <stdlib.h>
#include<string.h> 


int str_len(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

void   show_menu()
{
    int choisir;

    // printf("=========================================\n");
    // printf("      Analyseur de Texte & Moteur \n");
    // printf("=========================================\n");
    printf("\nVeuillez choisir une option :\n\n");

    printf("1 : Saisir un nouveau texte et analyser:\n");
    printf("2 : Afficher tous les mots (dictionnaire):\n");
    printf("3 : Rechercher un mot exact:\n");
    printf("4 : Rechercher un mot partiel:\n");
    printf("5 : Trier les mots :\n");
    printf("6 : Afficher les statistiques globales:\n");
    printf("7 : Analyses avancees :\n");
    printf("0 : Quitter le programme\n");
    printf("=========================================\n");

}
char *toLower(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 65 &&  str[i] <= 90)
        {
            str[i] = str[i] +32;
        }
        i++;
    }
    return str;  
}
char  *remove_flags(char *str)
{
    char *chain_afterRemove;
    int i = 0;
    str = toLower(str);
    int len  = str_len(str);
    chain_afterRemove = malloc(len * sizeof(char) + 1);
    
    int j = 0;
    while (str[i])
    {
        if (str[i] >= 97 && str[i] <= 122 || str[i] == 32)
        {
            chain_afterRemove[j] =  str[i];
            j++; 
        }
        i++;  
    }
    chain_afterRemove[j] = '\0';
   
    return chain_afterRemove;
}

int count_word(char * str)
{
    int j = 0;
    int i = 0;
    int found;
    while (str[i])
    {
        found = 0;
        if (str[i] == 32  )
        {
            found = 1;
            j++;
        }
        i++;
    }
    return j + 1; 
}
int  str_cmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i])
    {
        i++;
    }
    return s1[i] - s2[i];
    
}
void  stock(char *str_stock)
{
    int i = 0;
    int g = count_word(str_stock);
    char word[g][200];
    int j = 0;
    int c_word = 0;
    while (str_stock[i])
    {
        word[c_word][j] = str_stock[i];
        j++;
        if (str_stock[i] == 32)
        {
            word[c_word][j] = '\0';
            c_word++;
            j = 0;   
        }
        i++; 
    }
    word[c_word][j] = '\0';
    j = 0;
   
    
    i = 0;
    int cou = 1;
    
    while (i < g) 
    {
        printf("------------------\n\n"); 
        printf("mot =  \"%s", word[i]);
        printf("\nLongueur du mot  = %d  \n" , str_len(word[i]) -1 );
        printf("position = %d \n", i +1); 
        cou = 0; 
        cou = 0; 
    for (int c = 0; c < g; c++)
    {  
            if (str_cmp(word[i], word[c]) == 0)
            {  
                cou++; 
            }
    }
        printf("count word =  %d \n",cou );
        printf("------------------------\n"); 
        i++;   
    }
}

int main()
{
    int choisir;
    char str[2000];
    char mot_rocherche[100];
    int choi_statistiques; 
    
    int i  = 1;
    int count_add = 0;
    
    while (i)
    {
        show_menu();
        printf(" Entrez le numero de votre choix : ");
        scanf("%d", &choisir);
        getchar();
        if (choisir == 1)
        {
            printf("Nouveau texte : ");
            fgets(str, 2000, stdin);

            char *cleaned = remove_flags(str);  
            strcpy(str, cleaned);               
            free(cleaned);                       

            printf("%s\n", str);  
            count_add++;  
        }

        else if (choisir == 2 )
        {
            stock(str);  
        }
        else if (choisir == 3)
        {
            printf("Enter mot :");
            fgets(mot_rocherche, 100, stdin);
            mot_rocherche[strcspn(mot_rocherche, "\n")] = '\0';
            toLower(mot_rocherche);
            int found = 0; 
            if (strstr(str, mot_rocherche) != NULL)
                printf("Mot \"%s\" trouve dans le texte.\n", mot_rocherche);

            else
                printf("Mot \"%s\" non trouvé.\n", mot_rocherche);
        }
        else if (choisir == 5)
        {
            
            
        }
        else if (choisir == 6)
        {
            
        }
        
        
        
        if (choisir == 8)
            return 0;   
        
    }
}