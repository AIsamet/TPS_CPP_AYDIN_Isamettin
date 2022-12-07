# Refactoring d'après les principes SOLID, par Isamettin AYDIN et Younes BOKHARI

```
SOLID est un acronyme qui regroupe 5 principes de conception, considérés comme des bonnes pratiques pour les développeurs.
```
| Initial  | Principe | Etat |
| --------- | -------- | --------- |
| S | [Single responsibility principle](#s) | ✅ |
| O | [Open/closed principle](#o)          | ✅ |
| L | [Liskov substitution principle](#l)   | 😐 |
| I | [Interface segregation principle](#i) | 😐 |
| D | [Dependency inversion principle](#d)  | ✅ |

## <a name="s">S : Responsabilité unique</a>

```
Chaque entité ne doit avoir qu'une seule et unique responsabilité.
```
### Application du principe
Chaque classe possède sa propre responsabilité : 
- La classe **Grid** a été créée
    - Le **constructeur** de la classe remplace la méthode **InitGrid()**, présente auparavant dans les classes **Puissance4** et **Morpion**
    - La méthode **DisplayGrid()** remplace **DisplayPlate()**, présente auparavant dans les classes **Puissance4** et **Morpion**
    - La méthode **GetCellPositionFromId()** a été déplacée de la classe **Morpion** vers **Grid**
- La classe **Inputs** a été créée
    - Les méthodes **InputPlayerMorpion()** et **InputPlayerPuissance4()** remplacent la méthode **InputPlayer()**, présente auparavant dans les classes **Puissance4** et **Morpion**
    - Les méthodes **BotRandomInputGeneratorMorpion()** et **BotRandomInputGeneratorPuissance4()** remplacent la méthode **BotRandomInputGenerator()**, présente auparavant dans les classes **Puissance4** et **Morpion**
    - La méthode **InputGameChoice()** remplace le code qui permettait la saisie d'un jeu dans **Launcher.cpp**
    - La méthode **InputGameMode()** remplace **AskGameType()**, présente auparavant dans les classes **Puissance4** et **Morpion**
    - La méthode **InputPlayersNames()** remplace **AskPlayersName()**, présente auparavant dans les classes **Puissance4** et **Morpion**
- La classe **Game** a été modifiée
    - Les méthodes qui ne sont override dans les classes filles **Puissance4** et **Morpion** ont été remontées vers la classe mère **Game**
    - La méthode **PlayGame()** a été renommée en **PlayRound()**
___

## <a name="o">O : Ouvert / Fermé</a>

```
Les entités doivent être ouvertes à l'extension et fermées à la modification.
```
### Application du principe
- La méthode **InputPlayer()**, présente auparavant dans les classes **Puissance4** et **Morpion**, a été scindée en deux méthodes dans la classe **Inputs** : **InputPlayerPuissance4()** et **InputPlayerMorpion()**
- D'autres méthodes de la classe **Inputs** ont été scindées selon le type de jeu
___

## <a name="l">Principe L : Substitution de Liskov</a>

```
Chaque classe doit pouvoir considérer une classe enfant comme une classe parente. Toute classe dérivée doit conserver les fonctionnalités de la classe parente sans les remplacer pour autant.
```
### Application du principe
Aucune modification n'a été apportée, le principe ayant été respecté pour les héritages de la classe **Game**.

___

## <a name="i">Principe I : Ségrégation des interfaces</a>

```
Aucun client ne devrait être forcé à implémenter des méthodes/fonctions qu'il n'utilise pas. Il faut privilégier la multiplication des interfaces plutôt qu'une grande interface.
```
### Application du principe
Aucune modification n'a été apportée, les classes filles utilisent toutes les méthodes de leur classe mère **Game**.

___

## <a name="d">Principe D : Inversion des dépendances</a>

```
Les modules haut-niveau doivent être facilement réutilisables et ne pas être impactés par des modules bas-niveau avec des fonctionnalités dites utilitaires.
```
### Application du principe
- Les attributs **Player** des classes **Puissance4** et **Morpion** ont été déplacés vers la classe mère **Game**. Ainsi, nous sommes certains qu'un hériter de la classe **Game** contient les attributs **Player**, évitant des bugs lors des appels de méthodes utilisant de tels attributs (**CheckWin()** entre autres).