# Algoritmi i strukture podataka
Projekt - measures_v2.csv

## Opis projekta
Program koji je napravljen ima ulogu rada kao baza podataka. U ovom slučaju naša baza podataka je vektor koja dohvaća podatke iz .csv datoteke. Nad našom bazom podataka (vektorom) vrše se razne operacije kao što su brisanje, umetanje i pretraživanje podataka. Pretraživanje podataka odvija se pomoću binarnog pretraživanja. Umetanje i brisanje se odvija pomoću standardnih metoda(iteratori, erase, itd.) implementiranog vektora. Kako bi sve ovo bilo moguće bilo je potrebno stvoriti klasu. Problem s kojim sam susreo je bio kako u vektor pohraniti podatke kao tip double (jer s getline metodom dohvaćamo string) stoga sam koristio transform funkciju koja omogućuje prebacivanje podataka iz jednog vektora u drugi te mijenjanje početnog tipa varijable svakog elementa iz string u double(linija 45).

## Rezultati
    --spremanje u vektor: 3789887us
    --pretraživanje po ključu ili vrijednosti: 1994630us
    --brisanje po ključu ili vrijednosti: 1210788us
    --dodavanje po ključu ili vrijednosti: 1183834us
    --pretraga max vrijednosti: 2059725us
    --pretraga min vrijednosti: 2005633us