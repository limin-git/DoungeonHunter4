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
        struct ZhanDouDaShiDps
        {
            ZhanDouDaShiDps( double dps = 0, 
                size_t feng_bao = 0,
                size_t dong_cha = 0,
                size_t min_jie = 0,
                const std::string& ring = "" )
            : m_dps( dps ),
              m_feng_bao( feng_bao ),
              m_dong_cha( dong_cha ),
              m_min_jie( min_jie ),
              m_ring( ring )
            {
            }

            double m_dps;
            size_t m_feng_bao;
            size_t m_dong_cha;
            size_t m_min_jie;
            std::string m_ring;

            bool operator<( const ZhanDouDaShiDps& rhs ) const
            {
                return m_dps > rhs.m_dps;
            }

            void output( std::ostream& os ) const
            {
                os << "�籩=" << m_feng_bao << "������=" << m_dong_cha << "������=" << m_min_jie << "��" << m_ring << "������=" << std::setprecision(10) << m_dps;
            }
        };

        std::set<ZhanDouDaShiDps> dps_list;

        double max_dps = 0;
        size_t feng_bao = 0;
        size_t dong_cha = 0;
        size_t min_jie = 0;
        std::string ring;

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
                    if ( i + j + k != 15 )
                    {
                        continue;
                    }

                    for ( Rings::iterator it = all_ring.begin(); it != all_ring.end(); ++it )
                    {
                        ZhanDouDaShi zhan_dou_da_shi;

                        zhan_dou_da_shi.set_wu_qi( wu_qi );
                        zhan_dou_da_shi.set_fen_nu();           // �������ܣ���ŭ
                        zhan_dou_da_shi.set_ji_shu_lao_shou();  // �������ܣ���������

                        zhan_dou_da_shi.set_ring( *it );
                        zhan_dou_da_shi.set_feng_bao_fu_zhou( i );
                        zhan_dou_da_shi.set_dong_cha_fu_zhou( j );
                        zhan_dou_da_shi.set_min_jie_fu_zhou( k );

                        double dps = zhan_dou_da_shi.get_miao_shang();

                        dps_list.insert( ZhanDouDaShiDps( dps, i, j, k, it->m_name ) );
                    }
                }
            }
        }

        size_t i = 0;

        for ( std::set<ZhanDouDaShiDps>::iterator it = dps_list.begin(); it != dps_list.end() && i < 100; ++it, ++i  )
        {
            it->output( std::cout );
            std::cout << std::endl;
        }

        //std::cout << "�籩���䣺" << feng_bao << std::endl;
        //std::cout << "������䣺" << dong_cha << std::endl;
        //std::cout << "���ݷ��䣺" << min_jie << std::endl;
        //std::cout << "��ָ��    " << ring << std::endl;
        //std::cout << "�������ˣ�" << std::setprecision(10) << max_dps << std::endl;

        return max_dps;
    }

} // namespace DungeonHunter4
