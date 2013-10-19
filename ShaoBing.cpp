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
        ShaoBing shao_bing;

        shao_bing.set_wu_qi( Store::instance().get_wu_qi( "圣洁弯弓" ) );
        shao_bing.set_ji_xing();                // 主动技能：疾行
        shao_bing.set_bing_shuang_zhi_jian();   // 被动技能：冰霜之箭
        shao_bing.set_ying_yan();               // 被动技能：鹰眼
        shao_bing.set_ji_su_yao_ji();           // 药剂：疾速药剂
        shao_bing.set_shi_bing_shang_hai();     // 药剂：士兵伤害

        DpsList dps_list;
        Character::get_dps_list( shao_bing, dps_list );

        for ( DpsList::iterator it = dps_list.begin(); it != dps_list.end() && 0 < output_list_size; ++it, --output_list_size )
        {
            it->output();
            std::cout << std::endl;
        }

        return dps_list.begin()->m_dps;
    }

} // namespace DungeonHunter4
