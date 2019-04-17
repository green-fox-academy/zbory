#include <iostream>
#include <vector>

#include "Pokemon.h"

Pokemon chosenPokemon(std::vector<Pokemon> pokeList, Pokemon enemy);

std::vector<Pokemon> initializePokemons()
{
    std::vector<Pokemon> pokemons;

    pokemons.push_back(Pokemon("Balbasaur", "leaf", "water"));
    pokemons.push_back(Pokemon("Pikatchu", "electric", "water"));
    pokemons.push_back(Pokemon("Charizard", "fire", "leaf"));
    pokemons.push_back(Pokemon("Balbasaur", "water", "fire"));
    pokemons.push_back(Pokemon("Kingler", "water", "fire"));

    return pokemons;
}

int main(int argc, char *args[])
{
    std::vector<Pokemon> pokemonOfAsh = initializePokemons();

    // Every pokemon has a name and a type.
    // Certain types are effective against others, e.g. water is effective against fire.

    // Ash has a few pokemon.
    // A wild pokemon appeared!

    Pokemon wildPokemon("Oddish", "leaf", "water");

    // Which pokemon should Ash use?
    std::string name = chosenPokemon(pokemonOfAsh, wildPokemon)._name;

    std::cout << "I choose You, " << name << std::endl;
    return 0;
}

Pokemon chosenPokemon(std::vector<Pokemon> pokeList, Pokemon enemy)
{
    std::vector<Pokemon>::iterator pokeIterator;

    for (pokeIterator = pokeList.begin(); pokeIterator != pokeList.end(); pokeIterator++) {
        if (pokeIterator->isEffectiveAgainst(enemy)) {
            return *pokeIterator;
        }
    }
}