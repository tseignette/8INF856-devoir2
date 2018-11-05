# 8INF856 - Devoir 2

## Fonctionnement
* ``make d2s`` pour compiler la version séquentielle
* ``make d2p`` pour compiler la version parallèle
* ``make generator`` pour compiler le générateur de tableau
* ``make`` pour tout compiler

Les exécutables créés prennent respectivement le nom de ``d2s``, ``d2p`` et ``generator`` et se situent dans le dossier ``bin``.

## Générateur de tableau
``./bin/generator 1000`` pour générer deux tableaux triés de longueur 1000. Ils se situent dans le fichier ``./test/fichier_test``. Le premier nombre est la longueur du tableau.

## Test
Il est possible de compiler en mode test pour afficher le temps d'exécution au lieu du tableau de sortie : ``make d2s FLAG=-DTEST``. Pour la version parallèle, on peut aussi passer le nombre de threads et la limite avant d'utiliser l'algorithme séquentiel : ``make d2p FLAG="-DTEST -DNB_THREADS=8 -DLIMIT=10000"``.

``./test/launch_test.sh d2p 50 10000 1000 16`` pour lancer la version parallèle 50 fois avec une limite avant de lancer l'algorithme séquentiel de 1000 et 16 threads. La génération du fichier de test doit être effectuée manuellement avant.