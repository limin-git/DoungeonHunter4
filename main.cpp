// DungeonHunter4Character.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "ShaoBing.h"
#include "ZhanDouDaShi.h"
#include "Store.h"


using namespace DungeonHunter4;


int _tmain(int argc, _TCHAR* argv[])
{
#if 1
    {
        // 战斗大师

        ZhanDouDaShi zhan_dou_da_shi;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁长剑" );
        const Ring& ring = Store::instance().get_ring( "灰烬之戒" ); // 灰烬之戒 精神之戒 

        zhan_dou_da_shi.set_wu_qi( wu_qi );           // 武器
        zhan_dou_da_shi.set_ring( ring );             // 戒指
        zhan_dou_da_shi.set_feng_bao_fu_zhou( 4 );    // 风暴符咒
        zhan_dou_da_shi.set_min_jie_fu_zhou( 6 );     // 敏捷符咒
        zhan_dou_da_shi.set_dong_cha_fu_zhou( 5 );    // 洞察符咒
        zhan_dou_da_shi.set_fen_nu();                 // 被动技能：愤怒
        zhan_dou_da_shi.set_ji_shu_lao_shou();        // 被动技能：技术老手

        //std::cout <<  std::setprecision(20) << zhan_dou_da_shi.get_miao_shang() << std::endl;
        ZhanDouDaShi::ge_max_dps();
    }
#endif



#if 0
    {
        // 哨兵
        ShaoBing shao_bing;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁弯弓" );      // 圣洁弯弓 神圣长弓 食人魔长弓 毒域长弓 
        const Ring& ring = Store::instance().get_ring( "不朽之戒" );  // 蛇心指环 灰烬之戒 陨石指环 无名戒 莫比乌斯环 不朽之戒 精神之戒 公爵徽记之戒 极地指环 皇族之戒 死亡象征 污迹指环 圣力之戒 女巫之戒

        shao_bing.set_wu_qi( wu_qi );           // 武器
        shao_bing.set_ring( ring );          // 戒指
        shao_bing.set_feng_bao_fu_zhou( 5 );    // 风暴符咒
        shao_bing.set_min_jie_fu_zhou( 10 );     // 敏捷符咒
        //shao_bing.set_ying_yan();               // 被动技能：鹰眼
        shao_bing.set_bing_shuang_zhi_jian();   // 被动技能：冰霜之箭

        std::cout <<  std::setprecision(20) << shao_bing.get_miao_shang() << std::endl;
        //ShaoBing::ge_max_dps();
    }
#endif


	return 0;
}








































#if 0

// 圣洁弯弓
WuQi sheng_jie_wan_gong( 72484, 85999 );

// 食人魔
WuQi shi_ren_mo( 288, 327 );

// 神圣长弓
WuQi shen_sheng_chang_gong( 19209, 22685 );

// 圣洁长剑
WuQi sheng_jie_chang_jian( 113028, 136196 );

// 神圣宽剑
WuQi shen_sheng_kuan_jian( 29636, 35593 );

// 食人魔大剑
WuQi shi_ren_mo_da_jian( 406, 474 );

// 精神之戒
Ring jing_shen_zhi_jie( 0, 0.8, 0, 0.2 );

// 灰烬之戒
Ring hui_jin_zhi_jie( 0, 0, 0, 0.35 );

// 武器
const WuQi& wu_qi = sheng_jie_chang_jian;

// 戒指
const Ring& ring = jing_shen_zhi_jie;

DungeonHunter4Character hunter;

hunter.set_wu_qi( wu_qi );           // 武器
//hunter.set_ring( ring );          // 戒指
hunter.set_feng_bao_fu_zhou( 4 );    // 风暴符咒
hunter.set_min_jie_fu_zhou( 6 );     // 敏捷符咒
hunter.set_dong_cha_fu_zhou( 5 );    // 洞察符咒

//std::cout <<  std::setprecision(20) << hunter.get_miao_shang() << std::endl;



#endif