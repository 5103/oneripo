#include <stdio.h>


typedef struct Item 
{
	char name[30];	/* 商品名	*/
	int  same;		/* 商品数	*/
	int price;		/* 価格		*/
	int id;         /* 商品ID  */

}ITEM, *LPITEM ;
Item a ={ };

typedef struct Item2 
{
	int id;			/* 商品ID	*/
	int  buy;		/* 売った数	*/
	int price;		/* 価格		*/
	int  torihikisakiid;  /*取引先ID*/
}ITEM2, *IPITEM ;
Item b ={ };

typedef struct Item3 
{
	char torihikisaki[30];  /*取引先*/
	int torihikisakiid;  /*取引先ID*/
}ITEM3, *TPITEM ;
Item c ={ };

int main(void)
{
	int i;
	int y;
	int x;
	/* （２）構造体の宣言 */
	/* （３）構造体の初期化 */

	struct Item Item[] = 
	{
		{ "ボール", 1000, 500 ,0 },
		{ "バット",10 , 6000 ,1 },
		{ "グローブ", 20, 30000 ,2},
		{ "ベース", 4, 3000 ,3},
		{ "トンボ",10 , 1000  ,4},
		{ "帽子", 18, 500 ,5},
		{ "バッティングマシン", 2, 200000 ,6},
		{ "練習着",20 , 4000 ,7 },
		{ "手袋", 18,5000 ,8},
		{ "投球用的", 2, 5000 ,9},

	};
		struct Item2 Item2[] = 
	{
		{ 0,  500 ,0 ,500 },
		{ 6,    1 ,1 ,1 },
		{ 4,	3, 2 ,1000},
		{ 1,    5, 2 ,6000},
		{ 0,	2, 3 ,500},
		{ 1,	2, 3 ,6000},
		{ 2,	2, 3 ,30000},



	};
		struct Item3 Item3[] = 
	{
		{ "チリ",0},
		{ "赤地",1},
		{ "篠塚",2},
		{ "長老",3},


	};

	
	/* （４）構造体の参照 */

	for(i = 0; i < 10; i++) 
	{
		printf("%s %d %d\n",
			Item[i].name, Item[i].same, Item[i].price);
	}




	for(i = 0; i < 7; i++) 
	{
	
		//printf("%d %d %d %d\n",
		//	Item2[i].id, Item2[i].buy, Item2[i].price, Item2[i].torihikisakiid);
			int index1 = -1;
			int index3 = -1;
			for(y=0; y<10; y++)
			{
				if( Item2[i].id == Item[y].id )
				{
					index1 = y;
					break;
				}
			}
			for(x=0; x<4; x++)
			{
				if( Item2[i].torihikisakiid == Item3[x].torihikisakiid )
				{
					index3 = x;
					break;
				}
			}
		printf("%s %d %d %s\n",
			Item[index1].name, Item2[i].buy, Item2[i].price, Item3[index3].torihikisaki);

	}
	
	return 0;
}
