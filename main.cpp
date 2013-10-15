// DungeonHunter4Character.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "ShaoBing.h"
#include "ZhanDouDaShi.h"
#include "Store.h"


using namespace DungeonHunter4;

// 武器：圣洁弯弓 神圣长弓 食人魔长弓 毒域长弓
// 戒指：云端指环 蛇心指环 灰烬之戒 陨石指环 无名戒 莫比乌斯环 女巫之戒
//       不朽之戒 精神之戒 公爵徽记之戒 极地指环 皇族之戒 死亡象征 污迹指环 圣力之戒


// 哨兵
void test_shao_bing()
{
    ShaoBing shao_bing;

    const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁弯弓" );
    const Ring& ring = Store::instance().get_ring( "精神之戒" );

    shao_bing.set_wu_qi( wu_qi );           // 武器
    shao_bing.set_ring( ring );             // 戒指
    shao_bing.set_feng_bao_fu_zhou( 5 );    // 风暴符咒
    shao_bing.set_min_jie_fu_zhou( 10 );     // 敏捷符咒
    //shao_bing.set_seng_lv_fu_zhou( 1 );     // 僧侣符咒
    shao_bing.set_ji_xing();                // 主动技能：疾行
    shao_bing.set_ying_yan();               // 被动技能：鹰眼
    shao_bing.set_bing_shuang_zhi_jian();   // 被动技能：冰霜之箭
    //shao_bing.set_shen_en_tian_ci();        // 精神法术：神恩天赐
    shao_bing.set_ji_su_yao_ji();           // 药剂：疾速药剂
    shao_bing.set_shi_bing_shang_hai();     // 药剂：士兵伤害

    double miao_shang = shao_bing.get_miao_shang();
    std::cout << "哨兵：" << std::fixed <<  std::setprecision(2) << miao_shang << std::endl;

    ShaoBing::ge_max_dps();
}


// 战斗大师
void test_zhan_dou_da_shi()
{

    ZhanDouDaShi zhan_dou_da_shi;

    const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁长剑" );
    const Ring& ring = Store::instance().get_ring( "精神之戒" );

    zhan_dou_da_shi.set_wu_qi( wu_qi );           // 武器
    zhan_dou_da_shi.set_ring( ring );             // 戒指
    zhan_dou_da_shi.set_feng_bao_fu_zhou( 4 );    // 风暴符咒
    zhan_dou_da_shi.set_min_jie_fu_zhou( 6 );     // 敏捷符咒
    zhan_dou_da_shi.set_dong_cha_fu_zhou( 5 );    // 洞察符咒
    zhan_dou_da_shi.set_fen_nu();                 // 被动技能：愤怒
    zhan_dou_da_shi.set_ji_shu_lao_shou();        // 被动技能：技术老手
    zhan_dou_da_shi.set_ji_su_yao_ji();           // 药剂：疾速药剂
    zhan_dou_da_shi.set_shi_bing_shang_hai();     // 药剂：士兵伤害

    double miao_shang = zhan_dou_da_shi.get_miao_shang();
    std::cout << "战斗大师：" << std::fixed <<  std::setprecision(2) << miao_shang << std::endl;

    ZhanDouDaShi::ge_max_dps();
}


int _tmain(int argc, _TCHAR* argv[])
{

    test_shao_bing();
    test_zhan_dou_da_shi();

	return 0;
}
