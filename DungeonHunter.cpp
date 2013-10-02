// DungeonHunter4Character.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>



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
          double yuan_su_shang_hai_jia_cheng = 0 ) // 元素伤害
    {
        m_bao_ji_ji_lu_jia = bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia = bao_ji_jiang_li_jia;
        m_ji_chu_shang_hai_jia = ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng = yuan_su_shang_hai_jia_cheng;
    }

    double m_bao_ji_ji_lu_jia;
    double m_bao_ji_jiang_li_jia;
    double m_ji_chu_shang_hai_jia;
    double m_yuan_su_shang_hai_jia_cheng;
};



class DungeonHunter4Character
{
public:

    DungeonHunter4Character()
    {
        reset();
    }

    void reset()
    {
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
        m_ji_chu_shang_hai_jia += ring.m_ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng += ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lu_jia += ring.m_bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia += ring.m_bao_ji_jiang_li_jia;
    }

    double miao_shang_ji_suan_gong_shi()
    {
        // 基础伤害
        double ji_chu_shang_hai = std::ceil( ( m_wu_qi_shang_hai_min + m_wu_qi_shang_hai_max ) / 2.0 );
        m_ji_chu_shang_hai = ji_chu_shang_hai;
        m_ji_chu_shang_hai += m_ji_chu_shang_hai_jia; // 力量符咒
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_feng_bao_fu_zhou * 0.24; // 风暴符咒
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_ji_chu_shang_hai_jia_cheng; // 士兵伤害
        m_ji_chu_shang_hai += ji_chu_shang_hai * m_yuan_su_shang_hai_jia_cheng;

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

        return m_miao_shang + m_adjustment;
    }

public:

    double get_wu_qi_shang_hai()
    {
        return std::ceil( ( m_wu_qi_shang_hai_min + m_wu_qi_shang_hai_max ) / 2.0 );
    }

public:

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



class ShaoBing : public DungeonHunter4Character
{
public:

    ShaoBing()
    {
        m_gong_ji_su_du = 2;
    }

    void reset()
    {
        DungeonHunter4Character::reset();
        m_gong_ji_su_du = 2;
    }

    void set_ring( const Ring& ring )
    {
        m_ji_chu_shang_hai_jia += ring.m_ji_chu_shang_hai_jia;
        m_yuan_su_shang_hai_jia_cheng += ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lu_jia += ring.m_bao_ji_ji_lu_jia;
        m_bao_ji_jiang_li_jia += ring.m_bao_ji_jiang_li_jia;

        m_adjustment -= get_wu_qi_shang_hai() * 0.1 * ring.m_yuan_su_shang_hai_jia_cheng;
    }

    // 被动技能：冰霜之箭
    void set_bing_shuang_zhi_jian()
    {
        m_ji_chu_shang_hai_jia_cheng += 0.4;
    }

    // 被动技能：鹰眼
    void set_ying_yan()
    {
        // 被动技能：鹰眼技能
        // - 平均伤害的 10%
        // - 平均伤害 * 风暴符咒个数 * 风暴符咒伤害 * 10% 
        //m_bao_ji_ji_lu += 1.0;
        //m_bao_ji_jiang_li += 0.3;

        m_bao_ji_ji_lu_jia += 1.0;
        m_bao_ji_jiang_li_jia += 0.3;

        double shang_hai = get_wu_qi_shang_hai();
        m_adjustment -= shang_hai * 0.14;
        m_adjustment -= m_feng_bao_fu_zhou * 0.24 * shang_hai * 0.1;
    }


    static double caculate_max_dps()
    {
        double max_dps = 0;
        size_t feng_bao = 0;
        size_t min_jie = 0;

        // 圣洁弯弓
        WuQi sheng_jie_wan_gong( 72484, 85999 );

        ShaoBing shao_bing;

        for ( size_t i = 0; i < 15; ++i )
        {
            shao_bing.reset();
            shao_bing.set_wu_qi( sheng_jie_wan_gong );
            shao_bing.set_feng_bao_fu_zhou( i );
            shao_bing.set_min_jie_fu_zhou( 15 - i );
            shao_bing.set_bing_shuang_zhi_jian();   // 被动技能：冰霜之箭
            shao_bing.set_ying_yan();               // 被动技能：鹰眼

            double dps = shao_bing.miao_shang_ji_suan_gong_shi();

            if ( max_dps < dps )
            {
                max_dps = dps;
                feng_bao = i;
                min_jie = 15 - i;
            }
        }

        std::cout << "风暴符咒：" << feng_bao << std::endl;
        std::cout << "敏捷符咒：" << min_jie << std::endl;
        std::cout << "极限秒伤：" << std::setprecision(20) << max_dps << std::endl;

        return max_dps;
    }
};


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
    // 圣洁弯弓
    WuQi sheng_jie_wan_gong( 72484, 85999 );

    // 食人魔
    WuQi shi_ren_mo( 288, 327 );

    // 神圣
    WuQi shen_sheng( 19209, 22685 );

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


    ZhanDouDaShi::caculate_max_dps();

	return 0;
}

