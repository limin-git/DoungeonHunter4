#include "stdafx.h"
#include "ZhanDouDaShi.h"
#include "DpsConfiguration.h"


namespace DungeonHunter4
{

    ZhanDouDaShi::ZhanDouDaShi()
    {
        init();
    }


    void ZhanDouDaShi::init()
    {
        Character::init();

        m_gong_ji_su_du = 1.579707703543008;
    }


    // 被动技能：愤怒
    void ZhanDouDaShi::set_fen_nu()
    {
        m_shang_hai_jia_cheng += 0.4;
    }


    // 被动技能：技术老手
    void ZhanDouDaShi::set_ji_shu_lao_shou()
    {
        m_bao_ji_ji_lv_jia += 0.3;
        m_bao_ji_jiang_li_jia += 1;
    }


    // 药剂：疾速药剂
    void ZhanDouDaShi::set_ji_su_yao_ji()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // 药剂：士兵伤害
    void ZhanDouDaShi::set_shi_bing_shang_hai()
    {
        m_shang_hai_jia_cheng += 1.4;
    }


    double ZhanDouDaShi::ge_max_dps( size_t output_list_size )
    {
        ZhanDouDaShi zhan_dou_da_shi;

        zhan_dou_da_shi.set_wu_qi( Store::instance().get_wu_qi( "圣洁长剑" ) );
        zhan_dou_da_shi.set_fen_nu();                   // 被动技能：愤怒
        zhan_dou_da_shi.set_ji_shu_lao_shou();          // 被动技能：技术老手
        zhan_dou_da_shi.set_ji_su_yao_ji();             // 药剂：疾速药剂
        zhan_dou_da_shi.set_shi_bing_shang_hai();       // 药剂：士兵伤害

        DpsList dps_list;
        Character::get_dps_list( zhan_dou_da_shi, dps_list );

        for ( DpsList::iterator it = dps_list.begin(); it != dps_list.end() && 0 < output_list_size; ++it, --output_list_size )
        {
            it->output();
            std::cout << std::endl;
        }

        return dps_list.begin()->m_dps;
    }

} // namespace DungeonHunter4
