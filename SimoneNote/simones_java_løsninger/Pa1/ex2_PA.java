
// Opgave 2. Tidskompleksistet
// For at finde tidskompleksiteten fokuserer man på indre løkker og de operationer som udføres indeni.
// Den yderste løkke kører N gange, den miderste kører N/2 gange for hver iteration af den yderste løkke fordi j fordobles for hver iteration.
// Den inderste løkke kører N*sqrt(N) gange for hver iteration af den miderste løkke.
// Derfor er tidskompleksiteten: N*(N/2)*N*sqrt(N) = (1/2)*N^3*sqrt(N) = O(N^3*sqrt(N))
// Dominerende term: N^3*sqrt(N)
// Konstant faktor: 1/2 foran N^3*sqrt(N) påvirkervirker ikke den asymptoptiske vækst af algoritmen
// Andre operationer: de øvrige tager konstant tid og bidrager ikke til tidskompleksiteten
// Konklusion: Algoritmens tidskompleksistet er O(N^3*sqrt(N)), så udførelsestiden vokser meget hurtigt ift. inputstørrelsen N. For store N er den ikke så effektiv.