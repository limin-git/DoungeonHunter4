#include "stdafx.h"
#include "ZhanDouDaShi.h"


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
        m_bao_ji_ji_lu_jia += 0.3;
        m_bao_ji_jiang_li_jia += 1;
    }

    double ZhanDouDaShi::ge_max_dps()
    {
        double max_dps = 0;
        size_t feng_bao = 0;
        size_t dong_cha = 0;
        size_t min_jie = 0;
        std::string ring;

        // ʥ�೤��
        const WuQi& wu_qi = Store::instance().get_wu_qi( "ʥ�೤��" );
        std::map<std::string, Ring*>& all_ring = Store::instance().get_all_ring();

        for ( size_t i = 0; i <= 15; ++i ) // �籩
        {
            for ( size_t j = 0; j <= 15; ++j ) // ����
            {
                if ( i + j > 15 )
                {
                    continue;
                }

                for ( size_t k = 0; k <= 15; ++k ) // ����
                {
                    if ( i + j + k != 15 )
                    {
                        continue;
                    }

                    for ( std::map<std::string, Ring*>::iterator it = all_ring.begin(); it != all_ring.end(); ++it )
                    {
                        ZhanDouDaShi zhan_dou_da_shi;

                        zhan_dou_da_shi.set_wu_qi( wu_qi );
                        zhan_dou_da_shi.set_fen_nu();           // �������ܣ���ŭ
                        zhan_dou_da_shi.set_ji_shu_lao_shou();  // �������ܣ���������

                        zhan_dou_da_shi.set_ring( *(it->second) );
                        zhan_dou_da_shi.set_feng_bao_fu_zhou( i );
                        zhan_dou_da_shi.set_dong_cha_fu_zhou( j );
                        zhan_dou_da_shi.set_min_jie_fu_zhou( k );

                        double dps = zhan_dou_da_shi.get_miao_shang();

                        if ( max_dps < dps )
                        {
                            max_dps = dps;
                            feng_bao = i;
                            dong_cha = j;
                            min_jie = k;
                            ring = it->first;
                        }
                    }
                }
            }
        }

        std::cout << "�籩���䣺" << feng_bao << std::endl;
        std::cout << "������䣺" << dong_cha << std::endl;
        std::cout << "���ݷ��䣺" << min_jie << std::endl;
        std::cout << "��ָ��    " << ring << std::endl;
        std::cout << "�������ˣ�" << std::setprecision(20) << max_dps << std::endl;

        return max_dps;
    }

} // namespace DungeonHunter4
