#ifndef CONFIG_H
#define CONFIG_H
/************配置文件数据************/

/************游戏配置数据************/
#define GAME_WIDTH  544  //地图宽度（544）
#define GAME_WIDTH_1  694  //游戏真实宽度
#define GAME_HEIGHT  819  //地图高度（819）
#define GAME_TITLE  "领地之争 v1.0"  //标题
#define GAME_RATE  80  //刷新时间，单位毫秒
#define GAME_TIME  1500  //与GAME_RATE相乘，单位毫秒，为游戏最长时间(1500*80/1000=120s)
#define GAME_WIN  80  //胜利标准，深红色与红色方块的总和(80)
#define GAME_V  15  //标准速度


/************背景图配置数据************/
#define MAP_PATH ":/new_picture/new_pictures/01-background-blue.jpg" // 游戏界面背景图路径
#define CARD_PATH ":/new_picture/new_pictures/51-card.png" // 卡片背景图路径
#define SHOP_SUN_PATH ":/new_picture/new_pictures/52-cardshop-sun.png" // 商店阳光背景图路径
#define SHOP_CARD_PATH ":/new_picture/new_pictures/53-cardshop.png" // 商店卡片背景图路径
//#define START_MAP_PATH ":/new_picture/new_pictures/000-start.png" // 开始界面背景图路径
//#define WIN_MAP_PATH ":/pictures/999-win_image.png" // 游戏胜利界面背景图路径
//#define LOSE_MAP_PATH ":/pictures/999-lose_image.png" // 游戏失败界面背景图路径
#define PLANT_CARD_WIDTH 80     // 植物卡片宽度
#define PLANT_CARD_HEIGHT 100   // 植物卡片高度


/************阳光配置数据************/
#define SUN_PATH ":/new_picture/new_pictures/61-Sun.png" // 阳光背景图路径
#define SUN_SUM0 200 // 初始阳光值
#define MAX_BUTTONS 3  // 同时存在的最大数量
#define BUTTON_SIZE 78 // 阳光（按钮）的尺寸大小
#define SUN_COOLDOWN 3000 // 阳光冷却时间(ms)


/************按钮配置数据************/
#define BUTTON_WID 100 // 标准按钮高度


/************红色方块配置数据************/
#define BLOCK_PATH ":/new_picture/new_pictures/02-block-red.png" // 红色方块路径
#define BLOCK_NUM 288 // 红色方块数量


/************深红色方块配置数据************/
#define DBLOCK_PATH ":/new_picture/new_pictures/03-block-darkred.png" // 深红色方块路径
#define DBLOCK_NUM 486 // 深红色方块数量


/************子弹配置数据************/
#define BULLET_PATH ":/new_picture/new_pictures/04-bullet.png" //子弹图片路径
#define BULLET_INTERVAL 8 //发射间隔（*GAME_RATE）


/************加农炮1配置数据************/
#define CONNON1_PATH ":/new_picture/new_pictures/11-cannon-1.png" // 加农炮1图片路径
#define CONNON1_BULLET_NUM 36 // 加农炮1弹匣子弹数量
#define CONNON1_COST 100      // 加农炮1种植消耗阳光
#define CONNON1_COOLDOWN 5000 // 加农炮1冷却时间(ms)


/************加农炮3配置数据************/
#define CONNON3_PATH ":/new_picture/new_pictures/12-cannon-3.png" // 加农炮3图片路径
#define CONNON3_COST 200      // 加农炮3种植消耗阳光
#define CONNON3_BULLET_NUM_1 36 // 加农炮3左前弹匣子弹数量
#define CONNON3_BULLET_NUM_2 36 // 加农炮3正前弹匣子弹数量
#define CONNON3_BULLET_NUM_3 36 // 加农炮3右前弹匣子弹数量
#define CONNON3_COOLDOWN 5000 // 加农炮3冷却时间(ms)


/************滚轮配置数据************/
#define WHEEL_PATH ":/new_picture/new_pictures/21-wheel.png" // 滚轮图片路径
#define WHEEL_COST 150      // 滚轮种植消耗阳光
#define WHEEL_COOLDOWN 5000 // 滚轮冷却时间(ms)


/************敌机配置数据************/
#define ENEMY_PLANE_PATH ":/new_picture/new_pictures/31-warplane-red.png" // 敌机图片路径
#define ENEMY_PLANE_COOLDOWN 35000 // 敌机冷却时间(ms)


/************敌方云朵配置数据************/
#define CLOUDE_PATH ":/new_picture/new_pictures/41-cloud.png" // 敌方云朵图片路径
#define CLOUDE_COOLDOWN 20000 // 敌方云朵冷却时间(ms)


#endif // CONFIG_H
