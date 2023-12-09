#include <stdio.h>
#include <string.h>

struct Pokemon {
    char name[50];
    int health;
    int max_health;
    int attack;      
    int speed;       
};

struct Player {
    char name[50];
    struct Pokemon pokemon;
};

int main() {
  struct Player *player;
  struct Pokemon *pok;
  struct Player player1;
  player = &player1;
  pok= &(player -> pokemon);
  scanf("%s", player -> name);
  scanf("%s %d %d %d", pok->name, &(pok->health), &(pok->attack), &(pok->speed));
  pok->max_health = pok->health;
  struct Player player2;
  player = &player2;
  pok= &(player -> pokemon);
  scanf("%s", player -> name);
  scanf("%s %d %d %d", pok->name, &(pok->health), &(pok->attack), &(pok->speed));
  pok->max_health = pok->health;
  struct Player *first_player, *second_player;
  first_player = player1.pokemon.speed > player2.pokemon.speed ? &player1 : &player2;
  second_player = player1.pokemon.speed > player2.pokemon.speed ? &player2 : &player1;
  while(first_player -> pokemon.health > 0 && second_player -> pokemon.health > 0){
    printf("%s's %s attacks %s's %s\n", first_player-> name, first_player -> pokemon.name, second_player -> name, second_player -> pokemon.name);
    second_player -> pokemon.health -= first_player -> pokemon.attack;
    if (second_player -> pokemon.health <= 0){
      printf("%s has lost its battle capability.\n", second_player->pokemon.name);
      break;
    }
    printf("%s's health %d/%d\n", second_player->pokemon.name, second_player->pokemon.health, second_player->pokemon.max_health);
    printf("%s's %s attacks %s's %s\n", second_player-> name, second_player -> pokemon.name, first_player -> name, first_player -> pokemon.name);
    first_player -> pokemon.health -= second_player -> pokemon.attack;
    if (first_player -> pokemon.health <= 0){
      printf("%s has lost its battle capability.\n", first_player->pokemon.name);
      break;
    }
      printf("%s's health %d/%d\n", first_player->pokemon.name, first_player->pokemon.health, first_player->pokemon.max_health);
  }
  if (first_player->pokemon.health <= 0){
    printf("%s wins!\n", second_player -> name);
  }
  else{
    printf("%s wins!\n", first_player -> name);
  }
  return 0;
}
