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
char  *str_copy( char *dest, char *src )
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest ;
    
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
    printf("8 : exit\n");
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
char  **sort_ordre_alphab(char **word,  int size)
{
    char *swap = malloc(200 * sizeof(char));
    int i;
    while (size > 0)
    {
        i = 0;
        while (i < size -1)
        {
            if (str_cmp(word[i], word[i+1]) > 0)
            {
                str_copy(swap , word[i]);
                str_copy(word[i], word[i +1]);
                str_copy(word[i +1], swap);
                
            }
            i++;
        }
        size--;  
    }
    free(swap);
    return word; 
}

char  **stock(char *str_stock)
{
       
      char *cleaned = remove_flags(str_stock);   

    int g = count_word(cleaned);   
    char **word = malloc(g * sizeof(char *));         

    int i = 0;
    int j = 0;
    int c_word = 0;
    word[c_word] = malloc(200 * sizeof(char));         

    while (cleaned[i])
    {
        if (cleaned[i] != ' ')
        {
            word[c_word][j] = cleaned[i];
            j++;
        }
        else
        {
            word[c_word][j] = '\0';
            c_word++;
            j = 0;
            word[c_word] = malloc(200 * sizeof(char));      
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
        printf("mot =  \"%s\"", word[i]);
        printf("\nLongueur du mot  = %d  \n" , str_len(word[i]) );
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
     
    sort_ordre_alphab(word,g);
    return word;
    
}
void show_sort(char *str_stock) 
{
    char *cleaned = remove_flags(str_stock);   

    int g = count_word(cleaned);   
    char **word = malloc(g * sizeof(char *));         

    int i = 0;
    int j = 0;
    int c_word = 0;
    word[c_word] = malloc(200 * sizeof(char));         

    while (cleaned[i])
    {
        if (cleaned[i] != ' ')
        {
            word[c_word][j] = cleaned[i];
            j++;
        }
        else
        {
            word[c_word][j] = '\0';
            c_word++;
            j = 0;
            word[c_word] = malloc(200 * sizeof(char));      
        }
        i++;
    }
    word[c_word][j] = '\0';

    sort_ordre_alphab(word, g); 

    printf("\n Les mots tries alphabet\n");
    for (int i = 0; i < g; i++)
    {
        printf("%s\n", word[i]);
    }

    for (int i = 0; i < g; i++)
    {
        free(word[i]);
    }
    free(word);
    free(cleaned);
}

 void show_sort_Par_frequence(char *str_stock) 
{
    char *cleaned = remove_flags(str_stock);    

    int g = count_word(cleaned);   
    char **word = malloc(g * sizeof(char *));         

    int i = 0;
    int j = 0;
    int c_word = 0;
    word[c_word] = malloc(200 * sizeof(char));         

    while (cleaned[i])
    {
        if (cleaned[i] != ' ')
        {
            word[c_word][j] = cleaned[i];
            j++;
        }
        else
        {
            word[c_word][j] = '\0';
            c_word++;
            j = 0;
            word[c_word] = malloc(200 * sizeof(char));      
        }
        i++;
    }
    word[c_word][j] = '\0';
    struct count_unique
    {
        char str[200];
        int count;
    };

    struct count_unique  *C_farz = malloc(g * sizeof(char));
    
    int farz_count = 0;
    i = 0;
   
    while (i < g)
    {

        int found = 0;
        int j = 0;
        while (j < farz_count) 
        {
            if (strcmp(C_farz[j].str, word[i]) == 0) {
            C_farz[j].count++;
            found = 1;
            break;
        }
        j++;
        }
        if (found == 0) 
        {
             strcpy(C_farz[farz_count].str, word[i]);
             C_farz[farz_count].count = 1;
             farz_count++;
    }
         i++;
    }
    i = 0;
    while (i < g)
    {
        printf("%s\n", C_farz[i].str);
        i++;
    }
    
    for (int i = 0; i < g; i++)
    {
        free(word[i]);
    }
    free(word);
    free(cleaned);
}
void show_statistiques_globales(char *str_stock)
{
    char *cleaned = remove_flags(str_stock);    
    int g = count_word(cleaned);   
    char **word = malloc(g * sizeof(char *));         

    int i = 0;
    int j = 0;
    int c_word = 0;
    word[c_word] = malloc(200 * sizeof(char));         

    while (cleaned[i])
    {
        if (cleaned[i] != ' ')
        {
            word[c_word][j] = cleaned[i];
            j++;
        }
        else
        {
            word[c_word][j] = '\0';
            c_word++;
            j = 0;
            word[c_word] = malloc(200 * sizeof(char));      
        }
        i++;
    }
    word[c_word][j] = '\0';
    
    i = 0;
    int total = 0;
    while (i < g)
    {
        total = total + str_len(word[i]);
        i++;
    }
    
    printf("\n--------------------\n");
    printf(" le nombre total de mots  = %d \n", g);
    printf("nombre de mots uniques = \n");
    printf("longueur moyenne %d = \n"  ,total / g );
    printf("mot le plus long =  ")  ;     
    
    for (int i = 0; i < g; i++)
    {
        free(word[i]);
    }
    free(word);
    free(cleaned);


}

int main()
{
    int choisir;
    char str[2000];
    char mot_rocherche[100];
    char mot_rocherche_more[100];

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

        else if (choisir == 2)
        {
            stock(str);  
        }
        else if (choisir == 3)
        {
            printf("Enter mot :");
            fgets(mot_rocherche, 100, stdin);
            mot_rocherche[strcspn(mot_rocherche, "\n")] = 0;
            toLower(mot_rocherche);
            if (strstr(str, mot_rocherche) != NULL)
                printf("Mot \"%s\" trouve dans le texte.\n", mot_rocherche);

            else
                printf("Mot \"%s\" non trouvé.\n", mot_rocherche);
        }
        else if (choisir == 4 )
        {
             printf("Enter mot :");
             fgets(mot_rocherche_more, 100, stdin);
             mot_rocherche_more[strcspn(mot_rocherche_more, "\n")] = 0;
             if (strstr(str, mot_rocherche_more) != NULL)
             {
                printf("Mot \"%s\" trouve dans le texte.\n", mot_rocherche_more);
             }else
                printf("Mot \"%s\" non trouvé.\n", mot_rocherche_more);

        }
        
        else if (choisir == 5)
        {
            int choisir;
            printf("\n 1 : Par ordre alphabetique \n 2: Par freequence (decroissante)\n 3:Par longueur (croissante)\n\n");
            scanf("%d", &choisir); 
            if (choisir == 1)
            {
                show_sort(str);
            }
            else if(choisir == 2)
            {
                show_sort_Par_frequence(str);  
            }
            
        }
        else if (choisir == 6)
        {
            
            
        }
        
        
        
        if (choisir == 8)
            return 0;   
        
    }
}