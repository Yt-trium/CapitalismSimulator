# CapitalismSimulator
Capitalism Simulator : Projet de Système Distribués L3S6P17


## Projets
Le projet CapitalismSimulator est composé de 3 sous projets.

### CSProducer
Le producteur de ressources
Le nombre maximum de ressource est de 5.
Le nombre maximum de CSProducer est de 5 par ressource (25).

### CSAgent
Les agents (joueurs)
Le nombre maximum d'agent est de 30 (10 par types (individualiste, cooperatif, humain)).

### CSCoordinator
Le coordinateur du jeux

### Autres

CSLauncher est une interface graphique de lancement en C++/QT utiliser pour la présentation du programme.

CSCommon est le projet pour les fichiers communs.


## Fonctionnement

Lancer autant de CSAgent que nécessaire en leurs précisant en paramètre leur identifiant unique (0 -> 29)
(0->9) -> Humain
(10->19) -> Individualiste
(20->29) -> Cooperatifs

Lancer autant de CSProducer que nécessaire en leurs précisant en paramètre leur identifiant unique (0 -> 24)
(0->4) -> Ressource 1
(5->9) -> Ressource 2
(9->14) -> Ressource 3
(14->19) -> Ressource 4
(19->24) -> Ressource 5

Chaque identifiant correspond a (fichier CSCommon/define.h) :
- Une adresse ip
- Une numéro de programme unique

Lancer le CSCoordinator, en lui donnant en paramètres toutes les règles (afin qu'il complète une structure GameConfig)

Le CSCoordinator va ensuite contacter tout les CSAgent et CSProducer pour vérifier qu'ils soient bien lancé.
Le CSCoordinator va enregistrer la fonction de partage de configuration, puis contacter les CSAgent et CSProducer
pour les prévenirs que tout est prêt.
Les CSAgent et CSProducer vont ensuite attendre 1 seconde et demander la configuration au CSCoordinateur et commencer la partie.
La seconde de latence est utilisé pour que le CSCoordinateur ai le temps de contacter tout les CSAgent et CSProducer
avant de devoir envoyer les configuration.
La partie commence jusqu'à ce que l'objectifs fixé soit atteint.

#### Objectif
Si le paramètre objectif est fixé a 0, alors les producteur arrivé a 0 ressource n'en produiront plus.
Lorsqu'il n'existera plus aucun producteurs, alors le CSCoordinator enverra le signal d'extiction.

### Règles spécifiques

#### Actions coordonées
Lorsque les actions sont coordonnées, le CSCoordinator donne aux agents et producteurs l'ordre de commencer leurs tours.
Lorsque les actions ne sont pas coordonnées, c'est des alarmes qui gèrent le début des tours pour les joueurs.

#### Ressources épuisables
Lorsque les ressources sont épuisables, les prodcteur produise des ressources en fonctions de leurs stocks actuel.
S += S/2 + 1;

#### Observations
Lorsque les obserations sont activés, les agents du systèmes peuvent voir les ressources des producteurs et des autres agents.

#### Vol
Lorsque le vol est activés, un agent peut voler les ressource a un autre agent. Si l'agent en question était en train de surveiller
ces ressources, alors il gagne 2 fois ce qui devait être volé.

## Technologies
Langage : C
Bibliothèqes : C Standart Lib + RPC
