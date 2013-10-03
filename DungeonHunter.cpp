// DungeonHunter4Character.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <cassert>



struct WuQi
{
    WuQi( size_t wu_qi_shang_hai_min, size_t wu_qi_shang_hai_max )
    {
        m_wu_qi_shang_hai_min = wu_qi_shang_hai_min;
        m_wu_qi_shang_hai_max = wu_qi_shang_hai_max;
    }

    size_t m_wu_qi_shang_hai_min;
    size_t m_wu_qi_shang_hai_max;
};


struct Ring
{
    Ring( double bao_ji_ji_lu_jia = 0,             // 暴击几率
          double bao_ji_jiang_li_jia = 0,          // 暴击奖励
          double ji_chu_shang_hai_jia = 0,         // 基础伤害
          double yuan_su_shang_hai_jia_cheng = 0,  // 元素伤害加成
          double ji_chu_shang_hai_jia_cheng = 0 )  // 基础伤害加成
    {
        m_bao_ji_ji_lu_jia = bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia = bao_ji_jiang_li_jia;
        m_ji_chu_shang_hai_jia = ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng = yuan_su_shang_hai_jia_cheng;
        m_ji_chu_shang_hai_jia_cheng = ji_chu_shang_hai_jia_cheng;
    }

    double m_bao_ji_ji_lu_jia;
    double m_bao_ji_jiang_li_jia;
    double m_ji_chu_shang_hai_jia;
    double m_yuan_su_shang_hai_jia_cheng;
    double m_ji_chu_shang_hai_jia_cheng;
};



class Store
{
public:

    static Store& instance()
    {
        static Store store;
        return store;
    }

    const WuQi& get_wu_qi( const std::string& wu_qi_name )
    {
        std::map<std::string, WuQi*>::iterator find_it = m_wu_qi_map.find( wu_qi_name );

        if ( find_it == m_wu_qi_map.end() )
        {
            assert( false );
        }

        return *(find_it->second);
    }

    const Ring& get_jie_zhi( const std::string& jie_zhi_name )
    {
        std::map<std::string, Ring*>::iterator find_it = m_jie_zhi_map.find( jie_zhi_name );

        if ( find_it == m_jie_zhi_map.end() )
        {
            assert( false );
        }

        return *(find_it->second);
    }

    std::map<std::string, WuQi*>& get_all_wu_qi()
    {
        return m_wu_qi_map;
    }

    std::map<std::string, Ring*>& get_all_jie_zhi()
    {
        return m_jie_zhi_map;
    }

    void build_wu_qi()
    {
        m_wu_qi_map[ "圣洁弯弓" ]       = new WuQi( 72484, 85999 );
        m_wu_qi_map[ "食人魔长弓" ]     = new WuQi( 288, 327 );
        m_wu_qi_map[ "神圣长弓" ]       = new WuQi( 19209, 22685 );

        m_wu_qi_map[ "圣洁长剑" ]       = new WuQi( 113028, 136196 );
        m_wu_qi_map[ "神圣宽剑" ]       = new WuQi( 29636, 35593 );
        m_wu_qi_map[ "食人魔大剑" ]     = new WuQi( 406, 474 );
    }

    void build_ring()
    {
#if 0
        Ring( double bao_ji_ji_lu_jia = 0,             // 暴击几率
            double bao_ji_jiang_li_jia = 0,          // 暴击奖励
            double ji_chu_shang_hai_jia = 0,         // 基础伤害
            double yuan_su_shang_hai_jia_cheng = 0,  // 元素伤害加成
            double ji_chu_shang_hai_jia_cheng = 0 )   // 基础伤害加成
#endif
        m_jie_zhi_map[ "灰烬之戒" ]     = new Ring( 0, 0, 0, 0.35 );
        m_jie_zhi_map[ "蛇心指环" ]     = new Ring( 0, 0, 0, 0.11 );
        m_jie_zhi_map[ "不老之戒" ]     = new Ring( 0, 0, 0, 0.11 );
        m_jie_zhi_map[ "陨石指环" ]     = new Ring( 0, 0, 0, 0.35 );
        m_jie_zhi_map[ "赭石戒指" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "重环" ]         = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "奇异螺旋" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "蜥蜴之戒" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "无名戒" ]       = new Ring( 0, 0, 0, 0.20 );
        m_jie_zhi_map[ "莫比乌斯环" ]   = new Ring( 0, 0, 0, 0.20 );
        m_jie_zhi_map[ "不朽之戒" ]     = new Ring( 0, 0, 805, 0.20 );
        m_jie_zhi_map[ "精神之戒" ]     = new Ring( 0, 0.8, 0, 0.2 );
        m_jie_zhi_map[ "极地指环" ]     = new Ring( 0, 0.70, 637, 0, 0.07 );
        m_jie_zhi_map[ "皇族之戒" ]     = new Ring( 0, 0.70, 0, 0.07 );
        m_jie_zhi_map[ "圣力之戒" ]     = new Ring( 0, 0, 0, 0, 0.07 );
        m_jie_zhi_map[ "女巫之戒" ]     = new Ring( 0, 0, 637, 0, 0.07 );
        m_jie_zhi_map[ "污迹指环" ]     = new Ring( 0, 0, 0, 0.16 );
        m_jie_zhi_map[ "云端指环" ]     = new Ring( 0.06, 0, 0, 0, 0.06 );
        m_jie_zhi_map[ "坚韧指环" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "锯齿之环" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "金属戒指" ]     = new Ring( 0.05, 0.50, 0, 0 );
        m_jie_zhi_map[ "君王指环" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "恶魔之戒" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "死亡象征" ]     = new Ring( 0, 0, 380, 0, 0.05 );
        m_jie_zhi_map[ "遗产之戒" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "野蛮之戒" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "科纳西趾环" ]   = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "漆黑之戒" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "祖传戒指" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "埋藏之戒" ]     = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "锡戒指" ]       = new Ring( 0, 0, 0, 0 );
        m_jie_zhi_map[ "公爵徽记之戒" ] = new Ring( 0, 0, 214, 0 );
        m_jie_zhi_map[ "" ]             = new Ring( 0, 0, 0, 0 );
    }

public:

    Store()
    {
        build_wu_qi();
        build_ring();
    }

public:

    std::map<std::string, WuQi*> m_wu_qi_map;
    std::map<std::string, Ring*> m_jie_zhi_map;
};



class DungeonHunter4Character
{
public:

    DungeonHunter4Character()
    {
        reset();
    }

    virtual double get_adjustment()
    {
        return 0;
    }

    void reset()
    {
        m_ring = Ring();

        // 计算数据
        m_ji_chu_shang_hai = 0;
        m_miao_shang = 0;

        // 属性
        m_wu_qi_shang_hai_min = 0;
        m_wu_qi_shang_hai_max = 0;
        m_gong_ji_su_du = 0;
        m_bao_ji_ji_lu = 0.05;
        m_bao_ji_jiang_li = 0.5;

        // 符咒
        m_feng_bao_fu_zhou = 0;
        m_min_jie_fu_zhou = 0;
        m_dong_cha_fu_zhou = 0;

        // 属性加成
        m_gong_ji_su_du_jia_cheng = 0;
        m_ji_chu_shang_hai_jia = 0;
        m_ji_chu_shang_hai_jia_cheng = 0;
        m_yuan_su_shang_hai_jia_cheng = 0;
        m_bao_ji_ji_lu_jia = 0;
        m_bao_ji_jiang_li_jia = 0;
        m_shang_hai_jia_cheng = 0;

        // 微调
        m_adjustment = 0;
    }

    // 武器
    void set_wu_qi( const WuQi& wu_qi )
    {
        m_wu_qi_shang_hai_min = wu_qi.m_wu_qi_shang_hai_min;
        m_wu_qi_shang_hai_max = wu_qi.m_wu_qi_shang_hai_max;
    }

    // 武器
    void set_wu_qi( double wu_qi_shang_hai_min, double wu_qi_shang_hai_max )
    {
        m_wu_qi_shang_hai_min = wu_qi_shang_hai_min;
        m_wu_qi_shang_hai_max = wu_qi_shang_hai_max;
    }

    // 风暴符咒
    void set_feng_bao_fu_zhou( size_t feng_bao_fu_zhou )
    {
        m_feng_bao_fu_zhou = feng_bao_fu_zhou;
    }

    // 敏捷符咒
    void set_min_jie_fu_zhou( size_t min_jie_fu_zhou )
    {
        m_min_jie_fu_zhou = min_jie_fu_zhou;
    }

    // 洞察符咒
    void set_dong_cha_fu_zhou( size_t dong_cha_fu_zhou )
    {
        m_dong_cha_fu_zhou = dong_cha_fu_zhou;
    }

    void set_ring( const Ring& ring )
    {
        m_ring = ring;
    }

    double miao_shang_ji_suan_gong_shi()
    {
        // 戒指
        m_ji_chu_shang_hai_jia          += m_ring.m_ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng   += m_ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lu_jia              += m_ring.m_bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia           += m_ring.m_bao_ji_jiang_li_jia;
        m_ji_chu_shang_hai_jia_cheng    += m_ring.m_ji_chu_shang_hai_jia_cheng;

        // 基础伤害
        double ji_chu_shang_hai = std::ceil( ( m_wu_qi_shang_hai_min + m_wu_qi_shang_hai_max ) / 2.0 );
        m_ji_chu_shang_hai = ji_chu_shang_hai;
        m_ji_chu_shang_hai += m_ji_chu_shang_hai_jia; // 力量符咒
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_feng_bao_fu_zhou * 0.24; // 风暴符咒
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_ji_chu_shang_hai_jia_cheng; // 士兵伤害
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_yuan_su_shang_hai_jia_cheng; // 元素伤害

        // 暴击几率
        m_bao_ji_ji_lu += m_bao_ji_ji_lu_jia;
        m_bao_ji_ji_lu += m_dong_cha_fu_zhou * 0.1; // 洞察符咒

        // 暴击奖励
        m_bao_ji_jiang_li += m_bao_ji_jiang_li_jia;
        m_bao_ji_jiang_li += m_min_jie_fu_zhou * 1.0; // 敏捷符咒

        // 暴击伤害
        double bao_ji_shang_hai = m_ji_chu_shang_hai * ( 1.0 + m_bao_ji_jiang_li ) * m_bao_ji_ji_lu;

        // 普通伤害
        double pu_tong_shang_hai = 0;

        if ( m_bao_ji_ji_lu < 1 )
        {
            pu_tong_shang_hai = m_ji_chu_shang_hai * ( 1.0 - m_bao_ji_ji_lu );
        }
        
        // 平均伤害
        double ping_jun_shang_hai = bao_ji_shang_hai + pu_tong_shang_hai;

        // 伤害
        double shang_hai = ping_jun_shang_hai * ( 1 + m_shang_hai_jia_cheng );

        // 秒伤
        m_miao_shang = shang_hai * m_gong_ji_su_du;

        return m_miao_shang + get_adjustment();
    }

public:

    double get_wu_qi_shang_hai()
    {
        return std::ceil( ( m_wu_qi_shang_hai_min + m_wu_qi_shang_hai_max ) / 2.0 );
    }

public:

    Ring m_ring;

    // 计算数据
    double m_ji_chu_shang_hai;
    double m_miao_shang;

    // 属性
    double m_wu_qi_shang_hai_min;
    double m_wu_qi_shang_hai_max;
    double m_gong_ji_su_du;
    double m_bao_ji_ji_lu;
    double m_bao_ji_jiang_li;

    // 符咒
    size_t m_feng_bao_fu_zhou;
    size_t m_min_jie_fu_zhou;
    size_t m_dong_cha_fu_zhou;

    // 属性加成
    double m_gong_ji_su_du_jia_cheng;
    double m_ji_chu_shang_hai_jia;
    double m_ji_chu_shang_hai_jia_cheng;
    double m_yuan_su_shang_hai_jia_cheng;
    double m_bao_ji_ji_lu_jia;
    double m_bao_ji_jiang_li_jia;
    double m_shang_hai_jia_cheng;

    // 微调
    double m_adjustment;
};


// 哨兵
class ShaoBing : public DungeonHunter4Character
{
public:

    ShaoBing()
    {
        reset();
    }

    void reset()
    {
        DungeonHunter4Character::reset();
        m_gong_ji_su_du = 2;
        m_is_set_ying_yan = false;
    }

    // 被动技能：冰霜之箭
    void set_bing_shuang_zhi_jian()
    {
        m_yuan_su_shang_hai_jia_cheng += 0.4;
    }

    // 被动技能：鹰眼
    void set_ying_yan()
    {
        // 被动技能：鹰眼技能
        // - （武器伤害 + 元素伤害）* 10%

        m_is_set_ying_yan = true;

        m_bao_ji_ji_lu_jia += 1.0;
        m_bao_ji_jiang_li_jia += 0.3;
    }

    double get_adjustment()
    {
        if ( true == m_is_set_ying_yan )
        {
            m_adjustment = -1 * get_wu_qi_shang_hai() * ( 1 + get_yuan_su_shang_hai_jia_cheng() ) * 0.1;
        }

        return m_adjustment; // TODO: 去掉此变量
    }

    double get_yuan_su_shang_hai_jia_cheng()
    {
        return m_feng_bao_fu_zhou * 0.24 + m_yuan_su_shang_hai_jia_cheng;
    }

    static double caculate_max_dps()
    {
        double max_dps = 0;
        size_t feng_bao = 0;
        size_t min_jie = 0;
        std::string jie_zhi;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁弯弓" );

        ShaoBing shao_bing;

        for ( size_t i = 0; i < 15; ++i )
        {
            shao_bing.reset();
            shao_bing.set_wu_qi( wu_qi );
            shao_bing.set_feng_bao_fu_zhou( i );
            shao_bing.set_min_jie_fu_zhou( 15 - i );
            shao_bing.set_bing_shuang_zhi_jian();   // 被动技能：冰霜之箭
            shao_bing.set_ying_yan();               // 被动技能：鹰眼
            
            std::map<std::string, Ring*>& all_jie_zhi = Store::instance().get_all_jie_zhi();

            for ( std::map<std::string, Ring*>::iterator it = all_jie_zhi.begin(); it != all_jie_zhi.end(); ++it )
            {
                shao_bing.set_ring( *(it->second) );

                double dps = shao_bing.miao_shang_ji_suan_gong_shi();

                if ( max_dps < dps )
                {
                    max_dps = dps;
                    feng_bao = i;
                    min_jie = 15 - i;
                    jie_zhi = it->first;
                }
            }
        }

        std::cout << "风暴符咒：" << feng_bao << std::endl;
        std::cout << "敏捷符咒：" << min_jie << std::endl;
        std::cout << "戒指：    " << jie_zhi << std::endl;
        std::cout << "极限秒伤：" << std::setprecision(20) << max_dps << std::endl;

        return max_dps;
    }

    bool m_is_set_ying_yan; // 被动技能：鹰眼
};


// 战斗大师
class ZhanDouDaShi : public DungeonHunter4Character
{
public:
    
    ZhanDouDaShi()
    {
        m_gong_ji_su_du = 1.579707703543008;
    }

    void reset()
    {
        DungeonHunter4Character::reset();
        m_gong_ji_su_du = 1.579707703543008;
    }

    // 被动技能：愤怒
    void set_fen_nu()
    {
        m_shang_hai_jia_cheng += 0.4;
    }

    // 被动技能：技术老手
    void set_ji_shu_lao_shou()
    {
        m_bao_ji_ji_lu_jia += 0.3;
        m_bao_ji_jiang_li_jia += 1;
    }

    static double caculate_max_dps()
    {
        double max_dps = 0;
        size_t feng_bao = 0;
        size_t dong_cha = 0;
        size_t min_jie = 0;

        // 圣洁长剑
        WuQi sheng_jie_chang_jian( 113028, 136196 );

        // 精神之戒
        Ring jing_shen_zhi_jie( 0, 0.8, 0, 0.2 );

        ZhanDouDaShi zhan_dou_da_shi;

        for ( size_t i = 1; i <= 15; ++i ) // 风暴
        {
            for ( size_t j = 1; j <= 15; ++j ) // 洞察
            {
                if ( i + j > 15 )
                {
                    continue;
                }

                for ( size_t k = 1; k <= 15; ++k ) // 敏捷
                {
                    if ( i + j + k != 15 )
                    {
                        continue;
                    }

                    zhan_dou_da_shi.reset();
                    zhan_dou_da_shi.set_wu_qi( sheng_jie_chang_jian );
                    zhan_dou_da_shi.set_ring( jing_shen_zhi_jie );          // 戒指
                    zhan_dou_da_shi.set_feng_bao_fu_zhou( i );
                    zhan_dou_da_shi.set_dong_cha_fu_zhou( j );
                    zhan_dou_da_shi.set_min_jie_fu_zhou( k );
                    zhan_dou_da_shi.set_fen_nu();           // 被动技能：愤怒
                    zhan_dou_da_shi.set_ji_shu_lao_shou();  // 被动技能：技术老手

                    double dps = zhan_dou_da_shi.miao_shang_ji_suan_gong_shi();

                    if ( max_dps < dps )
                    {
                        max_dps = dps;
                        feng_bao = i;
                        dong_cha = j;
                        min_jie = k;
                    }
                }
            }
        }

        std::cout << "风暴符咒：" << feng_bao << std::endl;
        std::cout << "洞察符咒：" << dong_cha << std::endl;
        std::cout << "敏捷符咒：" << min_jie << std::endl;
        std::cout << "极限秒伤：" << std::setprecision(20) << max_dps << std::endl;

        return max_dps;
    }
};


int _tmain(int argc, _TCHAR* argv[])
{

    {
        // 哨兵
        ShaoBing shao_bing;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁弯弓" );      //神圣长弓 食人魔长弓
        const Ring& jie_zhi = Store::instance().get_jie_zhi( "不朽之戒" );  // 蛇心指环 灰烬之戒 陨石指环 无名戒 莫比乌斯环 不朽之戒 精神之戒 

        shao_bing.set_wu_qi( wu_qi );           // 武器
        shao_bing.set_ring( jie_zhi );          // 戒指
        shao_bing.set_feng_bao_fu_zhou( 5 );    // 风暴符咒
        shao_bing.set_min_jie_fu_zhou( 10 );     // 敏捷符咒
        shao_bing.set_ying_yan();               // 被动技能：鹰眼
        shao_bing.set_bing_shuang_zhi_jian();   // 被动技能：冰霜之箭

        std::cout <<  std::setprecision(20) << shao_bing.miao_shang_ji_suan_gong_shi() << std::endl;
        //ShaoBing::caculate_max_dps();
    }

    {
        // 战斗大师

        ZhanDouDaShi zhan_dou_da_shi;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁长剑" );
        const Ring& jie_zhi = Store::instance().get_jie_zhi( "精神之戒" );

        zhan_dou_da_shi.set_wu_qi( wu_qi );           // 武器
        zhan_dou_da_shi.set_ring( jie_zhi );          // 戒指
        zhan_dou_da_shi.set_feng_bao_fu_zhou( 4 );    // 风暴符咒
        zhan_dou_da_shi.set_min_jie_fu_zhou( 6 );     // 敏捷符咒
        zhan_dou_da_shi.set_dong_cha_fu_zhou( 5 );    // 洞察符咒
        zhan_dou_da_shi.set_fen_nu();                 // 被动技能：愤怒
        zhan_dou_da_shi.set_ji_shu_lao_shou();        // 被动技能：技术老手

        //std::cout <<  std::setprecision(20) << zhan_dou_da_shi.miao_shang_ji_suan_gong_shi() << std::endl;
        //ZhanDouDaShi::caculate_max_dps();
    }

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
const Ring& jie_zhi = jing_shen_zhi_jie;

DungeonHunter4Character hunter;

hunter.set_wu_qi( wu_qi );           // 武器
//hunter.set_ring( jie_zhi );          // 戒指
hunter.set_feng_bao_fu_zhou( 4 );    // 风暴符咒
hunter.set_min_jie_fu_zhou( 6 );     // 敏捷符咒
hunter.set_dong_cha_fu_zhou( 5 );    // 洞察符咒

//std::cout <<  std::setprecision(20) << hunter.miao_shang_ji_suan_gong_shi() << std::endl;



#endif