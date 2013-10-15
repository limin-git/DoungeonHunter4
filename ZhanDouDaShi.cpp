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


    // �������ܣ���ŭ
    void ZhanDouDaShi::set_fen_nu()
    {
        m_shang_hai_jia_cheng += 0.4;
    }


    // �������ܣ���������
    void ZhanDouDaShi::set_ji_shu_lao_shou()
    {
        m_bao_ji_ji_lv_jia += 0.3;
        m_bao_ji_jiang_li_jia += 1;
    }


    // ҩ��������ҩ��
    void ZhanDouDaShi::set_ji_su_yao_ji()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // ҩ����ʿ���˺�
    void ZhanDouDaShi::set_shi_bing_shang_hai()
    {
        m_shang_hai_jia_cheng += 1.4;
    }


    double ZhanDouDaShi::ge_max_dps( size_t output_list_size )
    {
        DpsList dps_list;

        // ʥ�೤��
        const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ�೤��" );
        Rings& all_ring = Store::instance().get_all_rings();

        for ( size_t i = 0; i <= 15; ++i ) // �籩
        {
            for ( size_t j = 0; j <= 15; ++j ) // ����
            {
                if ( 15 < i + j )
                {
                    continue;
                }

                for ( size_t k = 0; k <= 15; ++k ) // ����
                {
                    if ( 15 < i + j + k )
                    {
                        continue;
                    }

                    for ( size_t m = 0; m <= 15; ++m ) // ɮ��
                    {
                        if ( i + j + k + m != 15 )
                        {
                            continue;
                        }

                        for ( Rings::iterator it = all_ring.begin(); it != all_ring.end(); ++it ) // ��ָ
                        {
                            ZhanDouDaShi zhan_dou_da_shi;

                            zhan_dou_da_shi.set_wu_qi( wu_qi );
                            zhan_dou_da_shi.set_fen_nu();                   // �������ܣ���ŭ
                            zhan_dou_da_shi.set_ji_shu_lao_shou();          // �������ܣ���������
                            zhan_dou_da_shi.set_ji_su_yao_ji();             // ҩ��������ҩ��
                            zhan_dou_da_shi.set_shi_bing_shang_hai();       // ҩ����ʿ���˺�

                            zhan_dou_da_shi.set_ring( *it );
                            zhan_dou_da_shi.set_feng_bao_fu_zhou( i );
                            zhan_dou_da_shi.set_dong_cha_fu_zhou( j );
                            zhan_dou_da_shi.set_min_jie_fu_zhou( k );
                            zhan_dou_da_shi.set_seng_lv_fu_zhou( m );

                            double dps = zhan_dou_da_shi.get_miao_shang();

                            DpsConfiguration dps_config;

                            dps_config.set_dps( dps );
                            dps_config.add_configuration( "�籩", i );
                            dps_config.add_configuration( "����", j );
                            dps_config.add_configuration( "����", k );
                            dps_config.add_configuration( "ɮ��", m );
                            dps_config.add_configuration( it->m_name );

                            dps_list.insert( dps_config );
                        }
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
