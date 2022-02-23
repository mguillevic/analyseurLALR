# analyseurLALR

Notre analyseur permet de vérifier que la chaine de charactère entrée vérifie la structure gramaticale mise en place. 
Notre grammaire permet de réaliser des calculs de multiplications et additions tout en respectants les priorités.
Voici la grammaire utilisée:
1) E'->E
2)E->E+E
3)E->E*E
4)E->(E)
5)E->val

Pour débuter une analyse:
- Executez le fichier main.exe. 
- Entrez la chaine de charactère à analyser

L'analyseur vous indiquera si la syntaxe de la chaine entrée est valide ou non.
Si elle est valide, le resultat du calcul est affiché.
