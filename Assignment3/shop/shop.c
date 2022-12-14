#include <stdio.h>
#include "shop.h"
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int M, N, *K, **C, i, j, max = 0;
    if (argc<2)
    {
        printf("Need arguments to run!\n");
        exit(1);
    }
    M = atoi(argv[1]);        //Λαμβάνουμε το 2ο όρισμα από την γραμμή εντολών που αντιστοιχεί στα διαθέσιμα χρήματα
    if (scanf("%d", &N) != 1) //Διαβάζουμε από την είσοδο τον αριθμό των προϊόντων και σε περίπτωση που αποτύχει τερματίζεται το πρόγραμμα
        return 1;
    K = malloc(N * sizeof(int)); //Δυναμική δέσμευση των γραμμών του πίνακα K
    if (K == NULL)               //Σε περίπτωση που αποτύχει τερματίζεται το πρόγραμμα
        return -1;
    C = malloc(N * sizeof(int *)); //Δυναμική δέσμευση των γραμμών του πίνακα C
    if (C == NULL)                 //Σε περίπτωση που αποτύχει τερματίζεται το πρόγραμμα
        return -1;
    for (i = 0; i < N; i++) //Γέμισμα των πινάκων K και C
    {
        if (scanf("%d", &K[i]) != 1) //Διαβάζουμε από την είσοδο τον αριθμό των προϊόντων προς πώληση από κάθε είδος προϊόντως και σε περίπτωση που αποτύχει τερματίζεται το πρόγραμμα
            return 1;
        C[i] = malloc(K[i] * sizeof(int)); //Δεσμεύουμε για κάθε γραμμή του π΄ινακα C τόσες θέσεις όσο ο αριθμός των προϊόντων που έχουμε διαθέσιμα προς αγορά για κάθε τ΄ύπο προϊόντος
        if (C[i] == NULL)                  //Σε περίπτωση που αποτύχει τερματίζεται το πρόγραμμα
            return -1;
        for (j = 0; j < K[i]; j++)
            if (scanf("%d", &C[i][j]) != 1) //Διαβάζουμε από την είσοδο τις τιμές των προϊόντων από κάθε είδος προϊόντος και σε περίπτωση που αποτύχει τερματίζεται το πρόγραμμα
                return 1;
    }
    max = shop(M, N, K, C); //Καλείται η συνάρτηση για τον υπολογισμό του μέγιστου ποσού που μπορεί να ξοδευτεί με τα Μ χρήματα
    if (max > 0)            //Αν υπάρχει λύση την εμφαν΄ιζει αλλιώς εμφανίζει κατάλληλο μήνυμα
        printf("Maximum amount spent is: %d\n", max);
    else
        printf("No solution found\n");
    free(K); //Αποδέσμευση του πίνακα Κ
    for (i = 0; i < N; i++)
        free(C[i]); //Αποδέσμευση των στηλών του πίνακα c
    free(C);        //Αποδέσμευση των γραμμών του πίνακα C
}