#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<Windows.h>
struct character//人物基础属性面板
{
	char gender[6] = "\0";//性别
	char race[12] = "\0";//种族
	char alignment[12] = "\0";//阵营
	char backgroud[20] = "\0";//背景
	char Class[20] = "\0";//职业
	int strength = 0;//力量
	int dexterity = 0;//敏捷
	int constitution = 0;//体质
	int intelligence = 0;//智力
	int wisdom = 0;//感知
	int charisma = 0;//魅力
	int hitPoint = 0;//体力
	char traits[100] = "\0";//特性
	char language[50] = "\0";//熟练语言
	char equipmentProficiency[100] = "\0";//装备熟练项
	char toolProficiency[40] = "\0";//工具熟练项
	char skillProficiency[40] = "\0";//技能熟练项
	char saving[40] = "\0";//豁免项
	char equipment[500] = "\0";//持有装备
	char mainAbility[20] = "\0";//主要属性
	//int raceAndClass[][]=
};
int count = time(NULL);
int d6()//随机生成6，8，10以内数
{
	srand(count);
	count++;
	return rand() % 6 + 1;
}
int d8()
{
	srand(count);
	count++;
	return rand() % 8 + 1;
}
int d10()
{
	srand(count);
	count++;
	return rand() % 10 + 1;
}
int oneAbilityScore()//获取一个属性值
{
	int a[4], i, j, temp;
	for (i = 0; i < 4; i++)
	{
		a[i] = d6();
		//printf("%d ", a[i]);
	}

	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			if (a[i] < a[j])
			{

				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

	}
	return a[1] + a[2] + a[0];
}//获取一个属性值
void getAbilityScores(int a[])//获取六个属性值
{
	int i;

	for (i = 0; i < 6; i++)
	{
		a[i] = oneAbilityScore();
		printf("%d  ", a[i]);
	}

}
void creatHillDwarf(struct character* player)
{
	int n;
	char trait[] = "黑暗视觉 矮人体魄 石中精妙 矮人刚毅 ";
	char language[] = "通用语 矮人语 ";
	char race[] = "丘陵矮人";
	char equipment[] = "战斧，手斧，轻锤和战锤等;";
	char tool1[12] = "铁匠工具";
	char tool2[12] = "酿酒工具";
	char tool3[12] = "石匠工具";
	player->constitution += 2;
	player->wisdom++;
	player->hitPoint++;
	strcat(player->traits, trait);
	strcat(player->language, language);
	strcat(player->race, race);
	strcat(player->equipmentProficiency, equipment);
START:printf("选择你的熟练工具（1.铁匠工具 2.酿酒工具 3.石匠工具）");
	getchar();
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		strcat(player->toolProficiency, tool1);
		break;
	case 2:
		strcat(player->toolProficiency, tool2);
		break;
	case 3:
		strcat(player->toolProficiency, tool3);
		break;
	default:
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	}
	strcat(player->equipmentProficiency, equipment);
	
}//丘陵矮人
void creatMountainDwarf(struct character* player)
	{
	int n;
	char trait[] = "黑暗视觉 矮人体魄 石中精妙 ";
	char language[] = "通用语 矮人语 ";
	char race[] = "山地矮人";
	char equipment[] = "战斧，手斧，轻锤和战锤等;轻甲和中甲";
	player->constitution += 2;
	player->strength+=2;
	strcat(player->traits, trait);
	strcat(player->language, language);
	strcat(player->race, race);
	strcat(player->equipmentProficiency, equipment);
START:printf("选择你的熟练工具（1.铁匠工具 2.酿酒工具 3.石匠工具）");
	getchar();
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		strcat(player->toolProficiency, "铁匠工具");
		break;
	case 2:
		strcat(player->toolProficiency, "酿酒工具");
		break;
	case 3:
		strcat(player->toolProficiency, "石匠工具");
		break;
	default:
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	
	}
	}//山地矮人
void creatDwarf(struct character* player)
{
	int n;
	printf("选择亚种\n");
	printf("1.丘陵矮人 2.山地矮人\n");
	printf("输入相应数字查看亚种基本信息，输入字母开始选择亚种");
	while (scanf("%d", &n))
	{
		switch (n)
		{
		case 1:printf("作为一名丘陵矮人，你有着敏锐的感官，精确的直觉以及\
惊人的恢复力。费伦大陆庞大的南部王国中的金矮人 gold\
dwarf 就属于丘陵矮人。另外，龙枪设定的克莱恩世界里，遭\
到放逐的奈达矮人 Neidar 和被贬的克拉矮人 Klar 也属于丘陵\
矮人。\n");
			break;
		case 2:printf("作为一名坚强而健壮的山地矮人，你习惯于崎岖山地的艰\
苦生活。你肤色较浅，而身材在矮人中算是高个子。费伦大陆\
北部的盾矮人 shield dwarf，以及龙枪设定中掌权的海勒 Hylar\
氏族和贵族阶级的达瓦 Daewar 氏族都属于山地矮人。\n");
			break;
		default:printf("请输入正确的内容\n");
		}
	}
START: printf("开始选择种族,请输入相应序号：\n");
	getchar();
	scanf("%d", &n);
	switch (n)
	{
	case 1:creatHillDwarf(player);
		break;
	case 2:creatMountainDwarf(player);
		break;
	default:
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	}
}//矮人
void creatHighElf(struct character* player)
{
	int n;
	player->intelligence++;
	char race[] = "高等精灵";
	char equipment[] = "长剑、短剑、短弓和长弓等武器 ";
	char trait[] = "戏法 ";
	strcat(player->traits, trait);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->race, race);
START:printf("已习得精灵语、通用语，选择一门额外语言（1.矮人语 2.半身人语 3.龙语 4.侏儒语 5.兽人语 6.炼狱语）");
	getchar();
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		strcat(player->language, "矮人语");
		break;
	case 2:
		strcat(player->language, "半身人语");
		break;
	case 3:
		strcat(player->language, "龙语");
		break;
	case 4:
		strcat(player->language, "侏儒语");
		break;
	case 5:
		strcat(player->language, "兽人语");
		break;
	case 6:
		strcat(player->language, "炼狱语");
		break;
	default:
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	}
}//高等精灵
void creatWoodElf(struct character* player)
{
	player->wisdom++;
	char race[] = "木精灵";
	strcat(player->race, race);
	char equipment[] = "长剑、短剑、短弓和长弓等武器 ";
	char trait[] = "轻捷步伐 野性面具 ";
	strcat(player->traits, trait);
	strcpy(player->equipmentProficiency, equipment);
}//木精灵
void creatDarkElf(struct character* player)
{
	player->charisma++;
	char race[] = "黑暗精灵";
	strcat(player->race, race);
	char equipment[] = "刺剑、短剑和手弩等武器 ";
	char trait[] = "增强黑暗视觉 卓尔魔法 日照敏感 ";
	strcat(player->traits, trait);
	strcpy(player->equipmentProficiency, equipment);
}//黑暗精灵
void creatElf(struct character* player)
{
	int n;
	player->dexterity += 2;
	char skill[] = "察觉 ";
	char trait[] = "黑暗视觉 精灵血统 出神 ";
	char language[] = "通用语 精灵语 ";
	strcat(player->skillProficiency, skill);
	strcat(player->traits, trait);
	strcat(player->language, language);
	printf("选择亚种\n");
	printf("1.高等精灵 2.木精灵 3.黑暗精灵（卓尔）\n");
	printf("输入相应数字查看亚种基本信息，输入字母开始选择亚种");
	while (scanf("%d", &n))
	{
		switch (n)
		{
		case 1:printf("作为一名高等精灵，你拥有机敏的思维，且精通或多或少\
的魔法知识。在许多 D & D 世界中，都有 2 种高等精灵。其中一\
种傲慢而孤僻，坚信自己的族群远比其他种族，甚至比其它精\
灵族更加优越（包括灰鹰的灰精灵 gray elves 和山谷精灵 valley\
elves，龙枪的西瓦纳斯提精灵 Silvanesti，被遗忘的国度的日精\
灵 sun elves）。另一种则更常见也更友善，并且常常出现在人\
类或其他种族的群体中（包括灰鹰的高等精灵 high elves，龙枪\
的奎灵纳斯提精灵 Qualinesti，还有被遗忘的国度的月精灵\
moon elves）。\n\
费伦的日精灵（又被称为金精灵 gold elves 或者晨曦精灵\
sunrise elves）可能会长青铜色的皮肤，以及赤铜，黑色或者金\
黄色的头发。而眼睛则是金色，银色或黑色。而月精灵（也叫\
做银精灵 silver elves 或者灰精灵 gray elves）肤色则更苍白一\
些，他们长着雪花石膏般洁白光滑的皮肤，有时还会带着些许\
蓝色色调。他们的头发一般是银白，黑色或蓝色，但金黄色， 褐色或红色也不少见。他们的眼睛是蓝色或者绿色，其中还点\
缀着些许金色。\n");
			break;
		case 2:printf("作为木精灵，你拥有敏锐的感知能力和直觉。你步伐轻捷，\
可以快速隐秘地穿行在熟悉的森林中。这个分类包括灰鹰的野\
精灵 wild elves（戈鲁盖奇 grugach），龙枪的卡岗纳斯提精灵\
Kagonesti 和被遗忘的国度与灰鹰都有的木精灵 wood elves。在\
费伦，木精灵们（也被叫做野精灵 wild elves，绿精灵 green elves\
或者森林精灵 forest elves）离群索居，并且不相信非精灵种族。\
木精灵的肤色一般偏向赤铜色，有时会带着绿色色调。他\
们的发色一般介于褐色到黑色之间，但偶尔也会出现金黄色或\
者赤铜色。他们的眼睛则是绿色，褐色或淡褐色。\n");
			break;
		case 3:printf("卓尔传承自一个早期的黑皮肤精灵亚种，这些精灵因追随\
女神罗丝踏上邪恶与腐化之路，而被放逐出地表世界。时至今\
日，他们已经在幽暗地域的深处建起了自己的文明，尽管这一\
切都必须遵循罗丝女神的意志。卓尔又称为黑暗精灵，他们长\
着抛光黑曜石般的漆黑皮肤，以及苍白或黄白色的头发。他们\
的瞳色非常浅（以至于常被误认为是白色），并带有淡紫，银色，\
粉色，红色或白色色调。他们的身材通常也会比其他精灵更为\
瘦小。\n\
卓尔冒险者极其稀少，而这个种族也并非遍布世界各处。\
由此，你在选择扮演卓尔前必须由 DM 进行确认。\n");
		default:printf("请输入正确的内容\n");
		}
	}
	START:printf("开始选择亚族,请输入相应序号：\n");
	getchar();
	scanf("%d", &n);
	if (n < 1 || n>3)
	{
		printf("input error\n重新选择\n");
		goto START;
	};
	switch (n)
	{
	case 1:creatHighElf(player);
		break;
	case 2:creatWoodElf(player);
		break;
	case 3:creatDarkElf(player);
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
}//精灵
void creatLightfoot(struct character* player)
{
	player->charisma++;
	char race[] = "轻足半身人";
	strcat(player->race, race);
	char trait[] = "天生善匿 ";
	strcat(player->traits, trait);
}
void creatStout(struct character* player)
{
	player->constitution++;
	char race[] = "敦实半身人";
	strcat(player->race, race);
	char trait[] = "敦实体魄 ";
	strcat(player->traits, trait);
}
void creatHalfing(struct character* player)
{
	int n;
	player->dexterity += 2;
	char language[] ="通用语 半身人语 ";
	char trait[] ="幸运 勇气 半身人灵巧 ";
	printf("选择亚种\n");
	printf("1.轻足半身人 2.敦实半身人\n");
	printf("输入相应数字查看亚种基本信息，输入字母开始选择亚种");
	while (scanf("%d", &n))
	{
		switch (n)
		{
		case 1:printf("作为一名轻足半身人，你可以轻易的躲过别人耳目，甚至\
能够以其他人的身躯作为掩护。你和蔼可亲，容易相处。在被\
遗忘国度里，轻足半身人遍布甚广，是最常见的半身人。\n\
轻足半身人比其它半身人更喜欢游历，常居于其它种族附\
近或投身游牧生活。在灰鹰的世界里，他们被称为毛腿半身人\
hairfeet 或高挑半身人 tallfellow。\n");
			break;
		case 2:printf("作为一名敦实半身人，你普遍比其他半身人强壮，并对毒\
素有一定抗性。Ḁ些传闻有说敦实半身人混有矮人血统。在被\
遗忘国度中，这些半身人被称为强心半身人 strongheart，且较\
常见于南方。\n");
			break;
		default:printf("请输入正确的内容\n");
		}
	}
	printf("开始选择亚族,请输入相应序号：\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1:creatLightfoot(player);
		break;
	case 2:creatStout(player);
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
	
}
void creatHuman(struct character* player)
{
	int n;
	player->charisma++;
	player->constitution++;
	player->strength++;
	player->dexterity++;
	player->intelligence++;
	player->wisdom++;
	char race[] = "人类";
	strcat(player->race, race);
	START: printf("已习得通用语，选择一门额外语言（1.矮人语 2.半身人语 3.龙语 4.侏儒语 5.兽人语 6.炼狱语 7.精灵语）");
	scanf("%d", &n);
	if (n < 1 || n>7)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (n)
	{
	case 1:
		strcat(player->language, "通用语 矮人语 ");
		break;
	case 2:
		strcat(player->language, "通用语 半身人语 ");
		break;
	case 3:
		strcat(player->language, "通用语 龙语 ");
		break;
	case 4:
		strcat(player->language, "通用语 侏儒语 ");
		break;
	case 5:
		strcat(player->language, "通用语 兽人语 ");
		break;
	case 6:
		strcat(player->language, "通用语 炼狱语 ");
		break;
	case 7:
		strcat(player->language, "通用语 精灵语 ");
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}

}
void creatDragonborn(struct character* player)
{
	int n;
	player->strength += 2;
	player->charisma++;
	char language[] = "通用语 龙语 ";
	strcat(player->language, language);
	char race[] = "龙裔";
	strcat(player->race, race);
	char trait[] = "龙族血统 吐息武器 伤害抗性 ";
	strcat(player->traits, trait);
	printf("选择你的龙种：（1.黑 2.蓝 3.黄铜 4.青铜 5.赤铜 6.金 7.绿 8.红 9.银 10.白）");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		strcat(player->race, "（黑）");
		break;
	case 2:
		strcat(player->race, "（蓝）");
		break;
	case 3:
		strcat(player->race, "（黄铜）");
		break;
	case 4:
		strcat(player->race, "（青铜）");
		break;
	case 5:
		strcat(player->race, "（赤铜）");
		break;
	case 6:
		strcat(player->race, "（金）");
		break;
	case 7:
		strcat(player->race, "（绿）");
		break;
	case 8:
		strcat(player->race, "（红）");
		break;
	case 9:
		strcat(player->race, "（银）");
		break;
	case 10:
		strcat(player->race, "（白）");
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
}
void creatForestGnome(struct character* player)
{
	player->dexterity++;
	char race[] = "森林侏儒";
	strcat(player->race, race);
	char trait[] = "自然幻术师 小型野兽交谈 ";
	strcat(player->traits, trait);
}
void creatRockGnome(struct character* player)
{
	player->constitution++;
	char race[] = "岩侏儒";
	strcat(player->race, race);
	char trait[] = "工匠学识 修补匠 ";
	strcat(player->traits, trait);
}
void creatGnome(struct character* player)
{
	int n;
	player->intelligence += 2;
	char language[] = "通用语 侏儒语 ";
	strcat(player->language, language);
	char trait[] = "黑暗视觉 侏儒狡黠 ";
	strcat(player->traits, trait);
	printf("选择亚种\n");
	printf("1.森林侏儒 2.岩侏儒\n");
	printf("输入相应数字查看亚种基本信息，输入字母开始选择亚种");
	while (scanf("%d", &n))
	{
		switch (n)
		{
		case 1:printf("作为一名森林侏儒，你具有使用幻术的本领及与生俱来的\
机敏和隐匿特质。在 D & D 世界中，森林侏儒非常稀少而且行踪\
隐秘。他们在偏僻森林中的隐秘群落中聚居，并用幻术和诡计\
来掩盖自己避开威胁，或是在被发现时用作逃生的掩护。森林\
侏儒与其他善良精魄的林地住民友善相处，并将精灵和善良的\
精类生物视为其最重要的盟友。森林侏儒们还受着森林小动物\
们的爱戴，甚至会依靠小动物们警戒徘徊在其领地上的威胁。\n");
			break;
		case 2:printf("作为一名岩侏儒，你拥有超越其他侏儒的创造天赋与耐性。\
D & D 世界中的大部分侏儒都属于岩侏儒，包括龙枪设定里的修\
补匠侏儒 tinker gnomes。\n");
			break;
		default:printf("请输入正确的内容\n");
		}
	}
START:printf("开始选择亚族,请输入相应序号：\n");
	getchar();
	scanf("%d", &n);
	if (n < 1 || n>3)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (n)
	{
	case 1:creatForestGnome(player);
		break;
	case 2:creatRockGnome(player);
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
}
void creatHalfElf(struct character* player)
{
	int m, n;
	player->charisma += 2;
	char race[] = "半精灵";
	strcat(player->race, race);
	char trait[] = "黑暗视觉 精灵血统 ";
	strcat(player->traits, trait);
	char language[] = "通用语 精灵语 ";
	strcat(player->language, language);
	printf("已习得精灵语、通用语，选择一门额外语言（1.矮人语 2.半身人语 3.龙语 4.侏儒语 5.兽人语 6.炼狱语）");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		strcat(player->language, "矮人语");
		break;
	case 2:
		strcat(player->language, "半身人语");
		break;
	case 3:
		strcat(player->language, "龙语");
		break;
	case 4:
		strcat(player->language, "侏儒语");
		break;
	case 5:
		strcat(player->language, "兽人语");
		break;
	case 6:
		strcat(player->language, "炼狱语");
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
	printf("选择a,b两项技能熟练项（1.运动 2.体操 3.巧手 4.隐蔽 5.奥秘 6.历史 7.调查 8.自然 9.宗教 10.驯兽 11.洞悉 12.医药 13.察觉 14.求生 15.欺瞒 16.威吓 17.表演 18.游说）\n");
	scanf("%d,%d", &m, &n);
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 2:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 3:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 4:
		strcat(player->skillProficiency, "隐蔽 ");
		break;
	case 5:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 6:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 7:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 8:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 9:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 10:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 11:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 12:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 13:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 14:
		strcat(player->skillProficiency, "求生 ");
		break;
	case 15:
		strcat(player->skillProficiency, "期满 ");
		break;
	case 16:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 17:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 18:
		strcat(player->skillProficiency, "游说 ");
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 2:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 3:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 4:
		strcat(player->skillProficiency, "隐蔽 ");
		break;
	case 5:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 6:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 7:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 8:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 9:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 10:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 11:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 12:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 13:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 14:
		strcat(player->skillProficiency, "求生 ");
		break;
	case 15:
		strcat(player->skillProficiency, "期满 ");
		break;
	case 16:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 17:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 18:
		strcat(player->skillProficiency, "游说 ");
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
	printf("选择a,b两项不同属性各加一（1.力量 2.敏捷 3.体质 4.智力 5.感知 6.魅力）\n");
	scanf("%d,%d", &m, &n);
	switch (m)
	{
	case 1:player->strength++;
		break;
	case 2:player->dexterity++;
		break;
	case 3:player->constitution++;
		break;
	case 4:player->intelligence++;
		break;
	case 5:player->wisdom++;
		break;
	case 6:player->charisma++;
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
	switch (n)
	{
	case 1:player->strength++;
		break;
	case 2:player->dexterity++;
		break;
	case 3:player->constitution++;
		break;
	case 4:player->intelligence++;
		break;
	case 5:player->wisdom++;
		break;
	case 6:player->charisma++;
		break;
	default:
	{
		printf("input error");
		exit(0);
	}
	}
}
void creatHalfOrc(struct character* player)
{
	player->strength += 2;
	player->constitution++;
	char race[] = "半兽人";
	strcat(player->race, race);
	char trait[] = "黑暗视觉 坚韧不屈 凶蛮攻击 ";
	strcat(player->traits, trait);
	char language[] = "通用语 兽人语 ";
	strcat(player->language, language);
	char skill[] = "威吓";
	strcat(player->skillProficiency, skill);
}
void creatTiefling(struct character* player)
{
	player->intelligence++;
	player->charisma += 2;
	char race[] = "提夫林";
	strcat(player->race, race);
	char trait[] = "黑暗视觉 炎狱抗性 地狱馈赠 ";
	strcat(player->traits, trait);
	char language[] = "通用语 炼狱语 ";
	strcat(player->language, language);
}
void raceChoice(struct character* player)
{
	int n;
	printf("1.矮人Dwarf 2.精灵Elf 3.半身人Halfing 4.人类Human 5.龙裔Dragonborn 6.侏儒Gnome 7.半精灵Half-Elf 8.半兽人Half-Orc 9.提夫林Tiefling\n");
	START:printf("输入相应数字查看种族基本信息，输入字母开始选择种族");
	while (scanf("%d", &n))
	{
		switch (n)
		{
		case 1:printf("矮人");
			break;
		case 2:printf("精灵");
			break;
		case 3:printf("半身人");
			break;
		case 4:printf("人类");
			break;
		case 5:printf("龙裔");
			break;
		case 6:printf("侏儒");
			break;
		case 7:printf("半精灵");
			break;
		case 8:printf("半兽人");
			break;
		case 9:printf("提夫林");
			break;
		default:
		{
			printf("input error\n重新选择\n");
			goto START;
		}
		}
	}
	getchar();
		START1:printf("输入你的种族序号\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:creatDwarf(player);
			break;
		case 2:creatElf(player);
			break;
		case 3:creatHalfing(player);
			break;
		case 4:creatHuman(player);
			break;
		case 5:creatDragonborn(player);
			break;
		case 6:creatGnome(player);
			break;
		case 7:creatHalfElf(player);
			break;
		case 8:creatHalfOrc(player);
			break;
		case 9:creatTiefling(player);
			break;
		default:
		{
			printf("input error\n重新选择\n");
			goto START1;
		}
		}
	}//种族选择
void creatBarbarian(struct character* player)
{
	int m, n;
	player->hitPoint += 12;
	char Class[] = "野蛮人";
	char equipment[] = "轻甲、中甲、盾牌,简易武器、军用武器 ";
	char saving[] = "力量 体质 ";
	char trait[] = "狂暴 无甲防御 ";
	char goods[] = "一把巨斧或任意一把军用近战武器；两把手斧或任意一把简易武器；一个探索套组和四支标枪";
	char main[] = "力量";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
	START: printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.驯兽 2.运动 3.威吓 4.自然 5.察觉 6.求生）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>6 || m < 1 || m>6)
	{
			printf("input error\n重新选择\n");
			goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 4:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 5:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 6:
		strcat(player->skillProficiency, "求生 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 4:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 5:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 6:
		strcat(player->skillProficiency, "求生 ");
		break;
	}


}//野蛮人
void creatBard(struct character* player)
{
	int m, n, z;
	player->hitPoint += 8;
	char Class[] = "吟游诗人";
	char equipment[] = "简易武器、手弩、长剑、刺剑、短剑，轻甲 ";
	char tool[] = "自选三种乐器 ";
	char saving[] = "敏捷 魅力 ";
	char goods[] = "一把刺剑，一把长剑或任一把简易武器；一个大使套组或一个艺人套组；一个鲁特琴或其它乐器；皮甲和一把匕首";
	char main[] = "魅力";
	char trait[] = "诗人激励 ";
	strcat(player->traits, trait);
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->equipment, goods);
	strcat(player->toolProficiency, tool);
	START:printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b,c三项技能（1.运动 2.体操 3.巧手 4.隐蔽 5.奥秘 6.历史 7.调查 8.自然 9.宗教 10.驯兽 11.洞悉 12.医药 13.察觉 14.求生 15.欺瞒 16.威吓 17.表演 18.游说）\n");
	getchar();
	scanf("%d,%d,%d", &m, &n, &z);
	if (n < 1 || n>18 || m < 1 || m>18||z<1||z>18)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 2:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 3:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 4:
		strcat(player->skillProficiency, "隐蔽 ");
		break;
	case 5:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 6:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 7:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 8:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 9:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 10:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 11:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 12:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 13:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 14:
		strcat(player->skillProficiency, "求生 ");
		break;
	case 15:
		strcat(player->skillProficiency, "期满 ");
		break;
	case 16:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 17:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 18:
		strcat(player->skillProficiency, "游说 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 2:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 3:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 4:
		strcat(player->skillProficiency, "隐蔽 ");
		break;
	case 5:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 6:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 7:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 8:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 9:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 10:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 11:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 12:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 13:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 14:
		strcat(player->skillProficiency, "求生 ");
		break;
	case 15:
		strcat(player->skillProficiency, "期满 ");
		break;
	case 16:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 17:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 18:
		strcat(player->skillProficiency, "游说 ");
		break;
	}
	switch (z)
	{
	case 1:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 2:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 3:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 4:
		strcat(player->skillProficiency, "隐蔽 ");
		break;
	case 5:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 6:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 7:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 8:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 9:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 10:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 11:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 12:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 13:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 14:
		strcat(player->skillProficiency, "求生 ");
		break;
	case 15:
		strcat(player->skillProficiency, "期满 ");
		break;
	case 16:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 17:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 18:
		strcat(player->skillProficiency, "游说 ");
		break;
	}
}
void creatCleric(struct character* player)
{
	int m, n;
	player->hitPoint += 8;
	char Class[] = "牧师";
	char equipment[] = "轻甲、中甲、盾牌；简易武器 ";
	char saving[] = "感知 魅力 ";
	char trait[] = "神圣领域 ";
	char goods[] = "一把硬头锤或一把战锤（拥有熟练项时可选）；鳞甲，皮甲或链甲（拥有熟练项时可选）；一把轻弩和 20 支弩矢或任意简易武器；一个祭司套组或一个探索套组一个盾牌和一个圣徽";
	char main[] = "感知";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
	START:printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.历史 2.洞悉 3.医药 4.游说 5.宗教 ）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>5 || m < 1 || m>5)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 2:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 3:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 4:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 5:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 2:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 3:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 4:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 5:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
}
void creatDruid(struct character* player)
{
	int m, n;
	player->hitPoint += 8;
	char Class[] = "德鲁伊";
	char equipment[] = "轻甲、中甲、盾牌（德鲁伊不能装备或使用金属质的护甲和盾）；短棒、匕首、飞镖、ḷ枪、硬头锤、长棍、弯刀、镰刀、投石索、矛 ";
	char tool[] = "草药工具";
	char saving[] = "智力 感知 ";
	char goods[] = "一个木盾或任意简易武器;一把弯刀或任意简易近战武器;皮甲，一个探索套组和一件德鲁伊法器";
	char main[] = "感知";
	char language[] = "德鲁伊语 ";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->language, language);
	strcat(player->equipment, goods);
	strcat(player->toolProficiency, tool);
START:printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.奥秘 2.驯兽 3.洞悉 4.医药 5.自然 6.察觉 7.宗教 8.求生 ）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>8 || m < 1 || m>8)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 5:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 6:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 7:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 8:
		strcat(player->skillProficiency, "求生 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 5:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 6:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 7:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 8:
		strcat(player->skillProficiency, "求生 ");
		break;
	}
}
void creatFighter(struct character* player)
{
	int m, n;
	player->hitPoint += 10;
	char Class[] = "战士";
	char equipment[] = "所有护甲，盾牌，简易武器，军用武器 ";
	char saving[] = "力量 体质 ";
	char trait[] = "战斗风格 回气 ";
	char goods[] = "链甲或皮甲，长弓和 20 支箭；一把军用武器和一面盾牌或两把军用武器；一把轻弩和 20 支弩矢或两把手斧；一个地城套组或一个探索套组";
	char main[] = "力量或敏捷";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
START:printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.杂技 2.驯兽 3.运动 4.历史 5.洞悉 6.威吓 7.察觉 8.求生 ）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>8 || m < 1 || m>8)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "杂技 ");
		break;
	case 2:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 3:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 4:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 5:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 6:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 7:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 8:
		strcat(player->skillProficiency, "求生 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "杂技 ");
		break;
	case 2:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 3:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 4:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 5:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 6:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 7:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 8:
		strcat(player->skillProficiency, "求生 ");
		break;
	}
}
void creatMonk(struct character* player)
{
	int m, n;
	player->hitPoint += 8;
	char Class[] = "武僧";
	char equipment[] = "简易武器，短剑 ";
	char saving[] = "力量 敏捷 ";
	char tool[] = "选择一种工匠工具或一种乐器 ";
	char trait[] = "武艺 无甲防御 ";
	char goods[] = "一把短剑或任意一把简易武器；一个地城套组或（b）一个探索套组；10 支飞镖";
	char main[] = "敏捷和感知";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
START: printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.体操 2.运动 3.历史 4.洞悉 5.宗教 6.隐匿）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>6 || m < 1 || m>6)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 6:
		strcat(player->skillProficiency, "隐蔽 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "宗教 ");
		break;
	case 6:
		strcat(player->skillProficiency, "隐蔽 ");
		break;
	}
}
void creatPaladin(struct character* player)
{
	int m, n;
	player->hitPoint += 10;
	char Class[] = "圣武士";
	char equipment[] = "所有护甲，盾牌，简易武器，军用武器 ";
	char saving[] = "感知 魅力 ";
	char trait[] = "神圣感知 圣疗 ";
	char goods[] = "一把军用武器和一面盾牌或两把军用武器；五支标枪或任意简易近战武器；一个祭司套组或一个探索套组；链甲和一个圣徽";
	char main[] = "力量和魅力";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
START: printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.运动 2.洞悉 3.威吓 4.医药 5.说服 6.宗教）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>6 || m < 1 || m>6)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 2:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 3:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 4:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 5:
		strcat(player->skillProficiency, "说服 ");
		break;
	case 6:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 2:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 3:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 4:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 5:
		strcat(player->skillProficiency, "说服 ");
		break;
	case 6:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
}
void creatRanger(struct character* player)
{
	int m, n, z;
	player->hitPoint += 10;
	char Class[] = "游侠";
	char equipment[] = "轻甲，中甲，盾牌，简易武器，军用武器 ";
	char saving[] = "力量 敏捷 ";
	char trait[] = "宿敌 自然探索者 ";
	char goods[] = "鳞甲或皮甲；两把短剑或任意两把简易武器；一个地城套组或一个探索套组；一把长弓和一个箭袋（内含 20 支箭）";
	char main[] = "敏捷和感知";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
START:printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b,c三项技能（1.驯兽 2.运动 3.洞悉 4.调查 5.自然 6.察觉 7.隐匿 8.求生）\n");
	getchar();
	scanf("%d,%d,%d", &m, &n, &z);
	if (n < 1 || n>8 || m < 1 || m>8 || z < 1 || z>8)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 5:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 6:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 7:
		strcat(player->skillProficiency, "隐匿 ");
		break;
	case 8:
		strcat(player->skillProficiency, "求生 ");
		break;
	
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 5:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 6:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 7:
		strcat(player->skillProficiency, "隐匿 ");
		break;
	case 8:
		strcat(player->skillProficiency, "求生 ");
		break;
	}
	switch (z)
	{
	case 1:
		strcat(player->skillProficiency, "驯兽 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 5:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 6:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 7:
		strcat(player->skillProficiency, "隐匿 ");
		break;
	case 8:
		strcat(player->skillProficiency, "求生 ");
		break;
	}
}
void creatRogue(struct character* player)
{
	int m, n, z, x;
	player->hitPoint += 8;
	char Class[] = "游荡者";
	char equipment[] = "轻甲，简易武器，手弩，长剑，刺剑，短剑 ";
	char tool[] = "盗贼工具 ";
	char saving[] = "敏捷 智力 ";
	char language[] = "盗贼黑话 ";
	char trait[] = "专精 偷袭 ";
	char goods[] = "一把巨斧或任意一把军用近战武器；两把手斧或任意一把简易武器；一个探索套组和四支标枪";
	char main[] = "敏捷";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
	strcat(player->language, language);
	strcat(player->toolProficiency, tool);
START: printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b,c,d四项技能（1.体操 2.运动 3.欺瞒 4.洞悉 5.威吓 6.调查 7.察觉 8.表演 9.游说 10.巧手 11.隐匿）\n");
	getchar();
	scanf("%d,%d,%d,%d", &m, &n, &z, &x);
	if (n < 1 || n>11 || m < 1 || m>11||z<1||z>11||x<1||x>11)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 6:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 7:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 8:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 9:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 10:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 11:
		strcat(player->skillProficiency, "隐匿 ");
		break;

	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 6:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 7:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 8:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 9:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 10:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 11:
		strcat(player->skillProficiency, "隐匿 ");
		break;
	}
	switch (z)
	{
	case 1:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 6:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 7:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 8:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 9:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 10:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 11:
		strcat(player->skillProficiency, "隐匿 ");
		break;
	}
	switch (x)
	{
	case 1:
		strcat(player->skillProficiency, "体操 ");
		break;
	case 2:
		strcat(player->skillProficiency, "运动 ");
		break;
	case 3:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 6:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 7:
		strcat(player->skillProficiency, "察觉 ");
		break;
	case 8:
		strcat(player->skillProficiency, "表演 ");
		break;
	case 9:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 10:
		strcat(player->skillProficiency, "巧手 ");
		break;
	case 11:
		strcat(player->skillProficiency, "隐匿 ");
		break;
	}
}
void creatSorcerer(struct character* player)
{
	int m, n;
	player->hitPoint += 6;
	char Class[] = "术士";
	char equipment[] = "匕首，飞镖，投石索，长棍，轻弩 ";
	char saving[] = "魅力 体质 ";
	char trait[] = "术法起源 ";
	char goods[] = "一把轻弩与 20 支弩矢或任意一件简单武器；一个材料包或一件奥术法器；一个地城套组或一个探索套组；两把匕首";
	char main[] = "魅力";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
START: printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.奥秘 2.欺瞒 3.洞悉 4.威吓 5.游说 6.宗教）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>6 || m < 1 || m>6)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 5:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 6:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 5:
		strcat(player->skillProficiency, "游说 ");
		break;
	case 6:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
}
void creatWarlock(struct character* player)
{
	int m, n;
	player->hitPoint += 8;
	char Class[] = "邪术师";
	char equipment[] = "轻甲，简易武器 ";
	char saving[] = "感知 魅力 ";
	char trait[] = "异界宗主 契约魔法 ";
	char goods[] = "一把轻弩和 20 支弩矢或任意一把简易武器；一个材料包或一件奥术法器；一个学者套组或一个地城套组；皮甲、任意简易武器和两把匕首";
	char main[] = "魅力";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
START: printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.奥秘 2.欺瞒 3.威吓 4.洞悉 5.历史 6.自然 7.宗教）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>7 || m < 1 || m>7)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 3:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 6:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 7:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "欺瞒 ");
		break;
	case 3:
		strcat(player->skillProficiency, "威吓 ");
		break;
	case 4:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 5:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 6:
		strcat(player->skillProficiency, "自然 ");
		break;
	case 7:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
}
void creatWizard(struct character* player)
{
	int m, n;
	player->hitPoint += 6;
	char Class[] = "法师";
	char equipment[] = "匕首，飞镖，投石索，长棍，轻弩 ";
	char saving[] = "感知 智力 ";
	char trait[] = "奥数回想 ";
	char goods[] = "一根长棍或一把匕首；一个材料包或一件奥术法器；一个学者套组或一个探索套组；一本法术书";
	char main[] = "智力";
	strcat(player->mainAbility, main);
	strcat(player->equipmentProficiency, equipment);
	strcat(player->saving, saving);
	strcat(player->Class, Class);
	strcat(player->traits, trait);
	strcat(player->equipment, goods);
START: printf("已持有技能：%s\n", player->skillProficiency);
	printf("选择a,b两项技能（1.奥秘 2.历史 3.洞悉 4.调查 5.医药 6.宗教）\n");
	getchar();
	scanf("%d,%d", &m, &n);
	if (n < 1 || n>6 || m < 1 || m>6)
	{
		printf("input error\n重新选择\n");
		goto START;
	}
	switch (m)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 5:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 6:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
	switch (n)
	{
	case 1:
		strcat(player->skillProficiency, "奥秘 ");
		break;
	case 2:
		strcat(player->skillProficiency, "历史 ");
		break;
	case 3:
		strcat(player->skillProficiency, "洞悉 ");
		break;
	case 4:
		strcat(player->skillProficiency, "调查 ");
		break;
	case 5:
		strcat(player->skillProficiency, "医药 ");
		break;
	case 6:
		strcat(player->skillProficiency, "宗教 ");
		break;
	}
}
void classChoice(struct character* player)
{
	int n;
	printf("1.野蛮人Barbarian 2.吟游诗人Bard 3.牧师Cleric 4.德鲁伊Druid 5.战士Fighter 6.武僧Monk 7.圣武士Paladin 8.游侠Ranger 9.游荡着Rogue 10.术士Sorcerer 11.邪术师Warlock 12.法师Wizard\n");
	START:printf("输入相应数字查看职业基本信息，输入字母开始选择职业");
	while (scanf("%d", &n))
	{
	if (n < 1 || n>12)
	{
			printf("input error\n重新选择\n");
			getchar();
			goto START;
	}
		switch (n)
		{
		case 1:printf("野蛮人");
			break;
		case 2:printf("吟游诗人");
			break;
		case 3:printf("牧师");
			break;
		case 4:printf("德鲁伊");
			break;
		case 5:printf("战士");
			break;
		case 6:printf("武僧");
			break;
		case 7:printf("圣武士");
			break;
		case 8:printf("游侠");
			break;
		case 9:printf("游荡者");
			break;
		case 10:printf("术士");
			break;
		case 11:printf("邪术师");
			break;
		case 12:printf("法师");
			break;
		default:
		{
			printf("input error");
			exit(0);
		}
		}
	}
START1:printf("输入你的职业序号\n");
	getchar();
	scanf("%d", &n);
	if (n < 1 || n>12)
	{
			printf("input error\n重新选择\n");
			getchar();
			goto START1;
	}
	switch (n)
	{
	case 1:creatBarbarian(player);
		break;
	case 2:creatBard(player);
		break;
	case 3:creatCleric(player);
		break;
	case 4:creatDruid(player);
		break;
	case 5:creatFighter(player);
		break;
	case 6:creatMonk(player);
		break;
	case 7:creatPaladin(player);
		break;
	case 8:creatRanger(player);
		break;
	case 9:creatRogue(player);
		break;
	case 10:creatSorcerer(player);
		break;
	case 11:creatWarlock(player);
		break;
	case 12:creatWizard(player);
		break;
	}
}//职业选择
void determineAbilityScores(int a[], struct character* player)
{
	int i;
	int b[6];
	printf("%s的主属性为%s，豁免熟练项为%s\n",player->Class,player->mainAbility,player->saving);
	printf("1.力量 2.敏捷 3.体质 4.智力 5.感知 6.魅力\n");
	printf("输入属性对应属性值（如力量=%d 敏捷=%d 体质=%d 智力=%d 感知=%d 魅力=%d,则输入：3 1 5 2 4 6）：",a[2], a[0], a[4], a[1], a[3], a[5]);
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] < 1)
		{
			printf("input error\n");
			exit(0);
		}
		b[i]--;
	}
	player->strength += a[b[0]];
	player->dexterity += a[b[1]];
	player->constitution += a[b[2]];
	player->intelligence += a[b[3]];
	player->wisdom += a[b[4]];
	player->charisma += a[b[5]];
	player->hitPoint += (a[b[2]] - 10) / 2;
}//属性分配
void alignmentChoice(struct character* player)
{
	int n;
START: printf("选择阵营；（1.守序 2.中立 3.混乱）\n");
	getchar();
	scanf("%d", &n);
	if (n < 1 || n>3)
		{
			printf("input error\n重新选择\n");
			goto START;
		}
	switch (n)
	{
	case 1:
		strcat(player->alignment, "守序");
		break;
	case 2:
		strcat(player->alignment, "中立");
		break;
	case 3:
		strcat(player->alignment, "混乱");
		break;
	}
START1:printf("选择阵营；（1.善良 2.中立 3.邪恶）\n");
	getchar();
	scanf("%d", &n);
	if (n < 1 || n>3)
	{
		printf("input error\n重新选择\n");
		goto START1;
	}
	switch (n)
	{
	case 1:
		strcat(player->alignment, "善良");
		break;
	case 2:
		strcat(player->alignment, "中立");
		break;
	case 3:
		strcat(player->alignment, "邪恶");
		break;
	}
	char temp1[] = "中立中立";
	char temp2[] = "绝对中立";
	if (strcmp(player->alignment, temp1) == 0)
	{
		strcpy(player->alignment, temp2);
	}
}
int main()
	{
		int n;
		printf("龙与地下城是一款剑与魔法奇幻背景的叙事性角色扮演游戏。与孩童时代的过家家扮演游戏相似，D & D 依靠的是玩家无穷的想象力。你所需要做的，即是描述场景如暴风骤雨里，夜空下的Ḁ座高耸古堡。然后想象奇幻世界中的冒险者们会如何迎接即将到来的挑战。\n");
		printf("\n开始创建龙与地下城（Dungeons and Dragons）人物卡\n");
		system("pause");
		struct character player;
		int a[6];
		raceChoice(&player);
		classChoice(&player);
		getAbilityScores(a);
		printf("\n");
		determineAbilityScores(a, &player);
		alignmentChoice(&player);
		START:printf("选择性别；（1.男 2.女）\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			strcat(player.gender, "男");
			break;
		case 2:
			strcat(player.gender, "女");
			break;
		default:
		{
			printf("input error\n重新选择\n");
			goto START;
		}
		}

	}
