# CapitalismSimulator
Capitalism Simulator : Projet de Système Distribués L3S6P17


## Projets
Le projet CapitalismSimulator est composé de 3 sous projets.

### CSProducer
Le nombre maximum de ressource est de 5.
Le nombre maximum de CSProducer est de 5 par ressource (25).
// TODO //

### CSAgent
Le nombre maximum d'agent est de 30 (10 par types (individualiste, cooperatif, humain)).
// TODO //

### CSCoordinator
// TODO //

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



### Règles spécifiques

#### Actions coordonées

#### Ressources épuisables
#### Observations
#### Vol

## Technologies
Langage : C
Bibliothèqes : C Standart Lib + RPC
