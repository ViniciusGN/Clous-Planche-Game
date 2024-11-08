#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Planche {
private:
    std::vector<Compteur*> compteurs;
    Lanceur lanceur;
public:
    Planche(int nombreDeCompteurs) {
        std::srand(std::time(0)); // Inicializa o gerador de números aleatórios
        // Cria o último nível de compteurs
        for (int i = 0; i < nombreDeCompteurs; i++) {
            compteurs.push_back(new Compteur());
        }

        // Cria os níveis de clous de baixo para cima
        for (int niveau = nombreDeCompteurs - 1; niveau > 0; niveau--) {
            std::vector<Obstacle*> clousNiveau;
            for (int i = 0; i < niveau; i++) {
                Obstacle* gauche = compteurs[i];
                Obstacle* droit = compteurs[i + 1];
                clousNiveau.push_back(new Clou(gauche, droit));
            }
            compteurs.pop_back();
            for (int i = 0; i < clousNiveau.size(); i++) {
                compteurs[i] = dynamic_cast<Compteur*>(clousNiveau[i]);
            }
        }
    }

    void simuler(int nombreDePalets) {
        for (int i = 0; i < nombreDePalets; i++) {
            lanceur.lancer(compteurs[0]);
        }

        // Exibir os resultados da simulação
        int c0 = compteurs[0]->getCount();
        for (int i = 0; i < compteurs.size(); i++) {
            std::cout << "Compteur " << i << ": " << std::round((float)compteurs[i]->getCount() / c0) << std::endl;
        }
    }

    ~Planche() {
        for (Compteur* compteur : compteurs) {
            delete compteur;
        }
    }
};