# pip install colorama

import time
from colorama import init, Fore

# Initialiser colorama pour les systèmes Windows
init(autoreset=True)

# Liste des couleurs disponibles
colors = [Fore.RED, Fore.YELLOW, Fore.GREEN, Fore.CYAN, Fore.BLUE, Fore.MAGENTA]

def afficher_couleurs_turbo_dynamique(duree):
    idx = 0
    debut = time.time()
    while True:
        # Alternance entre les couleurs
        print(colors[idx % len(colors)] + "Turbo Dynamique", end='\r')
        
        # Augmenter l'index de couleur
        idx += 1

        # Vérifier si le temps écoulé atteint la durée spécifiée
        if time.time() - debut >= duree:
            break

        # Attendre un court instant pour l'effet dynamique
        time.sleep(0.1)

    # Remettre l'affichage à une ligne vide à la fin
    print()

if __name__ == "__main__":
    duree_animation = 10  # Durée de l'effet en secondes
    afficher_couleurs_turbo_dynamique(duree_animation)
