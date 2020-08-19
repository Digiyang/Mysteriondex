#ifndef SORT_H_
#define SORT_H_ SORT_H_


void Tausche(TCD * A, TCD * B);


int partition(TCD * Array, int ui, int oi, int (*Fkt)(TCD *, TCD *));


void qSort(TCD * Array, int ui, int oi, int (*Fkt)(TCD *, TCD *));


void QSort(TCD * Array, int Anz, int (*Fkt)(TCD *, TCD *));


int VerglTitel(TCD *A, TCD *B);


int VerglJahr(TCD *A, TCD *B);


int VerglLieder(TCD *A, TCD *B);


int VerglIntr(TCD *A, TCD *B);

#endif // SORT_H_
