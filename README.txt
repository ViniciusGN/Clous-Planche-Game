Vinicius Nascimento et Luciana Adriao dos Santos
TP4 C++ Group 4
© 2024 ENSICAEN. All rights reserved.
This code is the intellectual property of ENSICAEN and is subject to the institution's terms and conditions.
Unauthorized reproduction, distribution, or use is strictly prohibited.

Question 1

Dans le contexte des associations Clou-Obstacle et Compteur-Obstacle, le sous-graphe formé par la relation « père-fils » pour la désallocation est un arbre. 
En effet, un arbre est un type de sous-graphe orienté acyclique où chaque nœud (obstacle) n'a qu'un seul parent ou aucun parent (racine). 
Dans ce cas, la relation « père-fils » entre les obstacles représente un arbre où chaque obstacle est relié à ses successeurs de manière hiérarchique, 
garantissant ainsi que la structure reste sans cycles et permet de gérer correctement la désallocation des objets.

Question 2

Pour assurer un fonctionnement correct de la destruction récursive des obstacles, le destructeur de la classe des obstacles doit être virtuel.
Cela garantit que lorsque la destruction est appelée via un pointeur de type Obstacle, le destructeur des classes dérivées (comme Clou ou Compteur) sera également appelé.
Cela permet la désallocation correcte des ressources dans les classes dérivées et assure que la destruction récursive des objets fonctionne comme prévu.