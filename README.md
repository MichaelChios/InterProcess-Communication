# InterProcess-Communication
Use of fork() and pipelines


Υπολογισμός αθροίσματος με χρήση συνεργαζόμενων διεργασιών

Να γραφεί πρόγραμμα σε γλώσσα C, που υπολογίζει το άθροισμα
των φυσικών αριθμών μέχρι το ένα μεγάλο Ν, (π.χ. Ν = 1.000.000)
δηλ sum = 1 + 2 + 3 + ... + Ν

Για τον υπολογισμό του αθροίσματος να χρησιμοποιηθούν
4 συνεργαζόμενες διεργασίες παιδιά, που θα τις δημιουργεί
μια γονική διεργασία.
Κάθε διεργασία παιδί θα υπολογίζει το άθροισμα των 1/4 των όρων
και θα επιστρέφει το αποτέλεσμα στη γονική διεργασία,
που θα υπολογίζει την τελική τιμή.

Επίσης, η γονική διεργασία ελέγχει το τελικό αποτέλεσμα
με τη βοήθεια του τύπου:
1 + 2 + 3 + ... + Ν = Ν(Ν + 1)/2

Απαραίτητη χρήση Linux.
