## Task Description

There are four Pokémon trainers: Roy, Ray, Bob, and Jim. Each of them has their own Pokémon—Roy has Pikachu, Ray has Mega Charizard X, Bob has Mewtwo, and Jim has Magikarp.

They will engage in one-on-one battles to find out who is the best Pokémon trainers. Please write a C program to simulate the results of the battles.

![image](https://lh3.googleusercontent.com/pw/ADCreHfYFvxynJYp8NNy8wRH_yD6PgWxW3ZWCkUSK3JApx0NcSjJTvQQo7qWSBTevCdGXkz1UJr5WmSnrM9mzuRGksgYnzvlGsCneTkZYcgwvVQ9j8FXmHk=w1800)

Below is the battle process.

### 1. Determine the Attacker and Defender:

    1.1 At the start of each round, determine the roles of the attacker and defender based on the speed attribute of both Pokémon.
    
    1.2 The Pokémon with the higher speed will become the attacker.

### 2. Attack Actions:

    2.1 Each round, the attacker and defender take turns attacking each other.

    2.2 The attacker's Pokémon will attack the defender's Pokémon, reducing its health by the attack value of the attacker's Pokémon.

    2.3 Subsequently, the roles switch between the defender and the attacker. 

    2.4 Whenever an attack happens, please print the attack flows. For example: `printf("%s's %s attacks %s's %s.", Attacker's Player Name, Attacker's Pokémon Name, Defender's Player Name, Defender's Pokémon Name);

    2.5 Whenever an attack action occurs, if the health of the defending Pokémon is greater than 0, print its remaining health and initial health. For example: "printf("%s's health %d/%d\n", Defender's Pokémon Name, defender's Pokémon health, defender's Pokémon max_health);"


### 3. Health Calculation and Battle Capability Assessment:

    3.1 After each attack, immediately check whether the health of each Pokémon has fallen to or below zero.

    3.2 If the health of a Pokémon drops to or below zero, you need to print that the Pokémon has lost its battle capability. For example: printf("%s has lost its battle capability.\n", the name of the Pokémon);. The opposing side will be declared the victor. Print the name of the winner. For example: `printf("%s wins!\n", Player's name);`.


In this program, you must implement two structs: one for Pokémon and another for players. Here are the struct definitions:

```C
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
```

## Input Format
The input consists of a total of 4 lines. The first line is the name of Player 1. The second line contains information about the Pokémon Player 1 is using, with the details from left to right being the name, health, attack, and speed. The third line is the name of Player 2. The fourth line contains information about the Pokémon Player 2 is using, with the details from left to right being the name, health, attack, and speed.

## Output Format

Battle log must include the attack sequence(2.4), details about the targeted Pokémon (2.5), and the outcome of the battle (3.2).


## Sample Input 1
```
Ray
Mega_Charizard_X 50 40 40
Bob
Mewtwo 70 35 80
```
## Sample Output 1
```
Bob's Mewtwo attacks Ray's Mega_Charizard_X
Mega_Charizard_X's health 15/50
Ray's Mega_Charizard_X attacks Bob's Mewtwo
Mewtwo's health 30/70
Bob's Mewtwo attacks Ray's Mega_Charizard_X
Mega_Charizard_X has lost its battle capability.
Bob wins!
```

## Sample Input 2
```
Jim
Magikarp 20 5 50
Bob
Mewtwo 70 35 80
```
## Sample Output 2
```
Bob's Mewtwo attacks Jim's Magikarp
Magikarp has lost its battle capability.
Bob wins!
```