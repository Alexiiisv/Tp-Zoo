<h1 align="center">ZooPtycon, 2021 best simulation game</h1>

<h2 align="center">
Metacritic : 9.5/10
</h2>
<h2 align="center">
JeuxVideo : 9/10
</h2>
<h2 align="center">
UrMum : 10/10
</h2>
<br><br>

# Table of Contents

- [Table of Contents](#table-of-contents)
- [Le jeu](#le-jeu)
- [Règles du jeu](#règles-du-jeu)
    - [Les animaux](#les-animaux)
    - [Achat/Vente](#achat-ou-vente)
    - [Evenements possibles](#evenements-possibles)
    - [Evenements exceptionnels](#evenements-exceptionnels)
    - [Autres informations](#autres-informations)
- [Comment jouer ?](#comment-jouer)
    - [Commande pour VS code](#commande-pour-vs-code)
- [Modification des valeurs de base du sujet](#modification-des-valeurs-de-base-du-sujet)
- [L'équipe de développement](#l-equipe-de-developpement)
<br><br>

# Le jeu

ZooPtycon est un jeu de simulation en temps presque réel dans lequel le but est de construire un zoo rentable pour se faire un max d'argent.<br>
ZooPtycon, c'est pas moins de 3 espèces différentes, 4 succès à obtenir, et plusieurs niveaux de difficultés.<br> 
## Vas-tu devenir riche grâce à ton zoo? Ou bien seras-tu complètement ruiné?
<br><br>

# Règles du jeu

La clé de ce jeu est la gestion de tes animaux. Il existe 3 espèces différentes, chacune avec ses spécificités.
<br><br>

## Les animaux
- Tigre : cher mais attire de nombreux visiteurs. Ils sont maximum 2 par habitats. Le mâle peut se reproduire à partir de 6 ans et la femelle à partir de 4 ans.

- Aigle : Moyennement cher et attire quelques visiteurs. Le mâle et la femelle se repoduisent à partir de 4 ans mais ne pondent leurs oeufs qu'en mars. Ils peuvent être 4 par habitats mais ils sont fidèles, ce qui signifie qu'ils ne sont fertile qu'en présence de leur amant. Si l'un meurt, l'autre ne se reproduira plus jamais.

- Poule/coq : Peu cher mais attire très peu de visiteur. Ils peuvent être 10 dans le même habitat. Un coq permet à 4 poules de pondre des oeufs. Les poules pondent tous les mois paires et les oeufs éclosent les mois impairs. Une poule produit environ 24 oeufs par an (200 c'est beaucoup à gérer!)
<br><br>

## Achat ou Vente
Dans le jeu tu pourras acheter et vendre des animaux et leur habitat ainsi que de la nourriture. Chaque animaux valent un prix différent et même au sein d'une espèce le prix varie en fonction de son âge. Tu auras dans le jeu un menu parfaitement bien réalisé qui te guidera dans tes achats/ventes.
<br><br>

## Evenements possibles
- Grossesse : Les aigles et les poules pondent et les tigresses mettent bas. En période de gestion, les tigres et les aigles consomment 2x plus de nourriture et sont écartées des visiteurs.
- Naissance : Lors de l'éclosion ou de la mise à bas, de nouveaux individus sont intégrés au zoo. Vous pouvez nommer les bébés aigles et tigres (les poules sont nommées aléatoirement). Attention, les bébés apparaissent dans l'habitat de leur mère et prennent de la place ! Si leur habitat n'est pas assez grand pour tout le monde, il risque de mourrir !
- Mort infantile : Il existe un risque assez important que les bébés meurent à la naissance, ce nombre est aléatoire.
- Fin de vie d'un individu : Lorsqu'il atteint un âge avancé, l'animal meurt. (25 ans pour les aigles et les tigres, 15 pour les poules et les coqs)
- Surpopulation : Comme évoqué précedemment, le nombre d'individus par habitat est limité (2 pour les tigres, 4 pour les aigles, 10 pour les poules/coqs). Lorsque ce nombre est dépassé, il y a 50% de risque qu'un individu meurt (4 individus pour les poules/coqs)
- Maladie : La maladie des animaux durent environ un mois. Lorsqu'ils sont malade, ils ne se reproduisent plus et ont même un risque de mourir (10%). Chaque animal ne peut être malade qu'une fois par année. Les pourcentages de risque de tomber malade pour chaque espèce par mois : tigre 10%, aigles 8%, poules 5%.
<br><br>

## Evenements exceptionnels
- Feu: Un incendie s'est déclaré. Si les pompiers ne l'ont pas maitrisé, tu perds un habitat et tous ses habitants ! (proba de 1% par mois)

- Vol: Si le voleur n'a pas été attrapé par la police, tu perds un animal aléatoirement (proba de 1% par mois)

- Nuisible: Tu perds 10% de tes réserves de graine (proba de 20% par mois)

- Viande avariée: Tu perds 20% de tes réserves de viande (proba de 10% par mois)
<br><br>

## Autres informations
- Chaque nouvelle année, tu recevras une subvention pour chaque tigre et aigle de ton zoo
- Le nombre de visiteurs dépend de tes animaux, de la saison (haute ou basse) ainsi que d'un nombre aléatoire pouvant baisser ou augmenter de 20%
<br><br>

# Comment jouer

Le programme a été créé sur VScode. Vous pouvez utiliser tout autre IDE, cependant par soucis de compatibilité, il serait plus judicieux de compilé sur VScode. (CLion ne prend pas en compte notre fonction Clear, qui "clear" le terminal a certains moment pour le rendre plus lisible). Il est également préférable de lancer le fichier .exe créé plutôt que sur le terminal de l'IDE et de mettre la fenêtre en plein écran.

## Commande pour VS code
<br>
gcc main.cpp ./c++/zoo.cpp ./c++/aigle.cpp ./c++/poule.cpp ./c++/coq.cpp ./c++/tigre.cpp ./c++/ianimal.cpp ./c++/eagleHabitat.cpp ./c++/chickenHabitat.cpp ./c++/tigerHabitat.cpp ./c++/ihabitat.cpp ./c++/actionMonth.cpp ./c++/success.cpp ./c++/visitor.cpp ./c++/utils.cpp ./c++/infoZoo.cpp ./c++/foodStorage.cpp -lstdc++ -o main.exe
<br><br>

# Modification des valeurs du sujet de base
Certaines valeurs du sujet ont été changé pour le bien du jeu :
- Pourcentage de maladie: Le pourcentage a été réduit pour éviter que tous les animaux ne soient malade dès les premiers mois de l'année
- Nombre d'oeufs de poule: Gérer les poules est assez long et 200 oeufs par an et par poules était beaucoup trop important
<br><br>

# L equipe de developpement
Ce jeu a été développé par Alexis Velleine et Sven Dockx en partenariat avec le ministère de l'éducation et des animaux