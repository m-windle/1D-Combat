class Soldier{
	public:
		int getAttack(){ return attack; }
		int getDamage(){ return damage; }
		int getHealth(){ return health; }

	protected:
		int attack;
		int damage;
		int health;
};

struct Samurai : public Soldier
{
	Samurai(){
		Soldier::attack = 130;
		Soldier::damage = 5;
		Soldier::health = 30;
	}
};

struct Knight : public Soldier
{
	Knight(){
		Soldier::attack = 120;
		Soldier::damage = 3;
		Soldier::health = 50;
	}
};