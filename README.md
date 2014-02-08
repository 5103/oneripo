oneripo
=======
#include <iostream>
using namespace std;
class Enemy {
	int x,y;
public:
	void setPos(int wx,int wy){x= wx;y=wy;}
	void draw() {cout << "(" << x <<"," << y << "に描画します。\n";}
};
class Boss :public Enemy{
	int hp;
public:
	void setHp(int h){hp = h;}
	void draw(){
	Enemy:: draw();
	cout << "耐久値は" << hp << "です。\n";
	}
};	
int main (){

	Boss boss1;
	boss1.setPos(10,20);
	boss1.setHp(100);
	boss1.draw();
	return 0;
}

