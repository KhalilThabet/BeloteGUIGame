# Projet C++ : jeu Belote

>Le but de ce projet consiste à programmer une version simplifiée du Jeu de Belote Classique. Après avoir appris la programmation orienté objet en **C++**.Notre jeu contient deux versions :
>* Une version console. 
>* Une version graphique en : GUI (**Qt**). 

>Nous avons détaillé les caractéristiques du jeu et les règles dans les parties suivantes.  
# Présentation de jeu :
>C'est un jeu  de cartes à quatre joueurs avec un paquet de 32  cartes contenant 4 Couleurs (Pique, Cœur, Carreau et Trèfle) et 8 valeurs.
>
>La valeur d’une carte dépend de si elle est atout ou pas. Au première tour le joueur humain choisit l’un des bois pour être l’atout de la partie. Si des cartes ne sont pas des atouts, alors ces valeurs de la plus forte à la moins forte sont: Hors atout : As (11)– Dix(10) – Roi(4) – Dame(3) – Valet(2) – Neuf(0) – Huit(0) – Sept(0). Si elles sont des atouts, l’ordre change comme suit : toujours de la plus forte à la moins forte. A l’atout : Valet(20) – Neuf(14) – As(11) – Dix(10)– Roi(4) – Dame(3) – Huit(0) – Sept(0).

# Les règles de Jeu

>Une fois que l’atout choisi, un joueur commence à jouer sa première carte. Ici il n’est pas obligé de jouer un atout, il peut jouer n’importe quelle carte qu’il souhaite. On appellera le pli la collection de quatre cartes qui seront sur la table. Ensuite aux tours des autres joueurs, chaque joueur devrait jouer une carte du même bois que celle de la première carte du pli. Si un joueur n’en a pas, il sera obligé de jouer une carte atout. S’il n’a pas d’atout non plus, alors il est autorisé de jouer une carte quelconque. Quand chaque jouer à jouer une carte, on dit le pli est terminé et il est remporté par celui qui a joué la plus forte carte. S’il y des cartes atouts, alors la carte la plus forte sera l’atout plus fort, en respectant l’ordre que nous avons présentée au-dessus. S’il n’y a pas d’atout, la carte la plus forte est celle qui est la plus forte dans le bois de la première carte du pli. Celui qui vient de remporter le pli commence le pli suivant. Les équipes :
>Les joueurs forment deux équipes de deux. Les joueurs 1 et 3 forment première équipe, et les joueurs 2 et 4 forment deuxième équipe. A la fin de la partie, chaque équipe compte ses points en additionnant les points des cartes qu’elle a gagnées. L’équipe qui a remporté le dernier pli a droit à 10 points supplémentaires. L’équipe qui a plus de points au total remporte la partie.



# Digramme de classe
>On présente ci-dessous le diagramme de classe de la partie console et la partie graphique.
>
>![alt text](https://i.ibb.co/PY3nB0X/186493269-951275558781774-4261187433453887083-n.png)
