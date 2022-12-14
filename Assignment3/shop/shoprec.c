#include <stdio.h>
int minn(int i, int P, int n, int *k, int **c, int m)
{
    int R, j, min = m;
    if (P < 0) //Αν τα χρήματα είναι αρνητικό ποσό επιστρέφει το αρχικό ποσό
        return m;
    if (i == n) //Αν έχουμε φτάσει στα τελευταία στοιχεία του πίνακα επιστρέφει απλ΄΄α την τιμή τους
        return P;
    for (j = 0; j < k[i]; j++) //Εύρεση του μικρότερου κάθε γραμμής
    {
        R = minn(i + 1, P - c[i][j], n, k, c, m); //Υπολογισμός του επόμενου ποσού
        if (R < min)                              //Αν είναι μικρότερο το ποσό που βρέθηκε από το μέχρι στιγμής μικρότερο της γραμμής το θέτουμε ως μικρότερο
            min = R;
    }
    return min; //Επιστρέφει το μικρότερο κάθε γραμμής
}
int shop(int m, int n, int *k, int **c)
{
    int R, P = m, i = 0, j = 1;
    R = minn(i, P, n, k, c, m); //Υπολογισμός του μικρότερου υπολειπόμενου ποσού για την αγορά των προϊόντων
    R = m - R;                  //Υπολογισμός του μέγιστου δυνατού ποσού που μπορεί να ξοδευτεί
    return R;                   //Επιστροφή του αποτελέσματος
}
