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


    // �������ܣ�����
    void ShaoBing::set_ji_xing()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // �������ܣ���˪֮��
    void ShaoBing::set_bing_shuang_zhi_jian()
    {
        m_yuan_su_shang_hai_jia_cheng += 0.4;
    }


    // �������ܣ�ӥ��
    void ShaoBing::set_ying_yan()
    {
        // �������ܣ�ӥ�ۼ���
        // + 100% ��������
        // + 30% �����˺�����
        // - 10% �����˺�
        // - 10% �����˺� x Ԫ���˺�

        m_is_set_ying_yan = true;

        m_bao_ji_ji_lv_jia += 1;
        m_bao_ji_jiang_li_jia += 0.3;
    }


    // ҩ��������ҩ��
    void ShaoBing::set_ji_su_yao_ji()
    {
        m_gong_ji_su_du_jia_cheng += 0.5;
    }


    // ҩ����ʿ���˺�
    void ShaoBing::set_shi_bing_shang_hai()
    {
        m_shang_hai_jia_cheng += 1;
    }


    double ShaoBing::ge_max_dps( size_t output_list_size )
    {
        DpsList dps_list;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ���乭" );
        Rings& all_ring = Store::instance().get_all_rings();

        for ( size_t i = 0; i <= 15; ++i ) // �籩
        {
            for ( size_t j = 0; j <= 15; ++j ) // ����
            {
                if ( i + j > 15 )
                {
                    continue;
                }

                for ( size_t k = 0; k <= 15; ++k ) // ɮ��
                {
                    if ( i + j + k != 15 )
                    {
                        continue;
                    }

                    for ( Rings::iterator it = all_ring.begin(); it != all_ring.end(); ++it ) // ��ָ
                    {
                        ShaoBing shao_bing;

                        shao_bing.set_wu_qi( wu_qi );
                        shao_bing.set_ji_xing();                // �������ܣ�����
                        shao_bing.set_bing_shuang_zhi_jian();   // �������ܣ���˪֮��
                        shao_bing.set_ying_yan();               // �������ܣ�ӥ��
                        //shao_bing.set_shen_en_tian_ci();        // �������ܣ�������
                        shao_bing.set_ji_su_yao_ji();           // ҩ��������ҩ��
                        shao_bing.set_shi_bing_shang_hai();     // ҩ����ʿ���˺�

                        shao_bing.set_feng_bao_fu_zhou( i );
                        shao_bing.set_min_jie_fu_zhou( j );
                        shao_bing.set_seng_lv_fu_zhou( k );
                        shao_bing.set_ring( *it );

                        double dps = shao_bing.get_miao_shang();

                        DpsConfiguration dps_config;

                        dps_config.set_dps( dps );
                        dps_config.add_configuration( "�籩", i );
                        dps_config.add_configuration( "����", j );
                        dps_config.add_configuration( "ɮ��", k );
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
