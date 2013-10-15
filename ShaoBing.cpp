#include "stdafx.h"
#include "ShaoBing.h"
#include "DpsConfiguration.h"


namespace DungeonHunter4
{

    ShaoBing::ShaoBing()
    {
        init();
    }


    void ShaoBing::init()
    {
        Character::init();

        m_gong_ji_su_du = 2;
        m_is_set_ying_yan = false;
    }


    // 主动技能：疾行
    void ShaoBing::set_ji_xing()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // 被动技能：冰霜之箭
    void ShaoBing::set_bing_shuang_zhi_jian()
    {
        m_yuan_su_shang_hai_jia_cheng += 0.4;
    }


    // 被动技能：鹰眼
    void ShaoBing::set_ying_yan()
    {
        // 被动技能：鹰眼技能
        // + 100% 暴击几率
        // + 30% 暴击伤害奖励
        // - 10% 武器伤害
        // - 10% 武器伤害 x 元素伤害

        m_is_set_ying_yan = true;

        m_bao_ji_ji_lv_jia += 1;
        m_bao_ji_jiang_li_jia += 0.3;
    }


    // 药剂：疾速药剂
    void ShaoBing::set_ji_su_yao_ji()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // 药剂：士兵伤害
    void ShaoBing::set_shi_bing_shang_hai()
    {
        m_shang_hai_jia_cheng += 1;
    }


    double ShaoBing::ge_max_dps( size_t output_list_size )
    {
        DpsList dps_list;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁弯弓" );
        Rings& all_ring = Store::instance().get_all_rings();

        for ( size_t i = 0; i <= 15; ++i ) // 风暴
        {
            for ( size_t j = 0; j <= 15; ++j ) // 敏捷
            {
                if ( i + j > 15 )
                {
                    continue;
                }

                for ( size_t k = 0; k <= 15; ++k ) // 僧侣
                {
                    if ( i + j + k != 15 )
                    {
                        continue;
                    }

                    for ( Rings::iterator it = all_ring.begin(); it != all_ring.end(); ++it ) // 戒指
                    {
                        ShaoBing shao_bing;

                        shao_bing.set_wu_qi( wu_qi );
                        shao_bing.set_ji_xing();                // 主动技能：疾行
                        shao_bing.set_bing_shuang_zhi_jian();   // 被动技能：冰霜之箭
                        shao_bing.set_ying_yan();               // 被动技能：鹰眼
                        //shao_bing.set_shen_en_tian_ci();        // 被动技能：神恩天赐
                        shao_bing.set_ji_su_yao_ji();           // 药剂：疾速药剂
                        shao_bing.set_shi_bing_shang_hai();     // 药剂：士兵伤害

                        shao_bing.set_feng_bao_fu_zhou( i );
                        shao_bing.set_min_jie_fu_zhou( j );
                        shao_bing.set_seng_lv_fu_zhou( k );
                        shao_bing.set_ring( *it );

                        double dps = shao_bing.get_miao_shang();

                        DpsConfiguration dps_config;

                        dps_config.set_dps( dps );
                        dps_config.add_configuration( "风暴", i );
                        dps_config.add_configuration( "敏捷", j );
                        dps_config.add_configuration( "僧侣", k );
                        dps_config.add_configuration( it->m_name );

                        dps_list.insert( dps_config );
                    }
                }
            }
        }

        assert( false == dps_list.empty() );

        size_t i = 0;

        for ( DpsList::iterator it = dps_list.begin(); it != dps_list.end() && i < output_list_size; ++it, ++i )
        {
            it->output();
            std::cout << std::endl;
        }

        return dps_list.begin()->m_dps;
    }

} // namespace DungeonHunter4
