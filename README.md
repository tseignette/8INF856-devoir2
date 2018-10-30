# 8INF856 - Devoir 2

## Fonctionnement
* ``make d2s`` pour compiler la version séquentielle
* ``make d2p`` pour compiler la version parallèle
* ``make generator`` pour compiler le générateur de tableau
* ``make`` pour tout compiler

Les exécutables créés prennent respectivement le nom de ``d2s``, ``d2p`` et ``generator`` et se situent dans le dossier ``bin``.

## Générateur de tableau
``./bin/generator 1000`` pour générer deux tableaux triés de longueur 1000. Ils se situent dans le fichier ``./test/fichier_test``. Le premier nombre est la longueur du tableau.

## Lanceur de test
``./test/launch_test.sh d2p 1000000 8 50`` pour générer deux tableaux de 1000000 éléménts puis lancer la version parallèle 50 fois avec 8 threads. Le générateur et les deux versions de l'algorithme doivent être compilés avant de lancer ce script.