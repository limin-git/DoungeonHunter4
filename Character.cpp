#include "stdafx.h"
#include "Character.h"


namespace
{
    const size_t MAX_FUZHOU_NUM = 15;           // ·ûÖä¸öÊı
    const double SENG_LV_L05 = 0.17;            // É®ÂÂ£¨05¼¶£©
    const double SENG_LV_L10 = 0.32;            // É®ÂÂ£¨10¼¶£©
    const double& SENG_LV_LEVEL = SENG_LV_L05;  // µ±Ç°É®ÂÂµÈ¼¶
}


namespace DungeonHunter4
{

    Character::Character()
    {
        init();
    }


    void Character::init()
    {
        // ½ÇÉ«Êı¾İ
        m_miao_shang = 0;

        // ¹¥»÷Êı¾İ
        m_shang_hai = 0;                     // ÉËº¦
        m_gong_ji_su_du = 0;                 // ¹¥»÷ËÙ¶È
        m_bao_ji_ji_lv = 0.05;               // ±©»÷¼¸ÂÊ
        m_bao_ji_jiang_li = 0.5;             // ±©»÷ÉËº¦½±Àø
        m_gong_ji_su_du_jia_cheng = 0;       // +%¹¥»÷ËÙ¶È
        m_ji_chu_li_liang_jia = 0;           // +»ù´¡Á¦Á¿
        m_yuan_su_shang_hai_jia_cheng = 0;   // +%ÔªËØÉËº¦£¨À×±ù£©
        m_bao_ji_ji_lv_jia = 0;              // +%±©»÷¼¸ÂÊ
        m_bao_ji_jiang_li_jia = 0;           // +%±©»÷ÉËº¦½±Àø
        m_shang_hai_jia_cheng = 0;           // +%ÉËº¦

        // ÎïÆ·
        Ring m_ring = Ring();                // ½äÖ¸
        m_feng_bao_fu_zhou = 0;              // ·ç±©·ûÖä
        m_min_jie_fu_zhou = 0;               // Ãô½İ·ûÖä
        m_dong_cha_fu_zhou = 0;              // ¶´²ì·ûÖä
        m_seng_lv_fu_zhou = 0;               // É®ÂÂ·ûÖä
    }


    // ÎäÆ÷
    void Character::set_wu_qi( const WuQi& wu_qi )
    {
        m_wu_qi = wu_qi;
    }


    // ·ç±©·ûÖä
    void Character::set_feng_bao_fu_zhou( size_t feng_bao_fu_zhou )
    {
        m_feng_bao_fu_zhou = feng_bao_fu_zhou;
    }


    // Ãô½İ·ûÖä
    void Character::set_min_jie_fu_zhou( size_t min_jie_fu_zhou )
    {
        m_min_jie_fu_zhou = min_jie_fu_zhou;
    }


    // ¶´²ì·ûÖä
    void Character::set_dong_cha_fu_zhou( size_t dong_cha_fu_zhou )
    {
        m_dong_cha_fu_zhou = dong_cha_fu_zhou;
    }


    // É®ÂÂ·ûÖä
    void Character::set_seng_lv_fu_zhou( size_t seng_lv_fu_zhou )
    {
        m_seng_lv_fu_zhou = seng_lv_fu_zhou;
    }


    // ½äÖ¸
    void Character::set_ring( const Ring& ring )
    {
        m_ji_chu_li_liang_jia           -= m_ring.m_ji_chu_li_liang_jia;
        m_yuan_su_shang_hai_jia_cheng   -= m_ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lv_jia              -= m_ring.m_bao_ji_ji_lv_jia;
        m_bao_ji_jiang_li_jia           -= m_ring.m_bao_ji_jiang_li_jia;
        m_shang_hai_jia_cheng           -= m_ring.m_shang_hai_jia_cheng;

        m_ji_chu_li_liang_jia           += ring.m_ji_chu_li_liang_jia;
        m_yuan_su_shang_hai_jia_cheng   += ring.m_yuan_su_shang_hai_jia_cheng;
        m_bao_ji_ji_lv_jia              += ring.m_bao_ji_ji_lv_jia;
        m_bao_ji_jiang_li_jia           += ring.m_bao_ji_jiang_li_jia;
        m_shang_hai_jia_cheng           += ring.m_shang_hai_jia_cheng;

        m_ring = ring;
    }


    // ¾«Éñ·¨Êõ£ºÉñ¶÷Ìì´Í
    void Character::set_shen_en_tian_ci()
    {
        // TODO:
        //m_shang_hai_jia_cheng += 1.2;
        //m_bao_ji_ji_lv_jia += 0.96;
        //m_bao_ji_jiang_li_jia += 0.48;
    }


    // Ò©¼Á£º¼²ËÙÒ©¼Á
    void Character::set_ji_su_yao_ji()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // Ò©¼Á£ºÊ¿±øÉËº¦
    void Character::set_shi_bing_shang_hai()
    {
        m_shang_hai_jia_cheng += 1;
    }


    // ÃëÉË¹«Ê½
    double Character::get_miao_shang()
    {
        // ±©»÷¼¸ÂÊ
        double bao_ji_ji_lv = m_bao_ji_ji_lv;
        bao_ji_ji_lv += m_bao_ji_ji_lv_jia;
        bao_ji_ji_lv += m_dong_cha_fu_zhou * 0.10; // ¶´²ì·ûÖä£¨10¼¶£©

        // ±©»÷ÉËº¦½±Àø
        double bao_ji_jiang_li = m_bao_ji_jiang_li;
        bao_ji_jiang_li += m_bao_ji_jiang_li_jia;
        bao_ji_jiang_li += m_min_jie_fu_zhou * 1.00; // Ãô½İ·ûÖä£¨10¼¶£©

        // ¹¥»÷ËÙ¶È
        double gong_ji_su_du = m_gong_ji_su_du;
        gong_ji_su_du *= ( 1 + m_gong_ji_su_du_jia_cheng + m_seng_lv_fu_zhou * SENG_LV_LEVEL ); // É®ÂÂ·ûÖä

        // »ù´¡ÉËº¦
        double ji_chu_shang_hai = get_wu_qi_shang_hai() + m_ji_chu_li_liang_jia; // +»ù´¡Á¦Á¿

        // ÉËº¦
        double shang_hai = ji_chu_shang_hai;
        shang_hai += ji_chu_shang_hai * m_feng_bao_fu_zhou * 0.24;     // ·ç±©·ûÖä£¨10¼¶£©
        shang_hai += ji_chu_shang_hai * m_yuan_su_shang_hai_jia_cheng; // +%ÔªËØÉËº¦

        // ±©»÷ÉËº¦
        double bao_ji_shang_hai = shang_hai * ( 1 + bao_ji_jiang_li ) * bao_ji_ji_lv;

        // ÆÕÍ¨ÉËº¦
        double pu_tong_shang_hai = shang_hai * ( 1 - bao_ji_ji_lv );

        // Æ½¾ùÉËº¦
        double ping_jun_shang_hai = bao_ji_shang_hai + pu_tong_shang_hai;

        // ÃëÉË
        double miao_shang = ( ping_jun_shang_hai * gong_ji_su_du ) * ( 1 + m_shang_hai_jia_cheng ); // +%ÉËº¦

        m_miao_shang = miao_shang;

        return m_miao_shang;
    }


    // ÎäÆ÷ÉËº¦
    double Character::get_wu_qi_shang_hai()
    {
        return m_wu_qi.get_shang_hai();
    }


    // ÃëÉËÁĞ±í
    void Character::get_dps_list( const Character& character_, DpsList& dps_list )
    {
        Character& character = const_cast<Character&>( character_ );
        Rings& all_ring = Store::instance().get_all_rings();

        dps_list.clear();

        for ( size_t i = 0; i <= MAX_FUZHOU_NUM; ++i ) // ·ç±©·ûÖä
        {
            for ( size_t j = 0; j <= MAX_FUZHOU_NUM; ++j ) // ¶´²ì·ûÖä
            {
                if ( MAX_FUZHOU_NUM < i + j )
                {
                    continue;
                }

                for ( size_t k = 0; k <= MAX_FUZHOU_NUM; ++k ) // Ãô½İ·ûÖä
                {
                    if ( MAX_FUZHOU_NUM < i + j + k )
                    {
                        continue;
                    }

                    for ( size_t m = 0; m <= MAX_FUZHOU_NUM; ++m ) // É®ÂÂ·ûÖä
                    {
                        if ( i + j + k + m != MAX_FUZHOU_NUM )
                        {
                            continue;
                        }

                        for ( Rings::iterator it = all_ring.begin(); it != all_ring.end(); ++it ) // ½äÖ¸
                        {
                            character.set_feng_bao_fu_zhou( i );
                            character.set_dong_cha_fu_zhou( j );
                            character.set_min_jie_fu_zhou( k );
                            character.set_seng_lv_fu_zhou( m );
                            character.set_ring( *it );

                            double dps = character.get_miao_shang();

                            DpsConfiguration dps_config;

                            dps_config.set_dps( dps );
                            dps_config.add_configuration( "·ç±©", i );
                            dps_config.add_configuration( "¶´²ì", j );
                            dps_config.add_configuration( "Ãô½İ", k );
                            dps_config.add_configuration( "É®ÂÂ", m );
                            dps_config.add_configuration( it->m_name );

                            dps_list.insert( dps_config );
                        }
                    }
                }
            }
        }

        assert( false == dps_list.empty() );
    }

} // DungeonHunter4
