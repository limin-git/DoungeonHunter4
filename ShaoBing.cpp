#include "stdafx.h"
#include "ShaoBing.h"


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

        m_bao_ji_ji_lu_jia += 1.0;
        m_bao_ji_jiang_li_jia += 0.3;
    }

    double ShaoBing::get_adjustment()
    {
        double adjustment = 0;

        if ( true == m_is_set_ying_yan )
        {
            adjustment -= 0.1 * get_wu_qi_shang_hai();
            adjustment -= 0.1 * get_wu_qi_shang_hai() * get_yuan_su_shang_hai_jia_cheng();

            // TODO: ��ָ��+������%�˺�
            double ring_adjustment = 0;
            ring_adjustment -= 0.1 * m_ring.m_ji_chu_li_liang_jia * ( 1 + m_ring.m_shang_hai_jia_cheng ) * ( 1 + m_ring.m_bao_ji_jiang_li_jia );
            ring_adjustment -= 0.1 * m_ring.m_ji_chu_li_liang_jia * ( 1 + m_ring.m_shang_hai_jia_cheng ) * m_ring.m_yuan_su_shang_hai_jia_cheng;

            adjustment += ring_adjustment;
        }

        return adjustment;
    }

    double ShaoBing::get_yuan_su_shang_hai_jia_cheng()
    {
        return m_feng_bao_fu_zhou * 0.24 + m_yuan_su_shang_hai_jia_cheng;
    }

    double ShaoBing::ge_max_dps()
    {
        double max_dps = 0;
        size_t feng_bao = 0;
        size_t min_jie = 0;
        std::string ring;

        const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ���乭" );
        Rings& all_ring = Store::instance().get_all_rings();

        for ( size_t i = 0; i <= 15; ++i )
        {
            for ( Rings::iterator it = all_ring.begin(); it != all_ring.end(); ++it )
            {
                ShaoBing shao_bing;

                shao_bing.set_wu_qi( wu_qi );
                shao_bing.set_bing_shuang_zhi_jian();   // �������ܣ���˪֮��
                shao_bing.set_ying_yan();               // �������ܣ�ӥ��

                shao_bing.set_ring( *it );
                shao_bing.set_feng_bao_fu_zhou( i );
                shao_bing.set_min_jie_fu_zhou( 15 - i );

                double dps = shao_bing.get_miao_shang();

                if ( max_dps < dps )
                {
                    max_dps = dps;
                    feng_bao = i;
                    min_jie = 15 - i;
                    ring = it->m_name;
                }

                std::cout << "�籩=" << i << "������=" << 15 - i << "��" << it->m_name << "������=" << std::setprecision(10) << dps << "" << std::endl;
            }
        }

        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "�籩���䣺" << feng_bao << std::endl;
        std::cout << "���ݷ��䣺" << min_jie << std::endl;
        std::cout << "��ָ��    " << ring << std::endl;
        std::cout << "�������ˣ�" << std::setprecision(10) << max_dps << std::endl;

        return max_dps;
    }

} // namespace DungeonHunter4
