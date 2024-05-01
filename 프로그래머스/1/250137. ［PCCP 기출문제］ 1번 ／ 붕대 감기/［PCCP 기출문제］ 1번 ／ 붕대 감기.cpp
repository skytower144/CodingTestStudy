#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth = health;
    
    int duration = bandage[0];
    int increase = bandage[1];
    int bonus = bandage[2];
    int bonusStack = 0;
    
    int exitTime = attacks.back()[0];
    int atkIdx = 0;

    for (int t = 1; t <= exitTime; t++) {
        if (attacks[atkIdx][0] == t) {
            health -= attacks[atkIdx][1];
            atkIdx++;
            bonusStack = 0;
            
            if (health <= 0) return -1;
            continue;
        }
        health += increase;
        bonusStack++;
        
        if (bonusStack == duration) {
            bonusStack = 0;
            health += bonus;
        }
        if (health > maxHealth)
            health = maxHealth;
    }
    return health;
}