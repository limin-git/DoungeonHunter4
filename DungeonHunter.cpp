// DungeonHunter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>


class DungeonHunter
{
public:

    DungeonHunter( double shang_hai_min, double shang_hai_max, double gong_ji_su_du, double bao_ji_ji_lu, double bao_ji_jiang_li )
        : m_shang_hai_min( shang_hai_min ),
          m_shang_hai_max( shang_hai_max ),
          m_gong_ji_su_du( gong_ji_su_du ),
          m_bao_ji_ji_lu( bao_ji_ji_lu ),
          m_bao_ji_jiang_li( bao_ji_jiang_li )
    {
        m_gong_ji_su_du = 2;

        m_feng_bao = 0;
        m_min_jie = 0;

        m_shang_hai_jia_cheng = 0;
    }


    DungeonHunter( size_t feng_bao, size_t ming_jie )
        : m_feng_bao( feng_bao ),
          m_min_jie( ming_jie )
    {
        
    }

    void set_feng_bao( size_t feng_bao )
    {
        m_feng_bao = feng_bao;
    }

    void set_min_jie( size_t min_jie )
    {
        m_min_jie = min_jie;
    }

    void set_bing_shuang_zhi_jian()
    {
        m_shang_hai_jia_cheng = 0.4;
    }




    double miao_shang()
    {
        double m_shang_hai = std::ceil( ( m_shang_hai_min + m_shang_hai_max ) / 2.0 );

        double bao_ji_shang_hai = m_shang_hai * ( 1 + m_bao_ji_jiang_li ) * m_bao_ji_ji_lu;

        double pu_tong_shang_hai = m_shang_hai * ( 1 - m_bao_ji_ji_lu );

        double miang_shang = ( bao_ji_shang_hai + pu_tong_shang_hai ) * m_gong_ji_su_du;

        return miang_shang;
    }


    double miao_shang_with_fu_shou()
    {
        double m_shang_hai = std::ceil( ( m_shang_hai_min + m_shang_hai_max ) / 2.0 );

        double bao_ji_shang_hai = ( m_shang_hai * ( 1.0 + m_bao_ji_jiang_li + m_min_jie ) * m_bao_ji_ji_lu );

        double pu_tong_shang_hai = ( m_shang_hai * ( 1.0 - m_bao_ji_ji_lu ) );

        double shang_hai = bao_ji_shang_hai;
        
        if ( 0 < pu_tong_shang_hai )
        {
            shang_hai += pu_tong_shang_hai;
        }

        double miang_shang = shang_hai * m_gong_ji_su_du;

        return miang_shang * ( 1 + m_feng_bao * 0.24 + m_shang_hai_jia_cheng );
    }

private:

    double m_shang_hai_min;
    double m_shang_hai_max;
    double m_gong_ji_su_du;
    double m_bao_ji_ji_lu;
    double m_bao_ji_jiang_li;

    // ¼¼ÄÜ
    double m_shang_hai_jia_cheng;

    // ·ûÖä

    size_t m_feng_bao;
    size_t m_min_jie;
};



// ÉËº¦: 101107 = 100892 + 214
// ¹¥»÷ËÙ¶È: 0%
// ±©»÷¼¸ÂÊ: 5%
// ±©»÷½±Àø: 50%



//227424.48
//408254.68
//162446
//72484 - 85999 avg= 79241.5

//158483


#if 0
double caculate_max_dps()
{
    double max_dps = 0;
    size_t feng_bao = 0;
    size_t min_jie = 0;

    double shang_hai_min = 72484;
    double shang_hai_max = 85999;

    double gong_ji_su_du = 0;
    double bao_ji_ji_lu = 1.05;
    double bo_ji_jiang_li = 0.8;

    DungeonHunter my( shang_hai_min, shang_hai_max, gong_ji_su_du, bao_ji_ji_lu, bo_ji_jiang_li );


    for ( size_t i = 0; i < 15; ++i )
    {
        my.set_feng_bao( i );
        my.set_min_jie( 15 - i );

        double dps = my.miao_shang_with_fu_shou();

        if ( dps > max_dps )
        {
            max_dps = dps;
            feng_bao = i;
            min_jie = 15 - i;
        }
    }

    std::cout << "Feng Bao: " << feng_bao << std::endl;
    std::cout << "Min Jie:  " << min_jie << std::endl;

    return max_dps;
}

#endif



int _tmain(int argc, _TCHAR* argv[])
{
    double shang_hai_min = 72484;
    double shang_hai_max = 85999;

    //double shang_hai_min = 19209;
    //double shang_hai_max = 22685;

    //double shang_hai_min = 288;
    //double shang_hai_max = 327;

    //double shang_hai_min = 19209;
    //double shang_hai_max = 22685;

    double gong_ji_su_du = 0;
    double bao_ji_ji_lu = 0.05;
    double bo_ji_jiang_li = 0.5;

    DungeonHunter my( shang_hai_min, shang_hai_max, gong_ji_su_du, bao_ji_ji_lu, bo_ji_jiang_li );

    my.set_min_jie( 10 );
    my.set_feng_bao( 5 );
    my.set_bing_shuang_zhi_jian();

    //double miao_shang = my.miao_shang();
    double miao_shang_with_fu_zhou = my.miao_shang_with_fu_shou();

    //std::cout.unsetf( std::ios::scientific );
    //std::cout <<  std::setprecision(20) << miao_shang << std::endl;
    std::cout <<  std::setprecision(20) << miao_shang_with_fu_zhou << std::endl;


    //std::cout << caculate_max_dps() << std::endl;

	return 0;
}
