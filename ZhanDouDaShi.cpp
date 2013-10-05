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

    // 被动技能：愤怒
    void ZhanDouDaShi::set_fen_nu()
    {
        m_shang_hai_jia_cheng += 0.4;
    }

    // 被动技能：技术老手
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
                os << "风暴=" << m_feng_bao << "，洞察=" << m_dong_cha << "，敏捷=" << m_min_jie << "，" << m_ring << "，秒伤=" << std::setprecision(10) << m_dps;
            }
        };

        std::set<ZhanDouDaShiDps> dps_list;

        double max_dps = 0;
        size_t feng_bao = 0;
        size_t dong_cha = 0;
        size_t min_jie = 0;
        std::string ring;

        // 圣洁长剑
        const WuQi& wu_qi = Store::instance().get_wu_qi( "圣洁长剑" );
        Rings& all_ring = Store::instance().get_all_rings();

        for ( size_t i = 0; i <= 15; ++i ) // 风暴
        {
            for ( size_t j = 0; j <= 15; ++j ) // 洞察
            {
                if ( 15 < i + j )
                {
                    continue;
                }

                for ( size_t k = 0; k <= 15; ++k ) // 敏捷
                {
                    if ( i + j + k != 15 )
                    {
                        continue;
                    }

                    for ( Rings::iterator it = all_ring.begin(); it != all_ring.end(); ++it )
                    {
                        ZhanDouDaShi zhan_dou_da_shi;

                        zhan_dou_da_shi.set_wu_qi( wu_qi );
                        zhan_dou_da_shi.set_fen_nu();           // 被动技能：愤怒
                        zhan_dou_da_shi.set_ji_shu_lao_shou();  // 被动技能：技术老手

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

        //std::cout << "风暴符咒：" << feng_bao << std::endl;
        //std::cout << "洞察符咒：" << dong_cha << std::endl;
        //std::cout << "敏捷符咒：" << min_jie << std::endl;
        //std::cout << "戒指：    " << ring << std::endl;
        //std::cout << "极限秒伤：" << std::setprecision(10) << max_dps << std::endl;

        return max_dps;
    }

} // namespace DungeonHunter4
